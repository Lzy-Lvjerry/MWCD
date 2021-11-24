/********************************************

  class: QDrawWindow (QDrawWindow.cpp)

  author: Lvjerry
  date: August 7, 2021

  利用mathGL进行函数图像绘制的QWidget窗口

********************************************/


#pragma once

#include "mgl2/qmathgl.h"
#include "mgl2/qt.h"
#include <QWidget>

#include <vector>
#include <string>
#include <memory>
#include "QDWData.h"
#include "PlotGraph.h"
#include "TorusGraph.h"

class QDWImplementation final {
public:
    QDWImplementation();
    ~QDWImplementation();

    QDWImplementation( QDWImplementation & )                    = delete;
    QDWImplementation & operator =( const QDWImplementation & ) = delete;


public:
    QDWData _data;
    PlotGraph *_pPlotGraph;
    TorusGraph *_pTorusGraph;

    bool _emptyDraw;
};

class QDrawWindow final
{
public:


    QDrawWindow( QWidget*const ); // 窗口创建需要QWidget对象
    ~QDrawWindow();

    QDrawWindow( const QDrawWindow & )              = delete;
    QDrawWindow & operator =( const QDrawWindow & ) = delete;


public:

    ///
    /// \brief drawPlotByData 通过x轴和y轴的数据绘制平面图
    /// \param x x轴数据，元素ID与y对应
    /// \param y y轴数据，元素ID与x对应
    ///
    void drawByPlot( const std::vector<double> &x,
                     const std::vector<double> &y,
                     const std::string & legend    = "",
                     const std::string & xAxisText = "x",
                     const std::string & yAxisText = "y",
                     const bool & showTop          = false,
                     const bool & rangeIsZero      = false );


//    void drawSurfByData(const std::vector<double>&x, const std::vector<double>&y);

    ///
    /// \brief drawTorusByData 通过x轴、y轴的数据绘制环面图
    /// \param x x轴数据
    /// \param y y轴数据
    ///
    void drawByTorus( const std::vector<double> &x, const std::vector<double> &y );


    void clearDraw(); // 清空当前绘制窗口的内容


    void setDrawRotateOn(); // 设置窗口可旋转


    void setDrawRotateOff(); // 设置窗口不可旋转


    void setDrawZoomOn(); // 设置窗口可缩放


    void setDrawZoomOff(); // 设置窗口不可缩放


    void saveDraw( const std::string & filepath );


    bool drawWindowIsEmpty();


private:
    void drawBegin();


    void drawEnd();


private:
    std::unique_ptr<QDWImplementation> _upQDWImplementation;

    std::unique_ptr<QMathGL> _upQMGL;

};

