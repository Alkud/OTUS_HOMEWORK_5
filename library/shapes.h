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
};

/// Basic straight line defined by two points
class Line : public Shape
{
public:
  Line() = delete;
  Line(Point _startPoint, Point _endPoint, int _thickness = 1);
  virtual ~Line();

  void paint(Window* canvas) override;
  void move(int incrementX, int incrementY) override;
  ShapeSize getSize() override;

  Point startPoint;
  Point endPoint;
  int lineThickness;
};

/// Basic rectangle defined by two opposite corner points
class Rectangle : public Shape
{
public:
  Rectangle() = delete;
  Rectangle(Point _leftTop, Point _rightBottom, int _thickness = 1);
  virtual ~Rectangle();

  void paint(Window* canvas) override;
  void move(int incrementX, int incrementY) override;
  ShapeSize getSize() override;

  Point leftTop;
  Point rightBottom;
  int lineThickness;
};

/// Basic ellipse defined by two semi axes
class Ellipse : public Shape
{
public:
  Ellipse() = delete;
  Ellipse(Point _center, int _semiMajor, int _semiMinor, int _thickness = 1);
  virtual ~Ellipse();

  void paint(Window* canvas) override;
  void move(int incrementX, int incrementY) override;
  ShapeSize getSize() override;

  Point center;
  int semiMajor;
  int semiMinor;
  int lineThickness;
};

/// Circle as a special case of the ellipse
class Circle : public Ellipse
{
public:
  Circle () = delete;
  Circle (Point _center, int _radius, int _thickness = 1);
};
