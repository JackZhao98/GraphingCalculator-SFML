//
//  oprand.cpp
//  Algorithm
//
//  Created by Jack Zhao on 11/14/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "oprand.hpp"
oprand::oprand(double d): _oprand(d), token('n') {}

std::ostream& oprand::print(std::ostream& out)const {
    out << _oprand;
    return out;
}

bool oprand::action() {
    
    return true;
}
