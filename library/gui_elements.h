#pragma once
#include <string>
#include <vector>
#include <memory>

class Picture
{

};

/// GUI element interface class
class GUIElement
{
public:
  GUIElement() = delete;
  /// Main constructor
  GUIElement(std::string _title, GUIElement* _parent = nullptr);
  virtual ~GUIElement();

  /// Draw the element on the screen
  virtual void paint() = 0;
  /// Make element visible
  virtual void show() = 0;
  /// Hide element from the screen
  virtual void hide() = 0;
  /// Get canvas content as a raster image
  virtual Picture getPicture() = 0;

  /// Text shown in the element header
  std::string title;
  /// Absolute X coordinate of the elment's top left corner
  int posX;
  /// Absolute Y coordinate of the elment's top left corner
  int posY;
  /// Element horizontal size
  int width;
  /// Element vertical size
  int height;
  /// Elemnt visibility flag
  bool visible;
  /// Pointer to the parent element
  GUIElement* parent;
  /// Chaild elements vector
  std::vector<std::shared_ptr<GUIElement>> childs;
};


/// Basic window class
class Window : public GUIElement
{
public:
  Window() = delete;
  /// Main constructor
  Window(std::string _title, GUIElement* _parent = nullptr);

  /// Draw the element on the screen
  virtual void paint() override;
  /// Make element visible
  virtual void show() override;
  /// Hide element from the screen
  virtual void hide() override;
  /// Add a child element
  virtual void addChild(const std::shared_ptr<GUIElement>& _child);
  /// Get canvas content as a raster image
  Picture getPicture() override;
};


/// Menu item
class MenuItem : public GUIElement
{
public:
  MenuItem() = delete;
  /// Main constructor
  MenuItem(int _id, std::string _title, GUIElement* _parent = nullptr);

  /// Draw the element on the screen
  virtual void paint() override;
  /// Make element visible
  virtual void show() override;
  /// Hide element from the screen
  virtual void hide() override;
  virtual void addSubItem(const std::shared_ptr<MenuItem>& _subItem);
  /// Get canvas content as a raster image
  Picture getPicture() override;

  /// Unique menu item ID
  int id;
  /// Menu sub-items list
  std::vector<std::shared_ptr<MenuItem>> subItems;
};


/// Basic menu class
class Menu : public GUIElement
{
public:
  Menu() = delete;
  /// Main constructor
  Menu(std::string _title, GUIElement* _parent = nullptr);

  /// Draw the element on the screen
  virtual void paint() override;
  /// Make element visible
  virtual void show() override;
  /// Hide element from the screen
  virtual void hide() override;
  virtual void addItem(const std::shared_ptr<MenuItem>& _item);
  /// Get canvas content as a raster image
  Picture getPicture() override;
  /// Menu items list
  std::vector<std::shared_ptr<MenuItem>> items;
};


/// Basic button class
class Button : public GUIElement
{
public:
  Button() = delete;
  /// Main constructor
  Button(std::string _title, GUIElement* _parent = nullptr);

  /// Draw the element on the screen
  virtual void paint() override;
  /// Make element visible
  virtual void show() override;
  /// Hide element from the screen
  virtual void hide() override;
  /// Get canvas content as a raster image
  Picture getPicture() override;
};
