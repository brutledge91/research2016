#include "myrobot1.h"
#include <fstream>
#include <QString>
#include <QVector2D>
#include <cmath>
#include "detected_obstacle.h"

MyRobot1::MyRobot1()
{
    this->Mov = ObsMov;
}
void MyRobot1::SetRobotID(int ID_)
{
    this->RobotID = "Rob_" + QString::number(ID_);
}
void MyRobot1::SetGridInformation(QVector<QVector <QString> >* env_grid)
{
    this->Environment = env_grid;
}

QVector<double> MyRobot1::GetRobot_Radar_Data()
{
    return this->Robot_Radar_Data;
}
QVector<double> MyRobot1::GetRobot_Fuzzy_Data()
{
    return this->Robot_Fuzzy_Data;
}
QVector<double> MyRobot1::GetRobot_Final_Data()
{
    return this->Robot_Final_Data;
}
void MyRobot1::FindRobot()
{
    int gridsize = this->Environment->size();
    if (gridsize < 1) return;

    for (int i = 0 ; i < gridsize; i++)
    {
        for (int j = 0; j < gridsize; j++)
        {
            if (util1.IncludesRobot(Environment->at(j).at(i),this->RobotID))
            {
                RobotCoordinate.setX(i);
                RobotCoordinate.setY(j);
            }
        }
    }
}

void MyRobot1::FindTarget()
{
    int gridsize = this->Environment->size();
    if (gridsize < 1) return;

    for (int i = 0 ; i < gridsize; i++)
    {
        for (int j = 0; j < gridsize; j++)
        {
            if (util1.IncludesTarget(Environment->at(j).at(i)))
            {
                QPointF temp12;
                temp12.setX(i);
                temp12.setY(j);
                TargetCoordinate.push_back(temp12);
            }
        }
    }
}

void MyRobot1::SetXYMeasurements(double x_i, double y_i)
{
    x_distance = x_i;
    y_distance = y_i;
}

int MyRobot1::GetRobotRange()
{
    return Radar_Range;
}

double MyRobot1::GetDegreetoTarget()
{
    return DegreetoTarget;
}

double MyRobot1::GetDistancetoTarget()
{
    double x1 = this->currentTargetpoint().x() - RobotCoordinate.x();
    double y1 = this->currentTargetpoint().y() - RobotCoordinate.y();
    this->DistancetoTarget = qSqrt(x1*x1 + y1*y1);
    return this->DistancetoTarget;
}

void MyRobot1::InitializeRobot()
{
    //TargetCoordinate = new QStack<QPointF>();
    FindRobot();
    FindTarget();

}

void MyRobot1::ProcessDegreetoTarget()
{
    double x1 = this->currentTargetpoint().x() - RobotCoordinate.x();
    double y1 = this->currentTargetpoint().y() - RobotCoordinate.y();
    double z = y1 / x1;
    DegreetoTarget = qRadiansToDegrees(qAtan(z));
    if (x1 > 0 && y1 > 0 )
    {
        DegreetoTarget = 360 - DegreetoTarget ;
    }
    if (x1 > 0 && y1 < 0 )
    {
        DegreetoTarget = -1 * DegreetoTarget;
    }
    if (x1 < 0 && y1 > 0 )
    {
        DegreetoTarget = -1 * DegreetoTarget + 180;
    }
    if (x1 < 0 && y1 < 0 )
    {
        DegreetoTarget = 180 - DegreetoTarget ;
    }
}


void MyRobot1::ProcessRadar()
{
    for (int i = 0; i < Robot_Radar_Data.size(); i++)
    {
        double DegreeInRadian = qDegreesToRadians(i * this->Radar_step);
        double CosValue = qCos(DegreeInRadian);
        double SinValue = qSin(DegreeInRadian);
        int tempcellvalue = 0;
        double tempcelldistance = 1;
        for (double j = 1 ; j <= Radar_Range; j ++)
        {
            int temp_x = this->RobotCoordinate.x() + CosValue * j;
            int temp_y = this->RobotCoordinate.y() - SinValue * j;
            //if (QPointF(temp_x,temp_y) == this->RobotCoordinate) continue;
            if (util1.IncludesObstacle(this->Environment->at(temp_y).at(temp_x)))
            {
                tempcelldistance = j / Radar_Range;
                break;
            }
        }
        this->Robot_Radar_Data[i] = tempcelldistance;
        this->Robot_Fuzzy_Data[i] = getoutputfuzzy(i * this->Radar_step);
        this->Robot_Final_Data[i] = this->operator_output(this->Robot_Radar_Data[i], this->Robot_Fuzzy_Data[i]);
    }
}

QPointF MyRobot1::currentTargetpoint()
{

    QPointF temp = TargetCoordinate[TargetCoordinate.size() - 1];
    return temp;
}

double MyRobot1::getoutputfuzzy(int inp_)
{
    if ((qAbs(inp_ - DegreetoTarget) < Fuzzy_variable) || (qAbs(inp_ - 360 - DegreetoTarget) < Fuzzy_variable) || (qAbs(inp_ + 360 - DegreetoTarget) < Fuzzy_variable) )
    {
        return 1;
    }
   return 0;
}
double MyRobot1::operator_output(double input1, double input2)
{
    if (input1 < input2)
    {
        return input1;
    }
   return input2;
}


double MyRobot1::bestangle()
{
    segments.clear();
    int i = (int)DegreetoTarget - (Fuzzy_variable);
    while ( i < (int)DegreetoTarget + (Fuzzy_variable) )
    {
        int temp1 = i;
        if (temp1 < 0) temp1 += 360;
        if (temp1 > 359) temp1 -= 360;
        QList <int> temp2;
        while (this->Robot_Final_Data[temp1] > 0.8)
        {
            temp2.append(i);
            i++;
            temp1 = i;
            if (temp1 < 0) temp1 += 360;
            if (temp1 > 359) temp1 -= 360;
        }
        if (temp2.size() > 0)
        {
            segments.append(temp2);
        }
        i++;
    }

    QList <int> temp2;
    int maxnumber = 0;

    for (int l = 0; l < segments.size(); l++)
    {
            if (segments[l].size() > maxnumber)
            {
                temp2 =  segments[l];
                maxnumber = segments[l].size();
            }
    }

    //////////////////////////////////////////////////
    if (temp2.size() < 1)
    {
        double x_temp = RobotCoordinate.x() + qCos(qDegreesToRadians(DegreetoTarget - vp * (10))) * Radar_Range * 1;
        double y_temp = RobotCoordinate.y() - qSin(qDegreesToRadians(DegreetoTarget - vp * (10))) * Radar_Range * 1;
        if (x_temp < 0 || y_temp < 0 || y_temp > Environment->size())
        {
            vp = vp * -1;
            x_temp = RobotCoordinate.x() + qCos(qDegreesToRadians(DegreetoTarget - vp * (10))) * Radar_Range * 1;
            y_temp = RobotCoordinate.y() - qSin(qDegreesToRadians(DegreetoTarget - vp * (10))) * Radar_Range * 1;
        }
        else
        {
            if ( x_temp > Environment->at(y_temp).size())
            {
                x_temp = RobotCoordinate.x() - qCos(qDegreesToRadians(DegreetoTarget - vp * (10))) * Radar_Range * 1;
                y_temp = RobotCoordinate.y() - qSin(qDegreesToRadians(DegreetoTarget - vp * (10))) * Radar_Range * 1;
            }
        }
        QPointF temp12 ;
        temp12.setX(x_temp);
        temp12.setY(y_temp);
        if (TargetCoordinate.size() == 1)
        {
            TargetCoordinate.push(temp12);
        }
        else
        {

            TargetCoordinate[TargetCoordinate.size() - 1].setX(temp12.x());
            TargetCoordinate[TargetCoordinate.size() - 1].setY(temp12.y());
        }

        (*Environment)[temp12.y()][temp12.x()] = util1.AddVirtualPoint(this->Environment->at(temp12.y()).at(temp12.x()),this->RobotID);

//        if (this->Environment->at(TargetCoordinate[TargetCoordinate.size() - 1].y()).at(TargetCoordinate[TargetCoordinate.size() - 1].x()) != 1  )
//        {
//            (*Environment)[temp12.y()][temp12.x()] = 6;
//        }

        return -999;
    }
    //////////////////////////////////////////////////

    return (double)(temp2[(int)maxnumber / 2]);

}

int MyRobot1::move_()
{
    if (TargetCoordinate.size() == 0)
    {
        return 0;
    }
    if ((this->GetDistancetoTarget() < 1))
    {
        if (TargetCoordinate.size() > 0) TargetCoordinate.pop();
        if (TargetCoordinate.size() == 0)
        {
            return 0;
        }
    }
    double degree = this->bestangle();
    if (degree == -999) return 1;
    double x_ = qCos(qDegreesToRadians(degree));
    double y_ = qSin(qDegreesToRadians(degree));
    QPointF newRobotCoordinate ;
    newRobotCoordinate.setX(RobotCoordinate.x() + x_);
    newRobotCoordinate.setY(RobotCoordinate.y() - y_);

    (*Environment)[RobotCoordinate.y()][RobotCoordinate.x()] = util1.RemoveRobot(this->Environment->at(RobotCoordinate.y()).at(RobotCoordinate.x()),this->RobotID);
    (*Environment)[RobotCoordinate.y()][RobotCoordinate.x()] = util1.AddTail(this->Environment->at(RobotCoordinate.y()).at(RobotCoordinate.x()),this->RobotID);
    (*Environment)[newRobotCoordinate.y()][newRobotCoordinate.x()] = util1.AddRobot(this->Environment->at(newRobotCoordinate.y()).at(newRobotCoordinate.x()),this->RobotID);
    RobotCoordinate.setX(newRobotCoordinate.x());
    RobotCoordinate.setY(newRobotCoordinate.y());

    return 1;

}

void MyRobot1::SetRadarSize(int inp_)
{
    this->Robot_Radar_Data.resize(inp_);
    this->Robot_Fuzzy_Data.resize(inp_);
    this->Robot_Final_Data.resize(inp_);
    this->Radar_step = (double)360 / (double)this->Robot_Radar_Data.size();
}

int MyRobot1::ProcessStep()
{

    SpeedCounter ++;
    if (SpeedCounter == Speed)
    {
        SpeedCounter = 0;

        this->ProcessRadar();
        if (this->move_() == 0) return 1;
        this->ProcessDegreetoTarget();
    }
    return 0;
}
//\//////////////////////////////////////////////////////////////
QVector<double> MyRobot1::getProb(Detected_Obstacle obstacle, int move, int steps){
    QVector<double> v;
    QVector<double> result;

        for(int z = 0; z<= num_states - 1; z++){
            v.insert(z,Mov(move,z)); //Mov is in the header
        }

        QVector<QVector<double>> temp1;

        temp1.append(v);

        for(int i = 1; i <= steps; i++){

            QVector<QVector<double>> temp2;

            for(int j = 0; j <= temp1.size()-1; j++){

                QVector<double> temp3;

                for(int k = 0; k <= num_states -1; k++){
                    for(int l = 0; l <= num_states - 1; l++){
                        temp3[l] = temp1[j][l] * Mov(k,l);
                    }
                    temp2.append(temp3);
                }
            }
            temp1 = temp2;
        }

        for(auto& h : temp1){
            result.append(h);
        }
        return result;
}



QVector<QVector<int>> MyRobot1::findPaths(QVector<double> prob){
    //int stp = 0;
    int j = 0;
    int size = prob.size();
    QVector<QVector<int>> path;

    path.resize(size);
    for(int r = 0; r< path.size(); r++)
    {
        path[r].resize(num_step);
    }

    int x = 0;
    int bound = size / pow(num_states,(num_step -1));

    for(int step = 0; step <= num_step; step++){

        for(int index = 0; index <= prob.size() -1; index++){

            path[index][step] = j;

            if(x == bound -1){
                if(j == num_states){
                    j = 0;
                }
                else{
                    j++;
                    x = 0;
                }
            }
            else{
                x++;
            }
            if(j == num_states){
                j = 0;
            }
        }

    }
    return path;
}

QVector<QPointF> MyRobot1::findLocations(QVector<QVector<int>> qpath,QPointF location){



    //moves:
    int state;
    //constexpr int e = 4;//no movement
    int size = qpath.size();
    QVector<QPointF> result;

    result.resize(size);

for(int i = 0; i <= size; i++){

    QPointF newLocation = location;

    for(int j = 0; j <= num_step - 1; j++){

        state = qpath[i][j];

        switch(state){
        case Direction_::Left:
            newLocation.setX(newLocation.x() - step);
            newLocation.setY(newLocation.y());
            break;
        case Direction_::Right:
            newLocation.setX(newLocation.x() + step);
            newLocation.setY(newLocation.y());
            break;
        case Direction_::Forward:
            newLocation.setX(newLocation.x());
            newLocation.setY(newLocation.y() - step);
            break;
        case Direction_::Backward:
            newLocation.setX(newLocation.x());
            newLocation.setY(newLocation.y() + step);
            break;
        default:
            newLocation.setX(newLocation.x());
            newLocation.setY(newLocation.y() + step);
    }
   }
       result[i] = newLocation;
  }
return result;

}
//void Robot1::addDetectedObstacles(Detected)

//void MyRobot1::Message()
//{

//      //QString msg = RobotID + QString::number(RobotCoordinate.x())+ QString::number(RobotCoordinate.y());
//      //std::ofstream myfile("com.txt",std::ofstream::out);
//      //myfile << msg;
//      //myfile.close();

//      //QString QString::number ( double n, char format = 'g', int precision = 6 );

//      QString filename = comtxt;//file adding path
//      QFile file(filename);
//      file.open(QIODevice::Append);
//      QTextStream stream(&file);
//      stream << RobotID << " " << QString::number(RobotCoordinate.x()) << "," << QString::number(RobotCoordinate.y()) << endl;
//      file.close();
//}
