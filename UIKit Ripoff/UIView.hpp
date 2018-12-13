//
//  UIView.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef UIView_hpp
#define UIView_hpp

#include "CoreGraphics/CGRect.hpp"
#include "SFML/Graphics.hpp"

// An abstract UIView class.
// Creates boundaries and a Rectangle Shape to interact with the program.

class UIView {
private:
    sf::RectangleShape _View;
public:
    // CoreGraphics frame. Controls basic parameters of the UIView.
    CGRect frame;
    
    // CTORS
    UIView(CGRect frame = CGRect());
    // Accessor
    sf::RectangleShape getView() {return _View;}
    
    // Setup origin.
    void setPosition(const CGPoint& origin);
    // Setup size.
    void setSize(const CGSize& size);
    // Setup rectangleShape background color.
    void backgroundColor(const sf::Color& Color);
    // Setup rect border width.
    void borderWidth(const double& stroke);
    // Setup rect border color.
    void borderColor(const sf::Color& Color);
    // Get rect global bounds.
    sf::FloatRect getGlobalBounds();
    
};

#endif /* UIView_hpp */
