#pragma once

namespace core {

class Vector2 {
  public:
    Vector2();
    Vector2(const Vector2 &other);
    Vector2(float x, float y);

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

  private:
    float x_, y_;
};

} // namespace core