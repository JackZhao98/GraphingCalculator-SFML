//
//  VertexRect.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/26/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef VertexRect_hpp
#define VertexRect_hpp
#include "UIKit Ripoff/CoreGraphics/CGPoint.hpp"
class VertexRect {
private:
    sf::RectangleShape rect;
    int stroke;
    CGPoint start;
    CGPoint end;
    
    
public:
    VertexRect(): stroke(3) {}
    
    VertexRect(const CGPoint& _start, const CGPoint& _end): stroke(3), start(_start), end(_end) {
        
    }
    
    void initVertexRect() {
        rect.setOrigin(0, 0.5 * stroke);
        rect.setPosition(sf::Vector2f(start.x, start.y));
        // Possible misuse.
        rect.setOutlineThickness(1.0f);
        rect.setSize(sf::Vector2f(getLength(),stroke));
        rect.setRotation(getAngle());
    }
    
    const sf::RectangleShape getRect() {
        initVertexRect();
        return rect;
    }
    
    double getAngle() {
        double tan = atan(end.y - start.y);
        return tan*180/3.141592653589;
    }
    
    double getLength() {
        double dx2 = pow((end.x - start.x),2);
        double dy2 = pow((end.y - start.y),2);
        return (pow(dx2 + dy2, 0.5));
    }
    
    void setPosition(sf::Vector2f position) {
        rect.setPosition(position);
    }
    void setStroke(int _stroke) {
        stroke = _stroke;
    }
    void setStart(CGPoint _start) {
        start = _start;
    }
    void setEnd(CGPoint _end) {
        end = _end;
    }
    void setColor(const sf::Color& color) {
        rect.setOutlineColor(color);
        rect.setFillColor(color);
    }
    
};

#endif /* VertexRect_hpp */
