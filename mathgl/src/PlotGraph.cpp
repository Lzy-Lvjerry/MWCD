#include "PlotGraph.h"
#include <QDebug>
#include <QString>
#include <QLabel>
#include <QTextCodec>
PlotGraph::PlotGraph( const std::string &function ) :
    _graphData( GraphData( function ) )
{
}

PlotGraph::PlotGraph( const std::vector<double> &x, const std::vector<double> &y ) :
    _graphData( GraphData( x, y ) )
{
}

PlotGraph::~PlotGraph()
{
    qDebug() << "~PlotGraph";
}

PlotGraph::PlotGraph( const PlotGraph &copy )
{
    *this = copy;
}

PlotGraph &PlotGraph::operator =( const PlotGraph &rhs )
{
    if( this == &rhs )
    {
        return *this;
    }
    _graphData = rhs._graphData;
    return *this;
}

int PlotGraph::Draw( mglGraph *gr )
{
    initGraph( *gr );
    return 0;
}

void PlotGraph::setLegend( const std::string &legend )
{
    _graphData._legend = legend;
}

void PlotGraph::saveGraph( const std::string & savepath )
{
    mglGraph gr;
    initGraph( gr );
    gr.WritePNG( QString( savepath.c_str() ).toLocal8Bit().data() );
}

void PlotGraph::setxAxisText( const std::string &xText )
{
    _graphData._xAxisText = xText;
}

void PlotGraph::setyAxisText( const std::string &yText )
{
    _graphData._yAxisText = yText;
}

void PlotGraph::setRangeIs0( const bool &p )
{
    _graphData._AxisRangeIs0 = p;
}

void PlotGraph::setTopIsShow( const bool &show )
{
    _graphData._topIsShow = show;
}

void PlotGraph::initGraph( mglGraph &gr )
{
    if( _graphData._AxisRangeIs0 )
    {
        gr.SetRanges( -_graphData._xAxisData.Maximal(),
                _graphData._xAxisData.Maximal(),
                0,
                _graphData._yAxisData.Maximal() );
        gr.SetOrigin( 0, 0 );
    }
    else
    {
        gr.SetRanges( _graphData._xAxisData.Minimal(),
                _graphData._xAxisData.Maximal(),
                0,
                _graphData._yAxisData.Maximal() );
    }

    gr.Axis( "xy" );

    gr.Label( 'x', _graphData._xAxisText.c_str(), 1 );
    gr.Label( 'y', _graphData._yAxisText.c_str(), 0 );
    QString topPointInfo = QString( "(0, %1)" ).arg( _graphData._yAxisData.Maximal() );

//    gr.Line( mglPoint( _graphData._xAxisData.Minimal(), _graphData._yAxisData.Maximal() ),
//            mglPoint( 0, _graphData._yAxisData.Maximal() ), "B|" );
    gr.Plot( _graphData._xAxisData, _graphData._yAxisData, "r2-" );
    gr.AddLegend( ( _graphData._legend  ).c_str(), "r2" );

    gr.Legend();

    if( _graphData._topIsShow )
    {
        gr.Puts( mglPoint( 0, _graphData._yAxisData.Maximal() ), topPointInfo.toLocal8Bit().data() );
    }

}

