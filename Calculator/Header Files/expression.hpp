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
    
    queue<token*> get_token() {return __token;}
    string get_expression() {return _exp;}
    
    friend ostream& operator << (ostream& out, expression& PRINT);
    friend istream& operator >> (istream& ins, expression& e);
    double eval(double _x_value = 0);
    

private:
    void convert (string input);
    int priority(string OPERATOR);
    bool peek(string& s)const;
    
    queue<token*> __token;
    string _exp;
    int _error;
};



#endif /* calculator_hpp */
