#include "events.h"

GUIEvent::GUIEvent(GUIElement* _sender, EventType _type) :
  sender{_sender}, type{_type}
{

}


MouseEvent::MouseEvent(GUIElement* _sender, int _posX, int _posY) :
  GUIEvent{_sender, EventType::ET_MOUSE}, posX{_posX}, posY{_posY}
{

}


KeyboardEvent::KeyboardEvent(GUIElement* _sender, int _keyCode) :
  GUIEvent{_sender, EventType::ET_KEYBOARD}, keyCode{_keyCode}
{

}


MenuEvent::MenuEvent(GUIElement* _sender, int _itemID) :
  GUIEvent{_sender, EventType::ET_MENU}, itemID{_itemID}
{

}
