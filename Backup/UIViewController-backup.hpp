//
//  UIViewController.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef UIViewController_hpp
#define UIViewController_hpp
#include <vector>
#include "SFML/Graphics.hpp"
#include "constants.cpp"
#include "UIView.hpp"


class UIViewController {
public:
    UIViewController();
    void init();
 
    bool active() {return _window.isOpen();}
    bool pollEvenet(sf::Event &event) {return _window.pollEvent(event);}
    void clearBuffer() {_window.clear();}
    void terminate() {_window.close();}
    void display() {_window.display();}
    const sf::Vector2u getSizeOfWindow() {return _window.getSize();}
    
    void draw(const sf::Drawable& drawable) {_window.draw(drawable);}
    sf::RenderWindow _window;
};




#endif /* UIViewController_hpp */
