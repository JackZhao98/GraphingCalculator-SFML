#  Graphic Calculator

## Project Overview

This is a **SFML** based **C++** Graphic Calculator Project. Supports basic operators with open parentheses including: 

Operator | Definition | Type
------------ | -------------| -------------
+| Addition | Binary 
\- | Subtraction | Binary 
\* | Multiplication | Binary 
/ | Division | Binary 
x^2 | Squared | Binary 
x^y | Exponential | Binary 
neg( ) | Negation | Unary 
abs( ) | Absolute Value | Unary 
sqrt( ) | Square Root | Unary 
sin( ) | Sine | Unary 
cos( ) | Cosine | Unary 
tan( ) | Tangent | Unary 

## Features

Single variable, six equations in total, cartesian coordinates, with Button UI

### Keyboard Shortcut

Key | Functionality
------------ | -------------
M | Re-center
G | Hide/Show grids
I | Print Information in debug console
H (Tab Selected) | Hide/Show Equation Graph
C (Tab Selected) | Clear Tab
C (Tab Unselected) | Clear All
BackSpace (Tab Selected) | Remove Token
Enter (Tab Selected) | Next Tab

### Call in Main ()

```C++
graph g;
g.build();
```
</br></br>
# Part 1: Calculator

## graph

### Overview

Class graph is the major class integrated RPN (shunting yard) algorithm and SFML GUI libaries controlling the entire graphic calculator program. Member variables include **three** parts:
- Function Graph Parameters
- User Interface
- Renderings 
</br>
Similar to Apple's Autolayout, all UI objects in this object is in fixed aspect ratio or fixed leading/trailing distance to dynamically reisze and relocate with different window size. </br>

>(Note that the Render window width cannot be smaller than 500 pixels, otherwise the program crashes due to the sf::Text title limit).

</br>

### Function Graph Parameters

Contains basic graph parameters: 
```C++
vector<sf::Vector2f> coordinates[6];    // Vectors which store the pixel coordinate value
sf::Vector2f origin;                    // Origin position (pixel value)
float xMin;                             // Left domain of the graphSafeArea (cartesian)
float xMax;                             // Right domain of the graphSafeArea (cartesian)
float yMin;                             // Bottom range of the graphSafeArea (cartesian)
float yMax;                             // Top range of the graphSafeArea (cartesian)
float xValuePerPixel;                   // Cartesian value per pixel (horizontal direction)
float yValuePerPixel;                   // Cartesian value per pixel (vertical direction)
```
and parameters controlling the grids
```C++
unsigned int stepCoefficient = 0;       // 1,2,5 (Step level. With observation, steps in Desmos.com have these coefficients)
float xStep;                            // X direction step.
float yStep;                            // Y direction step.
```
</br>

### User Interface

```C++
GCTab tabs[6];                 // GCTab Class type static array. See details below.
bool showGrid;                 // Boolean, show grid or not.
UIButton _1;                   // A UIButton Class type object. See details below.    
UIButton _2;
UIButton sin;
UIButton cos;
/*
26 More UIbuttons are not displayed.
*/
```
</br>

### Renderings
SFML Objects are declared here.
```C++
sf::RenderWindow window;     // Render Window
Vector2i mousePos;           // Instant Mouse position
```
More Objects controlling the render event.</br>See details of Class **GCTab** and **UIView** below.
```C++
GCTab* activeTab;            // Active tab pointer. nullptr indicates no tabs is selected.
UIView graphSafeArea;        // Graphing area.
UIView controlPanelArea;     // Control Panel area.
```
</br>

### Important functions in class `graph`
```C++
void build();
```
Call to `build()` will run the program.
Render loop is in here.


```C++
void processEvents();
```
Poll and process mouse/keyboard actions from `sf::RenderWindow` object. Process most of the user actions including 
- **Zooming In/Out**
- **Mouse-hovering-triggered button color change**
- **Dragging**

```C++
void refreshPlots();
```
Call to `refreshPlots()` to update `vector<sf::Vector2f> coordinates[6]` values. 
Will recalculate every point coordinates based on the `xMin`, `xMax`.

```C++
void updateGraphingParameters();
```
Call to `updateGraphingParameters()` will automatically update all of the graphing parameters regarding the `xMin`, `xMax`, `yMin`, `yMax`.
```C++
bool trigNeedToMultiply (char c);
```
Automatically check if trig functions need to be multiplied first before append the functions.</br>
> e.x. 2 * tan (

</br></br>

## GCTab

### Overview
This class is a Tab object which contains a `UIButton` and an `expression`. </br> Equation displays as a string on the program window. Automatically check syntax and errors. Draw graph immediately if the equation can be solved, otherwise stop plotting and text color becomes red to warn users for bad input.

### Important Functions 
```C++
void removeToken();
```
Call to `removeToken()` can delete the entire token with one click.
```C++
void append();
```
Call to `append()` can append numbers/operators/functions to the equation string. 
```C++
void updateExpression();
```
Updates `expression` object. Call `updateExpression()` immediately after `append()` and `removeToken()`.

</br></br>

## Calculator (Group)

### Overview
Core algorithm of the Graphic Calculator. Uses Reverse Polish notation with Shunting Yard parsing algorithm to take in an equation string and calculate the value. This part contains an `expression` class, and a `token` class with its inherited classes `oprand`, `optr`, and `var`.

### Important Funcitons
```C++
expression a;
a.setEquation(const std::string& _string);
a.eval(double x);
```
Create an `expression` type object, call to `setEquation(_A_STRING)` to set expression equation and call `eval(_VARIABLE)` to get the value of the equation with given variable (or without).

</br></br>

# Part 2: UIKit (Rip-off with SFML)
## CoreGraphics
### Overview
The Core Graphics is an abstract graphic drawing framework, using numbers to store important parameters of SFML drawing objects. It provides low-level, lightweight 2D object render control.

</br>

## CGRect
A structure that contains the location and dimensions of a rectangle.
### Member Variables
```C++
CGPoint origin;
CGSize size;
```
### Important Functions
```C++
double CGRect::minX() const;                    // Returns the minimum X Value of the rectangle frame.
double CGRect::midX() const;                    // Returns the middle X Value of the rectangle frame.
double CGRect::maxX() const;                    // Returns the maximum X Value of the rectangle frame.
bool CGRect::contains(CGPoint aPoint) const;    // Returns whether a rectangle contains a specified point.
bool CGRect::contains(CGRect aRect) const;      // Returns whether the first rectangle contains the second rectangle.
```
</br>

## CGPoint
A structure that contains a point in a two-dimensional coordinate system.

### Member Variables
```C++
double x;
double y;
```
</br>

## CGSize
A structure that contains width and height values.
### Member Variables
```C++
double width;
double height;
```
</br>

## CGVector
A structure that contains a two-dimensional vector.

### Member Variables
```C++
double dx;
double dy;
```
</br>

## UIView

### Description:
Views are the foundamental building blocks of the app's user interface, and the `UIView` class defines the behaviors that are common to all views. A view object renders content within its bounds rectangle and handles any interactions with that content. The `UIView` class object can be filled with any background color and provides a concrete boundary for more sophisicated UI objects created inside.
### Member Variables
```C++
sf::RectangleShape _View;
CGRect frame;
```

</br>

## UIButton
A control that executes the custom code in response to user interactions. 
### Description:
Users communicate with the program with clicks and presses on the buttons. The appearance and title of a button is configurable. Created with `sf::RectangleShape`, `sf::CircleShape`, and `UILabel` class objects. 
### Member Variables
```C++
sf::CircleShape left;       // Left circle
sf::CircleShape right;      // Middle rectangle
sf::RectangleShape mid;     // Right circle
sf::Color Default;          // Default Button Color
sf::Color Highlighted;      // Highlighted Button Color
sf::Color Selected;         // Selected Button Color
double radius;              // Circle radius
double width;               // width of the middle rectangle.
UILabel title;              // Button title.
``` 
### Important Functions
```C++
void UIButton::setTextPositionToMiddle();
```
Calculate text boundary length and set button to the right position in order to align to center.

</br>

## UILabel
A view that displays one or more lines of read-only text, often used in conjunction with controls to describe their intended purpose.
### Description:
A text view with configurable appearance, can be modified to display any string contents. Labels need to be added programmatically to views.
```C++
sf::Font font;      // Text font
sf::Text title;     // UILabel String
bool _isEnabled;    // is label enabled?
```
-- Inherited from UIView class --

</br>

# Preview

![Screen Shot](GraphicCalculator-SFML/Resources/Screen Shot 2018-12-06 at 17.31.52.png)
![Screen Shot](GraphicCalculator-SFML/Resources/Screen Shot 2018-12-06 at 17.32.37.png)

## Issues
- CPU usage need to be optimized.
- Grid line number does not show in scientific notations properly.
- Plotting issue in discontinuity.

</br>

## To-do list (probably)
- [x] Autolayout. UIs are dynamically resized with render window size.
- [x] Dynamic grid line.
- [x] X and Y axis.
- [x] Buttons and Tabs Mouse Hovering color change.
- [x] Buttons pressed state added.
- [ ] Line color customization
- [ ] Grid line numbers


