/********************************************

  class: QDWData (QDWData.cpp)

  author: Lvjerry
  date: August 7, 2021

  PlotGraph和SurfGraph的数据接口

********************************************/

#pragma once

#include <string>
#include <vector>
#include "mgl2/qmathgl.h"
#include "mgl2/qt.h"
class GraphData final
{
public:


    GraphData();
    ~GraphData();
    GraphData( const std::string &func );
    GraphData( const std::vector<double> &x, const std::vector<double> &y );
    GraphData( const std::vector<double> & x, const std::vector<double> & y, const std::vector<double> & z );

    GraphData( const GraphData & );
    GraphData & operator=( const GraphData & rhs );


public:
    std::string _legend;

    mglData _xAxisData; // x轴数据
    mglData _yAxisData; // y轴数据
    mglData _zAxisData; // z轴数据

    std::string _xAxisText;
    std::string _yAxisText;

    bool _AxisRangeIs0 = false;
    bool _topIsShow    = false;
};

