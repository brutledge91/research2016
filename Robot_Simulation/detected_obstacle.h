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
    QGenericMatrix<matrix_size,matrix_size,double> Mov = ObsMov;
    //QGenericMatrix<matrix_size,matrix_size,float> Spd = ObsSpd;
    QVector<int> predictions;
public:
    int getSpeed();
    void setSpeed(int);
    QVector<int> getMov(int,int);
    //updateMov();
    //setSpd();
    void setLocation(QPointF);
    QPointF setEstLocation(QPointF,int);

    Detected_Obstacle();
};

#endif // DETECTED_OBSTACLE_H
