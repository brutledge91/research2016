#ifndef MYROBOT1_H
#define MYROBOT1_H

#include <QtCore>
#include <QtWidgets>
#include <QVector>
#include <QtMath>
#include "utilities.h"
#include "detected_obstacle.h"
#include "constants.h"

class MyRobot1
{
private:
    QVector<QVector <QString> > *Environment;

    //Functions
    void FindRobot();
    void FindTarget();
    void ProcessDegreetoTarget();
    void ProcessRadar();
    double getoutputfuzzy(int);
    double operator_output (double, double);
    double bestangle();
    int move_();
    QPointF currentTargetpoint();


    //Variables
    int vp = 1;
    QString RobotID;
    QList<QList <int> > segments;
    int SpeedCounter = 0;
    double x_distance, y_distance;
    double Radar_step = 1;
    QPointF RobotCoordinate;
    QStack<QPointF> TargetCoordinate;
    QVector <double> Robot_Radar_Data;
    QVector <double> Robot_Fuzzy_Data;
    QVector <double> Robot_Final_Data;
    double DegreetoTarget;
    double DistancetoTarget;
    Utilities util1;
    //Constants for Robot
    int Fuzzy_variable = 40;
    int Radar_Range = 5;
    int Speed = 10;
    //QString comtxt = "[AppStartupDir]/Maps/COM/com.txt";


public:
    MyRobot1();

    QVector<double> GetRobot_Radar_Data();
    QVector<double> GetRobot_Fuzzy_Data();
    QVector<double> GetRobot_Final_Data();

    void SetRobotID(int);
    void SetGridInformation(QVector<QVector <QString> >* env_grid);
    void SetRadarSize(int);
    void SetXYMeasurements(double, double);
    int GetRobotRange();
    double GetDegreetoTarget();
    double GetDistancetoTarget();
    void InitializeRobot();
    int ProcessStep();

    //void Message();
    QVector<Detected_Obstacle> obstacles;
    void AddObstacle(Detected_Obstacle);
    void RemoveObstacle(int);

    //\///////////////////////////
    QVector<double> getProb(Detected_Obstacle,int,int);
    QVector<QVector<int>> findPaths(QVector<double>);
    QVector<QPointF> findLocations(QVector<QVector<int>>, QPointF);
    //\///////////////////////////
    QString out;
    QVector<QString> in;
    QGenericMatrix<num_states,num_states,double> Mov = ObsMov;
};

#endif // MYROBOT1_H
