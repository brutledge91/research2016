#include "graphic_engine.h"
#include "constants.h"

Graphic_Engine::~Graphic_Engine()
{
    delete util1;
}
Graphic_Engine::Graphic_Engine(QWidget *parent, QGraphicsView* myscene)
{
    this->Scene_ = new QGraphicsScene(parent);
    this->Scene_View = myscene;
    QRect rcontent = this->Scene_View->contentsRect();
    this->Scene_->setSceneRect(0, 0, rcontent.width(), rcontent.height());
    this->Scene_View->setScene(Scene_);
    util1 = new Utilities();
    House.load(util1->String_Replace_Constants(Maps_Directory) + "/House.png");
    Grass.load(util1->String_Replace_Constants(Maps_Directory) + "/Grass.png");
    Person.load(util1->String_Replace_Constants(Maps_Directory) + "/Person.png");
    Bear.load(util1->String_Replace_Constants(Maps_Directory) + "/Bear.png");
    Food.load(util1->String_Replace_Constants(Maps_Directory) + "/Food.png");
}
void Graphic_Engine::Set_DataVariables(QVector<QVector <QString> > *Gd)
{
    this->Grid_data = Gd;
}

void Graphic_Engine::Clear_View(QWidget* parent, QGraphicsView* radar_flat_view)
{
    QGraphicsScene* round_radar_flat = new QGraphicsScene(parent);
    QRect rcontent = radar_flat_view->contentsRect();
    round_radar_flat->setSceneRect(0, 0, rcontent.width(), rcontent.height());
    radar_flat_view->setScene(round_radar_flat);
    delete round_radar_flat;
}

void Graphic_Engine::Draw_Radar_Flat(QWidget* parent, QGraphicsView* radar_flat_view, QVector<double>* radar_data, QColor color_)
{
    //delete radar_flat_view->scene();
    QGraphicsScene* round_radar_flat;
    if (!radar_flat_view->scene())
    {
        round_radar_flat = new QGraphicsScene(parent);
    }
    else
    {
        round_radar_flat = radar_flat_view->scene();
    }
    QRect rcontent = radar_flat_view->contentsRect();
    round_radar_flat->setSceneRect(0, 0, rcontent.width(), rcontent.height());
    radar_flat_view->setScene(round_radar_flat);
    QPen pen;
    double step = (double)rcontent.width() / (double)radar_data->size();

    for (int i = 1; i < radar_data->size(); i++)
    {
        pen.setColor(color_);
        round_radar_flat->addLine((int)((i-1) * step),rcontent.height()- radar_data->at(i-1)*rcontent.height(),(int)(i * step),rcontent.height() -radar_data->at(i)*rcontent.height(),pen);
    }
    //delete round_radar_flat;
    //radar_flat_view->fitInView(round_radar_flat->sceneRect(),Qt::IgnoreAspectRatio );
}
void Graphic_Engine::Draw_Radar_Round(QWidget* parent, QGraphicsView* radar_flat_view, QVector<double>* radar_data, QColor color_)
{
    //delete radar_flat_view->scene();
    QGraphicsScene* round_radar_flat;
    if (!radar_flat_view->scene())
    {
        round_radar_flat = new QGraphicsScene(parent);
    }
    else
    {
        round_radar_flat = radar_flat_view->scene();
    }
    QRect rcontent = radar_flat_view->contentsRect();
    round_radar_flat->setSceneRect(0, 0, rcontent.width(), rcontent.height());
    radar_flat_view->setScene(round_radar_flat);
    QPen pen;
    pen.setColor(Qt::red);
    double step = (double)360 / (double)radar_data->size();
    round_radar_flat->addEllipse(0,0,rcontent.width(),rcontent.height());

    for (int i = 1; i < radar_data->size(); i++)
    {
        double radiandegree = qDegreesToRadians((float)(i-1) * step);
        int x1 = (rcontent.width() /2) + qCos(radiandegree) *(rcontent.width() / 2) * radar_data->at(i-1);
        int y1 = (rcontent.height() /2) -qSin(radiandegree) *(rcontent.height() / 2) * radar_data->at(i-1);

        double radiandegree2 = qDegreesToRadians((float)(i) * step);
        int x2 = (rcontent.width() /2) + qCos(radiandegree2) *(rcontent.width() / 2) * radar_data->at(i);
        int y2 = (rcontent.height() /2) -qSin(radiandegree2) *(rcontent.height() / 2) * radar_data->at(i);

        pen.setColor(color_);

        round_radar_flat->addLine(x1,y1,x2,y2,pen);
    }
    //radar_flat_view->fitInView(round_radar_flat->sceneRect(),Qt::IgnoreAspectRatio );
}

void Graphic_Engine::run()
{
    this->Scene_->clear();
    int sizeofgrid = this->Grid_data->size();
    float BlockSize = Scene_->sceneRect().height() / sizeofgrid;

    QPen pen;
    QPointF Temp1 ;



    for (int i = 0 ; i < sizeofgrid ; i ++)
    {
        for (int j = 0; j < sizeofgrid ; j++)
        {
            float scalefactor = BlockSize / Grass.height();
            item = new QGraphicsPixmapItem(QPixmap::fromImage(Grass));
            item->setPos(BlockSize * j, BlockSize * i);
            item->setScale(scalefactor);
            //Scene_->addItem(item);
        }
    }

    for (int i = 0 ; i < sizeofgrid ; i ++)
    {
        for (int j = 0; j < sizeofgrid ; j++)
        {
            QString KL = this->Grid_data->at(i).at(j);


            if (util1->IncludesObstacle(KL))
            {
                QGraphicsRectItem *Rect = new QGraphicsRectItem(
                            BlockSize * j,
                            BlockSize * i,
                            BlockSize,
                            BlockSize);
                Rect->setBrush(QBrush(Qt::black));
                float scalefactor = BlockSize / House.width();
                //item = new QGraphicsPixmapItem(QPixmap::fromImage(House));
                //item->setPos(BlockSize * j, BlockSize * i);
                //item->setScale(scalefactor);
                Scene_->addItem(Rect);
            }
            else if (util1->IncludesVirtualPoint(KL))
            {
                QGraphicsRectItem *Rect = new QGraphicsRectItem(
                            BlockSize * j,
                            BlockSize * i,
                            BlockSize,
                            BlockSize);
                Rect->setBrush(QBrush(Qt::gray));
                Scene_->addItem(Rect);
                /*float scalefactor = BlockSize / Food.width();
                item = new QGraphicsPixmapItem(QPixmap::fromImage(Food));
                item->setPos(BlockSize * j, BlockSize * i);
                item->setScale(scalefactor);
                Scene_->addItem(item);*/
            }
            else if (util1->IncludesRobotTail(KL) > 0)
            {
                QGraphicsRectItem *Rect = new QGraphicsRectItem(
                            BlockSize * j,
                            BlockSize * i,
                            BlockSize,
                            BlockSize);
                Rect->setBrush(QBrush(Qt::gray));
                Scene_->addItem(Rect);
            }
            else if (util1->IncludesTarget(KL))
            {
                Temp1.setY(BlockSize * i);
                Temp1.setX(BlockSize * j);
                Scene_->addEllipse(Temp1.x()-10,Temp1.y()-10,BlockSize+20,BlockSize+20,pen,QBrush(QColor(Target_initial_color)));
                Scene_->addEllipse(Temp1.x()-5,Temp1.y()-5,BlockSize+10,BlockSize+10,pen,QBrush(Qt::white));
                Scene_->addEllipse(Temp1.x(),Temp1.y(),BlockSize,BlockSize,pen, QBrush(QColor(Target_initial_color)));
            }
            else if (util1->IncludesStartPoint(KL))
            {
                Temp1.setY(BlockSize * i);
                Temp1.setX(BlockSize * j);
                pen.setColor(QColor(Robot_initial_color));
                Scene_->addEllipse(Temp1.x()-10,Temp1.y()-10,BlockSize +20,BlockSize+20,pen,QBrush(QColor(Robot_initial_color)));
                Scene_->addEllipse(Temp1.x()-5,Temp1.y()-5,BlockSize +10,BlockSize+10,pen,QBrush(Qt::white));
                Scene_->addEllipse(Temp1.x(),Temp1.y(),BlockSize,BlockSize,pen, QBrush(QColor(Robot_initial_color)));
                /*
                 * float scalefactor = BlockSize / Person.width();
                item = new QGraphicsPixmapItem(QPixmap::fromImage(Person));
                item->setPos(BlockSize * j, BlockSize * i);
                item->setScale(4*scalefactor);
                Scene_->addItem(item);*/
            }
            else if (util1->IncludesRobot(KL))
            {
                Temp1.setY(BlockSize * i);
                Temp1.setX(BlockSize * j);
                pen.setColor(QColor(Robot_Radar_Color));
                Scene_->addEllipse(Temp1.x()-(Robot_radar_range*BlockSize),Temp1.y()-(Robot_radar_range*BlockSize),BlockSize+(2*(Robot_radar_range*BlockSize)),BlockSize+(2*(Robot_radar_range*BlockSize)),pen,QBrush(QColor(pen.color().red(),pen.color().green(),pen.color().blue(),100)));
                pen.setColor(QColor(Robot_Pixel_Color));

                Scene_->addEllipse(Temp1.x()-1,Temp1.y()-1,BlockSize+(2*1),BlockSize+(2*1),pen,QBrush(QColor(pen.color().red(),pen.color().green(),pen.color().blue(),255)));
                /*float scalefactor = BlockSize / Person.width();
                item = new QGraphicsPixmapItem(QPixmap::fromImage(Person));
                item->setPos(BlockSize * j, BlockSize * i);
                item->setScale(scalefactor);
                Scene_->addItem(item);*/
            }
            else if (util1->IncludesDO(KL,"DO_1"))
            {
                Temp1.setY(BlockSize * i);
                Temp1.setX(BlockSize * j);
                pen.setColor(QColor(Robot_Radar_Color));
                Scene_->addEllipse(Temp1.x()-(Robot_radar_range*BlockSize),Temp1.y()-(Robot_radar_range*BlockSize),BlockSize+(2*(Robot_radar_range*BlockSize)),BlockSize+(2*(Robot_radar_range*BlockSize)),pen,QBrush(QColor(pen.color().red(),pen.color().green(),pen.color().blue(),100)));
                pen.setColor(QColor(Robot_Pixel_Color));
                Scene_->addEllipse(Temp1.x()-1,Temp1.y()-1,BlockSize+(2*1),BlockSize+(2*1),pen,QBrush(QColor(pen.color().red(),pen.color().green(),pen.color().blue(),255)));
                /*float scalefactor = BlockSize / Bear.width();
                item = new QGraphicsPixmapItem(QPixmap::fromImage(Bear));
                item->setPos(BlockSize * j, BlockSize * i);
                item->setScale(scalefactor * 4);
                Scene_->addItem(item);*/
            }


        }
    }
    delete item;
}
