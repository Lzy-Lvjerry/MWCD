/********************************************

  class: QDrawWindow (QDrawWindow.cpp)

  author: Lvjerry
  date: August 7, 2021

  ����mathGL���к���ͼ����Ƶ�QWidget����

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


    QDrawWindow( QWidget*const ); // ���ڴ�����ҪQWidget����
    ~QDrawWindow();

    QDrawWindow( const QDrawWindow & )              = delete;
    QDrawWindow & operator =( const QDrawWindow & ) = delete;


public:

    ///
    /// \brief drawPlotByData ͨ��x���y������ݻ���ƽ��ͼ
    /// \param x x�����ݣ�Ԫ��ID��y��Ӧ
    /// \param y y�����ݣ�Ԫ��ID��x��Ӧ
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
    /// \brief drawTorusByData ͨ��x�ᡢy������ݻ��ƻ���ͼ
    /// \param x x������
    /// \param y y������
    ///
    void drawByTorus( const std::vector<double> &x, const std::vector<double> &y );


    void clearDraw(); // ��յ�ǰ���ƴ��ڵ�����


    void setDrawRotateOn(); // ���ô��ڿ���ת


    void setDrawRotateOff(); // ���ô��ڲ�����ת


    void setDrawZoomOn(); // ���ô��ڿ�����


    void setDrawZoomOff(); // ���ô��ڲ�������


    void saveDraw( const std::string & filepath );


    bool drawWindowIsEmpty();


private:
    void drawBegin();


    void drawEnd();


private:
    std::unique_ptr<QDWImplementation> _upQDWImplementation;

    std::unique_ptr<QMathGL> _upQMGL;

};

