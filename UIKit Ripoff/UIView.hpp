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

class UIView {
private:
    sf::RectangleShape _View;
    
public:
    CGRect _frame;
    
    UIView(CGRect frame = CGRect());
    
    sf::RectangleShape getView() {return _View;}
    
    void setOrigin(const CGPoint& origin);
    void setSize(const CGSize& size);
    void backgroundColor(const sf::Color& Color);
    void borderWidth(const double& stroke);
    void borderColor(const sf::Color& Color);
    
};

#endif /* UIView_hpp */
