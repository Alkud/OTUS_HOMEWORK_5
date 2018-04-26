#pragma once

#include "shapes.h"
#include "gui_elements.h"
#include <list>
#include <memory>

/// Contains drawing elements description,
/// creates and destroys shapes
class Document
{
public:
  Document(){}
  Document(const Document& other);
  Document(Document&& other);
  /// Create new shape according to the currntly selected type
  std::shared_ptr<Shape> createNewShape();
  /// Add new item to the shape list
  void addShape(const std::shared_ptr<Shape>& _shape);
  /// Remove an item from the list
  void removeShape(const std::shared_ptr<Shape>& _shape);
  /// Set the GUI element whos canvas is used to draw
  void setView(Window* _view);
  /// Redraw the view canvas
  void refreshView();

  void sendToDatabase();

  void receiveFromDatabase();

  void saveToFile(const std::string& fileName);

  void loadFromFile(const std::string& fileName);

  void modifyShape(Shape* shapeToModifiy, int newThickness, Color newColor);

  void replaceShapes(ShapeType typeToReplace, ShapeType newType, int filterSize, Color filterColor);

  Document& operator=(const Document& other);

  bool operator==(const Document& other);


protected:
  /// Contains shapes consisting the drawing
  std::list<std::shared_ptr<Shape>> shapes;
  /// GUI element whos canvas is used to draw
  Window* view;
  /// Shape type currently selected by user and used when creating new item
  ShapeType currentShapeType;
};

