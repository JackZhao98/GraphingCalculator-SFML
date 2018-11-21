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
#include "UIView.hpp"
#include "UILabel.hpp"
//#include "UIButton.hpp"

class UIViewController {
public:
    UIViewController();
    void init();
    void addSubView(UIView View);
    void addLabel(UILabel Label);
    void drawView(sf::RenderWindow window);
    
private:
    sf::RenderWindow _window;
    std::vector<UIView> _views;
    std::vector<UILabel> _Labels;
    std::vector<std::vector<sf::Vector2f>> _lines;
//    std::vector<UIButton> _Buttons;
    
//    UIButton _0;
//    UIButton _1;
//    UIButton _2;
//    UIButton _3;
//    UIButton _4;
//    UIButton _5;
//    UIButton _6;
//    UIButton _7;
//    UIButton _8;
//    UIButton _9;
//    UIButton _decimal;      // .
//    UIButton _clear;        // c
//    UIButton _equal;        // =
//    UIButton _plus;         // +
//    UIButton _minus;        // -
//    UIButton _multplication;// *
//    UIButton _division;     // ÷
//    UIButton _exponential;  // ^
//    UIButton _sqrt;         // √
//    UIButton _neg;          // +/-
//    UIButton _left_par;     // (
//    UIButton _right_par;    // )
    
};

#endif /* UIViewController_hpp */
