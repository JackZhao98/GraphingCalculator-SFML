//
//  variable.hpp
//  Algorithm
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef variable_hpp
#define variable_hpp
#include "token.hpp"

// class: var, inherited from token.
// stores a variable.
class var: public token {
private:
    char _var;
    
public:
    var(char v = char());
    
};

#endif /* variable_hpp */
