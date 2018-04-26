#pragma once
#include "gui_elements.h"

/// Point coordinates
struct Point
{
  int x;
  int y;
};

/// Enclosing rectangle size
struct ShapeSize
{
  int width;
  int height;
};

/// RGB color data
struct Color
{
  uint32_t red;
  uint32_t green;
  uint32_t blue;
};

enum class ShapeType
{
  Line,
  Rectangle,
  Ellipse
};

/// Shape interface class
class Shape
{
public:
  /// Drawing a shape
  virtual void paint(Window* canvas) = 0;
  /// Change shape's position
  virtual void move(int incrementX, int incrementY) = 0;
  /// Get enclosing rectangle size
  virtual ShapeSize getSize() = 0;
  /// Set new size of the shape
  virtual void setSize(const ShapeSize& newSize) = 0;
  /// Get line color
  virtual Color getLineColor() = 0;
  /// Set new line color
  virtual void setLineColor(const Color& newColor) = 0;

protected:
  /// Main constructor
  Shape(int _thickness = 1, Color _lineColor = Color{0,0,0}) :
    lineThickness{_thickness}, lineColor{_lineColor}{}

  virtual ~Shape();

  int lineThickness;
  Color lineColor;
};

/// Basic straight line defined by two points
class Line : public Shape
{
public:
  Line() = delete;
  Line(Point _startPoint, Point _endPoint, int _thickness = 1, Color _lineColor = Color{0,0,0});
  virtual ~Line();

  /// Drawing a shape
  void paint(Window* canvas);
  /// Change shape's position
  void move(int incrementX, int incrementY);
  /// Get enclosing rectangle size
  ShapeSize getSize();
  /// Set new size of the shape
  void setSize(const ShapeSize& newSize);
  /// Get line color
  Color getLineColor();
  /// Set new line color
  void setLineColor(const Color& newColor);

protected:
  /// Line's first point
  Point startPoint;
  /// Line's second point
  Point endPoint;  
};

/// Basic rectangle defined by two opposite corner points
class Rectangle : public Shape
{
public:
  Rectangle() = delete;
  /// Main constructor
  Rectangle(Point _leftTop, Point _rightBottom, int _thickness = 1, Color _lineColor = Color{0,0,0});
  virtual ~Rectangle();

  /// Drawing a shape
  void paint(Window* canvas);
  /// Change shape's position
  void move(int incrementX, int incrementY);
  /// Get enclosing rectangle size
  ShapeSize getSize();
  /// Set new size of the shape
  void setSize(const ShapeSize& newSize);
  /// Get line color
  Color getLineColor();
  /// Set new line color
  void setLineColor(const Color& newColor);

protected:
  /// Left top corner coordinates
  Point leftTop;
  /// Right bottom corner coordinates
  Point rightBottom;  
};

/// Basic ellipse defined by two semi axes
class Ellipse : public Shape
{
public:
  Ellipse() = delete;
  /// Main constructor
  Ellipse(Point _center, int _semiMajor, int _semiMinor, int _thickness = 1, Color _lineColor = Color{0,0,0});
  virtual ~Ellipse();

  /// Drawing a shape
  void paint(Window* canvas);
  /// Change shape's position
  void move(int incrementX, int incrementY);
  /// Get enclosing rectangle size
  ShapeSize getSize();
  /// Set new size of the shape
  void setSize(const ShapeSize& newSize);
  /// Get line color
  Color getLineColor();
  /// Set new line color
  void setLineColor(const Color& newColor);

protected:
  /// Center coordinates
  Point center;
  /// Major semi-axis size
  int semiMajor;
  /// Minor semi-axis size
  int semiMinor;  
};

/// Circle as a special case of the ellipse
class Circle : public Ellipse
{
public:
  Circle () = delete;
  /// Main constructor
  Circle (Point _center, int _radius, int _thickness = 1, Color _lineColor = Color{0,0,0});
  virtual ~Circle();
};
