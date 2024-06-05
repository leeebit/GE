#pragma once
#include "Elements.h"
#include <SFML/Graphics.hpp>

class Triangle : public Elements {
private:
    sf::ConvexShape triangleShape;

public:
    Triangle(const sf::Vector2f& position, float baseLength = 50.f, float height = 50.f); 
    ~Triangle();
    void drawElements(sf::RenderWindow& window) override;
    void moveElements(float offsetX, float offsetY) override;
    void resizeElements(float amount) override;
    void setfillColorFigure(const sf::Color& color);
    void setfillColorOutlineFigure(const sf::Color& color);
    //void getfillColorFigure(const sf::Color& color);
    //void getfillColorOutlineFigure(const sf::Color& color);
    sf::ConvexShape& getTriangleShape();
    sf::FloatRect getBounds();
};
