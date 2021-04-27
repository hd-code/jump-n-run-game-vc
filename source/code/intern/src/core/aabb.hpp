#pragma once

#include "core/vector2.hpp"

// -----------------------------------------------------------------------------

namespace core {

class AABB {
  public:
    AABB();
    AABB(const AABB &other);
    AABB(const Vector2 &min, const Vector2 &max);
    AABB(float minX, float minY, float maxX, float maxY);

    bool isValid() const;

    Vector2 &getMin();
    const Vector2 &getMin() const;

    void setMin(const Vector2 &min);
    void setMin(float x, float y);

    Vector2 &getMax();
    const Vector2 &getMax() const;

    void setMax(const Vector2 &max);
    void setMax(float x, float y);

    Vector2 getCenter() const;

    bool contains(const Vector2 &position) const;
    bool contains(const AABB &other) const;
    bool intersects(const AABB &other) const;

  private:
    Vector2 min_, max_;
};

} // namespace core