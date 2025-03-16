#include "formula_pi_expr.h"

Formula::Formula(std::string expr) {
    ParseFormula(expr);
}

bool Formula::IsCorrect() {
    return is_correct;
}

double Formula::GetValue() {
    if (!is_correct) {
        return 0.0;
    }
    return value_;
}

void Formula::ParseFormula(std::string expr) {
    double left = 0.0;
    double right = 0.0;
    bool is_negative = false;
    bool is_first = true;
    std::istringstream str(expr);
    char c;
    while (str >> c) {
        if (c == '-' && is_first) {
            is_negative = true;
            is_first = false;
            continue;
        } else if (c == 'P') {
            if (is_negative) {
                left = -Pi;
                is_negative = false;
            } else {
                left = Pi;
            }
        } else if (c == '*') {
            left *= GetIntNumber(str);
        } else if (c == '/') {
            right = GetIntNumber(str);
            if (right == 0) {
                std::cerr << "Division by zero is prohibited. Please correct formula." << std::endl;
                return;
            }
            left /= right;
            right = 0.0;
        }
    }
    value_ = left;
    is_correct = true;
}

double Formula::GetIntNumber(std::istream &in) {
    int val = 0;
    char b = in.peek();
    while (std::isdigit(b)) {
        in >> b;
        val = val * 10 + static_cast<int>(b - '0');
        if (in.peek() == in.eof()) {
            break;
        }
        b = in.peek();
    }
    return val;
}
