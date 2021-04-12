/* #include "gfx/main-menu-phase.hpp"

#include "gfx/asset-system.hpp"
#include "gui/main-menu-phase.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

MainMenuPhase::MainMenuPhase() : window(nullptr) {}
MainMenuPhase::~MainMenuPhase() {}

// -----------------------------------------------------------------------------

void MainMenuPhase::onEnter(sf::RenderWindow &window) {
    // this->window = &window;

    // sf::Font font = AssetSystem::getInstance().getFont();
    // labels[0].setFont(font);
    // labels[0].setCharacterSize(24);
    // labels[1].setFont(font);
    // labels[1].setCharacterSize(24);
}

void MainMenuPhase::onLeave() { this->window = nullptr; }

// -----------------------------------------------------------------------------

void MainMenuPhase::render() {
    window->clear();

    int selected = gui::MainMenuPhase::getInstance().getSelectedLabel();
    for (auto i = 0; i < 2; ++i) {
        if (i == selected) {
            labels[i].setStyle(sf::Text::Bold);
        } else {
            labels[i].setStyle(sf::Text::Regular);
        }

        window->draw(labels[i]);
    }

    window->display();
} */