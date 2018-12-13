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
    
    // Mouse dragging control.
    // Keep updating mouse position to get a movement vector.
    void draggingEvent(sf::Vector2i mouseVector);
    
    // Zoom in and zoom out based on mouse position.
    void zoomIn(sf::Vector2i instantMousePos);
    void zoomOut(sf::Vector2i instantMousePos);
    
    // Boolean, tells if the trig function need to append a "*" before the trig func
    bool trigNeedToMultiply (char c);
    
    // Calculates the left most coordinate of the grids.
    float leftMostGridPixelValue();
    // Calculates the top most coordinate of the grids.
    float topMostGridPixelValue();
    
private:
    // Graphing related
    vector<sf::Vector2f> coordinates[6];    // Stores up to six sets of coordinates.
                                            // This can save CPU usage by avoiding unnecessary calculation.
    sf::Vector2f origin;                    // Instant pixel position of the origin.
    float xMin;                             // left domain (cartesian value)
    float xMax;                             // right domain (cartesian value)
    float yMin;                             // Range (Max) (cartesian value)
    float yMax;                             // Range (Min) (cartesian value)
    float xValuePerPixel;                   // How much value per pixel in X direction
    float yValuePerPixel;                   // How much value per pixel in Y direction
    
    unsigned int stepCoefficient = 0; // 1,2,5
    float xStep;                            // Step length in X
    float yStep;                            // Step length in Y
    
    
    // Render Related: Render Window
    sf::RenderWindow window;                // Major program render window.
    Vector2i mousePos;                      // Instant mouse position in the window.
    GCTab* activeTab;                       // Pointing to the active GCTab item.
                                            // nullptr if none is activated.
    UIView graphSafeArea;                   // Graph safe area. Abstract area created by UIView
    UIView controlPanelArea;                // Control panel area. Abstract area created by UIView
    
    // UI Related : Buttons, tabs.
    GCTab tabs[6];
    bool showGrid;
    UIButton _1;    // #1
    UIButton _2;    // #2
    UIButton _3;    // #3
    UIButton _4;    // #4
    UIButton _5;    // #5
    UIButton _6;    // #6
    UIButton _7;    // #7
    UIButton _8;    // #8
    UIButton _9;    // #9
    UIButton _0;    // #0
    UIButton decimal;    // .
    UIButton equal;      // =
    UIButton plus;       // +
    UIButton minus;      // -
    UIButton multiply;   // *
    UIButton divide;     // /
    UIButton AC;         // AC
    UIButton neg;        // neg()
    UIButton Abs;        // abs()
    UIButton leftPara;   // (
    UIButton rightPara;  // )
    UIButton sin;        // sin()
    UIButton cos;        // cos()
    UIButton tan;        // tan()
    UIButton expo;       // ^
    UIButton pwr2;       // ^2
    UIButton sqrt;       // sqrt()
    UIButton pi;         // 3.14159265
    UIButton var;        // x
};


#endif /* graph_hpp */
