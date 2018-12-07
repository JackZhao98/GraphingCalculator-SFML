//
//  calculator.cpp
//  Algorithm
//
//  Created by Jack Zhao on 11/14/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "expression.hpp"

ostream& operator << (ostream& out, expression& PRINT) {
    out << "Expression: " << PRINT._exp << endl;
    out << "Result: " << PRINT.eval() << endl;
    return out;
}

istream& operator >> (istream& ins, expression& e) {
    std::string input;
    getline(std::cin, input);
    e._exp = input;
    return ins;
}

void expression::convert (string input) {
    int prev = 0;
    steck<string> op;
    if (input.length() <= 0) {
        _error = 1;
        return;
    }
    while (input[input.length() - 1] == ' ')
        input.pop_back();
    
    stringstream ss(input);
    string temp;
    while (__token.size() > 0) {
        delete __token.front();
        __token.pop();
    }
    while (!ss.eof()) {
        ss >> temp;
        if (peek(temp))
            __token.push(new oprand(stod(temp)));
        else {
            if (temp == "(") {
                op.push(temp);
            }
            else if (temp == ")") {
                while (!op.empty()) {
                    if (op.top() != "(") {
                        __token.push(new optr(op.pop()));
                    }
                    else {
                        op.pop();
                    }
                }
                if (!op.empty()) {
                    op.pop();
                }
                if (!op.empty()) {
                    if (priority(op.top()) == 0)
                        __token.push(new optr(op.pop()));
                }
            }
            else if (temp == "x") {
                __token.push(new var(temp[0]));
            }
            else {
                while (!op.empty()) {
                    if (op.top() == "(")
                        break;
                    prev = priority(op.top());
                    if (priority(temp) > prev)
                        break;
                    __token.push(new optr(op.pop()));
                }
                op.push(temp);
                prev = priority(temp);
            }
        }
    }
    while (!op.empty()) (op.top() != "(")? __token.push(new optr(op.pop())):void(op.pop());
}

double expression::eval(double _x_value) {
    if (_exp == string()) {
        _error = 1;
        return 0;
    }
    convert(_exp);
    if (__token.empty()) {
        _error = 1;
        return 0;
    }
    steck<double> result;
    while (!__token.empty()) {
        auto front = __token.front();
        if (front -> type() == 'v') {
            result.push(_x_value);
            delete __token.front();
            __token.pop();
            
        }
        else if (front -> type() == 'n') {
            result.push(front -> get_val());
            delete __token.front();
            __token.pop();
            
        }
        else if (front -> type() == 'u') {
            
            if (result.empty()) {
                _error = 1;
                return 0;
            }
            
            double num = result.top();
            result.pop();
            result.push(front -> do_math(num));
            delete __token.front();
            __token.pop();
        }
        else {
            if (result.empty()) {
                _error = 1;
                return 0;
            }
            double rhs = result.pop();
            
            if (result.empty()) {
                _error = 1;
                return 0;
            }
            
            double lhs = result.pop();
                
            result.push(front -> do_math(lhs, rhs));
            delete __token.front();
            __token.pop();
        }
    }
    _error = 0;
    return result.top();
    
}


bool expression::peek(string& s)const {
    return (isdigit(s[0]));
}


int expression::priority(string OPERATOR) {
    if (OPERATOR == "+" || OPERATOR == "-")
        return 1;
    if (OPERATOR == "*" || OPERATOR == "/")
        return 2;
    if (OPERATOR == "^")
        return 3;
    if (OPERATOR == "sqrt" || OPERATOR == "neg" || OPERATOR == "sin" || OPERATOR == "cos" || OPERATOR == "tan"|| OPERATOR == "abs")
        return 4;
    return 0;
}
