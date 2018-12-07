////
////  Graphing Calculator.cpp
////  Graphing Calculator CAS
////
////  Created by Jack Zhao on 11/20/18.
////  Copyright © 2018 Jack Zhao. All rights reserved.
////
//
//#include "Graphing Calculator.hpp"
////#include "UIKit Ripoff/constants.cpp"
////void graph::drawLines(string equation, sf::Color color) {
////
////}
//
//bool GraphingCalculator::init() {
//    textField.setTitle("Graphing Calculator");
//    textField.setPosition(sf::Vector2f(25,25));
//    // Create Graphing Area
//    
//    resetOrigin();
//    createPlots();
//    
//    while (mainWindow.active()) {
//        catchEvent();
//        processMouse();
//        render();
//    }
//    
//    return true;
//}
//
//// Update step and grid
//void GraphingCalculator::update() {
//    valuePerPixelX = (xMax - xMin)/(graphingArea._frame.maxX() - graphingArea._frame.minX());
//    valuePerPixelY = valuePerPixelX;
//    
//    origin.x = (0-xMin)*valuePerPixelX;
//    origin.y = yMax * valuePerPixelY;
//    
//    
//}
//
//// Render Control;
//void GraphingCalculator::render() {
//    mousePos = sf::Mouse::getPosition(mainWindow._window);
//    mainWindow.clearBuffer();
//    mainWindow.draw(graphingArea._View);
//    generateButtons();
//    drawAxis();
//    initTab();
//    textField.drawLabel(mainWindow);
//    drawRectangle(orangeDefault);
////    drawLine(orangeDefault);
//    mainWindow.display();
//}
//
//void GraphingCalculator::render(const sf::Drawable& anotherThing) {
//    mousePos = sf::Mouse::getPosition(mainWindow._window);
//    mainWindow.clearBuffer();
//    mainWindow.draw(graphingArea._View);
//    generateButtons();
//    drawAxis();
//    initTab();
//    textField.drawLabel(mainWindow);
//    mainWindow.draw(anotherThing);
//    drawRectangle(orangeDefault);
//    mainWindow.display();
//}
//
//
//// GCTabs Control
//void GraphingCalculator::initTab() {
//   
//    double offset = 0.032 * DEFAULT_W;
//    double vGap = (pi.origin().y + pi.getHeight() - leftPara.origin().y - 3 * tabs[0].getHeight()) / 4;
//    double buttonLength = 1.5 * AC.getRadius() + AC.getLength() * 6;
//    sf::Vector2f origin = leftPara.origin();
//    double length = origin.x - 3  * offset;
//    for (int i = 0; i < 3; ++ i) {
//        tabs[i].setPosition(origin - sf::Vector2f(1.5 *offset + length,-vGap - i * (vGap + tabs[i].getHeight())));
//        tabs[i].setLength(length);
//        tabs[i].drawTab(mainWindow);
//    }
//    for (int i = 3; i < 6; ++ i) {
//        tabs[3].setEquation("sin x");
//        tabs[i].setPosition(origin - sf::Vector2f(-1.5 *offset - buttonLength,-vGap - (i-3)* (vGap + tabs[i-3].getHeight())));
//        tabs[i].setLength(length);
//        tabs[i].drawTab(mainWindow);
//    }
//    
//    
//}
//
//
//
//// UI Generating: Grids.
//void GraphingCalculator::drawAxis() {
//    if (origin.x < graphingArea._frame.width()) {
//        sf::VertexArray yAxis(sf::Lines,2);
//        yAxis[0].position = (sf::Vector2f(origin.x,graphingArea._frame.minY()));
//        yAxis[1].position = (sf::Vector2f(origin.x,graphingArea._frame.maxY()));
//        yAxis[0].color = sf::Color::Black;
//        yAxis[1].color = sf::Color::Black;
//        mainWindow.draw(yAxis);
//    }
//    if (origin.y < graphingArea._frame.height()) {
//        sf::VertexArray xAxis(sf::Lines,2);
//        xAxis[0].position = (sf::Vector2f(graphingArea._frame.minX(),origin.y));
//        xAxis[1].position = (sf::Vector2f(graphingArea._frame.maxX(),origin.y));
//        xAxis[0].color = sf::Color::Black;
//        xAxis[1].color = sf::Color::Black;
//        mainWindow.draw(xAxis);
//    }
//}
//
//void GraphingCalculator::drawGrids() {
////    unsigned int split = (splitNum == 2)? 4:5;
////    unsigned int index = 0;
////    float subStepPixel = valuePerXPixel
//    
//}
//
//
//// UI Button Control
//// : generateButtons()
//// : drawButtons()
//// These functions generates Buttons and give it default settings.
//void GraphingCalculator::generateButtons () {
//    double radius = _1.getRadius();
//    double keyPadHeight = 5 * _1.getHeight() + 1.6 *radius;
//    double keyPadLength = 6 * _1.getLength() + 1.5 * radius;
//    // Set Button Origin Here...
//    const sf::Vector2f origin(graphingArea._frame.midX() - 0.5 * keyPadLength, graphingArea._frame.maxY() + (DEFAULT_H - graphingArea._frame.height() - keyPadHeight) * 0.5);
// 
//    // Button Settings...
//    
//    leftPara.setPosition(origin);
//    rightPara.setPosition(leftPara.origin() + sf::Vector2f(0.3 * radius + leftPara.getLength(),0));
//    AC.setPosition(rightPara.origin() + sf::Vector2f(0.3 * radius + rightPara.getLength(),0));
////    AC.setLength(2 * _1.getLength()+ 0.3 * radius);
//    abs.setPosition(AC.origin() + sf::Vector2f(0.3 * radius + AC.getLength(),0));
//    neg.setPosition(abs.origin() + sf::Vector2f(0.3 * radius + abs.getLength(),0));
//    divide.setPosition(neg.origin() + sf::Vector2f(0.3 * radius + neg.getLength(),0));
//
//    
//    pwr2.setPosition(leftPara.origin() + sf::Vector2f(0,leftPara.getHeight() + 0.4 * radius));
//    pwr3.setPosition(pwr2.origin() + sf::Vector2f(0.3 * radius + pwr2.getLength(),0));
//    _7.setPosition(pwr3.origin() + sf::Vector2f(0.3 * radius + pwr3.getLength(), 0));
//    _8.setPosition(_7.origin() + sf::Vector2f(0.3 * radius + _7.getLength(),0));
//    _9.setPosition(_8.origin() + sf::Vector2f(0.3 * radius + _8.getLength(),0));
//    
//    expo.setPosition(pwr2.origin() + sf::Vector2f(0,pwr2.getHeight() + 0.4 * radius));
//    sin.setPosition(expo.origin() + sf::Vector2f(0.3 * radius + expo.getLength(),0));
//    _4.setPosition(sin.origin() + sf::Vector2f(0.3 * radius + sin.getLength(),0));
//    _5.setPosition(_4.origin() + sf::Vector2f(0.3 * radius + _4.getLength(),0));
//    _6.setPosition(_5.origin() + sf::Vector2f(0.3 * radius + _5.getLength(),0));
//    
//    cos.setPosition(expo.origin() + sf::Vector2f(0,expo.getHeight() + 0.4 * radius));
//    tan.setPosition(cos.origin() + sf::Vector2f(0.3 * radius + cos.getLength(),0));
//    _1.setPosition(tan.origin() + sf::Vector2f(0.3 * radius + tan.getLength(),0));
//    _2.setPosition(_1.origin() + sf::Vector2f(0.3 * radius + _1.getLength(),0));
//    _3.setPosition(_2.origin() + sf::Vector2f(0.3 * radius + _2.getLength(),0));
//    
//    
//    pi.setPosition(cos.origin() + sf::Vector2f(0,cos.getHeight() + 0.4 * radius));
//    var.setPosition(pi.origin() + sf::Vector2f(0.3 * radius + pi.getLength(),0));
//    _0.setPosition(var.origin() + sf::Vector2f(0.3 * radius + var.getLength(),0));
//    _0.setLength(2 * var.getLength()+ 0.3 * radius);
//    decimal.setPosition(_0.origin() + sf::Vector2f(0.3 * radius + _0.getLength(),0));
//    
//    
//    multiply.setPosition(_9.origin() + sf::Vector2f(0.3 * radius + _9.getLength(),0));
//    minus.setPosition(multiply.origin() + sf::Vector2f(0,multiply.getHeight() + 0.4 * radius));
//    plus.setPosition(minus.origin() + sf::Vector2f(0,minus.getHeight() + 0.4 * radius));
//    equal.setPosition(plus.origin() + sf::Vector2f(0,plus.getHeight() + 0.4 * radius));
// 
//    
//    _1.setTitle("1");
//    _2.setTitle("2");
//    _3.setTitle("3");
//    _4.setTitle("4");
//    _5.setTitle("5");
//    _6.setTitle("6");
//    _7.setTitle("7");
//    _8.setTitle("8");
//    _9.setTitle("9");
//    _0.setTitle("0");
//    decimal.setTitle(".");
//    multiply.setTitle("x");
//    minus.setTitle("-");
//    plus.setTitle("+");
//    equal.setTitle("=");
//    AC.setTitle("AC");
//    abs.setTitle("abs");
//    neg.setTitle("neg");
//    divide.setTitle("/");
//    leftPara.setTitle("(");
//    rightPara.setTitle(")");
//    pwr3.setTitle("x^3");
//    pwr2.setTitle("x^2");
//    expo.setTitle("x^y");
//    sin.setTitle("sin");
//    cos.setTitle("cos");
//    tan.setTitle("tan");
//    pi.setTitle("Pi");
//    var.setTitle("x");
//
//    _1.setType(NUMBER);
//    _2.setType(NUMBER);
//    _3.setType(NUMBER);
//    _4.setType(NUMBER);
//    _5.setType(NUMBER);
//    _6.setType(NUMBER);
//    _7.setType(NUMBER);
//    _8.setType(NUMBER);
//    _9.setType(NUMBER);
//    _0.setType(NUMBER);
//    decimal.setType(NUMBER);
//    AC.setType(COMMAND);
//    neg.setType(COMMAND);
//    abs.setType(COMMAND);
//    plus.setType(OPERATOR);
//    minus.setType(OPERATOR);
//    multiply.setType(OPERATOR);
//    divide.setType(OPERATOR);
//    equal.setType(OPERATOR);
//    leftPara.setType(FUNCTION);
//    rightPara.setType(FUNCTION);
//    pwr2.setType(FUNCTION);
//    pwr3.setType(FUNCTION);
//    expo.setType(FUNCTION);
//    sin.setType(FUNCTION);
//    cos.setType(FUNCTION);
//    tan.setType(FUNCTION);
//    pi.setType(NUMBER);
//    var.setType(NUMBER);
//  
//    drawButtons();
//}
//
//void GraphingCalculator::drawButtons() {
//    _1.placeButton(mainWindow);
//    _2.placeButton(mainWindow);
//    _3.placeButton(mainWindow);
//    _4.placeButton(mainWindow);
//    _5.placeButton(mainWindow);
//    _6.placeButton(mainWindow);
//    _7.placeButton(mainWindow);
//    _8.placeButton(mainWindow);
//    _9.placeButton(mainWindow);
//    _0.placeButton(mainWindow);
//    decimal.placeButton(mainWindow);
//    multiply.placeButton(mainWindow);
//    minus.placeButton(mainWindow);
//    plus.placeButton(mainWindow);
//    equal.placeButton(mainWindow);
//    abs.placeButton(mainWindow);
//    AC.placeButton(mainWindow);
//    neg.placeButton(mainWindow);
//    divide.placeButton(mainWindow);
//    leftPara.placeButton(mainWindow);
//    rightPara.placeButton(mainWindow);
//    pwr3.placeButton(mainWindow);
//    pwr2.placeButton(mainWindow);
//    expo.placeButton(mainWindow);
//    sin.placeButton(mainWindow);
//    cos.placeButton(mainWindow);
//    tan.placeButton(mainWindow);
//    pi.placeButton(mainWindow);
//    var.placeButton(mainWindow);
//    
//}
//
//void GraphingCalculator::zoom(bool isZoomingIn, sf::Vector2i& currentMousePos) {
//    float mouseXRatio = (mousePos.x- graphingArea._frame.minX())/graphingArea._frame.width();
//    float mouseYRatio = (mousePos.x- graphingArea._frame.minX())/graphingArea._frame.width();
//    
//    float mouseXValue = xMin + (xMax - xMin) * mouseXRatio;
//    float mouseYValue = yMin - (yMax - yMin) * mouseYRatio;
//    
//    if (isZoomingIn) {
//        xMin = mouseXValue + ZoomingRatio * (xMin - mouseXValue);
//        xMax = mouseXValue + ZoomingRatio * (xMax - mouseXValue);
//        yMin = mouseYValue + ZoomingRatio * (yMin - mouseYValue);
//        yMax = mouseYValue + ZoomingRatio * (yMax - mouseYValue);
//    }
//    else {
//        xMin = mouseXValue + (xMin - mouseXValue) / ZoomingRatio;
//        xMax = mouseXValue + (xMax - mouseXValue) / ZoomingRatio;
//        yMin = mouseYValue + (yMin - mouseYValue) / ZoomingRatio;
//        yMax = mouseYValue + (yMax - mouseYValue) / ZoomingRatio;
//    }
//    update();
//}
//
//void GraphingCalculator::setOrigin(const CGPoint& newOrigin) {
//    origin = newOrigin;
//}
//
//CGPoint GraphingCalculator::getGraphingOrigin() {
//    return origin;
//}
//
//void GraphingCalculator::moveOrigin(const CGVector& drag) {
//    origin.x += drag.dx;
//    origin.y += drag.dy;
//}
//
//void GraphingCalculator::resetOrigin() {
//    origin = graphingArea._frame.midPoint();
//}
//
//
//// Catch Event
//// UIEvent
//void GraphingCalculator::catchEvent() {
//    sf::Event event;
//
//    
//    while (mainWindow.pollEvenet(event)) {
//
//        switch (event.type) {
//            case sf::Event::Closed:
//                mainWindow.terminate();
//                break;
//            case sf::Event::MouseWheelScrolled:
//                if (graphingArea.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                    if (event.mouseWheelScroll.delta > 0) {
//                        cout << "zoom out \n" << "Delta " << event.mouseWheelScroll.delta << endl;
//                        zoom(false, mousePos);
//                    } else if (event.mouseWheelScroll.delta < 0){
//                        cout << "zoom in \n"<< "Delta " << event.mouseWheelScroll.delta << endl;
//                        zoom(true, mousePos);
//                    }
//                    createPlots();
//                }
//                break;
//            case sf::Event::MouseButtonReleased:
//                for (int i = 0; i < 6; ++ i) {
//                    if (tabs[i].contains(sf::Vector2f(sf::Mouse::getPosition(mainWindow._window)))) {
//                        if (activeTab != nullptr)
//                            activeTab -> setState(DEFAULT);
//                        activeTab = (activeTab == &tabs[i])? nullptr:&tabs[i];
//                    }
//                }
//                if (activeTab != nullptr) {
//                    activeTab -> setState(SELECTED);
//                    cout << activeTab -> getState() << endl;
//                }
//                
//                
//                
//            default:
//                break;
//        }
//    }
//}
//
////void GraphingCalculator::zoomIn(bool isZoomingIn) {
////    if (isZoomingIn) {
////        xStep *= 0.9;
////        yStep *= 0.9;
////    } else {
////        xStep /= 0.9;
////        yStep /= 0.9;
////    }
////}
//
//void GraphingCalculator::processMouse() {
//    static int mouseX = 0;
//    static int mouseY = 0;
//    static sf::VertexArray referenceLine(sf::Lines, 2);
//    static CGVector mouseMovement;
//    sf::Vector2i mousePosition;
//
//    
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//        mousePosition = sf::Mouse::getPosition(mainWindow._window);
//        while (sf::Mouse::isButtonPressed(sf::Mouse::Left) && graphingArea._frame.contains(CGPoint(mousePosition.x, mousePosition.y))) {
//            sf::Vector2i newPos = mousePos;
//            sf::Vector2i mouseDelta = mousePosition - newPos;
//            
//            origin.x -= mouseDelta.x;
//            origin.y -= mouseDelta.y;
//            createPlots();
//            render();
//            mousePosition = newPos;
//        }
//    }
////    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
////        mouseX = sf::Mouse::getPosition(mainWindow._window).x;
////        mouseY = sf::Mouse::getPosition(mainWindow._window).y;
////        if (graphingArea._View.getGlobalBounds().contains(mouseX, mouseY)) {
////            referenceLine = createHoveringReferenceLine(mouseX);
////        }
////
////        processHoveringEvent(mouseX, mouseY);
////        render(referenceLine);
////    }
//
//    for (int i = 0; i < 6; ++ i) {
//        tabs[i].processTabMouseEvent(sf::Vector2i(mouseX,mouseY));
//    }
//    
//}
//
//sf::VertexArray GraphingCalculator::createHoveringReferenceLine(int mouseX) {
//    sf::VertexArray referenceLine(sf::Lines, 2);
//    referenceLine[0].position = (sf::Vector2f(mouseX, graphingArea._frame.minY()));
//    referenceLine[1].position = (sf::Vector2f(mouseX, graphingArea._frame.maxY()));
//    referenceLine[0].color = orangeDefault;
//    referenceLine[1].color = orangeDefault;
//    return referenceLine;
//}
//// Change color upon mouse hovering
//void GraphingCalculator::processHoveringEvent(int mouseX, int mouseY) {
//    _1.setState(_1.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _2.setState(_2.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _3.setState(_3.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _4.setState(_4.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _5.setState(_5.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _6.setState(_6.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _7.setState(_7.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _8.setState(_8.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _9.setState(_9.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    _0.setState(_0.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    decimal.setState(decimal.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    AC.setState(AC.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    neg.setState(neg.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    abs.setState(abs.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    plus.setState(plus.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    minus.setState(minus.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    multiply.setState(multiply.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    divide.setState(divide.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    equal.setState(equal.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    leftPara.setState(leftPara.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    rightPara.setState(rightPara.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    pwr2.setState(pwr2.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    pwr3.setState(pwr3.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    expo.setState(expo.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    sin.setState(sin.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    cos.setState(cos.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    tan.setState(tan.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    pi.setState(pi.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    var.setState(var.contains(sf::Vector2f(mouseX, mouseY))? HIGHLIGHTED:DEFAULT);
//    
//}
//
//
//
//// Function Plotting/ Calculation
//void GraphingCalculator::createPlots() {
//    int index = 0;
//    for (int i = 0;i < lineSet.size(); ++ i) {
//        lineSet[i].clear();
//    }
//    lineSet.clear();
//    
//    while (index <= 6) {
//        if (tabs[index].Available()) {
//            vector<CGPoint> plots;
//            for (double i = xMin; i < xMax; i += valuePerPixelX) {
//                plots.push_back(CGPoint((i - xMin)/valuePerPixelX, (yMax - tabs[index]. equation.eval(i))/valuePerPixelY));
//                cout << "x: " << (i - xMin)/valuePerPixelX << "y: " <<  (yMax - tabs[index]. equation.eval(i))/valuePerPixelY << "\n";
//            }
//            lineSet.push_back(plots);
//        }
//        index ++;
//    }
//}
////    if (equation.size() == 0) {
////        cout << "NO equation\n";
////        return;
////    }
////    int leftDomain = graphingArea._frame.minX();
////    int rightDomain = graphingArea._frame.maxX();
////    double maxRange = (origin.y - graphingArea._frame.minY()) * yStep;
////    double minRange = (origin.y - graphingArea._frame.maxY()) * yStep;
////    double tempY = 0;
////    for (int i = 0;i < lineSet.size(); ++ i) {
////        lineSet[i].clear();
////    }
////    lineSet.clear();
////
////    for (int i = 0; i < equation.size(); ++ i) {
////        vector<CGPoint> line;
////        for (int j = leftDomain; j < rightDomain; j += 1) {
////            tempY = getY(i, (j - origin.x) * xStep);
////            if (tempY >= minRange && tempY <= maxRange) {
////                line.push_back(CGPoint(j, origin.y - tempY/yStep));
////            }
////        }
////        lineSet.push_back(line);
////    }
//
//void GraphingCalculator::coordinateCorrection(const CGVector& vector) {
//    for (int i = 0; i < lineSet.size(); ++ i) {
//        for (int j = 0; j < lineSet[i].size(); ++ j) {
//            
//            lineSet[i][j].x += vector.dx;
//            lineSet[i][j].y += vector.dy;
//        }
//    }
//}
//
//
//
//
//
//// Graphing.
//
//void GraphingCalculator::drawRectangle(const sf::Color& color) {
//    for (int index = 0; index < lineSet.size(); ++ index) {
////        vector<sf::RectangleShape> rectangles;
//        for (int i = 1; i < lineSet[index].size() - 1; ++ i) {
//            VertexRect rect;
//            rect.setStart(CGPoint(lineSet[index][i-1].x,lineSet[index][i-1].y));
//            rect.setEnd(CGPoint(lineSet[index][i].x,lineSet[index][i].y));
//            rect.setColor(orangeDefault);
//            mainWindow.draw(rect.getRect());
//        }
//    }
//}
//
//void GraphingCalculator::drawLine(const sf::Color& color) {
//    for (int index = 0; index < lineSet.size(); ++ index) {
//        for (int i = 1; i < lineSet[index].size(); ++ i) {
//            sf::VertexArray line(sf::Lines, 2);
//            line[0].position = (sf::Vector2f(lineSet[index][i].x, lineSet[index][i].y));
//            line[1].position = (sf::Vector2f(lineSet[index][i - 1].x, lineSet[index][i-1].y));
//            line[0].color = color;
//            line[1].color = color;
//            
//            mainWindow.draw(line);
//        }
//    }
//}
//
//void GraphingCalculator::drawDots(const sf::Color& color) {
//    for (int index = 0; index < lineSet.size(); ++ index) {
//        for (int i = 0; i < lineSet[index].size(); ++ i) {
//            sf::CircleShape dot;
//            dot.setRadius(2);
//            dot.setPosition(sf::Vector2f(lineSet[index][i].x, lineSet[index][i].y));
//            dot.setFillColor(color);
//            
//            mainWindow.draw(dot);
//        }
//    }
//}
