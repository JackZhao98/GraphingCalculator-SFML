//
//  UIView.cpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//
#include <iostream>
#include "UIView.hpp"
UIView::UIView(CGRect frame): frame(frame) {
    _View.setFillColor(sf::Color::Green);
    _View.setOutlineColor(sf::Color::Transparent);
    _View.setPosition(frame.origin.x, frame.origin.y);
    _View.setSize(sf::Vector2f(frame.width(), frame.height()));
}

void UIView::setPosition(const CGPoint& origin) {
    frame.setOrigin(origin);
    _View.setPosition(frame.origin.x, frame.origin.y);
}

void UIView::setSize(const CGSize& size) {
    frame.setSize(size);
    _View.setSize(sf::Vector2f(frame.width(), frame.height()));
}

void UIView::backgroundColor(const sf::Color& Color) {
    _View.setFillColor(Color);
}

void UIView::borderWidth(const double& stroke) {
    _View.setOutlineThickness(stroke);
}

void UIView::borderColor(const sf::Color& Color) {
    _View.setOutlineColor(Color);
}

sf::FloatRect UIView::getGlobalBounds() {return _View.getGlobalBounds();}

