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


// Class: GCTab
// Creates a button with configurable string inside. 
// It Stores an expression type object, keep equation updated based on current string.
// Automatic checks equation availability to setup text color.

class GCTab {

private:
    string tempEquation;
    sf::Color color;
    bool isAvailable;
    bool isEnabled;
    UIButton tab;
public:
    // Public member. Stores a equation.
    expression equation;
    
    // CTOR.
    GCTab() {
        enabled();
        tempEquation = "";
        tab.setType(TAB);
        tab.autoSetColor();
        equation.setEquation(tempEquation);
        updateExpression();
    }
    // Accessor
    bool Enabled() {
        /*
        *   Returns if the tab is enabled.
        */
        return static_cast<void>((tabAutoTextColor())),isEnabled;
    }
     sf::Color getColor() const {
         /*
        *   Returns the line color.
        */
        return color;
    }
    double getLength()const {
        /*
        *   Returns the tab button length.
        */
        return tab.getLength();
    }
    double getHeight() const {
        /*
        *   Returns the tab button height.
        */
        return tab.getHeight();
    }
    STATE getState() const {
        /*
        *   Returns the STATE of the button.
        */
        return tab.getState();
    }
    
    void enabled() {
        /*
        *   Enables the GCTab, and sets the text color.
        */
        tabAutoTextColor();
        isEnabled = true;
    }
    void disabled() {
        /*
        *   Disables the GCTab, and sets the text color.
        */
        tabAutoTextColor();
        isEnabled = false;
    }
    void append(const string& token) {
        /*
        *   Append token (string type) to the expression,
        *   and update the equation with new string.
        */
        if (tempEquation.size() > 0 ) {
            if (needSpace(token))
                tempEquation.append(" ");
        }
        tempEquation.append(token);
        updateExpression();
    }
    bool needSpace(const string& token) {
        /*
        *   Checks if the current need to be appended a space to keep syntax correct.
        */
        return !((isdigit(tempEquation[tempEquation.size() - 1]) && (isdigit(token[0])||token[0] == '.')) || (isdigit(token[0]) && tempEquation[tempEquation.size() - 1] == '.'));
    }
    void clear() {
         /*
         *   Clear tab.
         *   Deletes the expression in the tab and update appearance.
         */
        tempEquation = "";
        updateExpression();
    }

    void removeToken() {
         /*
         *   Remove a token.
         *   Allow user to delete a complete token with one click.
         */
        if (tempEquation.size() > 0)
            tempEquation.pop_back();
        // Only pop back when the size is greater than zero.
        while(tempEquation.size() > 0) {
            if (getLastChar() == ' ') {
                tempEquation.pop_back();
                break;
            }
            tempEquation.pop_back();
        }
        updateExpression();
    }
    
  
    void drawTab(sf::RenderWindow& _window) {
        /*
         *   Draw sfml objects inside the window.
         */
        tab.placeButton(_window);
    }
    bool contains(sf::Vector2f MousePos) {
        /*
         *   Checks if the tab contains a point.
         */
        return tab.contains(MousePos);
    }
    
    // Set State
    void setState(STATE state) {
        tab.setState(state);
    }
    // Set Tab position
    void setPosition(sf::Vector2f _pos) {
        tab.setPosition(_pos);
    }
    // Set Individual Tab Height
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
