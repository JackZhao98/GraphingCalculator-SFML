//
//  operator.hpp
//  Algorithm
//
//  Created by Jack Zhao on 11/14/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef operator_hpp
#define operator_hpp
#include <string>
#include <cmath>
#include "token.hpp"

class optr: public token {
private:
    std::string _op;
public:
    optr(char _op = char());
    optr(std::string op = std::string());
    double do_math(const double& Unary);
    double do_math(const double& LHS, const double& RHS);
    double Tan(const double& var);
    std::ostream& print(std::ostream& out)const;
};

#endif /* operator_hpp */
