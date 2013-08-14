#include "Vector2.h"
#include <math.h>

//Vector2 DOWN(1.0f, 0.0f);
//Vector2 LEFT(-1.0f, 0.0f);
//  = new Vector2(-1.0f, 0.0f);
//Vector2 UP    = new Vector2(0.0f, -1.0f);
//Vector2 DOWN  = new Vector2(1.0f, 0.0f);
//Vector2 RIGHT = new Vector2(1.0f, 0.0f);

const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);

const Vector2 Vector2::DOWN = Vector2(0.0f, 1.0f);
const Vector2 Vector2::UP   = Vector2(0.0f, -1.0f);

const Vector2 Vector2::LEFT  = Vector2(-1.0f, 0.0f);
const Vector2 Vector2::RIGHT = Vector2(1.0f, 0.0f);

const Vector2 Vector2::RIGHTUP = Vector2(1.0f, -1.0f);
const Vector2 Vector2::RIGHTDOWN = Vector2(1.0f, 1.0f);
const Vector2 Vector2::LEFTDOWN = Vector2(-1.0f, 1.0f);
const Vector2 Vector2::LEFTUP = Vector2(-1.0f, -1.0f);

bool Vector2::operator==(const Vector2& vector) const {
	return x == vector.x && y == vector.y;
}

bool Vector2::operator!=(const Vector2& vector) const {
	return x != vector.x || y != vector.y;
}

Vector2 Vector2::operator+(const Vector2& pVector) const {
	return Vector2(x + pVector.x, y + pVector.y);
}

Vector2 Vector2::operator-(const Vector2& pVector) const {
	return Vector2(x - pVector.x, y - pVector.y);
}

Vector2 Vector2::operator*(const float& num) const {
	return Vector2(x * num, y * num);
}

Vector2 Vector2::operator/(const float& num) const {
	return Vector2(x / num, y / num);
}

Vector2 Vector2::operator*(const Vector2& vector) const {
	return Vector2(x * vector.x, y * vector.y);
}

Vector2 Vector2::operator/(const Vector2& vector) const {
	return Vector2(x / vector.x, y / vector.y);
}

void Vector2::operator+=(const Vector2& pVector) {
	x += pVector.x;
	y += pVector.y;
}

void Vector2::operator-=(const Vector2& pVector) {
	x -= pVector.x;
	y -= pVector.y;
}

void Vector2::operator*=(const float& num) {
	x *= num;
	y *= num;
}

void Vector2::operator/=(const float& num) {
	x /= num;
	y /= num;
}

void Vector2::operator=(const Vector2& pVector) {
	x = pVector.x;
	y = pVector.y;
}

void Vector2::Normalize(const float& value) {
	float l = Length();

	if (l == 0)
		return;

	x = x / l * value;
	y = y / l * value;	
}

float Vector2::Length() const {
	return sqrt(pow(x, 2.0f) + pow(y, 2.0f));
}

void Vector2::Clamp(const float &value) {
	if(Length() <= value)
		return;
	Normalize();
	*this *= value;
}

void Vector2::Round() {
	x = round(x);
	y = round(y);
}
