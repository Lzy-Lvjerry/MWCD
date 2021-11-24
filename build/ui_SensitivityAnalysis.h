/********************************************************************************
** Form generated from reading UI file 'SensitivityAnalysis.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSITIVITYANALYSIS_H
#define UI_SENSITIVITYANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SensitivityAnalysis
{
public:
    QWidget *wg_drawWindow;
    QComboBox *cb_selectVar;
    QPushButton *bt_startSens;
    QLabel *lb_sensRange;
    QLabel *label__;
    QLineEdit *le_sensMin;
    QLineEdit *le_sensMax;
    QTableView *tv_resultTable;
    QPushButton *bt_saveGraph;
    QPushButton *bt_copyTableData;

    void setupUi(QDialog *SensitivityAnalysis)
    {
        if (SensitivityAnalysis->objectName().isEmpty())
            SensitivityAnalysis->setObjectName(QString::fromUtf8("SensitivityAnalysis"));
        SensitivityAnalysis->resize(763, 480);
        wg_drawWindow = new QWidget(SensitivityAnalysis);
        wg_drawWindow->setObjectName(QString::fromUtf8("wg_drawWindow"));
        wg_drawWindow->setGeometry(QRect(20, 10, 461, 371));
        wg_drawWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 227);"));
        cb_selectVar = new QComboBox(SensitivityAnalysis);
        cb_selectVar->addItem(QString());
        cb_selectVar->addItem(QString());
        cb_selectVar->addItem(QString());
        cb_selectVar->addItem(QString());
        cb_selectVar->addItem(QString());
        cb_selectVar->addItem(QString());
        cb_selectVar->addItem(QString());
        cb_selectVar->setObjectName(QString::fromUtf8("cb_selectVar"));
        cb_selectVar->setGeometry(QRect(30, 420, 211, 22));
        bt_startSens = new QPushButton(SensitivityAnalysis);
        bt_startSens->setObjectName(QString::fromUtf8("bt_startSens"));
        bt_startSens->setGeometry(QRect(460, 420, 75, 23));
        lb_sensRange = new QLabel(SensitivityAnalysis);
        lb_sensRange->setObjectName(QString::fromUtf8("lb_sensRange"));
        lb_sensRange->setGeometry(QRect(320, 400, 54, 12));
        label__ = new QLabel(SensitivityAnalysis);
        label__->setObjectName(QString::fromUtf8("label__"));
        label__->setGeometry(QRect(350, 430, 21, 16));
        le_sensMin = new QLineEdit(SensitivityAnalysis);
        le_sensMin->setObjectName(QString::fromUtf8("le_sensMin"));
        le_sensMin->setGeometry(QRect(270, 420, 61, 20));
        le_sensMax = new QLineEdit(SensitivityAnalysis);
        le_sensMax->setObjectName(QString::fromUtf8("le_sensMax"));
        le_sensMax->setGeometry(QRect(370, 420, 61, 20));
        tv_resultTable = new QTableView(SensitivityAnalysis);
        tv_resultTable->setObjectName(QString::fromUtf8("tv_resultTable"));
        tv_resultTable->setGeometry(QRect(500, 10, 231, 371));
        bt_saveGraph = new QPushButton(SensitivityAnalysis);
        bt_saveGraph->setObjectName(QString::fromUtf8("bt_saveGraph"));
        bt_saveGraph->setGeometry(QRect(570, 390, 75, 23));
        bt_copyTableData = new QPushButton(SensitivityAnalysis);
        bt_copyTableData->setObjectName(QString::fromUtf8("bt_copyTableData"));
        bt_copyTableData->setGeometry(QRect(650, 390, 75, 23));

        retranslateUi(SensitivityAnalysis);

        QMetaObject::connectSlotsByName(SensitivityAnalysis);
    } // setupUi

    void retranslateUi(QDialog *SensitivityAnalysis)
    {
        SensitivityAnalysis->setWindowTitle(QApplication::translate("SensitivityAnalysis", "Dialog", nullptr));
        cb_selectVar->setItemText(0, QApplication::translate("SensitivityAnalysis", "\345\255\224\351\232\231\345\272\246\316\246(f)", nullptr));
        cb_selectVar->setItemText(1, QApplication::translate("SensitivityAnalysis", "\346\260\224\344\272\225\345\260\204\345\255\224\346\256\265\345\272\225\351\203\250\351\253\230\345\272\246h2(m)", nullptr));
        cb_selectVar->setItemText(2, QApplication::translate("SensitivityAnalysis", "\346\260\224\344\272\225\346\211\223\345\274\200\345\216\232\345\272\246hp(m)", nullptr));
        cb_selectVar->setItemText(3, QApplication::translate("SensitivityAnalysis", "\350\241\250\347\232\256\347\263\273\346\225\260S(f)", nullptr));
        cb_selectVar->setItemText(4, QApplication::translate("SensitivityAnalysis", "\344\276\233\347\273\231\345\215\212\345\276\204re(m)", nullptr));
        cb_selectVar->setItemText(5, QApplication::translate("SensitivityAnalysis", "\345\215\212\347\220\203\351\235\242\345\220\221\345\277\203\346\265\201\345\215\212\345\276\204r1(m)", nullptr));
        cb_selectVar->setItemText(6, QApplication::translate("SensitivityAnalysis", "\346\260\224\344\272\225\345\260\204\345\255\224\346\256\265\345\272\225\351\203\250\344\272\247\351\207\217q(10^4*m^3/d)", nullptr));

        bt_startSens->setText(QApplication::translate("SensitivityAnalysis", "\350\277\233\350\241\214\345\210\206\346\236\220", nullptr));
        lb_sensRange->setText(QApplication::translate("SensitivityAnalysis", "\345\210\206\346\236\220\350\214\203\345\233\264", nullptr));
        label__->setText(QApplication::translate("SensitivityAnalysis", "~", nullptr));
        bt_saveGraph->setText(QApplication::translate("SensitivityAnalysis", "\344\277\235\345\255\230\345\233\276\345\203\217", nullptr));
        bt_copyTableData->setText(QApplication::translate("SensitivityAnalysis", "\345\244\215\345\210\266\350\241\250\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SensitivityAnalysis: public Ui_SensitivityAnalysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSITIVITYANALYSIS_H
