#pragma once
#include <cmath>

class Point {
public:
	float x;
	float y;
	Point();
	Point(float x_, float y_);
};

class Platno {
private:
	const int pocetRadku = 28;
	const int pocetSloupcu = 56;

	char platno[28][56];
public:
	Platno() {
		Vymaz();
	}
	void Vymaz();
	void Zobraz();
	void nakresliZnak(char znak, float x, float y);
	void nakresliUsecku(const Point& p1, const Point& p2);
	Point Rotation(Point center, float angle, Point point);
	Point Scale(Point pos, Point center, float scale);
	float angle;
	float scale;
};