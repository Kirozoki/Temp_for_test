#ifndef ROBOT_MATH_H
#define ROBOT_MATH_H

#pragma once
#include "matrix.h"

#include <memory>
#include <vector>
#include <cmath>

struct Point3D {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

class RobotMath {
public:
    RobotMath(Matrix& input_par_ptr);

    void UpdateValues();

    void UpdatedRowThetaValue(int i);

    Point3D GetFinalPoint();

private:
    const Matrix& in_params_ptr_;
    std::vector<Matrix> joints_T;

    void Update();
    // i = index of joint data
    void SetMatrixRowValues(int i);

    //case when only Theta angle is changed
    void ChangedThetaRowValues(int i);

};

#endif // ROBOT_MATH_H
