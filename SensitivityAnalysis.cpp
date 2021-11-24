#include "Sensitivityanalysis.h"
#include "ui_SensitivityAnalysis.h"
#include <vector>
#include <QFileDialog>
#include <QModelIndexList>
#include <QModelIndex>
#include <QMap>
#include <QClipboard>

const int TABLEDATANUM = 1000;

SensitivityAnalysis::SensitivityAnalysis( QWidget *parent ) :
    QDialog( parent ),
    ui( new Ui::SensitivityAnalysis ),
    _pDrawWindow( nullptr )
{
    ui->setupUi( this );
    initConnect();
    initWidget();

    _pDrawWindow = new QDrawWindow( ui->wg_drawWindow );
    _pDrawWindow->setDrawZoomOff();
    this->setWindowTitle( QString::fromLocal8Bit( "敏感性分析" ) );
}

SensitivityAnalysis::~SensitivityAnalysis()
{
    delete _pDrawWindow;
    delete ui;
}

void SensitivityAnalysis::on_bt_startSens_clicked()
{
    if( MWCDModel::getMWCDModel().paramsHasZero() )
    {
        return;
    }
    double sensMin = ui->le_sensMin->text().toDouble();
    double sensMax = ui->le_sensMax->text().toDouble();

    QStandardItemModel *itemModel = new QStandardItemModel( this );

    // 第0列表头 t(a)
    itemModel->setItem( 0, 0, new QStandardItem( "t(a)" ) );

    std::vector<double> xData;
    std::vector<double> yData;

    if( sensMin >= sensMax )
    {
        return;
    }
    double forStep = ( sensMax - sensMin ) / TABLEDATANUM;

    qDebug() << "Clicked bt_startSens: " << MWCDModel::getMWCDModel();

    analyticParams = ANALYTICPARAMS( ui->cb_selectVar->currentIndex() );
    double breakTime;
    int    row = 1;
    double paramTemp;

    for( double i = sensMin; i < sensMax; i += forStep, ++row )
    {
        switch( analyticParams )
        {
            // 孔隙度
            case AP_FI:
            {
                itemModel->setItem( 0, 1, new QStandardItem( QString::fromLocal8Bit( "Φ(f)" ) ) );
                _upMWCDModel->setParamFi( i );
                break;
            }
            // 高度h2
            case AP_H2:
            {
                itemModel->setItem( 0, 1, new QStandardItem( "h2(m)" ) );
                _upMWCDModel->setParamH2( i );
                break;
            }
            // hp
            case AP_HP:
            {
                itemModel->setItem( 0, 1, new QStandardItem( "hp(m)" ) );
                _upMWCDModel->setParamHp( i );
                break;
            }
            // S
            case AP_S:
            {
                itemModel->setItem( 0, 1, new QStandardItem( "S(f)" ) );
                _upMWCDModel->setParamS( i );
                break;
            }
            // re
            case AP_RE:
            {
                itemModel->setItem( 0, 1, new QStandardItem( "re(m)" ) );
                _upMWCDModel->setParamRe( i );
                break;
            }
            // r1
            case AP_R1:
            {
                itemModel->setItem( 0, 1, new QStandardItem( "r1(m)" ) );
                _upMWCDModel->setParamR1( i );
                break;
            }
            // q
            case AP_Q:
            {
                itemModel->setItem( 0, 1, new QStandardItem( "q(10^4*m^3/d)" ) );
                _upMWCDModel->setParamQ( i );
                break;
            }
        }
        breakTime =  _upMWCDModel->getBreakthroughTime();
        qDebug() << *_upMWCDModel;
        itemModel->setItem( row, 0, new QStandardItem(  QString::number( breakTime, 'f' ) )  );
        itemModel->setItem( row, 1, new QStandardItem( QString::number( i, 'f' ) ) );

        if( breakTime <= 0 )
        {
            continue;
        }
        xData.push_back( i );
        yData.push_back( breakTime );


    }
    std::string xText = std::string( ui->cb_selectVar->currentText().toLocal8Bit() );
    _pDrawWindow->drawByPlot( xData, yData, xText, xText, "t(d)", false, false );
    ui->tv_resultTable->setModel( itemModel );

}

void SensitivityAnalysis::on_bt_saveGraph_clicked()
{
    if( _pDrawWindow->drawWindowIsEmpty() )
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
    _pDrawWindow->saveDraw( filepath );
}

void SensitivityAnalysis::on_bt_copyTableData_clicked()
{
    if( _pDrawWindow->drawWindowIsEmpty() )
    {
        qDebug() << "drawing window empty";
        return;
    }
    QString rs = "";

    QAbstractItemModel *model = ui->tv_resultTable->model();
    QModelIndex        index;
    QVariant           data;

    for( int row = 0; row <= TABLEDATANUM; ++row )
    {
        for( int col = 0; col < 2; ++col )
        {
            index = model->index( row, col );
            data  = model->data( index );
            rs   += data.toString() + "\t";
        }
        rs += "\n";
    }


    QClipboard *board = QApplication::clipboard();
    board->setText( rs );
}

void SensitivityAnalysis::initConnect()
{
    qDebug() << "init sens connect";
}

void SensitivityAnalysis::initWidget()
{
    qDebug() << "init sens widget";

    ui->le_sensMin->setValidator( new QDoubleValidator() );
    ui->le_sensMax->setValidator( new QDoubleValidator() );
    ui->le_sensMin->setText( QString::number( 0 ) );
}

