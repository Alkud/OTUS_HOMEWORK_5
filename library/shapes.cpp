#include "shapes.h"

/*=========================================================*/
Line::Line(Point _startPoint, Point _endPoint, int _thickness) :
  startPoint{_startPoint}, endPoint{_endPoint}, lineThickness{_thickness}
{}

void Line::paint(Window* canvas)
{

}

void Line::move(int incrementX, int incrementY)
{

}

ShapeSize Line::getSize()
{

}


/*=========================================================*/
Rectangle::Rectangle(Point _leftTop, Point _rightBottom, int thickness) :
  leftTop{_leftTop}, rightBottom{_rightBottom}, lineThickness{thickness}
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


/*=========================================================*/
Ellipse::Ellipse(Point _center, int _semiMajor, int _semiMinor, int _thickness) :
  center{_center}, semiMajor{_semiMajor}, semiMinor{_semiMinor}, lineThickness{_thickness}
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


/*=========================================================*/
Circle::Circle(Point _center, int _radius, int _thickness) :
  Ellipse{_center, _radius, _radius, _thickness}
{

}
