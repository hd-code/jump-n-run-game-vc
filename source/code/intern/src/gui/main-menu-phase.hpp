#pragma once

#include "core/singleton.hpp"
#include "data/event-listener.hpp"

namespace gui {

struct SelectedLabel {
    typedef enum {
        BeginGame,
        Exit,
        Length,
    } Enum;
};

class MainMenuPhase : public core::Singleton<MainMenuPhase>,
                      public data::EventListener {
  public:
    void onEnter();
    void onLeave();

    void onEvent(const data::Event &event);

    SelectedLabel::Enum getSelectedLabel() const;
    bool beginGame() const;
    bool exit() const;

  private:
    template <class T> friend class core::Singleton;
    MainMenuPhase();
    ~MainMenuPhase();

    SelectedLabel::Enum selectedLabel_;

    bool escapePressed_;
    bool enterPressed_;
};

} // namespace gui