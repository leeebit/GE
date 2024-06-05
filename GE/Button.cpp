//#include "Button.h"
//
//Button::Button(sf::IntRect r, sf::Color c, Action on_click_action) :
//    rect(r), color(c), click(on_click_action)
//{
//    rect_shape.setFillColor(color);
//    rect_shape.setPosition(sf::Vector2f(rect.left, rect.top));
//    rect_shape.setSize(sf::Vector2f(rect.width, rect.height));
//}
//
//bool Button::isClicked(sf::Vector2i mouse)
//{
//    return rect.contains(mouse);
//}
//
//void Button::setOnClick(function a)
//{
//    click = a;
//}
//
//bool Button::Click()
//{
//    return click();
//}
//
//void Button::draw(sf::RenderWindow& window)
//{
//    window.draw(rect_shape);
//}
