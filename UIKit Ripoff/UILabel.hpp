//
//  UILabel.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/20/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef UILabel_hpp
#define UILabel_hpp

#include "constants.cpp"
#include "SFML/Graphics.hpp"

class UILabel {
private:
    sf::Font font;
    sf::Text title;
    bool _isEnabled;
    
public:
    
    // UILabel CTORS.
    UILabel();
    UILabel(std::string title);

    void drawLabel(sf::RenderWindow& mainWindow) {
        if (_isEnabled)
            mainWindow.draw(title);
    }
    
    // isEnabled modifier
    bool isEnabled() const;
    void disable();
    void enable();
    
    // sf::Text Modifier
    void setTitleOffset(double offestY);
    void setTitle(const std::string& title);
    void setFillColor(const sf::Color& color);
    void setTitleFont(const sf::Font _font);
    sf::Vector2f getPosition()const;
    sf::FloatRect getBoundary()const;
    void setCharacterSize(unsigned int TextSize);
    void setPosition(const sf::Vector2f origin) {
        title.setPosition(origin);
    }
    void loadFontFromFile(std::string fontPath);
    std::string getString()const {return title.getString();}
    const sf::Text& getText()const {return title;}
    
};

#endif /* UILabel_hpp */
