#include "TorusGraph.h"
#include <QDebug>
TorusGraph::TorusGraph( const std::vector<double> &x, const std::vector<double> &y ) :
    _graphData( GraphData( x, y ) )
{
}

TorusGraph::~TorusGraph()
{
    qDebug() << "~TorusGraph";
}

TorusGraph::TorusGraph( const TorusGraph &copy )
{
    *this = copy;
}

TorusGraph &TorusGraph::operator =( const TorusGraph &rhs )
{
    if( this == &rhs )
    {
        return *this;
    }
    _graphData = rhs._graphData;

    return *this;
}

int TorusGraph::Draw( mglGraph *gr )
{
    initGraph( *gr );
    return 0;
}

void TorusGraph::saveGraph( const std::string &savepath )
{
    mglGraph gr;
    initGraph( gr );
    gr.WritePNG( QString( savepath.c_str() ).toLocal8Bit().data() );
}

void TorusGraph::initGraph( mglGraph &gr )
{
    gr.SetRanges( _graphData._xAxisData.Minimal() - 20,
            _graphData._xAxisData.Maximal() + 20,
            _graphData._xAxisData.Minimal() - 20,
            _graphData._xAxisData.Maximal() + 20,
            0,
            _graphData._yAxisData.Maximal() + 5 );
    gr.Rotate( 50, 60 );
    gr.Grid( "xyz", "h" );
    gr.Torus( _graphData._xAxisData, _graphData._yAxisData, "b# z", "light on" );
    gr.Axis( "xyz" );
    gr.Label( 'x', "r(m)", 0 );
    gr.Label( 'y', "r(m)", 0 );
    gr.Label( 'z', "z(m)", 1 );
}

