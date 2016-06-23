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
//      const int x = 1;
//    for(int i=0; i <= num_states - 1; i++){
//        p.append(Mov(obs,i));
//        }

//    s = p;
//    qSort(s.begin(), s.end(),qGreater<qreal>());

//    for(int j=0; j<= num_states - 1; j++){
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

    QVector<int> result;
    QVector<double> temp;
        for(int z = 0; z<= num_states - 1; z++){
            temp.insert(z,Mov(z,obs));
        }
    QGenericMatrix<num_states,num_states,double> temp2 = Mov;

    for(int i = 0; i <= num_states - 1; i++){
        for(int j = 0; j<= num_states - 1; j++){
            temp2(i,j) = temp2(i,j)*temp.at(j);
        }
    }
    int index_1;
    int index_2;
    double max;

    for(int l = 0; l <= num_states - 1; l++){
        for(int k = 0; k<= num_states - 1; k++){
            if(temp2(l,k) > max){
                max = temp2(l,k);
                index_1 = l;
                index_2 = k;
            }
        }
    }
    result.append(index_1);
    result.append(index_2);
    return result;
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



