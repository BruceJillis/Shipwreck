#ifndef VECTOR2_H_
#define VECTOR2_H_

class Vector2 {
	public:
		float x, y;
		
		Vector2() {
			x = 0.0f;
			y = 0.0f;
		}
		
		Vector2(float _x, float _y) {
			x = _x;
			y = _y;
		}
				
		Vector2 operator+(const Vector2& pVector) const;
		Vector2 operator-(const Vector2& pVector) const;
		Vector2 operator*(const float& num) const;
		Vector2 operator/(const float& num) const;
		Vector2 operator*(const Vector2& vector) const;
		Vector2 operator/(const Vector2& vector) const;
		
		void operator+=(const Vector2& pVector);
		void operator-=(const Vector2& pVector);
		void operator*=(const float& num);
		void operator/=(const float& num);
		void operator=(const Vector2& pVector);
		bool operator==(const Vector2& vector) const;
	    bool operator!=(const Vector2& vector) const;
	
		void Normalize(const float& value = 1.0f);
		float Length() const;
		void Clamp(const float &value);
		void Round();
		
		static const Vector2 ZERO;
		
		static const Vector2 DOWN;
		static const Vector2 UP;
		static const Vector2 LEFT;
		static const Vector2 RIGHT;
		
		static const Vector2 RIGHTUP;
		static const Vector2 RIGHTDOWN;
		static const Vector2 LEFTDOWN;
		static const Vector2 LEFTUP;

};

#endif
