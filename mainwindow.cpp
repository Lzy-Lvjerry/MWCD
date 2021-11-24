#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QDebug>
#include <QDoubleValidator>
#include <QAction>
#include <sstream>
#include <QFileDialog>
#include <QTextCodec>
#include <QIntValidator>
#include <QMessageBox>
#include <QScreen>
#include <QToolButton>
#include <QDesktopWidget>
#include <QObjectList>
#include <iomanip>
#include <iostream>
#include <QClipboard>
MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow ),
    _pDrawMethodGroup( new QButtonGroup( this ) )
{
    ui->setupUi( this );
    this->setWindowTitle( QString::fromLocal8Bit( "底水气藏水锥动态模拟软件" ) );
    // 需初始化在setupUi后，无法使用std::unique_ptr
    _pPlotDrawWindow  = new QDrawWindow( ui->wg_plotDrawWindow );
    _pTorusDrawWindow = new QDrawWindow( ui->wg_torusDrawWindow );
    autoZoomUI();
    initQObject();
    initConnect();
    initModel();
}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow";
    delete _pTorusDrawWindow;
    delete _pPlotDrawWindow;
    delete _pDrawMethodGroup;
    delete ui;
}

void MainWindow::initModel()
{
    MWCDModel::getMWCDModel().setModelParams(
            ui->lineEdit_K->text().toDouble(),
            ui->lineEdit_hp->text().toDouble(),
            ui->lineEdit_rg->text().toDouble(),
            ui->lineEdit_u->text().toDouble(),
            ui->lineEdit_rw->text().toDouble(),
            ui->lineEdit_r1->text().toDouble(),
            ui->lineEdit_S->text().toDouble(),
            ui->lineEdit_re->text().toDouble(),
            ui->lineEdit_q->text().toDouble(),
            ui->lineEdit_h2->text().toDouble(),
            ui->lineEdit_fi->text().toDouble(),
            ui->lineEdit_Swi->text().toDouble(),
            ui->lineEdit_Sgr->text().toDouble() );

}

void MainWindow::on_bt_startDraw_clicked()
{
    initModel();

    if( MWCDModel::getMWCDModel().paramsHasZero() )
    {
        QMessageBox::critical( NULL, QString::fromLocal8Bit( "错误" ),
                QString::fromLocal8Bit( "参数存在空值(或0)" ) );
        return;
    }
    std::tuple<std::vector<double>, std::vector<double> > resultTuple;

    if( ui->rb_drawBreakthroughTime->isChecked() )
    {
        qDebug() << "rb_drawBreakthroughTime";
        resultTuple = MWCDModel::getMWCDModel().getBTPredicionData();

    }
    else if( ui->rb_drawInputTime->isChecked() )
    {
        qDebug() << "rb_drawInputTime: " << ui->lineEdit_time->text();
        resultTuple = MWCDModel::getMWCDModel().getITPredicionData( ui->lineEdit_time->text().toDouble() );
    }

    auto [ xAxisData, yAxisData ] = resultTuple;

    _xData = xAxisData;
    _yData = yAxisData;

    double legendNum = ( static_cast<int>( MWCDModel::getMWCDModel().getBreakthroughTime() * 10 + 0.5 ) ) / 10.0;
    qDebug() << legendNum;

    _pPlotDrawWindow->drawByPlot( xAxisData, yAxisData,
            MWCDTool::doubleToString( legendNum ), "r(m)", "z(m)", true );
    _pTorusDrawWindow->drawByTorus( xAxisData, yAxisData );

    MWCDModel::printModelParams();
    qDebug() << MWCDTool::doubleToString( MWCDModel::getMWCDModel().getBreakthroughTime() ).c_str();

    outputResult();
//    test();
}

void MainWindow::outputResult()
{
    QString time( QString::fromLocal8Bit( "见水时间 t = %1年" ).arg( MWCDModel::getMWCDModel().getBreakthroughTime() ) );
    ui->tb_resultView->setText( time );
}

void MainWindow::autoZoomUI()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    int lcd_width  = screen->size().width();
    int lcd_height = screen->size().height();
    qDebug() << QString::fromLocal8Bit( "当前分辨率：" ) << screen->size();

    double factorX = lcd_width / 1920.0;
    double factorY = lcd_height / 1080.0;

    if( factorX >= 1
        && factorY >= 1 )
    {
        return;
    }
    setFixedSize( QDesktopWidget().width() * factorX, QDesktopWidget().height() * factorY );
    ui->wg_plotDrawWindow->setFixedSize( ui->wg_plotDrawWindow->size().width() * factorX,
            ui->wg_plotDrawWindow->size().height() * factorY );
    ui->wg_torusDrawWindow->setFixedSize( ui->wg_torusDrawWindow->size().width() * factorX,
            ui->wg_torusDrawWindow->size().height() * factorY );
    ui->wg_plotDrawWindow->move( ui->wg_plotDrawWindow->x() * factorX,
            ui->wg_plotDrawWindow->y() * factorY );
    ui->wg_torusDrawWindow->move( ui->wg_torusDrawWindow->x() * factorX,
            ui->wg_torusDrawWindow->y() * factorY );

    ui->rb_drawBreakthroughTime->move( ui->rb_drawBreakthroughTime->x() * factorX,
            ui->rb_drawBreakthroughTime->y() * factorY );
    ui->rb_drawInputTime->move( ui->rb_drawInputTime->x() * factorX,
            ui->rb_drawInputTime->y() * factorY );
    resetLineEditGeometry( factorX, factorY );
    resetButtonGeometry( factorX, factorY );

}

void MainWindow::resetButtonGeometry( const double &factorX, const double &factorY )
{
    QList<QPushButton*> lBt = this->findChildren<QPushButton*>();

    for( auto bt : lBt )
    {
        bt->move( bt->x() * factorX, bt->y() * factorY );
        bt->adjustSize();
//        bt->setMaximumSize(bt->width()*factorX,bt->height()*factorY);
//        bt->setMinimumSize(bt->width()*factorX, bt->height()*factorY);
    }
}

void MainWindow::resetLineEditGeometry( const double &factorX, const double &factorY )
{
    QList<QLineEdit*> lLE = this->findChildren<QLineEdit*>();
    QList<QLabel*>    lLb = this->findChildren<QLabel*>();

    for( auto le : lLE )
    {
        le->move( le->x() * factorX, le->y() * factorY );
        le->resize( le->width() * factorX, le->height() * factorY );
    }
    QFont ft;
    ft.setPointSize( 8 );

    for( auto lb : lLb )
    {
        lb->move( lb->x() * factorX, lb->y() * factorY );
        lb->resize( lb->width() * factorX, lb->height() * factorY );
        lb->setFont( ft );
        lb->adjustSize();
    }
}

void MainWindow::on_bt_clearDraw_clicked()
{
    _pPlotDrawWindow->clearDraw();
    _pTorusDrawWindow->clearDraw();
    ui->tb_resultView->clear();
}

void MainWindow::on_action_close_clicked()
{
    this->close();
}

void MainWindow::initConnect()
{
    // connect(ui->action_close, SIGNAL(triggered()), this, SLOT(on_action_close_clicked()));
    connect( ui->actionExit, &QAction::triggered, this, [ this ]() {
        this->close();
    } );
    connect( ui->action_sens, SIGNAL(triggered()), this, SLOT(on_action_sens_clicked()) );
}

void MainWindow::on_bt_clearInput_clicked()
{
    ui->lineEdit_K->clear();
    ui->lineEdit_S->clear();
    ui->lineEdit_Sgr->clear();
    ui->lineEdit_Swi->clear();
    ui->lineEdit_fi->clear();
    ui->lineEdit_h2->clear();
    ui->lineEdit_hp->clear();
    ui->lineEdit_q->clear();
    ui->lineEdit_r1->clear();
    ui->lineEdit_re->clear();
    ui->lineEdit_rg->clear();
    ui->lineEdit_rw->clear();
    ui->lineEdit_u->clear();
}

void MainWindow::initQObject()
{
    ui->lineEdit_K->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_S->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_Sgr->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_Swi->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_fi->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_h2->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_hp->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_q->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_r1->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_re->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_rg->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_rw->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_u->setValidator( new QDoubleValidator( this ) );
    ui->lineEdit_time->setValidator( new QDoubleValidator( this ) );
    _pDrawMethodGroup->addButton( ui->rb_drawBreakthroughTime );
    _pDrawMethodGroup->addButton( ui->rb_drawInputTime );
    ui->rb_drawBreakthroughTime->setChecked( true );


    ui->lineEdit_K->setText( QString::number( 8.3408 ) );
    ui->lineEdit_hp->setText( QString::number( 91 ) );
    ui->lineEdit_rg->setText( QString::number( 0.59 ) );
    ui->lineEdit_u->setText( QString::number( 0.02 ) );
    ui->lineEdit_rw->setText( QString::number( 0.1 ) );
    ui->lineEdit_r1->setText( QString::number( 80 ) );
    ui->lineEdit_S->setText( QString::number( -3 ) );
    ui->lineEdit_re->setText( QString::number( 1100 ) );
    ui->lineEdit_q->setText( QString::number( 400000 ) );
    ui->lineEdit_h2->setText( QString::number( 80 ) );
    ui->lineEdit_fi->setText( QString::number( 0.035 ) );
    ui->lineEdit_Swi->setText( QString::number( 0.28 ) );
    ui->lineEdit_Sgr->setText( QString::number( 0.25 ) );
}

void MainWindow::on_bt_savePlotDraw_clicked()
{
    if( _pPlotDrawWindow->drawWindowIsEmpty() )
    {
        return;
    }
    std::string filepath = QFileDialog::getSaveFileName( this,
            "choose Directory",
            "",
            tr( "(*.png)" ) ).toStdString();

    if( filepath.empty() )
    {
        return;
    }
    qDebug() << filepath.c_str();
    _pPlotDrawWindow->saveDraw( filepath );
}

void MainWindow::on_bt_saveTorusDraw_clicked()
{
    if( _pTorusDrawWindow->drawWindowIsEmpty() )
    {
        return;
    }
    std::string filepath = QFileDialog::getSaveFileName( this,
            "choose Directory",
            "",
            tr( "(*.png)" ) ).toStdString();

    if( filepath.empty() )
    {
        return;
    }
    qDebug() << filepath.c_str();
    _pTorusDrawWindow->saveDraw( filepath );
}

// 打开敏感性分析窗口
void MainWindow::on_action_sens_clicked()
{
    initModel();
    _pSAWindow = new SensitivityAnalysis();
    _pSAWindow->show();
}

void MainWindow::on_bt_copyData_clicked()
{
    if( _pPlotDrawWindow == nullptr )
    {
        return;
    }
    std::string rs = "r(m)\tz(m)\n";

    for( int i = _xData.size() - 1; i >= 0; --i )
    {
        rs += std::to_string( _xData[ i ] ) + "\t" + std::to_string( _yData[ i ] ) + "\n";
    }
    QClipboard *board = QApplication::clipboard();
    board->setText( QString::fromStdString( rs ) );
}

