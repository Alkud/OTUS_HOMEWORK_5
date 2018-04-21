#pragma once
#include "gui_elements.h"
#include <vector>

enum class EventType
{
  ET_MOUSE,
  ET_KEYBOARD,
  ET_MENU
};

enum class MouseEventDetail
{
  LeftButtonDown,
  LeftButtonUp,
  RightButtonDown,
  RightButtonUp,
  Move
};

enum class KeyboardEventDetail
{
  KeyDown,
  KeyUp
};


/// Abstract GUI Event
class GUIEvent
{
public:
  GUIEvent() = delete;
  GUIEvent(GUIElement* _sender, EventType _type);
  virtual ~GUIEvent() = default;

  /// GUI element that triggered the event
  GUIElement* sender;
  EventType type;
};

/// Basic mouse event
class MouseEvent : public GUIEvent
{
public:
  MouseEvent() = delete;
  MouseEvent(GUIElement* _sender, int _posX, int _posY);
  ~MouseEvent() = default;

  /// Cursor position X cordinate relative to sender position
  int posX;
  /// Cursor position Y cordinate relative to sender position
  int posY;
  /// Event detail combination, describing the event
  std::vector<MouseEventDetail> description;
};

/// Basic keyboard event
class KeyboardEvent : public GUIEvent
{
public:
  KeyboardEvent() = delete;
  KeyboardEvent(GUIElement* _sender, int _keyCode);
  ~KeyboardEvent() = default;

  /// Unicode character corresponding to the pressed key
  int keyCode;
  /// Event details
  KeyboardEventDetail description;
};

/// Basic menu event
class MenuEvent : public GUIEvent
{
public:
  MenuEvent() = delete;
  MenuEvent(GUIElement* _sender, int _itemID);
  ~MenuEvent() = default;

  /// Selected menu item ID
  int itemID;
};
