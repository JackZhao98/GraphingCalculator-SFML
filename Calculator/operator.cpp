//
//  operator.cpp
//  Algorithm
//
//  Created by Jack Zhao on 11/14/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "operator.hpp"
optr::optr(std::string op): _op(op), token() {
    if (_op == "+" || _op == "-" || _op == "*") {
        set_type('1');
    }
    else if ( _op == "/") {
        set_type('2');
    }
    else if (_op == "^") {
        set_type('3');
    }
    else if (_op == "neg" || _op == "sqrt" || _op == "sin" || _op == "cos" || _op == "tan" || _op == "abs") {
        set_type('u');
    }
    else if (_op == "(") {
        set_type('(');
    }
    else if (_op == ")") {
        set_type(')');
    }
    else {
        token();
    }
}

double optr::do_math(const double& LHS, const double& RHS) {
    if (_op == "+")
        return (LHS + RHS);
    if (_op == "-")
        return (LHS - RHS);
    if (_op == "*")
        return (LHS * RHS);
    if (_op == "/")
        return (LHS / RHS);
    if (_op == "^")
        return (pow(LHS,RHS));
    return 0;
}

double optr::do_math(const double& Unary) {
    if (_op == "sqrt")
        return (pow(Unary, 0.5));
    if (_op == "neg")
        return (-1 * Unary);
    if (_op == "sin")
        return sin(Unary);
    if (_op == "cos")
        return cos(Unary);
    if (_op == "tan") {
        return sin(Unary)/cos(Unary);
    }
    if (_op == "abs")
        return fabs(Unary);
    return 0;
}
//
//double optr::Tan(const double& var) {
//    const double error = 0.000001;
//    while ((var-tan(var))>error) {
//
//    }
//}
std::ostream& optr::print(std::ostream& out)const {
    out << _op;
    return out;
}
//double optr::eval(const double& LHS, const double& RHS) {
//    
//}
