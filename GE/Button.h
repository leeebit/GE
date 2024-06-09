#pragma once
#include <SFML/Graphics.hpp>

class GraphicEditor;

typedef bool (GraphicEditor::*Action)();

class Button
{
private:
	GraphicEditor* _instance;
public:
	sf::IntRect rect;
	sf::RectangleShape rect_shape;
	sf::Color color;
	Action click ;

	Button(sf::IntRect r, sf::Color c, Action& function, GraphicEditor& instance);

	bool isClicked(sf::Vector2i mouse);
	void setOnClick(Action on_click_action);
	bool Click();

	void draw(sf::RenderWindow& window);

};

