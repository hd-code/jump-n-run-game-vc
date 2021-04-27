#include "gfx/main-menu-phase.hpp"
#include "core/config.hpp"
#include "gui/main-menu-phase.hpp"
#include <assert.h>

using namespace gfx;

// -----------------------------------------------------------------------------

MainMenuPhase::MainMenuPhase() : window_(nullptr) {}

MainMenuPhase::~MainMenuPhase() {}

// -----------------------------------------------------------------------------

void MainMenuPhase::onEnter(sf::RenderWindow &window) {
    window_ = &window;

    std::string filepath;

    filepath = core::Config::screensDir + "menu-begin.png";
    assert(textures_[gui::SelectedLabel::BeginGame].loadFromFile(filepath));
    screens_[gui::SelectedLabel::BeginGame].setTexture(
        textures_[gui::SelectedLabel::BeginGame]);

    filepath = core::Config::screensDir + "menu-exit.png";
    assert(textures_[gui::SelectedLabel::Exit].loadFromFile(filepath));
    screens_[gui::SelectedLabel::Exit].setTexture(
        textures_[gui::SelectedLabel::Exit]);
}

void MainMenuPhase::onLeave() {}

// -----------------------------------------------------------------------------

void MainMenuPhase::render() {
    window_->clear();
    auto label = gui::MainMenuPhase::getInstance().getSelectedLabel();
    window_->draw(screens_[label]);
    window_->display();
}