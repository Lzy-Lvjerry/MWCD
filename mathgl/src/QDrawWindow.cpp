#include "QDrawWindow.h"
#include <QDebug>
#include <QLocale>
QDWImplementation::QDWImplementation() :
    _data( QDWData() ),
    _pPlotGraph( nullptr ),
    _pTorusGraph( nullptr ),
    _emptyDraw( true )
{
}

QDWImplementation::~QDWImplementation()
{
    qDebug() << "~QDWImplementation";
}

QDrawWindow::QDrawWindow( QWidget *const qwidget ) :
    _upQDWImplementation( new QDWImplementation() ),
    _upQMGL( new QMathGL( qwidget ) )
{
//    QLocale local(QLocale(QLocale::Chinese, QLocale::China));
//    _upQMGL.get()->setLocale(local);
}

QDrawWindow::~QDrawWindow()
{
    qDebug() << "~QDrawWindow";
}

void QDrawWindow::drawBegin()
{
    _upQMGL.get()->restore();
    _upQMGL.get()->adjust();
    _upQDWImplementation.get()->_emptyDraw = false;
}

void QDrawWindow::drawEnd()
{
}

void QDrawWindow::drawByPlot( const std::vector<double> &x, const std::vector<double> &y, const std::string & legend,
                              const std::string & xAxisText, const std::string & yAxisText, const bool & showTop, const bool & rangeIsZero )
{
    drawBegin();
    _upQDWImplementation->_pPlotGraph = new PlotGraph( x, y );// 每次setDraw()会析构上次的mglDraw对象，故需新建对象，且在最后一次使用delete就行
    _upQDWImplementation->_pPlotGraph->setLegend( legend );
    _upQDWImplementation->_pPlotGraph->setxAxisText( xAxisText );
    _upQDWImplementation->_pPlotGraph->setyAxisText( yAxisText );
    _upQDWImplementation->_pPlotGraph->setTopIsShow( showTop );
    _upQDWImplementation->_pPlotGraph->setRangeIs0( rangeIsZero );
    _upQMGL.get()->setDraw( _upQDWImplementation.get()->_pPlotGraph );
    _upQMGL.get()->update();

    _upQDWImplementation->_pTorusGraph = nullptr;
    drawEnd();
}

void QDrawWindow::drawByTorus( const std::vector<double> &x, const std::vector<double> &y )
{
    drawBegin();
    _upQDWImplementation->_pTorusGraph = new TorusGraph( x, y );
    _upQMGL->setDraw( _upQDWImplementation.get()->_pTorusGraph );
    _upQMGL->update();

    _upQDWImplementation->_pPlotGraph = nullptr;
    drawEnd();
}

void QDrawWindow::clearDraw()
{
    _upQMGL->setDraw([ ]( mglGraph* gr ) -> int {
        gr->FPlot( "" );
        return 0;
    } );
    _upQMGL->update();
    _upQDWImplementation.get()->_pTorusGraph = nullptr;
    _upQDWImplementation.get()->_pPlotGraph  = nullptr;
    _upQDWImplementation.get()->_emptyDraw   = true;

}

void QDrawWindow::setDrawRotateOn()
{
    _upQDWImplementation.get()->_data.setRotate( true );
    _upQMGL.get()->setRotate( _upQDWImplementation.get()->_data.rotate() );
}

void QDrawWindow::setDrawRotateOff()
{
    _upQDWImplementation.get()->_data.setRotate( false );
    _upQMGL.get()->setRotate( _upQDWImplementation.get()->_data.rotate() );
}

void QDrawWindow::setDrawZoomOn()
{
    _upQDWImplementation.get()->_data.setZoom( true );
    _upQMGL.get()->setZoom( _upQDWImplementation.get()->_data.zoom() );
}

void QDrawWindow::setDrawZoomOff()
{
    _upQDWImplementation.get()->_data.setZoom( false );
    _upQMGL.get()->setZoom( _upQDWImplementation.get()->_data.zoom() );
}

void QDrawWindow::saveDraw( const std::string & filepath )
{
    if( _upQDWImplementation.get()->_pPlotGraph != nullptr )
    {
        _upQDWImplementation.get()->_pPlotGraph->saveGraph( filepath );
    }

    if( _upQDWImplementation.get()->_pTorusGraph != nullptr )
    {
        _upQDWImplementation.get()->_pTorusGraph->saveGraph( filepath );
    }
}

bool QDrawWindow::drawWindowIsEmpty()
{
    return _upQDWImplementation.get()->_emptyDraw;
}

