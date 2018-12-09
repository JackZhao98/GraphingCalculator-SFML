//
//  graph.cpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/29/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#include "graph.hpp"
Graph::Graph(): showGrid(true) {
    initRenderWindow(); // Initialize render window.
    initTabsColor();
}

// Initializer
void Graph::initRenderWindow() {
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(VideoMode(DEFAULT_W, DEFAULT_H), "Graph.io",sf::Style::Close | sf::Style::Resize, settings);
    window.setFramerateLimit(FrameRate);
    window.setVerticalSyncEnabled(true);
    
    graphSafeArea.setPosition(CGPoint(0,0));
    graphSafeArea.setSize(CGSize(DEFAULT_W, 0.65 * DEFAULT_H - 25 - graphSafeArea.frame.origin.y));
    graphSafeArea.backgroundColor(sf::Color{20,20,20});
    
    controlPanelArea.setPosition(CGPoint(graphSafeArea.frame.minX(), graphSafeArea.frame.maxY()));
    controlPanelArea.setSize(CGSize(DEFAULT_W,DEFAULT_H-graphSafeArea.frame.height()));
    controlPanelArea.backgroundColor(sf::Color{10,10,10});
    resetPos();
}
void Graph::initButtons() {
    double radius = _1.getRadius();
    double keyPadHeight = 5 * _1.getHeight() + 1.6 *radius;
    double keyPadLength = 6 * _1.getLength() + 1.5 * radius;
    // Set Button Origin Here...
    const sf::Vector2f origin(graphSafeArea.frame.midX() - 0.5 * keyPadLength, graphSafeArea.frame.maxY() + (DEFAULT_H - graphSafeArea.frame.height() - keyPadHeight) * 0.5);
    
    // Button Settings...
    
    leftPara.setPosition(origin);
    rightPara.setPosition(leftPara.origin() + sf::Vector2f(0.3 * radius + leftPara.getLength(),0));
    AC.setPosition(rightPara.origin() + sf::Vector2f(0.3 * radius + rightPara.getLength(),0));
    //    AC.setLength(2 * _1.getLength()+ 0.3 * radius);
    Abs.setPosition(AC.origin() + sf::Vector2f(0.3 * radius + AC.getLength(),0));
    neg.setPosition(Abs.origin() + sf::Vector2f(0.3 * radius + Abs.getLength(),0));
    divide.setPosition(neg.origin() + sf::Vector2f(0.3 * radius + neg.getLength(),0));
    
    
    pwr2.setPosition(leftPara.origin() + sf::Vector2f(0,leftPara.getHeight() + 0.4 * radius));
    sqrt.setPosition(pwr2.origin() + sf::Vector2f(0.3 * radius + pwr2.getLength(),0));
    _7.setPosition(sqrt.origin() + sf::Vector2f(0.3 * radius + sqrt.getLength(), 0));
    _8.setPosition(_7.origin() + sf::Vector2f(0.3 * radius + _7.getLength(),0));
    _9.setPosition(_8.origin() + sf::Vector2f(0.3 * radius + _8.getLength(),0));
    
    expo.setPosition(pwr2.origin() + sf::Vector2f(0,pwr2.getHeight() + 0.4 * radius));
    sin.setPosition(expo.origin() + sf::Vector2f(0.3 * radius + expo.getLength(),0));
    _4.setPosition(sin.origin() + sf::Vector2f(0.3 * radius + sin.getLength(),0));
    _5.setPosition(_4.origin() + sf::Vector2f(0.3 * radius + _4.getLength(),0));
    _6.setPosition(_5.origin() + sf::Vector2f(0.3 * radius + _5.getLength(),0));
    
    cos.setPosition(expo.origin() + sf::Vector2f(0,expo.getHeight() + 0.4 * radius));
    tan.setPosition(cos.origin() + sf::Vector2f(0.3 * radius + cos.getLength(),0));
    _1.setPosition(tan.origin() + sf::Vector2f(0.3 * radius + tan.getLength(),0));
    _2.setPosition(_1.origin() + sf::Vector2f(0.3 * radius + _1.getLength(),0));
    _3.setPosition(_2.origin() + sf::Vector2f(0.3 * radius + _2.getLength(),0));
    
    
    pi.setPosition(cos.origin() + sf::Vector2f(0,cos.getHeight() + 0.4 * radius));
    var.setPosition(pi.origin() + sf::Vector2f(0.3 * radius + pi.getLength(),0));
    _0.setPosition(var.origin() + sf::Vector2f(0.3 * radius + var.getLength(),0));
    _0.setLength(2 * var.getLength()+ 0.3 * radius);
    decimal.setPosition(_0.origin() + sf::Vector2f(0.3 * radius + _0.getLength(),0));
    
    
    multiply.setPosition(_9.origin() + sf::Vector2f(0.3 * radius + _9.getLength(),0));
    minus.setPosition(multiply.origin() + sf::Vector2f(0,multiply.getHeight() + 0.4 * radius));
    plus.setPosition(minus.origin() + sf::Vector2f(0,minus.getHeight() + 0.4 * radius));
    equal.setPosition(plus.origin() + sf::Vector2f(0,plus.getHeight() + 0.4 * radius));
    
    
    _1.setTitle("1");
    _2.setTitle("2");
    _3.setTitle("3");
    _4.setTitle("4");
    _5.setTitle("5");
    _6.setTitle("6");
    _7.setTitle("7");
    _8.setTitle("8");
    _9.setTitle("9");
    _0.setTitle("0");
    decimal.setTitle(".");
    multiply.setTitle("x");
    minus.setTitle("-");
    plus.setTitle("+");
    equal.setTitle("=");
    AC.setTitle((activeTab == nullptr)? "AC":"C");
    Abs.setTitle("abs");
    neg.setTitle("neg");
    divide.setTitle("/");
    leftPara.setTitle("(");
    rightPara.setTitle(")");
    sqrt.setTitle("sqrt");
    pwr2.setTitle("x^2");
    expo.setTitle("x^y");
    sin.setTitle("sin");
    cos.setTitle("cos");
    tan.setTitle("tan");
    pi.setTitle("Pi");
    var.setTitle("x");
    
    _1.setType(NUMBER);
    _2.setType(NUMBER);
    _3.setType(NUMBER);
    _4.setType(NUMBER);
    _5.setType(NUMBER);
    _6.setType(NUMBER);
    _7.setType(NUMBER);
    _8.setType(NUMBER);
    _9.setType(NUMBER);
    _0.setType(NUMBER);
    decimal.setType(NUMBER);
    AC.setType(COMMAND);
    neg.setType(COMMAND);
    Abs.setType(COMMAND);
    plus.setType(OPERATOR);
    minus.setType(OPERATOR);
    multiply.setType(OPERATOR);
    divide.setType(OPERATOR);
    equal.setType(OPERATOR);
    leftPara.setType(FUNCTION);
    rightPara.setType(FUNCTION);
    pwr2.setType(FUNCTION);
    sqrt.setType(FUNCTION);
    expo.setType(FUNCTION);
    sin.setType(FUNCTION);
    cos.setType(FUNCTION);
    tan.setType(FUNCTION);
    pi.setType(NUMBER);
    var.setType(NUMBER);
    
    mouseHoveringAndPressingEvent();
    drawButtons();
}
void Graph::initTabs() {
    double offset = 0.032 * DEFAULT_W;
    double vGap = (pi.origin().y + pi.getHeight() - leftPara.origin().y - 3 * tabs[0].getHeight()) / 4;
    double buttonLength = 1.5 * AC.getRadius() + AC.getLength() * 6;
    sf::Vector2f origin = leftPara.origin();
    double length = origin.x - 3  * offset;
    for (int i = 0; i < 3; ++ i) {
        tabs[i].setPosition(origin - sf::Vector2f(1.5 *offset + length,-vGap - i * (vGap + tabs[i].getHeight())));
        tabs[i].setLength(length);
        tabs[i].drawTab(window);
    }
    for (int i = 3; i < 6; ++ i) {
        tabs[i].setPosition(origin - sf::Vector2f(-1.5 *offset - buttonLength,-vGap - (i-3)* (vGap + tabs[i-3].getHeight())));
        tabs[i].setLength(length);
        tabs[i].drawTab(window);
    }
}
void Graph::initTabsColor() {
    tabs[0].setColor(lineRed);
    tabs[1].setColor(lineBlue);
    tabs[2].setColor(lineOrange);
    tabs[3].setColor(lineGreen);
    tabs[4].setColor(linePurple);
    tabs[5].setColor(lineWhite);
}


// Render
void Graph::build() {
    while (window.isOpen()) {
        processEvents();
        render();
    }
}
void Graph::render() {
    window.clear();
    window.draw(graphSafeArea.getView());
    createAndDrawAxis();
    drawLines();
    window.draw(controlPanelArea.getView());
    initTabs();
    initButtons();
    window.display();
}
void Graph::processEvents() {
    Event event;
    mousePos = Mouse::getPosition(window);
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    draggingEvent(Mouse::getPosition(window) - mousePos);
                    refreshPlots();
                    render();
                }
                break;
            case sf::Event::MouseWheelScrolled:
                if (graphSafeArea.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    if (event.mouseWheelScroll.delta > 0) {
                        zoomOut(mousePos);
                    }
                    else if (event.mouseWheelScroll.delta < 0) {
                        zoomIn(mousePos);
                    }
                    refreshPlots();
                }
                render();
                break;
            case sf::Event::MouseButtonReleased:
                buttonInput();
                for (int i = 0; i < 6; ++ i) {
                    if (tabs[i].contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
                        if (activeTab != nullptr)
                            activeTab -> setState(DEFAULT);
                        activeTab = (activeTab == &tabs[i])? nullptr:&tabs[i];
                    }
                }
                if (activeTab != nullptr) {
                    activeTab -> setState(SELECTED);
                }
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::BackSpace:
                        if (activeTab != nullptr)
                            activeTab -> removeToken();
                        break;
                    case sf::Keyboard::C:
                        if (activeTab != nullptr)
                            activeTab -> clear();
                        else
                            for (int i = 0; i < 6; ++ i) {
                                tabs[i].clear();
                            }
                        break;
                    case sf::Keyboard::M:
                        resetPos();
                        break;
                    case sf::Keyboard::H:
                        if (activeTab != nullptr) {
                            if (activeTab -> Enabled())
                                activeTab -> disabled();
                            else
                                activeTab -> enabled();
                        }
                        break;
                    case sf::Keyboard::Enter:
                        if (activeTab != nullptr)
                            activeTab -> setState(DEFAULT);
                        activeTab = nullptr;
                        break;
                    case sf::Keyboard::I:
                        cout << "Graphing Height cal: " << 0.65 * DEFAULT_H - 25 - graphSafeArea.frame.origin.y << endl;
                        cout << "get height: " << graphSafeArea.frame.height() << endl;
                        cout << "get panel height: " << controlPanelArea.frame.height() << endl;
                        cout << "get total: " << DEFAULT_H << endl;
                        cout << "origin: (" << origin.x << "," << origin.y << ")" << endl;
                        cout << "mousePos: (" << mousePos.x << "," << mousePos.y << ")" << endl;
                        break;
                    case sf::Keyboard::G:
                        showGrid = !showGrid;
                        break;
                    default:
                        break;
                }
                refreshPlots();
                break;
            default:
                break;
        }
    }
}
// For Every button, check mouse cursor contained events and change button state.
void Graph::mouseHoveringAndPressingEvent() {
    _1.setState(_1.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _2.setState(_2.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _3.setState(_3.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _4.setState(_4.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _5.setState(_5.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _6.setState(_6.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _7.setState(_7.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _8.setState(_8.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _9.setState(_9.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    _0.setState(_0.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    decimal.setState(decimal.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    plus.setState(plus.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    minus.setState(minus.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    multiply.setState(multiply.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    divide.setState(divide.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    equal.setState(equal.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    Abs.setState(Abs.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    neg.setState(neg.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    AC.setState(AC.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    
    leftPara.setState(leftPara.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    rightPara.setState(rightPara.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    pwr2.setState(pwr2.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    sqrt.setState(sqrt.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    expo.setState(expo.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    sin.setState(sin.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    cos.setState(cos.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    tan.setState(tan.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    pi.setState(pi.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    var.setState(var.contains(Vector2f(mousePos))? ((Mouse::isButtonPressed(Mouse::Left))? PRESSED:HIGHLIGHTED):DEFAULT);
    
    for (int i = 0; i < 6; ++ i) {
        if (tabs[i].getState() != SELECTED)
            tabs[i].setState(tabs[i].contains(Vector2f(mousePos))? HIGHLIGHTED:DEFAULT);
    }
}
// Input/button settings
void Graph::buttonInput() {
    
    if (_1.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("1");
    }
    if (_2.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("2");
    }
    if (_3.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("3");
    }
    if (_4.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("4");
    }
    if (_5.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("5");
    }
    if (_6.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("6");
    }
    if (_7.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("7");
    }
    if (_8.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("8");
    }
    if (_9.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("9");
    }
    if (_0.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("0");
    }
    if (plus.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("+");
    }
    if (minus.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("-");
    }
    if (multiply.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("*");
    }
    if (divide.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("/");
    }
    if (decimal.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append(".");
    }
    
    
    if (AC.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> clear();
        else
            for (int i = 0; i < 6; ++ i) {
                tabs[i].clear();
            }
    }
    if (Abs.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("abs (");
    }
    if (neg.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("neg (");
    }
    if (leftPara.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("(");
    }
    if (rightPara.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append(")");
    }
    if (pwr2.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("^ 2");
    }
    if (sqrt.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("sqrt (");
    }
    if (expo.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("^");
    }
    if (sin.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr) {
            if (trigNeedToMultiply(activeTab -> getLastChar()) && activeTab -> getString().size()>0) {
                activeTab -> append("*");
            }
            activeTab -> append("sin (");
        }
    }
    if (cos.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr) {
            if (trigNeedToMultiply(activeTab -> getLastChar()) && activeTab -> getString().size()>0) {
                activeTab -> append("*");
            }
            activeTab -> append("cos (");
        }
    }
    if (tan.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr) {
            if (trigNeedToMultiply(activeTab -> getLastChar()) && activeTab -> getString().size()>0) {
                activeTab -> append("*");
            }
            activeTab -> append("tan (");
        }
    }
    if (pi.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr)
            activeTab -> append("3.1415926");
    }
    if (var.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
        if (activeTab != nullptr) {
            if (activeTab -> getLastChar() == ')' || isdigit(activeTab->getLastChar())) {
                activeTab->append("*");
            }
            activeTab -> append("x");
        }
        
    }
    refreshPlots();
}


// Plotting
void Graph::drawLines() {
    for (int i = 0; i < 6; ++ i) {
        for (int j = 1; j < coordinates[i].size(); ++ j) {
            if (abs(coordinates[i][j].y - coordinates[i][j-1].y) < graphSafeArea.frame.height() ) {
                if (coordinates[i][j].y < graphSafeArea.frame.height() && coordinates[i][j].y > 0) {
                    VertexRect line;
                    line.setColor(tabs[i].getColor());
                    line.setStart(CGPoint(coordinates[i][j-1].x,coordinates[i][j-1].y));
                    line.setEnd(CGPoint(coordinates[i][j].x,coordinates[i][j].y));
                    window.draw(line.getRect());
                    /*
                     VertexArray line(LineStrip, 2);
                     line[0].position = coordinates[i][j-1];
                     line[1].position = coordinates[i][j];
                     line[0].color = tabs[i].getColor();
                     line[1].color = tabs[i].getColor();
                     window.draw(line);
                     */
                }
                
            }
        }
    }
}
void Graph::refreshPlots() {
    for (int i = 0; i < 6; ++ i) {
        if (!tabs[i].Available() || !tabs[i].Enabled()) {
            // Possible bug in empty vector check.
            coordinates[i].clear();
            continue;
        }
        vector<Vector2f> singleLineSet;
        for (double j = xMin; j < xMax; j += xValuePerPixel) {
            singleLineSet.push_back(Vector2f((j - xMin)/xValuePerPixel, (yMax - tabs[i].equation.eval(j))/yValuePerPixel));
        }
        coordinates[i] = singleLineSet;
    }
}
void Graph::updateGraphingParameters() {
    xValuePerPixel = (xMax - xMin)/(graphSafeArea.frame.width());
    yValuePerPixel = (yMax - yMin)/(graphSafeArea.frame.height());
    origin.x = -xMin / xValuePerPixel;
    origin.y = yMax / yValuePerPixel;
    // Update step here...
}
void Graph::resetPos() {
    xMin = -10;
    xMax = 10;
    xValuePerPixel = (xMax - xMin)/graphSafeArea.frame.width();
    yValuePerPixel = xValuePerPixel;
    yMin = -graphSafeArea.frame.midY()*yValuePerPixel;
    yMax = -yMin;
    
    
    stepCoefficient = 2;
    xStep = 2;
    yStep = xStep;
    updateGraphingParameters();
}


// User Interface Section
void Graph::drawButtons() {
    _1.placeButton(window);
    _2.placeButton(window);
    _3.placeButton(window);
    _4.placeButton(window);
    _5.placeButton(window);
    _6.placeButton(window);
    _7.placeButton(window);
    _8.placeButton(window);
    _9.placeButton(window);
    _0.placeButton(window);
    decimal.placeButton(window);
    multiply.placeButton(window);
    minus.placeButton(window);
    plus.placeButton(window);
    equal.placeButton(window);
    Abs.placeButton(window);
    AC.placeButton(window);
    neg.placeButton(window);
    divide.placeButton(window);
    leftPara.placeButton(window);
    rightPara.placeButton(window);
    sqrt.placeButton(window);
    pwr2.placeButton(window);
    expo.placeButton(window);
    sin.placeButton(window);
    cos.placeButton(window);
    tan.placeButton(window);
    pi.placeButton(window);
    var.placeButton(window);

}
void Graph::drawGrids() {
    double startingXPosition = leftMostGridPixelValue();
    for (double i = startingXPosition; i < DEFAULT_W; i += xStep / xValuePerPixel) {
        switch (stepCoefficient) {
            case 2:
                for (int j = 0; j < 4;) {
                    VertexArray gridLine(Lines,2);
                    gridLine[0].position = sf::Vector2f(i + j * 0.25 * xStep / xValuePerPixel, 0);
                    gridLine[1].position = sf::Vector2f(i + j * 0.25 * xStep / xValuePerPixel, graphSafeArea.frame.height());
                    if (j++ == 0) {
                        gridLine[0].color = Color{120,120,120};
                        gridLine[1].color = Color{120,120,120};
                    } else {
                        gridLine[0].color = Color{40,40,40};
                        gridLine[1].color = Color{40,40,40};
                    }
                    window.draw(gridLine);
                }
                break;
            case 1:
            case 5:
                for (int j = 0; j < 5;) {
                    VertexArray gridLine(Lines,2);
                    gridLine[0].position = sf::Vector2f(i + j * 0.2 * xStep / xValuePerPixel, 0);
                    gridLine[1].position = sf::Vector2f(i + j * 0.2 * xStep / xValuePerPixel, graphSafeArea.frame.height());
                    if (j++ == 0) {
                        gridLine[0].color = Color{120,120,120};
                        gridLine[1].color = Color{120,120,120};
                    } else {
                        gridLine[0].color = Color{40,40,40};
                        gridLine[1].color = Color{40,40,40};
                    }
                    window.draw(gridLine);
                }
                break;
            default:
                break;
        }
        
    }
    
    double startingYPosition = topMostGridPixelValue();
    for (int i = startingYPosition; i < graphSafeArea.frame.height(); i += yStep/yValuePerPixel) {
        switch (stepCoefficient) {
            case 2:
                for (int j = 0; j < 4;) {
                    VertexArray gridLine(Lines,2);
                    gridLine[0].position = sf::Vector2f(0, i + j * 0.25 * yStep / yValuePerPixel);
                    gridLine[1].position = sf::Vector2f(graphSafeArea.frame.width(), i + j * 0.25 * yStep / yValuePerPixel);
                    if (j++ == 0) {
                        gridLine[0].color = Color{120,120,120};
                        gridLine[1].color = Color{120,120,120};
                    } else {
                        gridLine[0].color = Color{40,40,40};
                        gridLine[1].color = Color{40,40,40};
                    }
                    window.draw(gridLine);
                }
                break;
            case 1:
            case 5:
                for (int j = 0; j < 5;) {
                    VertexArray gridLine(Lines,2);
                    gridLine[0].position = sf::Vector2f(0, i + j * 0.2 * yStep / yValuePerPixel);
                    gridLine[1].position = sf::Vector2f(graphSafeArea.frame.width(), i + j * 0.2 * yStep / yValuePerPixel);
                    if (j++ == 0) {
                        gridLine[0].color = Color{120,120,120};
                        gridLine[1].color = Color{120,120,120};
                    } else {
                        gridLine[0].color = Color{40,40,40};
                        gridLine[1].color = Color{40,40,40};
                    }
                    window.draw(gridLine);
                }
                break;
            default:
                break;
        }
    }
}
void Graph::createAndDrawAxis() {
    updateGraphingParameters();
    if (showGrid)
        drawGrids();
    if (origin.x < graphSafeArea.frame.width()) {
        VertexRect yAxis;
        yAxis.setStart(CGPoint(origin.x, 0));
        yAxis.setEnd(CGPoint(origin.x, graphSafeArea.frame.height()));
        yAxis.setStroke(0.2);
        yAxis.setColor(sf::Color::White);
        window.draw(yAxis.getRect());
    }
    if (origin.y < graphSafeArea.frame.height()) {
        VertexRect xAxis;
        xAxis.setStart(CGPoint(0,origin.y));
        xAxis.setEnd(CGPoint(graphSafeArea.frame.width(),origin.y));
        xAxis.setStroke(0.2);
        xAxis.setColor(sf::Color::White);
        window.draw(xAxis.getRect());
    }
    
}
void Graph::draggingEvent(sf::Vector2i mouseVector) {
    if (graphSafeArea.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        mousePos = Mouse::getPosition(window);
        xMin -= mouseVector.x * xValuePerPixel;
        xMax -= mouseVector.x * xValuePerPixel;
        yMax += mouseVector.y * yValuePerPixel;
        yMin += mouseVector.y * yValuePerPixel;
        updateGraphingParameters();
    }
}
//Zoom in/out
void Graph::zoomIn(sf::Vector2i instantMousePos) {
    float mouseXRatio = (instantMousePos.x- graphSafeArea.frame.minX())/graphSafeArea.frame.width();
    float mouseYRatio = (instantMousePos.y - graphSafeArea.frame.maxY())/graphSafeArea.frame.height();
    float mouseXValue = xMin + (xMax - xMin) * mouseXRatio;
    float mouseYValue = yMin - (yMax - yMin) * mouseYRatio;
    
    xMin = mouseXValue + ZoomingRatio * (xMin - mouseXValue);
    xMax = mouseXValue + ZoomingRatio * (xMax - mouseXValue);
    yMin = mouseYValue + ZoomingRatio * (yMin - mouseYValue);
    yMax = mouseYValue + ZoomingRatio * (yMax - mouseYValue);
    
    float blockNum = (xMax - xMin) / xStep;
    
    switch (stepCoefficient) {
        case 1:
            if (blockNum <= 9.2) {
                xStep /= 2;
                yStep = xStep;
                stepCoefficient = 5;
            }
            break;
        case 2:
            if (blockNum <= 9) {
                xStep /= 2;
                yStep = xStep;
                stepCoefficient = 1;
            }
            break;
        case 5:
            if (blockNum <= 7) {
                xStep /= 2.5;
                yStep = xStep;
                stepCoefficient = 2;
            }
            break;
            
        default:
            break;
    }
    updateGraphingParameters();
}
void Graph::zoomOut(sf::Vector2i instantMousePos) {
    float mouseXRatio = (instantMousePos.x- graphSafeArea.frame.minX())/graphSafeArea.frame.width();
    float mouseYRatio = (instantMousePos.y - graphSafeArea.frame.maxY())/graphSafeArea.frame.height();
    
    float mouseXValue = xMin + (xMax - xMin) * mouseXRatio;
    float mouseYValue = yMin - (yMax - yMin) * mouseYRatio;
    
    xMin = mouseXValue + (xMin - mouseXValue) / ZoomingRatio;
    xMax = mouseXValue + (xMax - mouseXValue) / ZoomingRatio;
    yMin = mouseYValue + (yMin - mouseYValue) / ZoomingRatio;
    yMax = mouseYValue + (yMax - mouseYValue) / ZoomingRatio;
    
    float blockNum = (xMax - xMin) / xStep;
    switch (stepCoefficient) {
        case 1:
            if (blockNum >= 17) {
                xStep *= 2;
                yStep = xStep;
                stepCoefficient = 2;
            }
            break;
        case 2:
            if (blockNum >= 16.5) {
                xStep *= 2.5;
                yStep = xStep;
                stepCoefficient = 5;
            }
            break;
        case 5:
            if (blockNum >= 17.4) {
                xStep *= 2;
                yStep = xStep;
                stepCoefficient = 1;
            }
            break;
            
        default:
            break;
    }
    updateGraphingParameters();
}
bool Graph::trigNeedToMultiply (char c) {
    return !(c == '+'||c == '-'||c == '*'||c == '/'||c == '(');
}
float Graph::leftMostGridPixelValue() {
    float pixelPerStep = xStep / xValuePerPixel;
    float x = origin.x; // 原点的坐标值
    if (x > 0) {
        for (; x > 0; x -= pixelPerStep);
        return x;
    }
    for (; x < -pixelPerStep; x += pixelPerStep);
    return x;
}
float Graph::topMostGridPixelValue() {
    float pixelPerStep = yStep / yValuePerPixel;
    float y = origin.y;
    if (y > 0) {
        for (; y > 0; y -= pixelPerStep);
        return y;
    }
    for (; y < -pixelPerStep; y += pixelPerStep);
    return y;
    return y;
}
