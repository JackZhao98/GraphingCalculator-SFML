//
//  graph.hpp
//  Graphing Calculator CAS
//
//  Created by Jack Zhao on 11/29/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp
#include <vector>
#include <cmath>
#include "UIKit Ripoff/UIButton.hpp"
#include "VertexRect.hpp"
#include "UIKit Ripoff/UIView.hpp"
#include "GCTab.hpp"
using namespace sf;
class Graph {
    
public:
    // CTORS
    Graph();
    
    //------------ Init Section ---------------
    void initRenderWindow();
    /*  Render Window initializer. Creates and Gives sf::RenderWindow default values
     */
    void initButtons();
    /*
     * Initialize buttons with position, title, size.
     */
    void initTabs();
    /*
     * Initialize Tabs with position, title, size.
     */
    void initTabsColor();
    /*
     * Initialize Tabs with default color set.
     */
    
    //------------ Render Section ---------------
    void build();
    /*
     * Call to run the program.
     */
    void render();
    /*
     * Render loop. All drawings function calls are inside.
     */
    void processEvents();
    /*
     * Poll and process most of the events here.
     */
    void mouseHoveringAndPressingEvent();
    /*
    * Process mouse press and hover on buttons.
    */
    void buttonInput();
    /*
    * Click on buttons and do actions.
    * Input equations into tabs.
    */
    
    //------------ Plotting Section ---------------
    void drawLines();
    /*
     * Draw lines on the screen with pre-stored value inside the vector array.
     */
    void refreshPlots();
    /*
     * Recalculate the coordinates with new xMin and xMax.
     */
    void updateGraphingParameters();
    /*
     * Update params with new xMin and xMax.
     */
    void resetPos();
    /*
     * Reset xMin and xMax to Default
     */

    //---------- User Interface Section -------------
    void drawButtons();
    void drawGrids();
    void createAndDrawAxis();
    void draggingEvent(sf::Vector2i mouseVector);
    void zoomIn(sf::Vector2i instantMousePos);
    void zoomOut(sf::Vector2i instantMousePos);
    bool trigNeedToMultiply (char c);
    float leftMostGridPixelValue();
    float topMostGridPixelValue();
    
private:
    // 跟画图有关
    // Graphing related
    vector<sf::Vector2f> coordinates[6];
    sf::Vector2f origin;
    float xMin;
    float xMax;
    float yMin;
    float yMax;
    float xValuePerPixel;
    float yValuePerPixel;
    
    unsigned int stepCoefficient = 0; // 1,2,5
    float xStep;
    float yStep;
    
    
    // Render Related: Render Window
    sf::RenderWindow window;
    Vector2i mousePos;
    GCTab* activeTab;
    UIView graphSafeArea;
    UIView controlPanelArea;
    // UI Related : Buttons, tabs.
    GCTab tabs[6];
    bool showGrid;
    UIButton _1;
    UIButton _2;
    UIButton _3;
    UIButton _4;
    UIButton _5;
    UIButton _6;
    UIButton _7;
    UIButton _8;
    UIButton _9;
    UIButton _0;
    UIButton decimal;
    UIButton equal;
    UIButton plus;
    UIButton minus;
    UIButton multiply;
    UIButton divide;
    UIButton AC;
    UIButton neg;
    UIButton Abs;
    UIButton leftPara;
    UIButton rightPara;
    UIButton sin;
    UIButton cos;
    UIButton tan;
    UIButton expo;
    UIButton pwr2;
    UIButton sqrt;
    UIButton pi;
    UIButton var;
    
    
    
};


#endif /* graph_hpp */
