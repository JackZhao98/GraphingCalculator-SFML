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

// Button states.
enum STATE {
    DEFAULT,
    HIGHLIGHTED,
    PRESSED,
    SELECTED
};

// Button Type
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
    sf::CircleShape left;       // Circle shape on the left
    sf::CircleShape right;      // Circle shape on the right
    sf::RectangleShape mid;     // Rectangle shape in the middle
    sf::Color Default;
    sf::Color Highlighted;
    sf::Color Selected;
    double radius;
    double width;
    
    UILabel title;
    STATE state;
    TYPE type;
    
public:
    //CTORS
    UIButton();
    
    // Modifier.
    void setType(TYPE _type);                //  Setup button type.
    void setState(STATE _state);             //  Setup button state.
    void setLength(double _length);          //  Setup button length.
    void setHeight(double _width);           //  Setup button height.
    void setCornerRadius(double _radius);    //  Setup button corner radius.
    void setPosition(const sf::Vector2f& _position); // Setup button position.
    void setTitle(const std::string& _title);        // Setup button title.
    void setTitleSize(unsigned int size);            // Setup button title character size.
    void setTitleOffset(double offestY);             // Setup title offset vertically
    void setBackGroundColor(const sf::Color& color); // Setup Button background
    void setTitleFillColor(const sf::Color& color);  // Setup title text color.
    bool contains(const sf::Vector2f& mouseCursor);  // Boolean if the button shape contains a point.
    void textAlignToLeft();             // Set text position alignment to left.
    void textAlignToCenter();           // Set text alignment to middle
    void applyButtonPosition();         // Apply button position settings.
    void autoSetColor();                // Automatic setup color based on types and states.
    
    // Accessors
    double getLength () const;
    double getHeight() const;
    STATE getState() const {
        return state;
    }
    std::string getTitle() const {
        return title.getString();
    }
    void placeButton(sf::RenderWindow& window);
    double getRadius()const {return radius;}
    sf::Vector2f origin() const;
    
};
#endif /* UIButton_hpp */
