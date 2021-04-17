#pragma once

// -----------------------------------------------------------------------------

namespace core {

class Vector2;

class AABB {
  public:
    AABB();
    AABB(const AABB &other);
    AABB(const Vector2 &min, const Vector2 &max);
    AABB(float minX, float minY, float maxX, float maxY);

    bool isValid() const;

    Vector2 getMin() const;
    void setMin(const Vector2 &min);

    Vector2 getMax() const;
    void setMax(const Vector2 &max);

    bool contains(const Vector2 &position) const;
    bool contains(const AABB &other) const;
    bool intersects(const AABB &other) const;

  private:
    float minX_, minY_, maxX_, maxY_;
};

} // namespace core