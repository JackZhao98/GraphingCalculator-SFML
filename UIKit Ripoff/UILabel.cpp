//
//  UILabel.cpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/20/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "UILabel.hpp"
UILabel::UILabel(CGRect frame, std::string Title):UIView(frame), _isEnabled(true) {
    text.setString(Title);
    text.setPosition(sf::Vector2f(_frame.origin.x, _frame.origin.y));
}

void UILabel::draw() {
    // Draw.
    
}

bool UILabel::isEnabled() {
    return _isEnabled;
}

void UILabel::disable() {
    _isEnabled = false;
}
void UILabel::enable() {
    _isEnabled = true;
}
void UILabel::textColor(sf::Color TextColor) {
    text.setFillColor(TextColor);
}
void UILabel::textSize(int TextSize) {
    text.setCharacterSize(TextSize);
}
