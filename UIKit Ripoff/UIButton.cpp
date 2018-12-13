//
//  UIButton.cpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "UIButton.hpp"

UIButton::UIButton() {
    type = NA;
    state = DEFAULT;
    // Format button shape.
    // 圆的位置是从左上角开始算
    radius = 0.015 * DEFAULT_W;
    width = 0.4 * radius;
    left.setPosition(0, 0);
    left.setRadius(radius);
    applyButtonPosition();
    
    // Set color
    Default = darkGreyDefault;
    left.setFillColor(Default);
    mid.setFillColor(Default);
    right.setFillColor(Default);
    
    // Format button title
    title.loadFontFromFile(regularFont);
    title.setCharacterSize(radius - 9);
    title.setTitle("");

    textAlignToCenter();
}

// Modifier.
void UIButton::setType(TYPE _type) {
    type = _type;
    autoSetColor();
}

void UIButton::setState(STATE _state) {
    state = _state;
    autoSetColor();
}

void UIButton::setLength(double _length) {
    width = _length - 2 * radius;
    applyButtonPosition();
}

void UIButton::setHeight(double height) {
    radius = 0.5 * height;
    applyButtonPosition();
}

void UIButton::setCornerRadius(double _radius) {
    radius = _radius;
    left.setRadius(radius);
    applyButtonPosition();
}

void UIButton::setPosition(const sf::Vector2f& _position) {
    left.setPosition(_position);
    applyButtonPosition();
    textAlignToCenter();
}

void UIButton::setTitleSize(unsigned int size) {
    title.setCharacterSize(size);
}

void UIButton::setTitleOffset(double offestY) {
    title.setPosition(title.getPosition() + sf::Vector2f(0, offestY));
}

void UIButton::setTitle(const std::string& _title) {
//    title.setString(_title);
    title.setTitle(_title);
}

void UIButton::setBackGroundColor(const sf::Color& color) {
    left.setFillColor(color);
    mid.setFillColor(color);
    right.setFillColor(color);
}

void UIButton::setTitleFillColor(const sf::Color& color) {
    title.setFillColor(color);
}

bool UIButton::contains(const sf::Vector2f& mouseCursor) {
    return (left.getGlobalBounds().contains(mouseCursor) || mid.getGlobalBounds().contains(mouseCursor) ||right.getGlobalBounds().contains(mouseCursor));
}

void UIButton::applyButtonPosition() {
    sf::Vector2f left_position = left.getPosition();
    left.setRadius(radius);
    mid.setPosition(left_position.x + radius, left_position.y);
    mid.setSize(sf::Vector2f(width, 2 * radius));
    right.setPosition(left_position.x + width, left_position.y);
    right.setRadius(radius);
}

void UIButton::textAlignToLeft() {
    double textHeight = title.getBoundary().height;
    sf::Vector2f startPoint = mid.getPosition();
    title.setPosition(startPoint + sf::Vector2f(0,startPoint.y + radius - textHeight));
    
}

void UIButton::textAlignToCenter() {
    double textLength = title.getBoundary().width;
    double textHeight = title.getBoundary().height;
    sf::Vector2f midPoint = mid.getPosition() + sf::Vector2f(0.5 * mid.getGlobalBounds().width, 0.5 * mid.getGlobalBounds().height);
    title.setPosition(midPoint - sf::Vector2f(0.5 * textLength, textHeight));
}

// Automatic change button color based on current state and type.
void UIButton::autoSetColor() {
    switch (state) {
        case DEFAULT:
            
            switch (type) {
                case NUMBER:
                    setBackGroundColor(darkGreyDefault);
                    break;
                case COMMAND:
                    setBackGroundColor(lightGreyDefault);
                    setTitleFillColor(sf::Color::Black);
                    break;
                case OPERATOR:
                    setBackGroundColor(orangeDefault);
                    break;
                case FUNCTION:
                    setBackGroundColor(charcoalDefault);
                    break;
                case TAB:
                    setBackGroundColor(TabDefault);
                    break;
                default:
                    break;
            }
            
            
            break;
        case HIGHLIGHTED:
            
            switch (type) {
                case NUMBER:
                    setBackGroundColor(darkGreyHighlighted);
                    break;
                case COMMAND:
                    setBackGroundColor(lightGreyHighlighted);
                    setTitleFillColor(sf::Color::Black);
                    break;
                case OPERATOR:
                    setBackGroundColor(orangeHighlighted);
                    break;
                case FUNCTION:
                    setBackGroundColor(charcoalHighlighted);
                    break;
                case TAB:
                    setBackGroundColor(TabHover);
                    break;
                default:
                    break;
            }
            
            break;
            
        case PRESSED:
            switch (type) {
                case NUMBER:
                    setBackGroundColor(darkGreyPressed);
                    break;
                case COMMAND:
                    setBackGroundColor(lightGreyPressed);
                    setTitleFillColor(sf::Color::Black);
                    break;
                case OPERATOR:
                    setBackGroundColor(orangePressed);
                    break;
                case FUNCTION:
                    setBackGroundColor(charcoalPressed);
                    break;
                case TAB:
                    setBackGroundColor(TabPressed);
                    break;
                default:
                    break;
            }
            break;
        case SELECTED:
            setBackGroundColor(TabSelected);
            break;
            
        default:
            break;
    }
}

double UIButton::getLength () const {
    return (right.getPosition().x + 2 * radius - left.getPosition().x);
}

double UIButton::getHeight() const {
    return 2 * radius;
}

void UIButton::placeButton(sf::RenderWindow& window) {
    window.draw(left);
    window.draw(right);
    window.draw(mid);
    title.drawLabel(window);
}

sf::Vector2f UIButton::origin() const {
    return left.getPosition();
}
