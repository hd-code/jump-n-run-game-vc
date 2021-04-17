#include "core/aabb.hpp"
#include "core/vector2.hpp"
#include <assert.h>

using namespace core;

// -----------------------------------------------------------------------------

AABB::AABB() : minX_(0.0f), minY_(0.0f), maxX_(0.0f), maxY_(0.0f) {}

AABB::AABB(const AABB &other) {
    minX_ = other.minX_;
    minY_ = other.minY_;
    maxX_ = other.maxX_;
    maxY_ = other.maxY_;
}

AABB::AABB(const Vector2 &min, const Vector2 &max) {
    setMin(min);
    setMax(max);
}

AABB::AABB(float minX, float minY, float maxX, float maxY)
    : minX_(minX), minY_(minY), maxX_(maxX), maxY_(maxY) {}

// -----------------------------------------------------------------------------

bool AABB::isValid() const { return minX_ <= maxX_ && minY_ <= maxY_; }

// -----------------------------------------------------------------------------

Vector2 AABB::getMin() const { return Vector2(minX_, minY_); }

void AABB::setMin(const Vector2 &min) {
    minX_ = min.getX();
    minY_ = min.getY();
}

// -----------------------------------------------------------------------------

Vector2 AABB::getMax() const { return Vector2(maxX_, maxY_); }

void AABB::setMax(const Vector2 &max) {
    maxX_ = max.getX();
    maxY_ = max.getY();
}

// -----------------------------------------------------------------------------

bool AABB::contains(const Vector2 &position) const {
    assert(isValid());

    return minX_ <= position.getX() && maxX_ >= position.getX() &&
           minY_ <= position.getY() && maxY_ >= position.getY();
}

bool AABB::contains(const AABB &other) const {
    assert(isValid());
    assert(other.isValid());

    return minX_ <= other.minX_ && maxX_ >= other.maxX_ &&
           minY_ <= other.minY_ && maxY_ >= other.maxY_;
}

bool AABB::intersects(const AABB &other) const {
    assert(isValid());
    assert(other.isValid());

    return !(minX_ > other.maxX_ || maxX_ < other.minX_ ||
             minY_ > other.maxY_ || maxY_ < other.minY_);
}