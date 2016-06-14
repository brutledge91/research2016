#include "dynamic_obstacle.h"


int Dynamic_Obstacle::TransferFunction()
{
    return direction;
}

void Dynamic_Obstacle::SetObsID(int ID_)
{
    this->Dynamic_Obstacle_ID = "DO_" + QString::number(ID_);
}
void Dynamic_Obstacle::SetGridInformation(QVector<QVector <QString> >* env_grid)
{
    this->Environment = env_grid;
}
void Dynamic_Obstacle::FindObs()
{
    int gridsize = this->Environment->size();
    if (gridsize < 1) return;

    for (int i = 0 ; i < gridsize; i++)
    {
        for (int j = 0; j < gridsize; j++)
        {
            if (util1.IncludesDO(Environment->at(j).at(i),this->Dynamic_Obstacle_ID))
            {
                ObstacleCoordinates.setX(i);
                ObstacleCoordinates.setY(j);
            }
        }
    }
}
int Dynamic_Obstacle::ProcessStep()
{
    SpeedCounter ++;
    if (SpeedCounter == Speed)
    {
        SpeedCounter = 0;
        if (this->move_() == 0) return 1;
    }
    return 0;
}
int Dynamic_Obstacle::move_()
{
    FindObs();

    double degree;
    //if (ObstacleCoordinates.y() >= 11)
    {
        //degree = 0;
    }
    double x_ = qCos(qDegreesToRadians(degree));
    double y_ = qSin(qDegreesToRadians(degree));

    QPointF newObstacleCoordinate ;
    newObstacleCoordinate.setX(ObstacleCoordinates.x() + x_);
    newObstacleCoordinate.setY(ObstacleCoordinates.y() - y_coeff * y_);

    (*Environment)[ObstacleCoordinates.y()][ObstacleCoordinates.x()] = util1.RemoveDO(this->Environment->at(ObstacleCoordinates.y()).at(ObstacleCoordinates.x()),this->Dynamic_Obstacle_ID);
    QString l = util1.AddDO(this->Environment->at(newObstacleCoordinate.y()).at(newObstacleCoordinate.x()),this->Dynamic_Obstacle_ID);
    (*Environment)[newObstacleCoordinate.y()][newObstacleCoordinate.x()] = l;
    ObstacleCoordinates.setX(newObstacleCoordinate.x());
    ObstacleCoordinates.setY(newObstacleCoordinate.y());


    //if (qAbs(ObstacleCoordinates.x() - 11) < 3 && qAbs(ObstacleCoordinates.y() - 20) < 3)
    {
         //QMessageBox::information(0,"Finished","Food was picked up...",0);
    }

    return 1;

}
Dynamic_Obstacle::Dynamic_Obstacle()
{
    direction = 1;
}
