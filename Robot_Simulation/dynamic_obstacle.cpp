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
                this->ObstacleCoordinates.setX(i);
                this->ObstacleCoordinates.setY(j);

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
int Dynamic_Obstacle::move_(){
    FindObs();

// //  double degree;
// //    if (ObstacleCoordinates.y() >= 11)
// //   {
// //       degree = 0;
// //   }
//   // double x_ = qCos(qDegreesToRadians(degree));
//   // double y_ = qSin(qDegreesToRadians(degree));


//    //newObstacleCoordinate.setX(ObstacleCoordinates.x() + x_);
//   // newObstacleCoordinate.setY(ObstacleCoordinates.y() - y_coeff * y_);

    // //////////////////////////////////////////////////////////////////////

    const int a = 0;//left
    const int b = 1;//right
    const int c = 2;//forward
    const int d = 3;//backward
    int init_mov;
    if(move == false)
    {
        while(true)
        {
            int min = 0;
            int max = matrix_size;   // matrix_size is defined in Constants.h
            std::random_device seed;
            std::mt19937 generator(seed());
            std::uniform_int_distribution<int> dist(min, max);
            init_mov = dist(generator);
            switch(init_mov)
            {
                case a:
                    newObstacleCoordinate.setX(ObstacleCoordinates.x() - step);
                    newObstacleCoordinate.setY(ObstacleCoordinates.y());
                    break;
                case b:
                    newObstacleCoordinate.setX(ObstacleCoordinates.x() + step);
                    newObstacleCoordinate.setY(ObstacleCoordinates.y());
                    break;
                case c:
                    newObstacleCoordinate.setX(ObstacleCoordinates.x());
                    newObstacleCoordinate.setY(ObstacleCoordinates.y() - step);
                    break;
                case d:
                    newObstacleCoordinate.setX(ObstacleCoordinates.x());
                    newObstacleCoordinate.setY(ObstacleCoordinates.y() + step);
                    break;
                default:
                    newObstacleCoordinate.setX(ObstacleCoordinates.x());
                    newObstacleCoordinate.setY(ObstacleCoordinates.y());
            }
            int tempx = newObstacleCoordinate.x();
            int tempy = newObstacleCoordinate.y();

            if( tempy > Environment->size())
            {
                continue;
            }
            else
            {
                if ( tempx < 0 || tempy < 0 || tempx > Environment->at(tempy).size())
                    continue;
            }
            if(util1.IncludesObstacle(this->Environment->at(tempy).at(tempx))){
                continue;
            }
            else
            {
                move = true;
                break;
            }

        }
    }
    else
    {
        QList<float> p;
        QList<float> s;
        int in;
        for(int i=0; i <= matrix_size - 1; i++)
        {
            p.append(OMov(init_mov,i)); //modify to update init_mov to previous move
        }
        s = p;
        qSort(s.begin(), s.end(),qGreater<qreal>());
        bool x_move = false;
        for(int j=0; j<= matrix_size - 1; j++)
        {
            float max = s.at(j);
            int count = p.count(max);
            for(int l =1; l <= count; l++)
            {
                in = p.indexOf(max,l);
                switch(in)
                {
                    case a:
                        newObstacleCoordinate.setX(ObstacleCoordinates.x() - step);
                        newObstacleCoordinate.setY(ObstacleCoordinates.y());
                        break;
                    case b:
                        newObstacleCoordinate.setX(ObstacleCoordinates.x() + step);
                        newObstacleCoordinate.setY(ObstacleCoordinates.y());
                        break;
                    case c:
                        newObstacleCoordinate.setX(ObstacleCoordinates.x());
                        newObstacleCoordinate.setY(ObstacleCoordinates.y() - step);
                        break;
                    case d:
                        newObstacleCoordinate.setX(ObstacleCoordinates.x());
                        newObstacleCoordinate.setY(ObstacleCoordinates.y() + step);
                        break;
                    default:
                        newObstacleCoordinate.setX(ObstacleCoordinates.x());
                        newObstacleCoordinate.setY(ObstacleCoordinates.y());
                }

                double tempx =  newObstacleCoordinate.x();
                double tempy =  newObstacleCoordinate.y();
                if(!util1.IncludesObstacle(this->Environment->at(tempy).at(tempx)))
                {
                    x_move = true;
                    break;
                }
            }
            if(x_move == true)
            {
                break;
            }
        }

    // ///////////////////////////////////////////////////////////////////////
    (*Environment)[ObstacleCoordinates.y()][ObstacleCoordinates.x()] = util1.RemoveDO(this->Environment->at(ObstacleCoordinates.y()).at(ObstacleCoordinates.x()),this->Dynamic_Obstacle_ID);
    QString l = util1.AddDO(this->Environment->at(newObstacleCoordinate.y()).at(newObstacleCoordinate.x()),this->Dynamic_Obstacle_ID);
    (*Environment)[newObstacleCoordinate.y()][newObstacleCoordinate.x()] = l;
    ObstacleCoordinates.setX(newObstacleCoordinate.x());
    ObstacleCoordinates.setY(newObstacleCoordinate.y());


    //if (qAbs(ObstacleCoordinates.x() - 11) < 3 && qAbs(ObstacleCoordinates.y() - 20) < 3)
   // {
         //QMessageBox::information(0,"Finished","Food was picked up...",0);
    }
//}
    return 1;
}
Dynamic_Obstacle::Dynamic_Obstacle(){
    direction = 1;
}
