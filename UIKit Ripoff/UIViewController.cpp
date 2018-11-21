//
//  UIViewController.cpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "UIViewController.hpp"
#include "constants.hpp"
UIViewController::UIViewController() {
    init();
}

void UIViewController::init() {
    _window.create(sf::VideoMode(DEFAULT_W,DEFAULT_H), "GC 0.1");
    _window.setFramerateLimit(FRAME_RATE);
    _window.setVerticalSyncEnabled(true);
}

void UIViewController::drawView(sf::RenderWindow window) {
    for (int i = 0; i < _views.size(); ++ i) {
        window.draw(_views[i].getView());
    }
}

void UIViewController::addSubView(UIView View) {
    _views.push_back(View);
}

void UIViewController::addLabel(UILabel Label) {
    
}



