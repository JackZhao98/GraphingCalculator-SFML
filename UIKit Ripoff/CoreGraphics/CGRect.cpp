//
//  CGRect.cpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "CGRect.hpp"
#include <iostream>
CGRect::CGRect(CGPoint _origin, CGSize _size): origin(_origin), size(_size) {}

CGRect::CGRect(double x, double y, double width, double height) {
    origin = CGPoint(x, y);
    size = CGSize(width, height);
}

void CGRect::setOrigin(const CGPoint& point) {
    origin = point;
}
void CGRect::setSize(const CGSize& _size) {
    size = _size;
}

double CGRect::height() const{
    return size.height;
}
double CGRect::width() const{
    return size.width;
}
double CGRect::minX() const{
    return origin.x;
}
double CGRect::midX() const{
    return size.width * 0.5 + origin.x;
}
double CGRect::maxX() const{
    return size.width + origin.x;
}
double CGRect::minY() const{
    return origin.y;
}
double CGRect::midY() const{
    return size.height * 0.5 + origin.y;
}
double CGRect::maxY() const{
    return size.height + origin.y;
}

CGPoint CGRect::midPoint() const {
    return CGPoint(midX(), midY());
}

bool CGRect::contains(CGPoint aPoint) const{
    return (aPoint.x >= minX() && aPoint.x <= maxX()
            && aPoint.y >= minY() && aPoint.y <= maxY());
}

bool CGRect::contains(CGRect aRect) const{
    return (contains(aRect.origin) && contains(CGPoint(aRect.maxX(), aRect.maxY())));
}
