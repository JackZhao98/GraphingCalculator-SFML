//
//  CGPoint.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef CGPoint_hpp
#define CGPoint_hpp

struct CGPoint {
    
    double x;
    double y;
    CGPoint(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }
    void init() {
        x = 0;
        y = 0;
    }
};

#endif /* CGPoint_hpp */
