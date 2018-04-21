#include "./library/gui_elements.h"
#include "./library/event_processor.h"


int main()
{
  std::shared_ptr<Window> mainWindow{std::make_shared<Window>("Vector editor", nullptr)};
  std::shared_ptr<Menu> mainMenu{std::make_shared<Menu>("Vector editor", mainWindow.get())};
  /* Add main menu items */


  EventProcessor eventProcessor{};

  /* Event loop */
  while(true)
  {
    eventProcessor.getNextEvent();
    eventProcessor.process();
    if (eventProcessor.shouldExit)
    {
      /* 'Quit' menu item selected or 'Alt +F4' pressed */
      break;
    }
  }

  return 0;
}
