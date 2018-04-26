#include "document.h"

Document::Document(const Document& other)
{

}

Document::Document(Document&& other)
{

}

std::shared_ptr<Shape> Document::createNewShape()
{

}

void Document::addShape(const std::shared_ptr<Shape>& _shape)
{

}

void Document::removeShape(const std::shared_ptr<Shape>& _shape)
{

}

void Document::setView(Window* _view)
{

}

void Document::refreshView()
{

}

void Document::sendToDatabase()
{

}

void Document::receiveFromDatabase()
{

}

void Document::saveToFile(const std::string& fileName)
{

}

void Document::loadFromFile(const std::string& fileName)
{

}

void Document::modifyShape(Shape* shapeToModifiy, int newThickness, Color newColor)
{

}

void Document::replaceShapes(ShapeType typeToReplace, ShapeType newType, int filterSize, Color filterColor)
{

}

Document& Document::operator=(const Document& other)
{
  shapes = other.shapes;
  currentShapeType = other.currentShapeType;
  return *this;
}

bool Document::operator==(const Document& other)
{
  return (shapes == other.shapes && view == other.view);
}
