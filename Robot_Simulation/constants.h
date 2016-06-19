#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <QtCore>
#include <QGenericMatrix>

#define PI_ 3.141592653589793238462643383279502884197169399375105820974

const QString Maps_Directory =  "[AppStartupDir]/Maps";
const QString Robot_initial_color = "#1D8012";
const QString Target_initial_color = "#B3002D";
const QString Robot_Radar_Color = "#F0DDEC";
const QString Robot_Pixel_Color = "#584FFF";

// HMM currently 4x4
const int matrix_size = 4;
//movement, left, right, forward, backward
const QGenericMatrix<matrix_size,matrix_size,double> ObsMov(new double[16]{0.1,0.3,0.5,0.1,0.2,0.3,0.5,0,0.1,0.1,0.3,0.5,0.2,0.2,0.3,0.3});
//speed, fast, normal, slow, none
//const QGenericMatrix<3,3,double> ObsSpd(new double[16]{0.1,0.3,0.5,0.1,0.2,0.3,0.5,0,0.1,0.1,0.3,0.5,0.2,0.2,0.3,0.3});
const double step = 10;

#endif // CONSTANTS_H
