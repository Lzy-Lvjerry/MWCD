#ifndef SENSITIVITYANALYSIS_H
#define SENSITIVITYANALYSIS_H

#include <QDialog>
#include "model/MWCDModel.h"
#include <memory>
#include <QDebug>
#include <QStandardItemModel>
#include <QTableView>
#include <QString>
#include <QStandardItem>
#include "mathgl/src/QDrawWindow.h"
namespace Ui {
    class SensitivityAnalysis;
}

class SensitivityAnalysis : public QDialog
{
    Q_OBJECT

public:
    enum ANALYTICPARAMS {
        AP_FI,
        AP_H2,
        AP_HP,
        AP_S,
        AP_RE,
        AP_R1,
        AP_Q
    } analyticParams;
    explicit SensitivityAnalysis( QWidget *parent = nullptr );

    ~SensitivityAnalysis();
private slots:
    void on_bt_startSens_clicked();


    void on_bt_saveGraph_clicked();


    void on_bt_copyTableData_clicked();


private:
    void initConnect();


    void initWidget();


private:
    Ui::SensitivityAnalysis *ui;

    QDrawWindow* _pDrawWindow;

//    std::unique_ptr<MWCDModel> _upMWCDModel;
//    std::unique_ptr<MWCDModel> _upOrignalModel;
};

#endif // SENSITIVITYANALYSIS_H

