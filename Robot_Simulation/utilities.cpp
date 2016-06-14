#include "utilities.h"

Utilities::Utilities()
{

}

QString Utilities::String_Replace_Constants(QString input_string)
{
    input_string = input_string.replace("[AppStartupDir]",QCoreApplication::applicationDirPath());
    return input_string;
}
QVector <QString> Utilities::Get_3rd_Dimention(QString Input_)
{
    QStringList Temp1 = Input_.split('|');
    QVector<QString> Temp2;
    foreach(QString str, Temp1) {
      Temp2.append(str);
    }
    return Temp2;
}
bool Utilities::IncludesRobot(QString Input_)
{
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str.split("_")[0] == "Rob") return true;    //Robot
    }
    return false;
}
bool Utilities::IncludesStartPoint(QString Input_)
{
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str == "SP") return true;    //StartPoint
    }
    return false;
}
bool Utilities::IncludesVirtualPoint(QString Input_)
{
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str == "VP") return true;    //VirtualPoint
    }
    return false;
}
bool Utilities::IncludesTarget(QString Input_)
{
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str == "T") return true;    //Target
    }
    return false;
}
bool Utilities::IncludesObstacle(QString Input_)
{
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str == "O") return true;    //Obstacle
    }
    return false;
}
int Utilities::IncludesRobotTail(QString Input_)
{
    int rt = 0;
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str == "RT") rt++;    //RobotTail
    }
    return rt;
}
QString Utilities::RemoveRobot(QString Input_, QString RobotID)
{
    QStringList Temp1 = Input_.split(',');
    QString l= "";
    foreach(QString str, Temp1) {
        if (str != RobotID)
        {
            l = l + str + ",";
        }
    }
    return l;
}
bool Utilities::IncludesRobot(QString Input_, QString RobotID)
{
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str == RobotID) return true;
    }
    return false;
}
QString Utilities::InitializeRobot(QString Input_, QString RobotID)
{
    QStringList Temp1 = Input_.split(',');
    QString l= "";
    foreach(QString str, Temp1) {
        if (str.split("_")[0] != "Rob")
        {
            l = l + str + ",";
        }
        else
        {
            l = l + RobotID + ",";
        }
    }
    return l;
}
QString Utilities::AddVirtualPoint(QString Input_, QString RobotID)
{
    QStringList Temp1 = Input_.split(',');
    QString l= "";
    int i_ = 0;
    foreach(QString str, Temp1) {
        if (str == "VP")
        {
            i_++;
        }
        l = l + str + ",";

    }
    if (i_ ==0 ) l = l + "VP,";
    return l;
}
QString Utilities::AddRobot(QString Input_, QString RobotID)
{
    QStringList Temp1 = Input_.split(',');
    QString l= "";
    int i_ = 0;
    foreach(QString str, Temp1) {
        if (str == RobotID)
        {
            i_++;
        }
        l = l + str + ",";

    }
    if (i_ == 0 ) l = l + RobotID + ",";
    return l;
}
QString Utilities::AddTail(QString Input_, QString RobotID)
{
    QStringList Temp1 = Input_.split(',');
    QString l= "";
    int i_ = 0;
    foreach(QString str, Temp1) {
        if (str == "RT")
        {
            i_++;
        }
        l = l + str + ",";

    }
    if (i_ == 0 ) l = l + "RT,";
    return l;
}


QString Utilities::InitializeDO(QString Input_, QString ObsID)
{
    QStringList Temp1 = Input_.split(',');
    QString l= "";
    foreach(QString str, Temp1) {
        if (str.split("_")[0] != "DO")
        {
            l = l + str + ",";
        }
        else
        {
            l = l + ObsID + ",";
        }
    }
    return l;
}
QString Utilities::AddDO(QString Input_, QString ObsID)
{
    QStringList Temp1 = Input_.split(',');
    QString l= "";
    int i_ = 0;
    foreach(QString str, Temp1) {
        if (str == ObsID)
        {
            i_++;
        }
        l = l + str + ",";

    }
    if (i_ == 0 ) l = l + ObsID + ",";
    return l;
}
QString Utilities::RemoveDO(QString Input_, QString ObsID)
{
    QStringList Temp1 = Input_.split(',');
    QString l= "";
    foreach(QString str, Temp1) {
        if (str != ObsID)
        {
            l = l + str + ",";
        }
    }
    return l;
}
/*bool Utilities::IncludesDO(QString Input_)
{
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str.split("_")[0] == "DO")
        {
            return true;    //Obstacle
        }
    }
    return false;
}*/
bool Utilities::IncludesDO(QString Input_, QString ObsID)
{
    QStringList Temp1 = Input_.split(',');
    foreach(QString str, Temp1) {
        if (str == ObsID)
        {
            return true;
        }
    }
    return false;
}
