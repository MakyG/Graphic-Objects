#pragma once

class Square;
class Tri;

class Menu {
public:
	void MainMenu();
private:
	void Render();
	void RenderObjects();
	void AddObject();
	void EditObjects();
	void RotateObjects();
	void ScaleObjects();
	void AddTriangle();
	void AddSquare();

	std::vector<Square> ctverce;
	std::vector<Tri> trojuhelniky;
	float angle;
	float scale = 1.0f;
};