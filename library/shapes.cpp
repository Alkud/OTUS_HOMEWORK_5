#include "shapes.h"

Shape::~Shape()
{

}


/*=========================================================*/
Line::Line(Point _startPoint, Point _endPoint, int _thickness, Color _lineColor) :
  Shape{_thickness, _lineColor},
  startPoint{_startPoint}, endPoint{_endPoint}
{}

Line::~Line()
{

}

void Line::paint(Window* canvas)
{

}

void Line::move(int incrementX, int incrementY)
{

}

ShapeSize Line::getSize()
{

}

void Line::setSize(const ShapeSize& newSize)
{

}

Color Line::getLineColor()
{

}

void Line::setLineColor(const Color& newColor)
{

}


/*=========================================================*/
Rectangle::Rectangle(Point _leftTop, Point _rightBottom, int _thickness, Color _lineColor) :
  Shape{_thickness, _lineColor},
  leftTop{_leftTop}, rightBottom{_rightBottom}
{

}

Rectangle::~Rectangle()
{

}

void Rectangle::paint(Window* canvas)
{

}

void Rectangle::move(int incrementX, int incrementY)
{

}

ShapeSize Rectangle::getSize()
{

}

void Rectangle::setSize(const ShapeSize& newSize)
{

}

Color Rectangle::getLineColor()
{

}

void Rectangle::setLineColor(const Color& newColor)
{

}


/*=========================================================*/
Ellipse::Ellipse(Point _center, int _semiMajor, int _semiMinor, int _thickness, Color _lineColor) :
  Shape{_thickness, _lineColor},
  center{_center}, semiMajor{_semiMajor}, semiMinor{_semiMinor}
{

}

Ellipse::~Ellipse()
{

}

void Ellipse::paint(Window* canvas)
{

}
void Ellipse::move(int incrementX, int incrementY)
{

}

ShapeSize Ellipse::getSize()
{

}

void Ellipse::setSize(const ShapeSize& newSize)
{

}

Color Ellipse::getLineColor()
{

}

void Ellipse::setLineColor(const Color& newColor)
{

}


/*=========================================================*/
Circle::Circle(Point _center, int _radius, int _thickness, Color _lineColor) :
  Ellipse{_center, _radius, _radius, _thickness, _lineColor}
{

}

Circle::~Circle()
{

}

