#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include "Render.h"


void Platno::Vymaz()
{
	for (size_t i = 0; i < pocetRadku; i++) {
		for (size_t j = 0; j < pocetSloupcu; j++) {
			platno[i][j] = '-';
		}
	}
}

void Platno::Zobraz()
{
	
	for (size_t i = 0; i < pocetRadku; i++) {
		for (size_t j = 0; j < pocetSloupcu; j++) {
			char znak = platno[pocetRadku - 1 - i][j];
			putchar(znak);
			putchar(' ');
		}
		putchar('\n');
	}
}

void Platno::nakresliZnak(char znak, float x, float y)
{
	unsigned int ix = (int)std::round(x);
	unsigned int iy = (int)std::round(y);

	if (ix >= pocetRadku || iy >= pocetSloupcu)
		return;

	platno[iy][ix] = znak;
}

void Platno::nakresliUsecku(const Point& p1, const Point& p2)
{
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;

	float d = std::fmaxf(std::abs(dx), std::abs(dy));

	dx /= d;
	dy /= d;

	float x = p1.x;
	float y = p1.y;

	for (unsigned int i = 0; i <= d; i++) {
		nakresliZnak('#', x, y);

		x += dx;
		y += dy;
	}
}

Point Platno::Rotation(Point center, float angle, Point point)
{
	angle *= M_PI / 180.f;

	point.x -= center.x;
	point.y -= center.y;
	
	float xt = point.x * std::cos(angle) - point.y * sin(angle);
	float yt = point.x * std::sin(angle) + point.y * cos(angle);

	point.x = xt + center.x;
	point.y = yt + center.y;

	return point;
}

Point Platno::Scale(Point point, Point center, float scale) {
	
	point.x -= center.x;
	point.y -= center.y;

	point.x = (float)point.x * scale;
	point.y = (float)point.y * scale;

	point.x = point.x + center.x;
	point.y = point.y + center.y;

	return point;
}

Point::Point() : x(0), y(0) {

}

Point::Point(float x_, float y_) : x(x_), y(y_) {

}

