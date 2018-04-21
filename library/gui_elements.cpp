#include "gui_elements.h"

GUIElement::GUIElement(std::string _title, GUIElement* _parent) :
  title{_title}, parent{_parent}
{

}

GUIElement::~GUIElement()
{

}

/*=========================================================*/
Window::Window(std::string _title, GUIElement* _parent) :
  GUIElement{_title, _parent}
{

}

void Window::paint()
{
  for (auto element : childs)
  {
    element->paint();
  }
}

void Window::show()
{
  visible = true;
  paint();
}

void Window::hide()
{
  visible = false;
  paint();
}

void Window::addChild(const std::shared_ptr<GUIElement>& _child)
{
  childs.push_back(_child);
}

/*=========================================================*/
MenuItem::MenuItem(int _id, std::string _title, GUIElement* _parent) :
  GUIElement{_title, _parent}, id{_id}
{

}

void MenuItem::paint()
{

}

void MenuItem::show()
{

}

void MenuItem::hide()
{

}

void MenuItem::addSubItem(const std::shared_ptr<MenuItem>& _subItem)
{
  subItems.push_back(_subItem);
}

/*=========================================================*/
Menu::Menu(std::string _title, GUIElement* _parent) :
  GUIElement{_title, _parent}
{

}

void Menu::paint()
{
  for (auto item : items)
  {
    item->paint();
  }
}

void Menu::show()
{
  visible = true;
  paint();
}

void Menu::hide()
{
  visible = false;
  paint();
}

void Menu::addItem(const std::shared_ptr<MenuItem>& _item)
{
  items.push_back(_item);
}


/*=========================================================*/
Button::Button(std::string _title, GUIElement* _parent) :
  GUIElement{_title, _parent}
{

}

void Button::paint()
{

}

void Button::show()
{
  visible = true;
  paint();
}

void Button::hide()
{
  visible = false;
  paint();
}
