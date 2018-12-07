////
////  Graphing Calculator.hpp
////  Graphing Calculator CAS
////
////  Created by Jack Zhao on 11/20/18.
////  Copyright © 2018 Jack Zhao. All rights reserved.
////
//
//#ifndef Graphing_Calculator_hpp
//#define Graphing_Calculator_hpp
//#include <cmath>
//#include <vector>
//#include "GCTab.hpp"
//
//#include "UIKit Ripoff/UILabel.hpp"
//#include "VertexRect.hpp"
//#include "Calculator/Header Files/expression.hpp"
//
//double getLength(const sf::Vector2f& start,const sf::Vector2f& end);
//class GraphingCalculator {
//private:
//    sf::Vector2i mousePos;
//    
//    UIViewController mainWindow;
//    UIView graphingArea;
//    GCTab tabs[6];
//    GCTab* activeTab;
//    CGPoint lineSets[6];
//    
//    
//    vector<expression> equation;
//    vector<vector<CGPoint>> lineSet;
//
//    // Graphing Origin
//    CGPoint origin;
//    // Graphing steps.
//    double xMax;           // Cartesian坐标 定义域 x最大值
//    double xMin;
//    double yMax;           // Cartesian坐标 值域 y最大值
//    double yMin;
//
//    double valuePerPixelX;  // 每像素是几
//    double valuePerPixelY;  //
//    
//    double xStep;           // x 的步长 步长-是什么意思呢？让一个数值在每次运算中加上某个数
//    double yStep;
//    unsigned int splitNum; // only 1 2 5;
//    
//    // Text Field
//    UILabel textField;
//    
//    // Buttons
//    UIButton _1;
//    UIButton _2;
//    UIButton _3;
//    UIButton _4;
//    UIButton _5;
//    UIButton _6;
//    UIButton _7;
//    UIButton _8;
//    UIButton _9;
//    UIButton _0;
//    UIButton decimal;
//    UIButton equal;
//    UIButton plus;
//    UIButton minus;
//    UIButton multiply;
//    UIButton divide;
//    UIButton AC;
//    UIButton neg;
//    UIButton abs;
//    
//    UIButton leftPara;
//    UIButton rightPara;
//    UIButton sin;
//    UIButton cos;
//    UIButton tan;
//    
//    UIButton expo;
//    UIButton pwr2;
//    UIButton pwr3;
//    UIButton sqrt;
//    UIButton pi;
//    UIButton var;
//
//    
//public:
//
//    
//    GraphingCalculator(): activeTab(nullptr) {
//        mainWindow.init();
//        
//        graphingArea.setPosition(CGPoint(0,0));
//        graphingArea.setSize(CGSize(DEFAULT_W, 0.65 * DEFAULT_H - 20 - graphingArea._frame.origin.y));
//        graphingArea.borderColor(lightGreyDefault);
//        graphingArea.borderWidth(2);
//        graphingArea.backgroundColor(sf::Color::Transparent/*sf::Color{230,230,230}*/);
//
//        xMax = 10;
//        xMin = -10;
//        
//    }
//    
//    bool init();
//    void update();
//    void catchEvent();
//    
//    void initTab();
//    
//    // Create plots
//    void createPlots();
//    void coordinateCorrection(const CGVector& vector);
//    
//    // Process Events
//    void processMouse();
//    
//    
//    double getAngle(const sf::Vector2f& start,const sf::Vector2f& end);
//    double getLength(const sf::Vector2f& start,const sf::Vector2f& end);
//    
//    
//    void processHoveringEvent(int mouseX, int mouseY);
//    sf::VertexArray createHoveringReferenceLine(int mouseX);
//    void zoom(bool isZoomingIn, sf::Vector2i& currentMousePos);
//    void zoomIn(bool isZoomingIn);
//   
//    void drawGrids();
//    void drawButtons();
//    void generateButtons ();
//    void drawAxis();
//    
//    void render();
//    void render(const sf::Drawable& anotherThing);
//    
//    void addEquation(const expression& _equation) {
//        equation.push_back(_equation);
//    }
//    double getXStep() const {return valuePerPixelX;}
//    double getYStep() const {return valuePerPixelY;}
//    void setXStep(double _xStep) {valuePerPixelX = _xStep;}
//    void setYStep(double _yStep) {valuePerPixelY = _yStep;}
//    double getY(int index, double x) {return equation[index].eval(x);}
//    
//    CGPoint getGraphingOrigin();
//    void moveOrigin(const CGVector& drag);
//    void setOrigin(const CGPoint& newOrigin);
//    void resetOrigin();
//    
//    
////    vector<CGPoint> plot(int index, const CGRect& View);
//    
//    
//    void drawLine(const sf::Color& color);
//    void drawDots(const sf::Color& color);
//    void drawRectangle(const sf::Color& color);
//};
//
//#endif /* Graphing_Calculator_hpp */
