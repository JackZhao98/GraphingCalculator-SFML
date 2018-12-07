//
//  CGVector.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/20/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef CGVector_hpp
#define CGVector_hpp

struct CGVector {
    double dx;
    double dy;
    
    CGVector(double x = 0, double y = 0): dx(x), dy(y) {}
};

#endif /* CGVector_hpp */
