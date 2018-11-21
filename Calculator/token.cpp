//
//  token.cpp
//  Algorithm
//
//  Created by Jack Zhao on 11/14/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "token.hpp"

std::ostream& token::print(std::ostream& out)const {
    out << "This shouldn't appear!\n";
    return out;
}
std::ostream& operator << (std::ostream& out, const token* _t) {
//
    return _t -> print(out);
}
