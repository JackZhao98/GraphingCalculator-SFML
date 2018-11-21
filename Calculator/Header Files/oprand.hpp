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

class oprand: public token {
private:
    double _oprand;
    
public:
    oprand(double d = double());
    std::ostream& print(std::ostream& out)const;
    double get_val() {return _oprand;}
    bool action();
};

#endif /* oprand_hpp */
