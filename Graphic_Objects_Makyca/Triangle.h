#pragma once

class Point;
class Platno;

class Tri {
public:
	Tri(Point point1_, Point point2_, Point point3_);
	~Tri();
	void RenderTriangle(Platno& platno);
private:
	Point center;

	Point p1;
	Point p2;
	Point p3;
};