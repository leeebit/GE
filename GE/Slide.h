#pragma once
#include "Elements.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "ImageElement.h"
#include "libtinyfiledialogs-master/tinyfiledialogs.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum ElementType {
    CIRCLE = 0,
    SQUARE = 1,
    TRIANGLE = 2,
    IMAGE = 3
};

class Slide
{
private:
    std::vector<Elements*> elements;
    sf::RectangleShape background;
    int elementType;
    Elements* currentElement;
    int chosenColorIndexElement = -1;

public:
    Slide();
    ~Slide();
    void createElements(const sf::Vector2f& clickPosition);
    void SetBackgroundColor(const sf::Color& color);
    int getElementType() const;
    int getChosenColorIndexElement();
    void setChosenColorIndexElement(int index);
    void setElementType(int type);
    std::vector<Elements*>& getElements();
    void setCurrentElement(Elements* element);
    Elements* getCurrentElement();
    int getElementCount();
    sf::RectangleShape& getBackground();
    void Draw(sf::RenderWindow& window);
};
