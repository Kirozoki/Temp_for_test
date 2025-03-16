#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.h"
#include "robot_math.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sb_th1_valueChanged(int arg1);

    void on_sb_th2_valueChanged(int arg1);

    void on_sb_th3_valueChanged(int arg1);

    void on_sb_th4_valueChanged(int arg1);

    void on_sb_th5_valueChanged(int arg1);

    void on_sb_th6_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Matrix input_params;
    RobotMath math;

    void ReadParameters();
    double GetRadiansValues(QString text);
    double FromDegreesToRadians(double value);
};
#endif // MAINWINDOW_H
