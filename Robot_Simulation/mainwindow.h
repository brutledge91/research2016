#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include "constants.h"
#include "graphic_engine.h"
#include "utilities.h"
#include "myrobot1.h"
#include "dynamic_obstacle.h"
#include <QVector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_Refresh_btn_clicked();

    void on_Load_btn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void new_clock();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    void Search_Maps();
    void Load_Maps(QString);
    void run_GPU(int = 0, int = 1);
    void RemoveAllfromNumber(int, int = 0);
    Utilities *util1;

    QTimer* main_clock;

    QVector<MyRobot1> MyRobot;
    QVector<Dynamic_Obstacle> MyDOs;

    Ui::MainWindow *ui;
    Graphic_Engine *GPU_;
    QVector<QVector <QString> > Grid_information;
    QDir Mydirectory;
    QStringList MapFiles_Paths;
};

#endif // MAINWINDOW_H
