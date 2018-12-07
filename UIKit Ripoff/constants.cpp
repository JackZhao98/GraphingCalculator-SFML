//
//  constants.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/19/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//
#include <string>
#include "SFML/Graphics.hpp"
const int FrameRate = 60;
const double H_W_RATIO = 0.5625; // 16:9
const int DEFAULT_W = 2600;
const int DEFAULT_H = DEFAULT_W * H_W_RATIO;
const float ZoomingRatio = 0.89089;
const int maxXSteps = 10;
const int maxYSteps = 6;


const std::string TITLE = "Graphing Calculator 0.2";
const std::string lightFont = "/Users/jackzhao/Documents/PCC Archived/Computer Science/CS 3A/Huge Final Project/Graphing Calculator CAS/Resources/SF-Light.otf";
const std::string regularFont = "/Users/jackzhao/Documents/PCC Archived/Computer Science/CS 3A/Huge Final Project/Graphing Calculator CAS/Resources/SF-Regular.otf";


const sf::Color darkGreyDefault = sf::Color{51,51,51};
const sf::Color darkGreyHighlighted = sf::Color{115,115,115};
const sf::Color darkGreyPressed = sf::Color{80,80,80};
const sf::Color lightGreyDefault = sf::Color{165,165,165};
const sf::Color lightGreyHighlighted = sf::Color{217,217,217};
const sf::Color lightGreyPressed = sf::Color{190,190,190};
const sf::Color orangeDefault = sf::Color{240,154,55};
const sf::Color orangeHighlighted = sf::Color{243,201,149};
const sf::Color orangePressed = sf::Color{240,180,120};
const sf::Color charcoalDefault = sf::Color{33,33,33};
const sf::Color charcoalHighlighted = sf::Color{77,77,77};
const sf::Color charcoalPressed = sf::Color{55,55,55};
const sf::Color TabDefault{50,50,50};
const sf::Color TabHover{70,70,70};
const sf::Color TabPressed{55,55,55};
const sf::Color TabSelected{110,110,110};

const sf::Color lineRed = sf::Color {185,77,70};
const sf::Color lineOrange = sf::Color {235,132,57};
const sf::Color lineBlue = sf::Color {62,112,174};
const sf::Color lineGreen = sf::Color {79,137,78};
const sf::Color linePurple = sf::Color {91,70,160};
const sf::Color lineWhite = sf::Color::White;
