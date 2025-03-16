#ifndef FORMULA_PI_EXPR_H
#define FORMULA_PI_EXPR_H

#pragma once
#include <iostream>
#include <sstream>
#include <cctype>

const double Pi = 3.14159265358979;

// Class is used for formulas of type P*12/14, -P*3/4, P/4 and etc. Integers are used only for getting share of Pi number.
class Formula{
public:
    Formula(std::string expr);

    bool IsCorrect();

    double GetValue();

private:
    double value_ = 0.0;
    bool is_correct = false;

    void ParseFormula(std::string expr);

    double GetIntNumber(std::istream& in);
};

#endif // FORMULA_PI_EXPR_H
