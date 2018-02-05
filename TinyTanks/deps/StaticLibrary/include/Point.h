#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
	Point();
	Point(float a_x, float a_y);
	void Set(float a_x, float a_y);
	void Get(float& a_x, float& a_y);
	void SetX(float a_x);
	float GetX();
	void SetY(float a_y);
	float GetY();

	//Operators
	operator float*();
	operator const float*() const;
	//+
	Point operator+(const Point& arg);
	Point operator+(const float& scalar) const;
	friend Point operator+(const float& scalar, const Point& a_v1);
	//-
	Point operator-(const Point& arg);
	Point operator-(const float& scalar) const;
	friend Point operator-(const float& scalar, const Point& a_v1);
	//*
	Point operator*(const Point& arg);
	Point operator*(const float& scalar) const;
	friend Point operator*(const float& scalar, const Point& a_v1);
	// /
	Point operator/(const Point& arg);
	Point operator/(const float& scalar) const;
	friend Point operator/(const float& scalar, const Point& a_v1);
	//Other
	bool operator!=(const Point& arg) const;
	bool operator==(const Point& arg) const;

private:
	float x;
	float y;
};

#endif _POINT_H_
