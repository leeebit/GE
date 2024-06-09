#include "Button.h"
#include "GraphicEditor.h"

Button::Button(sf::IntRect r, sf::Color c, Action& function, GraphicEditor& instance) :
    rect(r), color(c)
{
    _instance = &instance;
    setOnClick(function);
    rect_shape.setFillColor(color);
    rect_shape.setPosition(sf::Vector2f(rect.left, rect.top));
    rect_shape.setSize(sf::Vector2f(rect.width, rect.height));
    std::cout << "Right now function is " << function << "\n";
    std::cout << "Right now function is " << click << "\n";
}

bool Button::isClicked(sf::Vector2i mouse)
{
    return rect.contains(mouse);
}

void Button::setOnClick(Action a)
{
    click = a;
}

bool Button::Click()
{
    std::cout << "click ";
    std::cout << &(*_instance) << std::endl;
    return (_instance->*click)();
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(rect_shape);
}
