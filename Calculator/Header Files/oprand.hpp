//
//  oprand.hpp
//  Algorithm
//
//  Created by Jack Zhao on 11/14/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef oprand_hpp
#define oprand_hpp
#include "token.hpp"
// Class name: oprand
// Inherited from class token.
// This class take cares of operands in tokens.
// Stores double type numbers and allow users to access the elements.
class oprand: public token {
private:
    double _oprand;
    
public:
    oprand(double d = double());
    // Ostream.
    std::ostream& print(std::ostream& out)const;
    // Accessor.
    double get_val() {return _oprand;}
};

#endif /* oprand_hpp */
