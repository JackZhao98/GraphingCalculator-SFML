//
//  UILabel.cpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/20/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "UILabel.hpp"


UILabel::UILabel(): _isEnabled(true){
    font.loadFromFile(regularFont);
    title.setFont(font);
    title.setCharacterSize(50);
    title.setString("");
}
UILabel::UILabel(std::string _title): _isEnabled(true) {
    font.loadFromFile(regularFont);
    title.setFont(font);
    title.setCharacterSize(50);
    title.setString(_title);
}

void UILabel::setTitleOffset(double offestY) {
    title.setPosition(title.getPosition() + sf::Vector2f(0, offestY));
}

bool UILabel::isEnabled() const {
    return _isEnabled;
}

void UILabel::disable() {
    _isEnabled = false;
}
void UILabel::enable() {
    _isEnabled = true;
}

void UILabel::setTitle(const std::string& _title) {
    title.setString(_title);
}

void UILabel::setFillColor(const sf::Color& color) {
    title.setFillColor(color);
}

void UILabel::setCharacterSize(unsigned int TextSize) {
    title.setCharacterSize(TextSize);
}

void UILabel::setTitleFont(const sf::Font _font) {
    font = _font;
    title.setFont(font);
}

sf::Vector2f UILabel::getPosition()const {
    return title.getPosition();
}

sf::FloatRect UILabel::getBoundary()const {
    return title.getGlobalBounds();
}

void UILabel::loadFontFromFile(std::string fontPath) {
    font.loadFromFile(fontPath);
    title.setFont(font);
}


