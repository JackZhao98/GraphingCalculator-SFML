//
//  UILabel.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/20/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef UILabel_hpp
#define UILabel_hpp
#include "CoreGraphics/CGRect.hpp"
#include "SFML/Graphics.hpp"
#include "UIView.hpp"
class UILabel: public UIView {
private:
    sf::Text text;
    bool _isEnabled;
    
public:
    UILabel(CGRect frame, std::string Title);
    
    void draw();
    bool isEnabled();
    void disable();
    void enable();
    void textColor(sf::Color TextColor);
    void textSize(int TextSize);
    
    
};

#endif /* UILabel_hpp */
