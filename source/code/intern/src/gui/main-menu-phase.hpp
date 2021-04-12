#pragma once

#include "core/singleton.hpp"
#include "data/event-listener.hpp"
#include "data/event.hpp"

namespace gui {

class MainMenuPhase : public core::Singleton<MainMenuPhase>,
                      public data::EventListener {

public:
    int getSelectedLabel() const;

    void onEnter();
    void onLeave();
    int onRun();

    void onEvent(data::Event &event);

private:
    template <class T> friend class core::Singleton;
    MainMenuPhase();
    ~MainMenuPhase();

    int selectedLabel;

    bool arrowUpPressed;
    bool arrowDownPressed;
};

} // namespace gui