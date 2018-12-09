//
//  UIButton.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef UIButton_hpp
#define UIButton_hpp
#include <iostream>
#include "UILabel.hpp"
#include "SFML/Graphics.hpp"

enum STATE {
    DEFAULT,
    HIGHLIGHTED,
    PRESSED,
    SELECTED
};

enum TYPE {
    NA,
    NUMBER,
    COMMAND,
    FUNCTION,
    OPERATOR,
    TAB
};

class UIButton {
private:
    // Button Shape + Color
    sf::CircleShape left;
    sf::CircleShape right;
    sf::RectangleShape mid;
    sf::Color Default;
    sf::Color Highlighted;
    sf::Color Selected;
    double radius;
    double width;
    
    UILabel title;
    STATE state;
    TYPE type;
    
public:
    UIButton();
    
    void setType(TYPE _type);
    void setState(STATE _state);
    void setLength(double _length);
    void setHeight(double _width);
    void setRadius(double _radius);
    void setPosition(const sf::Vector2f& _position);
    void setTitle(const std::string& _title);
    void setTitleSize(unsigned int size);
    void setTitleOffset(double offestY);
    void setBackGroundColor(const sf::Color& color);
    void setTitleFillColor(const sf::Color& color);
    bool contains(const sf::Vector2f& mouseCursor);
    void setTextPositionToLeft();
    void textAlignToCenter();
    void applyButtonPosition();
    void autoSetColor();
    
    double getLength () const;
    double getHeight() const;
    STATE getState() const {
        return state;
    }
    std::string getTitle() const {
        return title.getString();
    }
    void placeButton(sf::RenderWindow& window) {
        window.draw(left);
        window.draw(right);
        window.draw(mid);
        title.drawLabel(window);
    }
    double getRadius()const {return radius;}
    sf::Vector2f origin() const {
        return left.getPosition();
    }
    
};
#endif /* UIButton_hpp */
