/********************************************

  class: SurfGraph (SurfGraph.cpp)

  author: Lvjerry
  date: August 7, 2021

  ����surf�ӿڻ�����άͼ��
  ��ʹ��ʱ��ʵ���������ͨ��MathGL::setDraw(SurfGraph)����ʵ�ֻ�ͼ

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
    int Draw(mglGraph* gr)override; // mglDraw��ͼ�ӿڣ�ͼ��ϸ����������ʵ��

    void saveGraph(const std::string& savepath);
private:

    void initGraph(mglGraph& gr);
private:
    GraphData _graphData;

};

