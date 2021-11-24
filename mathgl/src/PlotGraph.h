/********************************************

  class: PlotGraph (PlotGraph.cpp)

  author: Lvjerry
  date: August 7, 2021

  ����plot�ӿڻ�����άͼ��
  ��ʹ��ʱ��ʵ���������ͨ��MathGL::setDraw(PlotGraph)����ʵ�ֻ�ͼ

********************************************/

#pragma once

#include "mgl2/qmathgl.h"
#include "mgl2/qt.h"
#include "GraphData.h"
#include <string>
#include <memory>
class PlotGraph : public mglDraw
{
public:
    PlotGraph( const std::string &func = "" );
    PlotGraph( const std::vector<double> &x, const std::vector<double> &y );
    ~PlotGraph()override;

    PlotGraph( const PlotGraph & );
    PlotGraph & operator =( const PlotGraph &rhs );


public:
    int Draw( mglGraph* gr )override; // mglDraw��ͼ�ӿڣ�ͼ��ϸ����������ʵ��


    void setLegend( const std::string & legend );


    void saveGraph( const std::string & savepath );


    void setxAxisText( const std::string & xText );


    void setyAxisText( const std::string & yText );


    void setRangeIs0( const bool & );


    void setTopIsShow( const bool & );


private:
    void initGraph( mglGraph & gr );


private:
    GraphData _graphData;

};

