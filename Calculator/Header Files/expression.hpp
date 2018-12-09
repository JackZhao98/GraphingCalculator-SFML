//
//  calculator.hpp
//  Algorithm
//
//  Created by Jack Zhao on 11/14/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef calculator_hpp
#define calculator_hpp
#include <queue>
#include <sstream>
#include <string>
#include "stack.hpp"
#include "token.hpp"
#include "variable.hpp"
#include "oprand.hpp"
#include "operator.hpp"

using namespace std;

class expression {
public:
    expression(string _s_input = string()): _exp(_s_input), _error(0) {
        (_exp == string())? void():convert(_s_input);
    }
    
    // Accessor
    queue<token*> get_token() {return __token;}
    string getEquation() {return _exp;}
    bool isError() {
        return _error != 0;
    }
    // I/O Stream, for debug.
    friend ostream& operator << (ostream& out, expression& PRINT);
    friend istream& operator >> (istream& ins, expression& e);

    
    double eval(double _x_value = 0);
    /*
    * This function takes an x value and input to the equation.
    * Using RPN algorithm to calculate a correct Y value (result of the expression).
    *
    */
    void setEquation(const string& _input) {
        _exp = _input;
        eval();
    }
    /*
    * Set up equation.
    *
    */

private:
    void convert (string input);
    /*
    * Convert _exp string into tokens in RPN form.
    */
    int priority(string OPERATOR);
    /*
    * Determine operator priority.
    * Very dumb approach.
    */
    bool peek(string& s)const;
    /*
    * Peek at next char.
    * Returns if the next character is a digit.
    */
    queue<token*> __token;
    string _exp;
    int _error;
};



#endif /* calculator_hpp */
