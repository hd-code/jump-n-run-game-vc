#include "game/app.hpp"
#include <exception>
#include <iostream>

using namespace game;

// -----------------------------------------------------------------------------

int main() {
    try {
        App::getInstance().start(400, 300);
        App::getInstance().run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "unknown error" << std::endl;
    }

    try {
        App::getInstance().exit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "unknown error" << std::endl;
    }

    return 0;
}