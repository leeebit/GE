#pragma once
#include "Elements.h"

class Circle : public Elements {
private:
	sf::CircleShape* circleShape;
	//sf::RectangleShape* squareShape;
public:
	Circle(const sf::Vector2f& position);
	~Circle();
	void drawElements(sf::RenderWindow& window) override;
	void moveElements(float offsetX, float offsetY)override;
	void resizeElements(float amount) override;
	void setfillColorFigure(const sf::Color& color) override;
	void setfillColorOutlineFigure(const sf::Color& color) override;
	void getfillColorFigure(const sf::Color& color);
	void getfillColorOutlineFigure(const sf::Color& color);
	sf::CircleShape& getCircleShape();	
	sf::FloatRect getBounds();

};

