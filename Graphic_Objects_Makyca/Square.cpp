#include <cmath>
#include "Render.h"
#include "Square.h"

Square::Square(Point& center_, float side_length) {
	this->center = center_;
	
	this->side_length = side_length;
	float sd = side_length / 2;

	float x1 = center.x - sd;
	float y1 = center.y - sd;
	float x2 = center.x + sd;
	float y2 = center.y + sd;
	
	x1y1 = Point(x1, y1);
	x1y2 = Point(x1, y2);
	x2y1 = Point(x2, y1);
	x2y2 = Point(x2, y2);
}

Square::~Square() {

}

void Square::RenderSquare(Platno& platno)
{

	Point pt1 = x1y1;
	Point pt2 = x1y2;
	Point pt3 = x2y1;
	Point pt4 = x2y2;

	pt1 = platno.Rotation(center, platno.angle, pt1);
	pt2 = platno.Rotation(center, platno.angle, pt2);
	pt3 = platno.Rotation(center, platno.angle, pt3);
	pt4 = platno.Rotation(center, platno.angle, pt4);

	pt1 = platno.Scale(pt1, center, platno.scale);
	pt2 = platno.Scale(pt2, center, platno.scale);
	pt3 = platno.Scale(pt3, center, platno.scale);
	pt4 = platno.Scale(pt4, center, platno.scale);

	platno.nakresliUsecku(pt1, pt2);
	platno.nakresliUsecku(pt2, pt4);
	platno.nakresliUsecku(pt4, pt3);
	platno.nakresliUsecku(pt3, pt1);
}




