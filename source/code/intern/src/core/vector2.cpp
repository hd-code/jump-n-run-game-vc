#include "core/vector2.hpp"

using namespace core;

// -----------------------------------------------------------------------------

Vector2::Vector2() : x_(0.0f), y_(0.0f) {}
Vector2::Vector2(const Vector2 &other) : x_(other.x_), y_(other.y_) {}
Vector2::Vector2(float x, float y) : x_(x), y_(y) {}

// -----------------------------------------------------------------------------

float Vector2::getX() const { return x_; }
void Vector2::setX(float x) { x_ = x; }

// -----------------------------------------------------------------------------

float Vector2::getY() const { return y_; }
void Vector2::setY(float y) { y_ = y; }