#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include <QtCore>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QtMath>
#include <vector>
#include "constants.h"
#include "utilities.h"

class Graphic_Engine
{
private:
    QWindow *myparent;
    QGraphicsScene *Scene_;
    QGraphicsView  *Scene_View;
    QVector<QVector <QString> > *Grid_data;
    Utilities *util1;
    int x_step  ;
    int y_step ;
    QGraphicsPixmapItem* item;
    QImage House, Grass, Person, Bear, Food;

public:
    int Robot_radar_range;
    Graphic_Engine(QWidget *, QGraphicsView*);
    ~Graphic_Engine();
    void Set_DataVariables(QVector<QVector <QString> > *Gd);
    void Clear_View(QWidget*, QGraphicsView*);
    void Draw_Radar_Flat(QWidget*, QGraphicsView*, QVector<double>*, QColor = Qt::black);
    void Draw_Radar_Round(QWidget*, QGraphicsView*, QVector<double>*, QColor = Qt::black);

    void run();
};

#endif // GRAPHIC_ENGINE_H
