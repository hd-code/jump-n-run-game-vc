#pragma once

#include "core/event-listener.hpp"
#include "core/event.hpp"
#include "core/singleton.hpp"

namespace gui {

class MainMenuPhase : public core::Singleton<MainMenuPhase>,
                      public core::EventListener {

  public:
    int getSelectedLabel() const;

    void onEnter();
    void onLeave();
    int onRun();

    void onEvent(core::Event &event);

  private:
    template <class T> friend class core::Singleton;
    MainMenuPhase();
    ~MainMenuPhase();

    int selectedLabel;

    bool arrowUpPressed;
    bool arrowDownPressed;
};

} // namespace gui