#include "GraphData.h"
#include <QDebug>
GraphData::GraphData() :
    _legend( "" ),
    _xAxisData( std::vector<double>() ),
    _yAxisData( std::vector<double>() ),
    _zAxisData( std::vector<double>() ),
    _xAxisText( "x" ),
    _yAxisText( "y" )
{
}

GraphData::~GraphData()
{
    qDebug() << "~GraphData";
}

GraphData::GraphData( const std::string &func ) :
    _legend( func ),
    _xAxisData( std::vector<double>() ),
    _yAxisData( std::vector<double>() ),
    _zAxisData( std::vector<double>() ),
    _xAxisText( "x" ),
    _yAxisText( "y" )
{
}

GraphData::GraphData( const std::vector<double> &x, const std::vector<double> &y ) :
    _xAxisData( x ),
    _yAxisData( y ),
    _zAxisData( std::vector<double>() )
{
}

GraphData::GraphData( const std::vector<double> &x, const std::vector<double> &y, const std::vector<double> &z ) :
    GraphData( x, y )
{
    _zAxisData = z;
}

GraphData::GraphData( const GraphData &copy )
{
    *this = copy;
}

GraphData &GraphData::operator=( const GraphData &rhs )
{
    if( this == &rhs )
    {
        return *this;
    }
    _xAxisData = rhs._xAxisData;
    _yAxisData = rhs._yAxisData;
    _zAxisData = rhs._zAxisData;
    return *this;
}

