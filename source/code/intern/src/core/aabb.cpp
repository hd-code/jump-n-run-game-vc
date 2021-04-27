#include "core/aabb.hpp"
#include <assert.h>

using namespace core;

// -----------------------------------------------------------------------------

AABB::AABB() : min_(Vector2()), max_(Vector2()) {}

AABB::AABB(const AABB &other) : min_(other.min_), max_(other.max_) {}

AABB::AABB(const Vector2 &min, const Vector2 &max) : min_(min), max_(max) {}

AABB::AABB(float minX, float minY, float maxX, float maxY)
    : min_(Vector2(minX, minY)), max_(Vector2(maxX, maxY)) {}

// -----------------------------------------------------------------------------

bool AABB::isValid() const {
    return min_.getX() <= max_.getX() && min_.getY() <= max_.getY();
}

// -----------------------------------------------------------------------------

Vector2 &AABB::getMin() { return min_; }

const Vector2 &AABB::getMin() const { return min_; }

// -----------------------------------------------------------------------------

void AABB::setMin(const Vector2 &min) {
    min_.setX(min.getX());
    min_.setY(min.getY());
}

void AABB::setMin(float x, float y) {
    min_.setX(x);
    min_.setY(y);
}

// -----------------------------------------------------------------------------

Vector2 &AABB::getMax() { return max_; }

const Vector2 &AABB::getMax() const { return max_; }

// -----------------------------------------------------------------------------

void AABB::setMax(const Vector2 &max) {
    max_.setX(max.getX());
    max_.setY(max.getY());
}

void AABB::setMax(float x, float y) {
    max_.setX(x);
    max_.setY(y);
}

// -----------------------------------------------------------------------------

Vector2 AABB::getCenter() const {
    auto x = (min_.getX() + max_.getX()) / 2.0f;
    auto y = (min_.getY() + max_.getY()) / 2.0f;
    return Vector2(x, y);
}

// -----------------------------------------------------------------------------

bool AABB::contains(const Vector2 &position) const {
    assert(isValid());

    return min_.getX() <= position.getX() && max_.getX() >= position.getX() &&
           min_.getY() <= position.getY() && max_.getY() >= position.getY();
}

bool AABB::contains(const AABB &other) const {
    assert(isValid());
    assert(other.isValid());

    return min_.getX() <= other.min_.getX() &&
           max_.getX() >= other.max_.getX() &&
           min_.getY() <= other.min_.getY() && max_.getY() >= other.max_.getY();
}

bool AABB::intersects(const AABB &other) const {
    assert(isValid());
    assert(other.isValid());

    return !(
        min_.getX() > other.max_.getX() || max_.getX() < other.min_.getX() ||
        min_.getY() > other.max_.getY() || max_.getY() < other.min_.getY());
}