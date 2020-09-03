#include <vector>
#include <windows.h>
#include <iostream>
#include <string>

#include "Render.h"
#include "Triangle.h"
#include "Square.h"
#include "Menu.h"

void Menu::MainMenu() ////////////////////////// MAIN MENU
{
	system("cls");
	std::cout << "Main menu: " << std::endl;
	std::cout << "1. Render" << std::endl;
	std::cout << "2. Add object" << std::endl;
	std::cout << "3. Edit objects" << std::endl;
	std::cout << "0. Exit" << std::endl;

	int choice = 0;

	std::cin >> choice;

	switch (choice) {
	case 1:
		Render();
		break;
	case 2:
		AddObject();
		break;
	case 3:
		EditObjects();
		break;
	case 0:
		return;
		break;
	default:
		std::cout << "Wrong option!\n";
		system("pause");
		break;
	}
	MainMenu();
}
void Menu::Render() /////////////////////////////// RENDER
{
	system("cls");
	std::cout << "Render: " << std::endl;
	std::cout << "1. Render all" << std::endl;
	std::cout << "0. Back" << std::endl;

	auto choice = 0;
	std::cin >> choice;
	switch (choice)	{
	case 0:
		return;
		break;
	case 1:
		RenderObjects();
		break;
	default:
		std::cout << "Wrong option!" << std::endl;
		system("pause");
		break;
	}
	Render();
}

void Menu::RenderObjects() {
	system("cls");

	Platno platno;
	platno.angle = angle;
	platno.scale = scale;

	for (auto& ctverec : ctverce)
	{
		ctverec.RenderSquare(platno);
	}

	for (auto& trojuhelnik : trojuhelniky)
	{
		trojuhelnik.RenderTriangle(platno);
	}
	platno.Zobraz();
	system("pause");
}

void Menu::AddObject() { //////////////////////// ADD
	system("cls");
	std::cout << "Main menu: " << std::endl;
	std::cout << "1. Add square" << std::endl;
	std::cout << "2. Add triangle" << std::endl;
	std::cout << "0. Back" << std::endl;

	int choice = 0;
	std::cin >> choice;

	switch (choice) {
	case 1:
		AddSquare();
		break;
	case 2:
		AddTriangle();
		break;
	case 0:
		return;
	default:
		std::cout << "Wrong option!\n";
		system("pause");
		break;
	}
	AddObject();
}

void Menu::AddTriangle()
{
	Point p1, p2, p3;
	system("cls");
	std::cout << "Set triangle points: " << std::endl;
	std::cout << "\n" << "Point x1: ";
	std::cin >> p1.x;
	std::cout << "\n" << "Point y1: ";
	std::cin >> p1.y;
	std::cout << "\n" << "Point x2: ";
	std::cin >> p2.x;
	std::cout << "\n" << "Point y2: ";
	std::cin >> p2.y;
	std::cout << "\n" << "Point x3: ";
	std::cin >> p3.x;
	std::cout << "\n" << "Point y3: ";
	std::cin >> p3.y;

	trojuhelniky.emplace_back(p1, p2, p3);

}
void Menu::AddSquare()
{
	Point center(0, 0);
	float side_length;

	system("cls");
	std::cout << "Set square points: " << std::endl;
	std::cout << "\n" << "Center X: ";
	std::cin >> center.x;
	std::cout << "\n" << "Center Y: ";
	std::cin >> center.y;
	std::cout << "\n" << "Side length: ";
	std::cin >> side_length;

	ctverce.emplace_back(center, side_length);

}

void Menu::EditObjects() ///////////////////////// EDIT
{
	system("cls");
	std::cout << "Edit: " << std::endl;
	std::cout << "1. Rotation" << std::endl;
	std::cout << "2. Scale" << std::endl;
	std::cout << "0. Back" << std::endl;

	auto choice = 0;
	std::cin >> choice;
	switch (choice)	{
	case 0:
		return;
		break;
	case 1:
		RotateObjects();
		break;
	case 2:
		ScaleObjects();
		break;
	default:
		std::cout << "Wrong option!" << std::endl;
		system("pause");
		break;
	}
	EditObjects();
}

void Menu::RotateObjects() {
	system("cls");
	std::cout << "Rotate objects: " << std::endl;
	std::cout << "Angle: ";
	std::cin >> angle;
}

void Menu::ScaleObjects()
{
	system("cls");
	std::cout << "Resize objects: " << std::endl;
	std::cout << "Scale: ";
	std::cin >> scale;
}

