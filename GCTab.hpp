//
//  UITab.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/26/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef UITab_hpp
#define UITab_hpp
#include "UIKit Ripoff/UIButton.hpp"
#include "Calculator/Header Files/expression.hpp"




class GCTab {

private:
    string tempEquation;
    sf::Color color;
    bool isAvailable;
    bool isEnabled;
    UIButton tab;
public:
    expression equation;
    
    GCTab() {
        enabled();
        tempEquation = "";
        tab.setType(TAB);
        tab.autoSetColor();
        equation.setEquation(tempEquation);
        updateExpression();
    }
    bool Enabled() {
        return static_cast<void>((tabAutoTextColor())),isEnabled;}
    void enabled() {
        tabAutoTextColor();
        isEnabled = true;}
    void disabled() {
        tabAutoTextColor();
        isEnabled = false;
    }
    // 加token
    void append(const string& token) {
        if (tempEquation.size() > 0 ) {
            if (needSpace(token))
                tempEquation.append(" ");
        }
        tempEquation.append(token);
        updateExpression();
    }
    bool needSpace(const string& token) {
        return !((isdigit(tempEquation[tempEquation.size() - 1]) && (isdigit(token[0])||token[0] == '.')) || (isdigit(token[0]) && tempEquation[tempEquation.size() - 1] == '.'));
    }
    
    // 清空
    void clear() {
        tempEquation = "";
        updateExpression();
    }
    // 删掉最后一项
    void removeToken() {
        if (tempEquation.size() > 0)
            tempEquation.pop_back();
        while(tempEquation.size() > 0) {
            if (getLastChar() == ' ') {
                tempEquation.pop_back();
                break;
            }
            tempEquation.pop_back();
        }
        updateExpression();
    }
    
    sf::Color getColor() const {
        return color;
    }
    double getLength()const {
        return tab.getLength();
    }
    double getHeight() const {
        return tab.getHeight();
    }
    STATE getState() const {
        return tab.getState();
    }
    
    void drawTab(sf::RenderWindow& _window) {
        tab.placeButton(_window);
    }
    bool contains(sf::Vector2f MousePos) {
        return tab.contains(MousePos);
    }
    
    // 设置状态
    void setState(STATE state) {
        tab.setState(state);
    }
    // 设置位置
    void setPosition(sf::Vector2f _pos) {
        tab.setPosition(_pos);
    }
    void setHeight(double height) {
        tab.setHeight(height);
    }
    void setLength(double length) {
        tab.setLength(length);
    }
    // Call this in GC/
    void setEquation(const string& input) {
        tempEquation = input;
        updateExpression();
    }
    void updateExpression() {
        tab.setTitle(tempEquation);
        equation.setEquation(tempEquation);
        checkAvailability();
        tabAutoTextColor();
    }
    
    void setColor(const sf::Color& _color) {
        color = _color;
    }
    void setTitleColor(const sf::Color& textColor) {
        tab.setTitleFillColor(textColor);
    }
    void checkAvailability() {
        isAvailable = !equation.isError();
    }
    string getString() {
        return tempEquation;
    }
    char getLastChar() {
        return tempEquation[tempEquation.size()-1];
    }
    bool Available() {return (isAvailable && isEnabled);}
   
    
    void tabAutoTextColor() {
        if (!isEnabled) {
            tab.setTitleFillColor(lightGreyPressed);
        } else if (isAvailable) {
            tab.setTitleFillColor(sf::Color::White);
        }  else {
            tab.setTitleFillColor(sf::Color::Red);
        }
    }
    
    void processTabMouseEvent(const sf::Vector2i& mouseCursor) {
        if (tab.getState() != SELECTED)
            setState(tab.contains(sf::Vector2f(mouseCursor))? HIGHLIGHTED:DEFAULT);
    }
};

#endif /* UITab_hpp */
