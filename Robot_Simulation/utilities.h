#ifndef UTILITIES_H
#define UTILITIES_H

#include <QtCore>
#include <QString>
#include <QtGui>

class Utilities
{
public:
    Utilities();
    QString String_Replace_Constants(QString);
    QVector <QString> Get_3rd_Dimention(QString Input_);
    bool IncludesObstacle(QString);
    bool IncludesRobot(QString);
    bool IncludesRobot(QString, QString);
    bool IncludesStartPoint(QString);
    QString InitializeRobot(QString,QString);
    QString RemoveRobot(QString,QString);
    bool IncludesTarget(QString);
    int IncludesRobotTail(QString);
    bool IncludesVirtualPoint(QString);
    QString AddVirtualPoint(QString,QString);
    QString AddRobot(QString,QString);
    QString AddTail(QString,QString);

    //bool IncludesDO(QString);
    bool IncludesDO(QString, QString);
    QString AddDO(QString,QString);
    QString RemoveDO(QString,QString);
    QString InitializeDO(QString,QString);



private :

};

#endif // UTILITIES_H
