/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLineEdit *Robot_x_txt;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Robot_y_txt;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QLineEdit *Target_x_txt;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *Target_y_txt;
    QPushButton *pushButton_3;
    QLabel *label_7;
    QWidget *tab_3;
    QGroupBox *groupBox_4;
    QLineEdit *degrees_txt;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_5;
    QWidget *tab_2;
    QGraphicsView *Radar_Round_V;
    QGraphicsView *Radar_Flat_V;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *Distance_lbl;
    QLabel *Angle_lbl;
    QGroupBox *groupBox;
    QComboBox *ListMaps_cmb;
    QLabel *label_4;
    QLabel *LoadedMap_lbl;
    QPushButton *Load_btn;
    QPushButton *Refresh_btn;
    QLabel *label_6;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_5;
    QLabel *label_11;
    QLabel *Status_lbl;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(966, 676);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(630, 630, 121, 21));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 630, 601, 16));
        progressBar->setValue(0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(630, 150, 321, 451));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 301, 81));
        Robot_x_txt = new QLineEdit(groupBox_2);
        Robot_x_txt->setObjectName(QStringLiteral("Robot_x_txt"));
        Robot_x_txt->setGeometry(QRect(25, 26, 71, 27));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 21, 17));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 30, 16, 17));
        Robot_y_txt = new QLineEdit(groupBox_2);
        Robot_y_txt->setObjectName(QStringLiteral("Robot_y_txt"));
        Robot_y_txt->setGeometry(QRect(116, 26, 71, 27));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(192, 25, 99, 27));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 100, 301, 81));
        Target_x_txt = new QLineEdit(groupBox_3);
        Target_x_txt->setObjectName(QStringLiteral("Target_x_txt"));
        Target_x_txt->setGeometry(QRect(25, 26, 71, 27));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 21, 17));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 30, 16, 17));
        Target_y_txt = new QLineEdit(groupBox_3);
        Target_y_txt->setObjectName(QStringLiteral("Target_y_txt"));
        Target_y_txt->setGeometry(QRect(116, 26, 71, 27));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(192, 25, 99, 27));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(4, 180, 311, 91));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 301, 71));
        degrees_txt = new QLineEdit(groupBox_4);
        degrees_txt->setObjectName(QStringLiteral("degrees_txt"));
        degrees_txt->setGeometry(QRect(10, 30, 61, 27));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(77, 34, 141, 17));
        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 30, 71, 27));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 90, 301, 71));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Radar_Round_V = new QGraphicsView(tab_2);
        Radar_Round_V->setObjectName(QStringLiteral("Radar_Round_V"));
        Radar_Round_V->setGeometry(QRect(60, 10, 200, 200));
        Radar_Round_V->setFrameShape(QFrame::StyledPanel);
        Radar_Flat_V = new QGraphicsView(tab_2);
        Radar_Flat_V->setObjectName(QStringLiteral("Radar_Flat_V"));
        Radar_Flat_V->setGeometry(QRect(10, 220, 301, 121));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 350, 59, 14));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 370, 59, 14));
        Distance_lbl = new QLabel(tab_2);
        Distance_lbl->setObjectName(QStringLiteral("Distance_lbl"));
        Distance_lbl->setGeometry(QRect(70, 350, 59, 14));
        Angle_lbl = new QLabel(tab_2);
        Angle_lbl->setObjectName(QStringLiteral("Angle_lbl"));
        Angle_lbl->setGeometry(QRect(70, 370, 59, 14));
        tabWidget->addTab(tab_2, QString());
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(630, 20, 321, 121));
        ListMaps_cmb = new QComboBox(groupBox);
        ListMaps_cmb->setObjectName(QStringLiteral("ListMaps_cmb"));
        ListMaps_cmb->setGeometry(QRect(120, 50, 171, 27));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 101, 17));
        LoadedMap_lbl = new QLabel(groupBox);
        LoadedMap_lbl->setObjectName(QStringLiteral("LoadedMap_lbl"));
        LoadedMap_lbl->setGeometry(QRect(110, 30, 131, 17));
        Load_btn = new QPushButton(groupBox);
        Load_btn->setObjectName(QStringLiteral("Load_btn"));
        Load_btn->setGeometry(QRect(170, 85, 91, 27));
        Refresh_btn = new QPushButton(groupBox);
        Refresh_btn->setObjectName(QStringLiteral("Refresh_btn"));
        Refresh_btn->setGeometry(QRect(80, 85, 81, 27));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 54, 111, 17));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 600, 600));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(760, 630, 121, 21));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(630, 610, 59, 14));
        Status_lbl = new QLabel(centralWidget);
        Status_lbl->setObjectName(QStringLiteral("Status_lbl"));
        Status_lbl->setGeometry(QRect(680, 610, 121, 16));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(1010, 670, 21, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 966, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Start", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Robot's Initial Position", 0));
        Robot_x_txt->setText(QApplication::translate("MainWindow", "0", 0));
        label->setText(QApplication::translate("MainWindow", "x:", 0));
        label_2->setText(QApplication::translate("MainWindow", "y:", 0));
        Robot_y_txt->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Set", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Target's Initial Position", 0));
        Target_x_txt->setText(QApplication::translate("MainWindow", "0", 0));
        label_3->setText(QApplication::translate("MainWindow", "x:", 0));
        label_5->setText(QApplication::translate("MainWindow", "y:", 0));
        Target_y_txt->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Set", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Note: </p><p>Pressing &quot;Set&quot; button will initialize the robot. </p><p>So all data will be lost.</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Coordinates", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Radar Accuracy", 0));
        degrees_txt->setText(QApplication::translate("MainWindow", "360", 0));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p>degrees per round.</p></body></html>", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Set", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "HMM settings", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Robot Settings", 0));
        label_9->setText(QApplication::translate("MainWindow", "Distance:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Angle:", 0));
        Distance_lbl->setText(QApplication::translate("MainWindow", "<html><head/><body><p>uknown</p></body></html>", 0));
        Angle_lbl->setText(QApplication::translate("MainWindow", "uknown", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Robot Data", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Map Settings", 0));
        label_4->setText(QApplication::translate("MainWindow", "Current Map : ", 0));
        LoadedMap_lbl->setText(QApplication::translate("MainWindow", "Nothing", 0));
        Load_btn->setText(QApplication::translate("MainWindow", "Load", 0));
        Refresh_btn->setText(QApplication::translate("MainWindow", "Refresh", 0));
        label_6->setText(QApplication::translate("MainWindow", "Available Maps:", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Start", 0));
        label_11->setText(QApplication::translate("MainWindow", "Status:", 0));
        Status_lbl->setText(QApplication::translate("MainWindow", "Stop", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
