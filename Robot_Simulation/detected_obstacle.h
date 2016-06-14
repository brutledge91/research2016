#ifndef DETECTED_OBSTACLE_H
#define DETECTED_OBSTACLE_H

#include <QtCore>
#include <QGenericMatrix>
#include "constants.h"
#include "QList.h"

class Detected_Obstacle{

private:
    int speed = 0;
    QPointF location;
    QPointF est_location;
    QGenericMatrix<matrix_size,matrix_size,double> Mov = ObsMov;
    //QGenericMatrix<matrix_size,matrix_size,float> Spd = ObsSpd;
public:
    int getSpeed();
    void setSpeed(int);
    int getMov(int);
    //updateMov();
    //setSpd();
    void setLocation(QPointF);
    QPointF setEstLocation(QPointF,int);

    Detected_Obstacle();
};

#endif // DETECTED_OBSTACLE_H
