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
        
    sf::RectangleShape rect;    // SFML object, draw this.
    int stroke;                 // The desired width of rectangle line.
    CGPoint start;              // Starting position.
    CGPoint end;                // Ending position.
    
    
public:
    
    // CTORS
    VertexRect(): stroke(3) {}
    
    // Constructor with vertexes
    VertexRect(const CGPoint& _start, const CGPoint& _end): stroke(3), start(_start), end(_end) {
        
    }
    
    // Initialize the sfml rectangle with preset params.    
    // Run the init process and returns the sf::RectangleShape
    void initVertexRect() {
        rect.setOrigin(0, 0.5 * stroke);
        rect.setPosition(sf::Vector2f(start.x, start.y));
        // Possible misuse.
        rect.setOutlineThickness(1.0f);
        rect.setSize(sf::Vector2f(getLength(),stroke));
        rect.setRotation(getAngle());
    }
    

    // Accessor
    const sf::RectangleShape getRect() {
        initVertexRect();
        return rect;
    }

 
    // Modifier
    
    /*
    *   Calculate rotation angle using tangent
    *   We have the Y-difference from two points, and the x-difference is one pixel.
    */
    double getAngle() {
        double tan = atan(end.y - start.y);
        return tan*180/3.141592653589;
    }
    // Calculate the length of rect
    double getLength() {
        double dx2 = pow((end.x - start.x),2);
        double dy2 = pow((end.y - start.y),2);
        return (pow(dx2 + dy2, 0.5));
    }
    // Setup init position of rect
    void setPosition(sf::Vector2f position) {
        rect.setPosition(position);
    }
    void setColor(const sf::Color& color) {
        rect.setOutlineColor(color);
        rect.setFillColor(color);
    }
    
    // Param modifications 
    // Setup stroke of the rect
    void setStroke(int _stroke) {
        stroke = _stroke;
    }
    // Setup starting position
    void setStart(CGPoint _start) {
        start = _start;
    }
    // Setup ending position
    void setEnd(CGPoint _end) {
        end = _end;
    }

};

#endif /* VertexRect_hpp */
