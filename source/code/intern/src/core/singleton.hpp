#pragma once

#include "core/uncopyable.hpp"

namespace core {

template <class T> class Singleton : private Uncopyable {
  public:
    static T &getInstance() {
        static T instance;
        return instance;
    }
};

} // namespace core