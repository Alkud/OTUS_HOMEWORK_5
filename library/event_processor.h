#pragma once

#include "events.h"
#include "shapes.h"
#include <deque>
#include <memory>

/// Receives events from the operating system,
/// manages events queue,
/// handles different GUI events
class EventProcessor
{
public:
  EventProcessor();
  ~EventProcessor();
  /// Get new events from operating system
  void getNextEvent();
  /// Process events in the queue
  void process();
  /// Exit flag triggered by user menu or keyboard action
  bool shouldExit{false};

private:
  /// Mouse event handler
  void onMouseEvent(MouseEvent* event);
  /// Keyboard event handler
  void onKeyboardEvent(KeyboardEvent* event);
  /// Menu event handler
  void onMenuEvent(MenuEvent* event);

  std::deque<std::shared_ptr<GUIEvent>> eventQueue;
};
