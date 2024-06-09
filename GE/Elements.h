#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Elements
{
public:
	virtual void drawElements(sf::RenderWindow& window);
	virtual void moveElements(float offsetX, float offsetY) = 0;
	virtual void resizeElements(float amount)=0;
	virtual void setfillColorFigure(const sf::Color& color);
	virtual void setfillColorOutlineFigure(const sf::Color& color);
	virtual sf::FloatRect getBounds();
};

