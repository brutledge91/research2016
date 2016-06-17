#include "detected_obstacle.h"
#include "constants.h"
#include "QList.h"

int Detected_Obstacle::getSpeed(){
    return speed;
   }

void Detected_Obstacle::setSpeed(int spd){
    speed = spd;
   }

QVector<int> Detected_Obstacle::getMov(int obs, int num_step){
//    QVector<int> val;
//    QList<float> p;
//    QList<float> s;
      const int x = 1;
//    for(int i=0; i <= matrix_size - 1; i++){
//        p.append(Mov(obs,i));
//        }

//    s = p;
//    qSort(s.begin(), s.end(),qGreater<qreal>());

//    for(int j=0; j<= matrix_size - 1; j++){
//        bool move = false;
//        float max = s.at(j);
//        int count = s.count(max);
//        if(count > 1){
//            for(int l =1; l <= count; l++){
//                //val = p.indexOf(max,l);
//                //if(no walls){
//                //  move = true;
//                //  break;
//                //  }
//                }
//            }
//        else{
//                //val = p.indexOf(max);
//                //if(no walls){
//                //  move = true;
//                //  }
//                }

//        if(move == true){
//            break;
//            }
//        }

//    return val;

    QVector<double> temp;
        for(int z = 0; z<= matrix_size - 1; z++){
            temp.insert(z,Mov(z,obs));
        }

    QGenericMatrix<matrix_size,x,double> temp;
    QGenericMatrix<matrix_size,matrix_size,double> temp2;
    temp2.*(Mov,temp);
    int f = 0;
    int s = 0;
    double max = 0;


    }



//Detected_Obstacle::updateMov();
//Detected_Obstacle::setSpd();

void Detected_Obstacle::setLocation(QPointF){

    }

QPointF Detected_Obstacle::setEstLocation(QPointF location,int move){
    QPointF newLocation;
    //moves:
    const int a = 0;//left
    const int b = 1;//right
    const int c = 2;//forward
    const int d = 3;//backward
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



