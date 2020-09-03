#pragma once

class Point;
class Platno;

class Square {
public:
	Square(Point& center_, float side_length);
	~Square();
	void RenderSquare(Platno& platno);
private:
	Point center;
	float side_length;

	Point x1y1;
	Point x1y2;
	Point x2y1;
	Point x2y2;
};