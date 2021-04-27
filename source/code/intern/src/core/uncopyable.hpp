#pragma once

namespace core {

class Uncopyable {
  protected:
    Uncopyable() = default;
    ~Uncopyable() = default;

  private:
    Uncopyable(const Uncopyable &) = delete;            // is not implemented
    Uncopyable &operator=(const Uncopyable &) = delete; // is not implemented
};

} // namespace core