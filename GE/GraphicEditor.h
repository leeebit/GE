#pragma once
#include "Presentation.h"
#include "Slide.h"
#include "Elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class GraphicEditor {
private:

	std::vector<Presentation*> presentations;
	int presentationCount;
	sf::RectangleShape colorRectangles[36];
	sf::Color colors[36] = {
	sf::Color::Black, sf::Color(128, 128, 128), sf::Color(192, 192, 192),
	sf::Color::White, sf::Color(255, 0, 255), sf::Color(128, 0, 128),
	sf::Color::Red, sf::Color(128, 0, 0), sf::Color::Yellow,
	sf::Color(128, 128, 0), sf::Color::Green, sf::Color(0, 128, 0),
	sf::Color(0, 255, 255), sf::Color(0, 128, 128), sf::Color::Blue,
	sf::Color(128, 128, 128), sf::Color(0, 0, 128), sf::Color(255, 192, 203),
	sf::Color(255, 69, 0), sf::Color(255, 160, 122), sf::Color(230, 230, 250),
	sf::Color(255, 248, 220), sf::Color(245, 255, 250), sf::Color(245, 245, 245),
	sf::Color(211, 211, 211), sf::Color(105, 105, 105), sf::Color(255, 228, 225),
	sf::Color(188, 148, 143), sf::Color(245, 222, 179), sf::Color(245, 245, 220),
	sf::Color(222, 184, 135), sf::Color(70, 130, 180), sf::Color(255, 250, 205),
	sf::Color(34, 139, 34), sf::Color(102, 205, 170), sf::Color(255, 215, 0)
	};
	int currentSlideIndex = 1;
	int chosenColorIndex = -1;
	bool isColorPickerActive = false;
	bool isCreateElementMenuActive = false;
	bool isChangeElementPropertiesMenuActive = false;
	bool isElementTypeChosen = false;
	ElementType chosenElementType;
	Elements* selectedElement = nullptr;

public:
	GraphicEditor();
	~GraphicEditor();
	// void DeletePresentation();
	void App(sf::RenderWindow& window);
	bool on_presentation_clicked();
	int getCurrentSlideIndex();
	void setCurrentSlideIndex(int a);
	void CreatePresentation();
	void handleMouseClickOnElement(sf::Vector2f mousePosition);
	//bool on_click_Button1();
};

