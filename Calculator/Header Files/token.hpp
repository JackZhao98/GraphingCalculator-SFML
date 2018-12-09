//
//  token.hpp
//  Algorithm
//
//  Created by Jack Zhao on 11/14/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef token_hpp
#define token_hpp
#include <iostream>

// Class name: token
// Parent class of oprand and optr

class token {
private:
    // Token type.
    char _type;

public:
    token(char c = 'e'): _type(c) {}
    
    // Accessor.
    char type() {return _type;}
    // Modifier.
    // setup token type.
    void set_type(char c) {_type = c;}
    
    // Virtual functions.
    virtual double get_val(){return 0;}
    /*
    *   This function points to oprand type funcitons and
    *   return the oprand value.
    */
    virtual double do_math(const double& LHS, const double& RHS){return 0;}
    /*
    *   This function points to optr type funcitons and
    *   do binary operations.
    */
    virtual double do_math(const double& Unary){return 0;}
    /*
    *   This function points to optr type funcitons and
    *   do unary operations.
    */
    
    // IOStream, for dubug purposes.
    virtual std::ostream& print(std::ostream& out)const;
    friend std::ostream& operator << (std::ostream& out, const token* _t);
};

#endif /* token_hpp */
