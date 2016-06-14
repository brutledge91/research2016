#include "detected_obstacle.h"
#include "constants.h"
#include "QList.h"

int Detected_Obstacle::getSpeed(){
    return speed;
   }

void Detected_Obstacle::setSpeed(int spd){
    speed = spd;
   }

int Detected_Obstacle::getMov(int obs){
    int val = 0;
    QList<float> p;
    QList<float> s;

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
                val = p.indexOf(max,l);
                //if(no walls){
                //  move = true;
                //  break;
                //  }
                }
            }
        else{
                val = p.indexOf(max);
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



//Detected_Obstacle::updateMov();
//Detected_Obstacle::setSpd();

void Detected_Obstacle::setLocation(QPointF){

    }

QPointF Detected_Obstacle::setEstLocation(QPointF location,int move){
    QPointF newLocation;
    //moves:
    constexpr int a = 0;//left
    constexpr int b = 1;//right
    constexpr int c = 2;//forward
    constexpr int d = 3;//backward
  //constexpr int e = 4;//no movement
    switch(move){
        case a:
            newLocation.setX(location.x() - step);
            newLocation.setY(location.y());
            break;
        case b:
            newLocation.setX(location.x() + step);
            newLocation.setY(location.y());
            break;
        case c:
            newLocation.setX(location.x());
            newLocation.setY(location.y() - step);
            break;
        case d:
            newLocation.setX(location.x());
            newLocation.setY(location.y() + step);
            break;
        default:
            newLocation.setX(location.x());
            newLocation.setY(location.y() + step);
        }
    return newLocation;

}
Detected_Obstacle::Detected_Obstacle(){

}



