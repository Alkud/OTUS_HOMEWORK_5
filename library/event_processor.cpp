#include "event_processor.h"

EventProcessor::EventProcessor()
{

}

EventProcessor::~EventProcessor()
{

}

void EventProcessor::getNextEvent()
{
  /* wait for a new event from the operating sysytem*/

  /* determinr event source */
  GUIElement* sender{};

  /* determine its type */
  EventType type{};

  if (EventType::ET_MOUSE == type)
  {
    /* in case of a mouse event determine cursor position*/
    int posX{};
    int posY{};
    eventQueue.push_back(std::make_shared<MouseEvent>(sender, posX, posY));
    return;
  }
  else if (EventType::ET_KEYBOARD == type)
  {
    /* in case of a keyboard event get the pressed key code */
    int keyCode{};
    eventQueue.push_back(std::make_shared<KeyboardEvent>(sender, keyCode));
    return;
  }
  else if (EventType::ET_MENU == type)
  {
    /* in case of a menu event get the selected item ID */
    int itemID{};
    eventQueue.push_back(std::make_shared<MenuEvent>(sender, itemID));
    return;
  }
}

void EventProcessor::onMouseEvent(MouseEvent* event)
{

}

void EventProcessor::onKeyboardEvent(KeyboardEvent* event)
{

}

void EventProcessor::onMenuEvent(MenuEvent* event)
{

}

void EventProcessor::process()
{
  GUIEvent* event{eventQueue.front().get()};
  switch(event->type)
  {
  case EventType::ET_KEYBOARD:
    onKeyboardEvent(dynamic_cast<KeyboardEvent*>(event));
    break;
  case EventType::ET_MOUSE:
    onMouseEvent(dynamic_cast<MouseEvent*>(event));
    break;
  case EventType::ET_MENU:
    onMenuEvent(dynamic_cast<MenuEvent*>(event));
    break;
  }
  eventQueue.pop_front();
}
