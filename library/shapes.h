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

  virtual void setSize(const ShapeSize& newSize) = 0;

  virtual Color getLineColor() = 0;
  virtual void setLineColor(const Color& newColor) = 0;

protected:
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

  void paint(Window* canvas) override;
  void move(int incrementX, int incrementY) override;
  ShapeSize getSize() override;
  void setSize(const ShapeSize& newSize) override;
  Color getLineColor() override;
  void setLineColor(const Color& newColor) override;

protected:
  Point startPoint;
  Point endPoint;  
};

/// Basic rectangle defined by two opposite corner points
class Rectangle : public Shape
{
public:
  Rectangle() = delete;
  Rectangle(Point _leftTop, Point _rightBottom, int _thickness = 1, Color _lineColor = Color{0,0,0});
  virtual ~Rectangle();

  void paint(Window* canvas) override;
  void move(int incrementX, int incrementY) override;
  ShapeSize getSize() override;
  void setSize(const ShapeSize& newSize) override;
  Color getLineColor() override;
  void setLineColor(const Color& newColor) override;

protected:
  Point leftTop;
  Point rightBottom;  
};

/// Basic ellipse defined by two semi axes
class Ellipse : public Shape
{
public:
  Ellipse() = delete;
  Ellipse(Point _center, int _semiMajor, int _semiMinor, int _thickness = 1, Color _lineColor = Color{0,0,0});
  virtual ~Ellipse();

  void paint(Window* canvas) override;
  void move(int incrementX, int incrementY) override;
  ShapeSize getSize() override;
  void setSize(const ShapeSize& newSize) override;
  Color getLineColor() override;
  void setLineColor(const Color& newColor) override;

protected:
  Point center;
  int semiMajor;
  int semiMinor;  
};

/// Circle as a special case of the ellipse
class Circle : public Ellipse
{
public:
  Circle () = delete;
  Circle (Point _center, int _radius, int _thickness = 1, Color _lineColor = Color{0,0,0});
  virtual ~Circle();
};
