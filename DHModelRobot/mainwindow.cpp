#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formula_pi_expr.h"

struct Point3D;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), input_params(6, 4), math(input_params)
{
    ui->setupUi(this);
    ReadParameters();
    math.UpdateValues();
    Point3D result = math.GetFinalPoint();
    ui->lbl_result->setText(QString("X = %1, Y = %2, Z = %3").arg(result.x).arg(result.y).arg(result.z));
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::FromDegreesToRadians(double value) {

    return (value * Pi / 180);
}

void MainWindow::ReadParameters() {
    //Read 'theta' values with converting from Celsius degrees to rad and inserting in params matrix
    input_params.set_value(0, 0, FromDegreesToRadians(ui->sb_th1->text().toDouble()));
    input_params.set_value(1, 0, FromDegreesToRadians(ui->sb_th2->text().toDouble()));
    input_params.set_value(2, 0, FromDegreesToRadians(ui->sb_th3->text().toDouble()));
    input_params.set_value(3, 0, FromDegreesToRadians(ui->sb_th4->text().toDouble()));
    input_params.set_value(4, 0, FromDegreesToRadians(ui->sb_th5->text().toDouble()));
    input_params.set_value(5, 0, FromDegreesToRadians(ui->sb_th6->text().toDouble()));
    //Read 'a' values in m and inserting in params matrix
    input_params.set_value(0, 1, ui->lbl_a1->text().toDouble());
    input_params.set_value(1, 1, ui->lbl_a2->text().toDouble());
    input_params.set_value(2, 1, ui->lbl_a3->text().toDouble());
    input_params.set_value(3, 1, ui->lbl_a4->text().toDouble());
    input_params.set_value(4, 1, ui->lbl_a5->text().toDouble());
    input_params.set_value(5, 1, ui->lbl_a6->text().toDouble());
    //Read 'd' values in m and inserting in params matrix
    input_params.set_value(0, 2, ui->lbl_d1->text().toDouble());
    input_params.set_value(1, 2, ui->lbl_d2->text().toDouble());
    input_params.set_value(2, 2, ui->lbl_d3->text().toDouble());
    input_params.set_value(3, 2, ui->lbl_d4->text().toDouble());
    input_params.set_value(4, 2, ui->lbl_d5->text().toDouble());
    input_params.set_value(5, 2, ui->lbl_d6->text().toDouble());
    //Read 'alpha' values and inserting in params matrix
    input_params.set_value(0, 3, GetRadiansValues(ui->lbl_alpha1->text()));
    input_params.set_value(1, 3, GetRadiansValues(ui->lbl_alpha2->text()));
    input_params.set_value(2, 3, GetRadiansValues(ui->lbl_alpha3->text()));
    input_params.set_value(3, 3, GetRadiansValues(ui->lbl_alpha4->text()));
    input_params.set_value(4, 3, GetRadiansValues(ui->lbl_alpha5->text()));
    input_params.set_value(5, 3, GetRadiansValues(ui->lbl_alpha6->text()));
}

//It's considered that if 'P' is present then it's formula otherwise it is double value
double MainWindow::GetRadiansValues(QString text) {
    if (text.isEmpty()) {
        return 0.0;
    } else if (text.toStdString().find('P') != std::string::npos) {
        Formula formula(text.toStdString());
        return formula.GetValue();
    }

    return text.toDouble();
}

void MainWindow::on_sb_th1_valueChanged(int /*arg*/)
{
    input_params.set_value(0, 0, FromDegreesToRadians(ui->sb_th1->text().toDouble()));
    math.UpdatedRowThetaValue(0);
    Point3D result = math.GetFinalPoint();
    ui->lbl_result->setText(QString("X = %1, Y = %2, Z = %3").arg(result.x).arg(result.y).arg(result.z));
}


void MainWindow::on_sb_th2_valueChanged(int /*arg*/)
{
    input_params.set_value(1, 0, FromDegreesToRadians(ui->sb_th2->text().toDouble()));
    math.UpdatedRowThetaValue(1);
    Point3D result = math.GetFinalPoint();
    ui->lbl_result->setText(QString("X = %1, Y = %2, Z = %3").arg(result.x).arg(result.y).arg(result.z));
}


void MainWindow::on_sb_th3_valueChanged(int /*arg*/)
{
    input_params.set_value(2, 0, FromDegreesToRadians(ui->sb_th3->text().toDouble()));
    math.UpdatedRowThetaValue(2);
    Point3D result = math.GetFinalPoint();
    ui->lbl_result->setText(QString("X = %1, Y = %2, Z = %3").arg(result.x).arg(result.y).arg(result.z));
}


void MainWindow::on_sb_th4_valueChanged(int /*arg*/)
{
    input_params.set_value(3, 0, FromDegreesToRadians(ui->sb_th4->text().toDouble()));
    math.UpdatedRowThetaValue(3);
    Point3D result = math.GetFinalPoint();
    ui->lbl_result->setText(QString("X = %1, Y = %2, Z = %3").arg(result.x).arg(result.y).arg(result.z));
}


void MainWindow::on_sb_th5_valueChanged(int /*arg*/)
{
    input_params.set_value(4, 0, FromDegreesToRadians(ui->sb_th5->text().toDouble()));
    math.UpdatedRowThetaValue(4);
    Point3D result = math.GetFinalPoint();
    ui->lbl_result->setText(QString("X = %1, Y = %2, Z = %3").arg(result.x).arg(result.y).arg(result.z));
}


void MainWindow::on_sb_th6_valueChanged(int /*arg*/)
{
    input_params.set_value(5, 0, FromDegreesToRadians(ui->sb_th6->text().toDouble()));
    math.UpdatedRowThetaValue(5);
    Point3D result = math.GetFinalPoint();
    ui->lbl_result->setText(QString("X = %1, Y = %2, Z = %3").arg(result.x).arg(result.y).arg(result.z));
}

