#ifndef DYNAMIC_OBSTACLE_H
#define DYNAMIC_OBSTACLE_H

#include <QWidget>
#include <QtCore>
#include <QMessageBox>
#include "utilities.h"
#include "constants.h"
#include <random>

class Dynamic_Obstacle
{
private:
    void FindTarget();
    QVector<QVector <QString> > *Environment;
    QPointF ObstacleCoordinates;
    int direction;
    void FindObs();
    bool move = false;
    QString Dynamic_Obstacle_ID;
    Utilities util1;
    int SpeedCounter = 0;
    int Speed = 10;
    int move_();
    int y_coeff = 1;
    int o = 1;
    QGenericMatrix<matrix_size,matrix_size,double> OMov = ObsMov;
    QPointF newObstacleCoordinate;

public:
    void SetGridInformation(QVector<QVector <QString> >* env_grid);
    void SetObsID(int);
    int TransferFunction();
    int ProcessStep();

    Dynamic_Obstacle();
};

#endif // DYNAMIC_OBSTACLE_H
