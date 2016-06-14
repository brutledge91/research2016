#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    util1 = new Utilities();

    ui->setupUi(this);
    ui->progressBar->setVisible(false);
    this->GPU_ = new Graphic_Engine(this,ui->graphicsView);
    this->GPU_->Set_DataVariables(&Grid_information);
    //this->MyRobot = new QVector<MyRobot1>();
    this->GPU_->Robot_radar_range = 5;
    //this->GPU_->Robot_radar_range = this->MyRobot->GetRobotRange();
    Search_Maps();
    main_clock= new QTimer(this);
    connect(main_clock, SIGNAL(timeout()), this, SLOT(new_clock()));
}

MainWindow::~MainWindow()
{
    delete GPU_;
    delete util1;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for(int str = 0; str <  MyRobot.size(); str++)
    {
        MyRobot[str].InitializeRobot();
    }
    main_clock->start(1);
    ui->Status_lbl->setText("Simulating ...");
}

void MainWindow::new_clock()
{
    int numq = MyRobot.size();
    MyRobot[0].ProcessStep();
    for (int ij = 0; ij < MyRobot.size(); ij++)
    {
        if (MyRobot[ij].ProcessStep())
        {
            numq--;
        }

    }
    for (int j = 0 ; j < MyDOs.size();j++)
    {
        MyDOs[j].ProcessStep();
    }

    /*if (numq == 0)
    {
        this->run_GPU(2,1);   //Robot Radar Data
        this->run_GPU(3,0);   //Robot Radar Fuzzy
        this->run_GPU(4,0);   //Robot Radar After Operator
        main_clock->stop();
        QMessageBox::information(this,"Finished","Robot reached to the target point...",0);
        ui->Status_lbl->setText("Finished ...");
    }*/
    //ui->Angle_lbl->setText(QString::number(this->MyRobot->GetDegreetoTarget()));
    this->run_GPU(2,1);   //Robot Radar Data
    this->run_GPU(3,0);   //Robot Radar Fuzzy
    this->run_GPU(4,0);   //Robot Radar After Operator
}


void MainWindow::Load_Maps(QString MapName)
{
    int RobotCounter = 0;
    int DynamicObs = 0;
    MyRobot.clear();
    MyDOs.clear();
    foreach (const QString &str, MapFiles_Paths)
    {
        QFile temp (str);
        if(!temp.open(QIODevice::ReadOnly)) { QMessageBox::information(0,"error",temp.errorString());}
        if (temp.readLine().simplified() == MapName)
        {
            int x =  temp.readLine().simplified().toInt();
            ui->progressBar->setVisible(true);
            ui->progressBar->setMaximum(x*x);
            Grid_information.resize(x);         //Resize for y
            ui->progressBar->setValue(0);
            for (int j = 0; j < x; j++)
            {
                QString tempstr = temp.readLine().simplified();
                QVector<QString> Zz = util1->Get_3rd_Dimention(tempstr);
                Grid_information[j].resize(x);  //Resize for x
                for (int i = 0; i < x; i++)
                {
                    Grid_information[j][i] = Zz[i];
                    if (util1->IncludesStartPoint(Zz[i]))
                    {
                        RobotCounter ++;
                        MyRobot1 NewRobot;
                        NewRobot.SetRobotID(RobotCounter);
                        NewRobot.SetRadarSize(ui->degrees_txt->text().toInt());
                        Grid_information[j][i] = util1->AddRobot(Zz[i], "Rob_" + QString::number(RobotCounter));
                        NewRobot.SetGridInformation(&Grid_information);
                        //message
                        //NewRobot.Message();
                        this->MyRobot.push_back(NewRobot);
                    }
                    else if (util1->IncludesDO(Zz[i],"DO"))
                    {
                        DynamicObs ++;
                        Dynamic_Obstacle NewObstacle;
                        NewObstacle.SetObsID(DynamicObs);
                        Grid_information[j][i] = util1->AddDO(Zz[i], "DO_" + QString::number(DynamicObs));
                        NewObstacle.SetGridInformation(&Grid_information);
                        this->MyDOs.push_back(NewObstacle);
                    }
                    //ui->progressBar->setValue(ui->progressBar->value() + 1);
                }
            }
            temp.close();
            ui->LoadedMap_lbl->setText(MapName);
            ui->progressBar->setVisible(false);
            break;
        }
        temp.close();
    }
    this->run_GPU();
}

void MainWindow::run_GPU(int callingfunction, int run_)
{
    if (run_ == 1)
    {
        this->GPU_->run();
    }
    if (callingfunction == -1)
    {
        this->GPU_->Clear_View(this,ui->Radar_Flat_V);
        this->GPU_->Clear_View(this,ui->Radar_Round_V);
    }
//    if (callingfunction == 2)
//    {
//        this->run_GPU(-1,0); //clear
//        QVector<double> temp = this->MyRobot->GetRobot_Radar_Data() ;
//        this->GPU_->Draw_Radar_Flat(this,ui->Radar_Flat_V,&(temp));
//        this->GPU_->Draw_Radar_Round(this,ui->Radar_Round_V,&(temp));
//    }
//    if (callingfunction == 3)
//    {
//        QVector<double> temp = this->MyRobot->GetRobot_Fuzzy_Data() ;
//        this->GPU_->Draw_Radar_Flat(this,ui->Radar_Flat_V,&(temp), Qt::blue);
//         this->GPU_->Draw_Radar_Round(this,ui->Radar_Round_V,&(temp), Qt::blue);
//    }
//    if (callingfunction == 4)
//    {
//        QVector<double> temp = this->MyRobot->GetRobot_Final_Data() ;
//        this->GPU_->Draw_Radar_Flat(this,ui->Radar_Flat_V,&(temp),Qt::red);
//         this->GPU_->Draw_Radar_Round(this,ui->Radar_Round_V,&(temp),Qt::red);
//    }

}

void MainWindow::Search_Maps()
{
    ui->ListMaps_cmb->clear();
    MapFiles_Paths.clear();

    Mydirectory.setPath(util1->String_Replace_Constants(Maps_Directory));
    Mydirectory.setNameFilters(QStringList()<<"*.map");
    QStringList mapfiles = Mydirectory.entryList();


    foreach (const QString &str, mapfiles)
    {
        MapFiles_Paths.append(QString("%1/%2").arg(Mydirectory.absolutePath()).arg(str));
    }
    mapfiles.clear();
    foreach (const QString &str, MapFiles_Paths)
    {
        QFile temp (str);
        if(!temp.open(QIODevice::ReadOnly)) { QMessageBox::information(0,"error",temp.errorString());}
        mapfiles.append(temp.readLine().simplified());
        temp.close();
    }
    ui->ListMaps_cmb->addItems(mapfiles);
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::exit(0);
}

void MainWindow::on_Refresh_btn_clicked()
{
        this->Search_Maps();
}

void MainWindow::on_Load_btn_clicked()
{
        Load_Maps(ui->ListMaps_cmb->currentText());
}

void MainWindow::on_pushButton_2_clicked()
{
    if (Grid_information.size() < 1 )
    {
        QMessageBox::information(this,"Error","Please load a map first :)",0);
        return;
    }
    if (Grid_information.at(0).size() < 2 )
    {
        QMessageBox::information(this,"Error","Please load a map first with at least 1 column :)",0);
        return;
    }
    int tempx = ui->Robot_x_txt->text().toInt();
    int tempy = ui->Robot_y_txt->text().toInt();

    if (Grid_information.at(0).size() < tempx )
    {
        QMessageBox::information(this,"Error","Please decrease x value! The Map is smaller.",0);
        return;
    }
    if (Grid_information.size() < tempy )
    {
        QMessageBox::information(this,"Error","Please decrease y value! The Map is smaller.",0);
        return;
    }
    //this->RemoveAllfromNumber(2);
    this->Grid_information[tempy][tempx] = 2;
    //this->MyRobot->InitializeRobot();
    this->run_GPU(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    if (Grid_information.size() < 1 )
    {
        QMessageBox::information(this,"Error","Please load a map first :)",0);
        return;
    }
    if (Grid_information.at(0).size() < 2 )
    {
        QMessageBox::information(this,"Error","Please load a map first with at least 1 column :)",0);
        return;
    }
    int tempx = ui->Target_x_txt->text().toInt();
    int tempy = ui->Target_y_txt->text().toInt();

    if (Grid_information.at(0).size() < tempx - 1 )
    {
        QMessageBox::information(this,"Error","Please decrease x value! The Map is smaller.",0);
        return;
    }
    if (Grid_information.size() < tempy - 1 )
    {
        QMessageBox::information(this,"Error","Please decrease y value! The Map is smaller.",0);
        return;
    }
    //this->RemoveAllfromNumber(3);
    this->Grid_information[tempy][tempx] = 3;
    //this->MyRobot->InitializeRobot();
    this->run_GPU(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    foreach(MyRobot1 str, MyRobot) {
        str.SetRadarSize(ui->degrees_txt->text().toInt());
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    if (main_clock->isActive())
    {
        this->run_GPU(2,1);   //Robot Radar Data
        this->run_GPU(3,0);   //Robot Radar Fuzzy
        this->run_GPU(4,0);   //Robot Radar After Operator
        main_clock->stop();
        ui->Status_lbl->setText("Stopped ...");
    }
}

void MainWindow::on_pushButton_6_clicked()
{

}
