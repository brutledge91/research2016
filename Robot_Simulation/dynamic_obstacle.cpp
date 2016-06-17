#include "dynamic_obstacle.h"
#include <random>
#include "constants.h"

bool move = false;

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
 //    if (ObstacleCoordinates.y() >= 11)
 //   {
 //       degree = 0;
 //   }
    double x_ = qCos(qDegreesToRadians(degree));
    double y_ = qSin(qDegreesToRadians(degree));

    QPointF newObstacleCoordinate;
    newObstacleCoordinate.setX(ObstacleCoordinates.x() + x_);
    newObstacleCoordinate.setY(ObstacleCoordinates.y() - y_coeff * y_);

    // ///////////////////////////////////////////////////////////////////////

    if(move == false){
    while(true){
        int min = 0;
        int max = matrix_size;
        std::random_device seed;
        std::mt19937 generator(seed());
        std::uniform_int_distribution<int> dist(min, max);
        int init_mov = dist(generator);

        const int a = 0;//left
        const int b = 1;//right
        const int c = 2;//forward
        const int d = 3;//backward
      //constexpr int e = 4;//no movement

        switch(init_mov){
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

        if(tempx < 0 || tempy < 0 || tempy > Environment->size() || tempx > Environment->at(tempy).size() ){
            continue;
            }
        else if(util1.IncludesObstacle(this->Environment->at(tempy).at(tempx))){
            continue;
            }
        else{
            move = true;
            break;
            }

        }
        }

    else{
        bool break = false;
        QVector<int> val;
        QList<float> p;
        QList<float> s;
          const int x = 1;
        for(int i=0; i <= matrix_size - 1; i++){
            p.append(Mov(obs,i));
            }

        s = p;
        qSort(s.begin(), s.end(),qGreater<qreal>());

        for(int j=0; j<= matrix_size - 1; j++){
            bool move = false;
            float max = s.at(j);
            int count = s.count(max);
            if(count > 1){
                for(int l =1; l <= count; l++){
                    //val = p.indexOf(max,l);
                    //if(no walls){
                    //  move = true;
                    //  break;
                    //  }
                    }
                }
            else{
                    //val = p.indexOf(max);
                    //if(no walls){
                    //  move = true;
                    //  }
                    }

            if(move == true){
                break;
                }
            }

        return val;


    }


    // ///////////////////////////////////////////////////////////////////////
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
