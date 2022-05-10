#pragma once

struct Vector2D_t {
  int x, y;

  Vector2D_t() = default;
  Vector2D_t(int _x, int _y) : x(_x), y(_y) {}
};

inline Vector2D_t operator+ (const Vector2D_t &left, const Vector2D_t &right) {
  return Vector2D_t { left.x + right.x, left.y + right.y };
}

inline Vector2D_t operator- (const Vector2D_t &left, const Vector2D_t &right) {
  return Vector2D_t { left.x - right.x, left.y - right.y };
}

inline Vector2D_t operator* (const Vector2D_t &left, const int &right) {
  return Vector2D_t { left.x * right, left.y * right };
}

inline Vector2D_t operator* (const int &left, const Vector2D_t &right) {
  return right * left;
}

inline bool operator== (const Vector2D_t &left, const Vector2D_t &right) {
  return (left.x == right.x) && (left.y == right.y);
}

inline bool operator!= (const Vector2D_t &left, const Vector2D_t &right) {
  return !(left == right);
}

