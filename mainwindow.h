#pragma once

#include <QMainWindow>
#include "mgl2/qmathgl.h"
#include "mgl2/qt.h"
#include "mathgl/src/QDrawWindow.h"
#include "model/MWCDModel.h"
#include <memory>
#include <QButtonGroup>
#include "tool.h"
#include "Sensitivityanalysis.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );


    ~MainWindow();

private slots:
    void on_bt_clearInput_clicked();


    void on_bt_startDraw_clicked();


    void on_bt_clearDraw_clicked();


    void on_action_close_clicked();


    void on_bt_savePlotDraw_clicked();


    void on_bt_saveTorusDraw_clicked();


    void on_action_sens_clicked();


    void on_bt_copyData_clicked();


private:
    void initModel();


    void outputResult();


    void autoZoomUI();


    void resetButtonGeometry( const double &factorX, const double &factorY );


    void resetLineEditGeometry( const double &factorX, const double &factorY );


    void initConnect();


    void initQObject();


    Ui::MainWindow *ui;

    // ʹ������ָ�붨�崰�ڣ�������쳣����������ָ���ж����������ڹ����ʧЧ
    QDrawWindow* _pPlotDrawWindow;
    QDrawWindow* _pTorusDrawWindow;

    std::unique_ptr<MWCDModel> _upMWCDModel;

    QButtonGroup *_pDrawMethodGroup;

    SensitivityAnalysis* _pSAWindow;

    std::vector<double> _xData;
    std::vector<double> _yData;
};

