#pragma once

namespace core {

template <class T> class Singleton {
  public:
    static T &getInstance() {
        static T instance;
        return instance;
    }

  protected:
    Singleton() = default;
    ~Singleton() = default;

  private:
    Singleton(const T &original) = delete;    // is not implemented
    T &operator=(const T &original) = delete; // is not implemented
};

} // namespace core