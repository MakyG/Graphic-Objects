#include <cmath>
#include "Render.h"
#include "Triangle.h"

Tri::Tri(Point point1_, Point point2_, Point point3_) {
	Point center;
	p1 = point1_;
	p2 = point2_;
	p3 = point3_;

	center.x = (p1.x + p2.x + p3.x) / 3;
	center.y = (p1.y + p2.y + p3.y) / 3;

}

Tri::~Tri() { }

void Tri::RenderTriangle(Platno& platno)
{
	Point pt1 = p1;
	Point pt2 = p2;
	Point pt3 = p3;
	
	pt1 = platno.Rotation(center, platno.angle, pt1);
	pt2 = platno.Rotation(center, platno.angle, pt2);
	pt3 = platno.Rotation(center, platno.angle, pt3);

	pt1 = platno.Scale(pt1, center, platno.scale);
	pt2 = platno.Scale(pt2, center, platno.scale);
	pt3 = platno.Scale(pt3, center, platno.scale);

	platno.nakresliUsecku(pt1, pt2);
	platno.nakresliUsecku(pt2, pt3);
	platno.nakresliUsecku(pt3, pt1);
}






