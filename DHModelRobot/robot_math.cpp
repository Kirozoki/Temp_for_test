#include "robot_math.h"


RobotMath::RobotMath(Matrix &input_par_ptr) : in_params_ptr_(input_par_ptr)
    , joints_T(in_params_ptr_.get_rows_num(), Matrix{4, 4}){
}

void RobotMath::UpdateValues() {
    Update();
}

void RobotMath::UpdatedRowThetaValue(int i) {
    ChangedThetaRowValues(i);
}

Point3D RobotMath::GetFinalPoint() {
    Matrix results(4, 4);
    for (int i = 0; i < 4; ++i) {
        results.set_value(i, i, 1);
    }
    for(size_t i = 0; i < joints_T.size(); ++i) {
        results *= joints_T[i];
    }

    return {results.get_value(0,3), results.get_value(1,3), results.get_value(2,3)};

}

void RobotMath::Update() {
    for (int i = 0; i < in_params_ptr_.get_rows_num(); ++i) {
        SetMatrixRowValues(i);
    }
}

void RobotMath::SetMatrixRowValues(int i) {
    Matrix& matrix = joints_T[i];
    double theta = in_params_ptr_.get_value(i, 0);
    double a = in_params_ptr_.get_value(i, 1);
    double d = in_params_ptr_.get_value(i, 2);
    double alpha = in_params_ptr_.get_value(i, 3);

    matrix.set_value(0, 0, cos(theta));
    matrix.set_value(0, 1, - sin(theta) * cos(alpha));
    matrix.set_value(0, 2, sin(theta) * sin(alpha));
    matrix.set_value(0, 3, a * cos(theta));

    matrix.set_value(1, 0, sin(theta));
    matrix.set_value(1, 1, cos(theta) * cos(alpha));
    matrix.set_value(1, 2, -cos(theta) * sin(alpha));
    matrix.set_value(1, 3, a * sin(theta));

    matrix.set_value(2, 0, 0.0);
    matrix.set_value(2, 1, sin(alpha));
    matrix.set_value(2, 2, cos(alpha));
    matrix.set_value(2, 3, d);

    matrix.set_value(3, 0, 0.0);
    matrix.set_value(3, 1, 0.0);
    matrix.set_value(3, 2, 0.0);
    matrix.set_value(3, 3, 1);
}

void RobotMath::ChangedThetaRowValues(int i) {
    Matrix& matrix = joints_T[i];
    double theta = in_params_ptr_.get_value(i, 0);
    double a = in_params_ptr_.get_value(i, 1);
    double alpha = in_params_ptr_.get_value(i, 3);

    matrix.set_value(0, 0, cos(theta));
    matrix.set_value(0, 1, - sin(theta) * cos(alpha));
    matrix.set_value(0, 2, sin(theta) * sin(alpha));
    matrix.set_value(0, 3, a * cos(theta));

    matrix.set_value(1, 0, sin(theta));
    matrix.set_value(1, 1, cos(theta) * cos(alpha));
    matrix.set_value(1, 2, -cos(theta) * sin(alpha));
    matrix.set_value(1, 3, a * sin(theta));
}
