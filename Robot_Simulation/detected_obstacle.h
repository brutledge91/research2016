#ifndef DETECTED_OBSTACLE_H
#define DETECTED_OBSTACLE_H

#include <QtCore>
#include <QGenericMatrix>
#include <QVector>
#include <QtMath>
#include "constants.h"
#include "QList.h"

class Detected_Obstacle{

private:
    int speed = 0;
    QPointF location;
    QPointF est_location;
    QGenericMatrix<num_states,num_states,double> Mov = ObsMov;
    //QGenericMatrix<num_states,num_states,float> Spd = ObsSpd;
    QVector<int> predictions;
public:
    int getSpeed();
    void setSpeed(int);
    QVector<int> getMov(int,int);
    //updateMov();
    //setSpd();
    void setLocation(QPointF);
    QPointF setEstLocation(QPointF,int);
    //QGenericMatrix<num_states,num_states,double> GetMarkohv();

    Detected_Obstacle();
};

#endif // DETECTED_OBSTACLE_H
