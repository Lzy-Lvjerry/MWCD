/********************************************

  class: SurfGraph (SurfGraph.cpp)

  author: Lvjerry
  date: August 7, 2021

  调用surf接口绘制三维图像
  在使用时，实例化该类后，通过MathGL::setDraw(SurfGraph)即可实现绘图

********************************************/

#pragma once

#include"mgl2/qmathgl.h"
#include"mgl2/qt.h"
#include"QDWData.h"
#include<string>
#include"GraphData.h"
#include<memory>
class TorusGraph : public mglDraw
{
public:
    TorusGraph(const std::vector<double>&x, const std::vector<double>&y);
    ~TorusGraph()override;

    TorusGraph(const TorusGraph&);
    TorusGraph& operator =(const TorusGraph& rhs);

public:
    int Draw(mglGraph* gr)override; // mglDraw绘图接口，图像细节需在这里实现

    void saveGraph(const std::string& savepath);
private:

    void initGraph(mglGraph& gr);
private:
    GraphData _graphData;

};

