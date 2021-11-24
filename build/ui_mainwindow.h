/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *action_sens;
    QWidget *centralWidget;
    QPushButton *bt_startDraw;
    QLineEdit *lineEdit_K;
    QLabel *label_K;
    QLabel *label_K_u;
    QLabel *label_hp_u;
    QLineEdit *lineEdit_hp;
    QLabel *label_hp;
    QLabel *label_rg_u;
    QLineEdit *lineEdit_rg;
    QLabel *label_rg;
    QLabel *label_rw_u;
    QLabel *label_u_u;
    QLabel *label_r1_u;
    QLineEdit *lineEdit_u;
    QLineEdit *lineEdit_rw;
    QLineEdit *lineEdit_r1;
    QLabel *label_u;
    QLabel *label_rw;
    QLabel *label_r1;
    QLabel *label_S_u;
    QLabel *label_S;
    QLineEdit *lineEdit_S;
    QLineEdit *lineEdit_re;
    QLabel *label_re_u;
    QLabel *label_re;
    QLineEdit *lineEdit_q;
    QLabel *label_q;
    QLabel *label_q_u;
    QLineEdit *lineEdit_h2;
    QLineEdit *lineEdit_fi;
    QLabel *label_fi;
    QLabel *label_h2;
    QLabel *label_fi_u;
    QLabel *label_h2_u;
    QLabel *label_Swi_u;
    QLabel *label_Sgr;
    QLabel *label_Sgr_u;
    QLineEdit *lineEdit_Swi;
    QLabel *label_Swi;
    QLineEdit *lineEdit_Sgr;
    QWidget *wg_torusDrawWindow;
    QWidget *wg_plotDrawWindow;
    QPushButton *bt_clearInput;
    QPushButton *bt_clearDraw;
    QLabel *label_title;
    QTextBrowser *tb_resultView;
    QPushButton *bt_savePlotDraw;
    QPushButton *bt_saveTorusDraw;
    QLineEdit *lineEdit_time;
    QLabel *label_time_u;
    QRadioButton *rb_drawBreakthroughTime;
    QRadioButton *rb_drawInputTime;
    QPushButton *bt_copyData;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1127, 836);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        action_sens = new QAction(MainWindow);
        action_sens->setObjectName(QString::fromUtf8("action_sens"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bt_startDraw = new QPushButton(centralWidget);
        bt_startDraw->setObjectName(QString::fromUtf8("bt_startDraw"));
        bt_startDraw->setGeometry(QRect(290, 300, 101, 23));
        lineEdit_K = new QLineEdit(centralWidget);
        lineEdit_K->setObjectName(QString::fromUtf8("lineEdit_K"));
        lineEdit_K->setGeometry(QRect(160, 80, 81, 20));
        label_K = new QLabel(centralWidget);
        label_K->setObjectName(QString::fromUtf8("label_K"));
        label_K->setGeometry(QRect(20, 80, 131, 21));
        label_K->setStyleSheet(QString::fromUtf8(""));
        label_K_u = new QLabel(centralWidget);
        label_K_u->setObjectName(QString::fromUtf8("label_K_u"));
        label_K_u->setGeometry(QRect(250, 80, 71, 16));
        label_hp_u = new QLabel(centralWidget);
        label_hp_u->setObjectName(QString::fromUtf8("label_hp_u"));
        label_hp_u->setGeometry(QRect(250, 120, 41, 16));
        lineEdit_hp = new QLineEdit(centralWidget);
        lineEdit_hp->setObjectName(QString::fromUtf8("lineEdit_hp"));
        lineEdit_hp->setGeometry(QRect(160, 120, 81, 20));
        label_hp = new QLabel(centralWidget);
        label_hp->setObjectName(QString::fromUtf8("label_hp"));
        label_hp->setGeometry(QRect(20, 120, 131, 20));
        label_hp->setStyleSheet(QString::fromUtf8(""));
        label_rg_u = new QLabel(centralWidget);
        label_rg_u->setObjectName(QString::fromUtf8("label_rg_u"));
        label_rg_u->setGeometry(QRect(250, 160, 71, 16));
        lineEdit_rg = new QLineEdit(centralWidget);
        lineEdit_rg->setObjectName(QString::fromUtf8("lineEdit_rg"));
        lineEdit_rg->setGeometry(QRect(160, 160, 81, 20));
        label_rg = new QLabel(centralWidget);
        label_rg->setObjectName(QString::fromUtf8("label_rg"));
        label_rg->setGeometry(QRect(20, 160, 121, 20));
        label_rg->setStyleSheet(QString::fromUtf8(""));
        label_rw_u = new QLabel(centralWidget);
        label_rw_u->setObjectName(QString::fromUtf8("label_rw_u"));
        label_rw_u->setGeometry(QRect(250, 240, 71, 16));
        label_u_u = new QLabel(centralWidget);
        label_u_u->setObjectName(QString::fromUtf8("label_u_u"));
        label_u_u->setGeometry(QRect(250, 200, 71, 16));
        label_r1_u = new QLabel(centralWidget);
        label_r1_u->setObjectName(QString::fromUtf8("label_r1_u"));
        label_r1_u->setGeometry(QRect(640, 80, 71, 16));
        lineEdit_u = new QLineEdit(centralWidget);
        lineEdit_u->setObjectName(QString::fromUtf8("lineEdit_u"));
        lineEdit_u->setGeometry(QRect(160, 200, 81, 20));
        lineEdit_rw = new QLineEdit(centralWidget);
        lineEdit_rw->setObjectName(QString::fromUtf8("lineEdit_rw"));
        lineEdit_rw->setGeometry(QRect(160, 240, 81, 20));
        lineEdit_r1 = new QLineEdit(centralWidget);
        lineEdit_r1->setObjectName(QString::fromUtf8("lineEdit_r1"));
        lineEdit_r1->setGeometry(QRect(550, 80, 81, 20));
        label_u = new QLabel(centralWidget);
        label_u->setObjectName(QString::fromUtf8("label_u"));
        label_u->setGeometry(QRect(20, 200, 131, 20));
        label_u->setStyleSheet(QString::fromUtf8(""));
        label_rw = new QLabel(centralWidget);
        label_rw->setObjectName(QString::fromUtf8("label_rw"));
        label_rw->setGeometry(QRect(20, 240, 121, 16));
        label_rw->setStyleSheet(QString::fromUtf8(""));
        label_r1 = new QLabel(centralWidget);
        label_r1->setObjectName(QString::fromUtf8("label_r1"));
        label_r1->setGeometry(QRect(370, 80, 151, 20));
        label_r1->setStyleSheet(QString::fromUtf8(""));
        label_S_u = new QLabel(centralWidget);
        label_S_u->setObjectName(QString::fromUtf8("label_S_u"));
        label_S_u->setGeometry(QRect(640, 120, 71, 16));
        label_S = new QLabel(centralWidget);
        label_S->setObjectName(QString::fromUtf8("label_S"));
        label_S->setGeometry(QRect(370, 120, 151, 20));
        label_S->setStyleSheet(QString::fromUtf8(""));
        lineEdit_S = new QLineEdit(centralWidget);
        lineEdit_S->setObjectName(QString::fromUtf8("lineEdit_S"));
        lineEdit_S->setGeometry(QRect(550, 120, 81, 20));
        lineEdit_re = new QLineEdit(centralWidget);
        lineEdit_re->setObjectName(QString::fromUtf8("lineEdit_re"));
        lineEdit_re->setGeometry(QRect(550, 160, 81, 20));
        label_re_u = new QLabel(centralWidget);
        label_re_u->setObjectName(QString::fromUtf8("label_re_u"));
        label_re_u->setGeometry(QRect(640, 160, 41, 16));
        label_re = new QLabel(centralWidget);
        label_re->setObjectName(QString::fromUtf8("label_re"));
        label_re->setGeometry(QRect(370, 160, 151, 20));
        label_re->setStyleSheet(QString::fromUtf8(""));
        lineEdit_q = new QLineEdit(centralWidget);
        lineEdit_q->setObjectName(QString::fromUtf8("lineEdit_q"));
        lineEdit_q->setGeometry(QRect(550, 200, 81, 20));
        label_q = new QLabel(centralWidget);
        label_q->setObjectName(QString::fromUtf8("label_q"));
        label_q->setGeometry(QRect(370, 200, 161, 20));
        label_q->setStyleSheet(QString::fromUtf8(""));
        label_q_u = new QLabel(centralWidget);
        label_q_u->setObjectName(QString::fromUtf8("label_q_u"));
        label_q_u->setGeometry(QRect(640, 200, 71, 16));
        lineEdit_h2 = new QLineEdit(centralWidget);
        lineEdit_h2->setObjectName(QString::fromUtf8("lineEdit_h2"));
        lineEdit_h2->setGeometry(QRect(550, 240, 81, 20));
        lineEdit_fi = new QLineEdit(centralWidget);
        lineEdit_fi->setObjectName(QString::fromUtf8("lineEdit_fi"));
        lineEdit_fi->setGeometry(QRect(900, 80, 81, 20));
        label_fi = new QLabel(centralWidget);
        label_fi->setObjectName(QString::fromUtf8("label_fi"));
        label_fi->setGeometry(QRect(740, 80, 151, 20));
        label_fi->setStyleSheet(QString::fromUtf8(""));
        label_h2 = new QLabel(centralWidget);
        label_h2->setObjectName(QString::fromUtf8("label_h2"));
        label_h2->setGeometry(QRect(370, 240, 161, 20));
        label_h2->setStyleSheet(QString::fromUtf8(""));
        label_fi_u = new QLabel(centralWidget);
        label_fi_u->setObjectName(QString::fromUtf8("label_fi_u"));
        label_fi_u->setGeometry(QRect(990, 80, 41, 16));
        label_h2_u = new QLabel(centralWidget);
        label_h2_u->setObjectName(QString::fromUtf8("label_h2_u"));
        label_h2_u->setGeometry(QRect(640, 240, 41, 16));
        label_Swi_u = new QLabel(centralWidget);
        label_Swi_u->setObjectName(QString::fromUtf8("label_Swi_u"));
        label_Swi_u->setGeometry(QRect(990, 120, 41, 16));
        label_Sgr = new QLabel(centralWidget);
        label_Sgr->setObjectName(QString::fromUtf8("label_Sgr"));
        label_Sgr->setGeometry(QRect(740, 160, 151, 20));
        label_Sgr->setStyleSheet(QString::fromUtf8(""));
        label_Sgr_u = new QLabel(centralWidget);
        label_Sgr_u->setObjectName(QString::fromUtf8("label_Sgr_u"));
        label_Sgr_u->setGeometry(QRect(990, 160, 41, 16));
        lineEdit_Swi = new QLineEdit(centralWidget);
        lineEdit_Swi->setObjectName(QString::fromUtf8("lineEdit_Swi"));
        lineEdit_Swi->setGeometry(QRect(900, 120, 81, 20));
        label_Swi = new QLabel(centralWidget);
        label_Swi->setObjectName(QString::fromUtf8("label_Swi"));
        label_Swi->setGeometry(QRect(740, 120, 151, 20));
        label_Swi->setStyleSheet(QString::fromUtf8(""));
        lineEdit_Sgr = new QLineEdit(centralWidget);
        lineEdit_Sgr->setObjectName(QString::fromUtf8("lineEdit_Sgr"));
        lineEdit_Sgr->setGeometry(QRect(900, 160, 81, 20));
        wg_torusDrawWindow = new QWidget(centralWidget);
        wg_torusDrawWindow->setObjectName(QString::fromUtf8("wg_torusDrawWindow"));
        wg_torusDrawWindow->setGeometry(QRect(570, 340, 511, 391));
        sizePolicy.setHeightForWidth(wg_torusDrawWindow->sizePolicy().hasHeightForWidth());
        wg_torusDrawWindow->setSizePolicy(sizePolicy);
        wg_torusDrawWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        wg_plotDrawWindow = new QWidget(centralWidget);
        wg_plotDrawWindow->setObjectName(QString::fromUtf8("wg_plotDrawWindow"));
        wg_plotDrawWindow->setGeometry(QRect(30, 340, 481, 391));
        wg_plotDrawWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        bt_clearInput = new QPushButton(centralWidget);
        bt_clearInput->setObjectName(QString::fromUtf8("bt_clearInput"));
        bt_clearInput->setGeometry(QRect(990, 210, 75, 23));
        bt_clearDraw = new QPushButton(centralWidget);
        bt_clearDraw->setObjectName(QString::fromUtf8("bt_clearDraw"));
        bt_clearDraw->setGeometry(QRect(410, 300, 75, 23));
        label_title = new QLabel(centralWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(370, 10, 371, 51));
        label_title->setStyleSheet(QString::fromUtf8("font: 75 22pt \"Adobe Devanagari\";"));
        tb_resultView = new QTextBrowser(centralWidget);
        tb_resultView->setObjectName(QString::fromUtf8("tb_resultView"));
        tb_resultView->setGeometry(QRect(740, 200, 221, 61));
        tb_resultView->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe Devanagari\";"));
        bt_savePlotDraw = new QPushButton(centralWidget);
        bt_savePlotDraw->setObjectName(QString::fromUtf8("bt_savePlotDraw"));
        bt_savePlotDraw->setGeometry(QRect(30, 740, 75, 23));
        bt_saveTorusDraw = new QPushButton(centralWidget);
        bt_saveTorusDraw->setObjectName(QString::fromUtf8("bt_saveTorusDraw"));
        bt_saveTorusDraw->setGeometry(QRect(570, 740, 75, 23));
        lineEdit_time = new QLineEdit(centralWidget);
        lineEdit_time->setObjectName(QString::fromUtf8("lineEdit_time"));
        lineEdit_time->setGeometry(QRect(170, 300, 71, 20));
        label_time_u = new QLabel(centralWidget);
        label_time_u->setObjectName(QString::fromUtf8("label_time_u"));
        label_time_u->setGeometry(QRect(250, 300, 31, 16));
        rb_drawBreakthroughTime = new QRadioButton(centralWidget);
        rb_drawBreakthroughTime->setObjectName(QString::fromUtf8("rb_drawBreakthroughTime"));
        rb_drawBreakthroughTime->setGeometry(QRect(40, 280, 121, 16));
        rb_drawInputTime = new QRadioButton(centralWidget);
        rb_drawInputTime->setObjectName(QString::fromUtf8("rb_drawInputTime"));
        rb_drawInputTime->setGeometry(QRect(40, 300, 121, 16));
        bt_copyData = new QPushButton(centralWidget);
        bt_copyData->setObjectName(QString::fromUtf8("bt_copyData"));
        bt_copyData->setGeometry(QRect(120, 740, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        bt_saveTorusDraw->raise();
        bt_startDraw->raise();
        lineEdit_K->raise();
        label_K->raise();
        label_K_u->raise();
        label_hp_u->raise();
        lineEdit_hp->raise();
        label_hp->raise();
        label_rg_u->raise();
        lineEdit_rg->raise();
        label_rg->raise();
        label_rw_u->raise();
        label_u_u->raise();
        label_r1_u->raise();
        lineEdit_u->raise();
        lineEdit_rw->raise();
        lineEdit_r1->raise();
        label_u->raise();
        label_rw->raise();
        label_r1->raise();
        label_S_u->raise();
        label_S->raise();
        lineEdit_S->raise();
        lineEdit_re->raise();
        label_re_u->raise();
        label_re->raise();
        lineEdit_q->raise();
        label_q->raise();
        label_q_u->raise();
        lineEdit_h2->raise();
        lineEdit_fi->raise();
        label_fi->raise();
        label_h2->raise();
        label_fi_u->raise();
        label_h2_u->raise();
        label_Swi_u->raise();
        label_Sgr->raise();
        label_Sgr_u->raise();
        lineEdit_Swi->raise();
        label_Swi->raise();
        lineEdit_Sgr->raise();
        wg_torusDrawWindow->raise();
        wg_plotDrawWindow->raise();
        bt_clearInput->raise();
        bt_clearDraw->raise();
        label_title->raise();
        tb_resultView->raise();
        bt_savePlotDraw->raise();
        lineEdit_time->raise();
        label_time_u->raise();
        rb_drawBreakthroughTime->raise();
        rb_drawInputTime->raise();
        bt_copyData->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1127, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_sens);
        menu->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        action_sens->setText(QApplication::translate("MainWindow", "\346\225\217\346\204\237\346\200\247\345\210\206\346\236\220", nullptr));
        bt_startDraw->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\273\230\345\210\266", nullptr));
        label_K->setText(QApplication::translate("MainWindow", "\346\270\227\351\200\217\347\216\207       K\357\274\232", nullptr));
        label_K_u->setText(QApplication::translate("MainWindow", "(10^-3um^2)", nullptr));
        label_hp_u->setText(QApplication::translate("MainWindow", "(m)", nullptr));
        label_hp->setText(QApplication::translate("MainWindow", "\346\260\224\344\272\225\346\211\223\345\274\200\345\216\232\345\272\246hp\357\274\232", nullptr));
        label_rg_u->setText(QApplication::translate("MainWindow", "(f)", nullptr));
        label_rg->setText(QApplication::translate("MainWindow", "\346\260\224\344\275\223\347\233\270\345\257\271\345\257\206\345\272\246rg\357\274\232", nullptr));
        label_rw_u->setText(QApplication::translate("MainWindow", "(m)", nullptr));
        label_u_u->setText(QApplication::translate("MainWindow", "(mPa.s)", nullptr));
        label_r1_u->setText(QApplication::translate("MainWindow", "(m)", nullptr));
        label_u->setText(QApplication::translate("MainWindow", "\346\260\224\344\275\223\351\273\217\345\272\246     u\357\274\232", nullptr));
        label_rw->setText(QApplication::translate("MainWindow", "\344\272\225\345\215\212\345\276\204      rw\357\274\232", nullptr));
        label_r1->setText(QApplication::translate("MainWindow", "\345\215\212\347\220\203\351\235\242\345\220\221\345\277\203\346\265\201\345\215\212\345\276\204  r1\357\274\232", nullptr));
        label_S_u->setText(QApplication::translate("MainWindow", "(f)", nullptr));
        label_S->setText(QApplication::translate("MainWindow", "\350\241\250\347\232\256\347\263\273\346\225\260           S\357\274\232", nullptr));
        label_re_u->setText(QApplication::translate("MainWindow", "(m)", nullptr));
        label_re->setText(QApplication::translate("MainWindow", "\344\276\233\347\273\231\345\215\212\345\276\204          re\357\274\232", nullptr));
        label_q->setText(QApplication::translate("MainWindow", "\346\260\224\344\272\225\345\260\204\345\255\224\346\256\265\345\272\225\351\203\250\344\272\247\351\207\217 q\357\274\232", nullptr));
        label_q_u->setText(QApplication::translate("MainWindow", "(10^4m^3/d)", nullptr));
        label_fi->setText(QApplication::translate("MainWindow", "\345\255\224\351\232\231\345\272\246           \317\210\357\274\232", nullptr));
        label_h2->setText(QApplication::translate("MainWindow", "\346\260\224\344\272\225\345\260\204\345\255\224\346\256\265\345\272\225\351\203\250\351\253\230\345\272\246h2\357\274\232", nullptr));
        label_fi_u->setText(QApplication::translate("MainWindow", "(f)", nullptr));
        label_h2_u->setText(QApplication::translate("MainWindow", "(m)", nullptr));
        label_Swi_u->setText(QApplication::translate("MainWindow", "(f)", nullptr));
        label_Sgr->setText(QApplication::translate("MainWindow", "\346\256\213\344\275\231\346\260\224\351\245\261\345\222\214\345\272\246    Sgr\357\274\232", nullptr));
        label_Sgr_u->setText(QApplication::translate("MainWindow", "(f)", nullptr));
        label_Swi->setText(QApplication::translate("MainWindow", "\346\235\237\347\274\232\346\260\264\351\245\261\345\222\214\345\272\246    Swi\357\274\232", nullptr));
        bt_clearInput->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        bt_clearDraw->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\347\273\230\345\210\266", nullptr));
        label_title->setText(QApplication::translate("MainWindow", "\345\272\225\346\260\264\346\260\224\350\227\217\346\260\264\351\224\245\345\212\250\346\200\201\346\250\241\346\213\237\350\275\257\344\273\266", nullptr));
        bt_savePlotDraw->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        bt_saveTorusDraw->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        label_time_u->setText(QApplication::translate("MainWindow", "(a)", nullptr));
        rb_drawBreakthroughTime->setText(QApplication::translate("MainWindow", "\346\260\264\351\224\245\347\252\201\347\240\264\346\233\262\347\272\277\347\273\230\345\210\266", nullptr));
        rb_drawInputTime->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\346\227\266\351\227\264\346\233\262\347\272\277\347\273\230\345\210\266\357\274\232", nullptr));
        bt_copyData->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266\346\225\260\346\215\256", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
