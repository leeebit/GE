#pragma once
#include "Elements.h"
class Square : public Elements {
private:
	sf::RectangleShape* squareShape;
	float side = 50.0;
public:
	Square(const sf::Vector2f& position);
	~Square();
	void drawElements(sf::RenderWindow& window)override;
	void moveElements(float offsetX, float offsetY) override;
	void resizeElements(float amount) override;
	void setfillColorFigure(const sf::Color& color) override;
	void setfillColorOutlineFigure(const sf::Color& color) override;
	sf::RectangleShape& getSquareShape();
	sf::FloatRect getBounds();
};

