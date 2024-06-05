#pragma once
#include "Elements.h"
#include <SFML/Graphics.hpp>
#include <string>

class ImageElement : public Elements
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    ImageElement(const sf::Vector2f& position);
    ~ImageElement();
    bool loadFromFile(const std::string& filename);
    void drawElements(sf::RenderWindow& window) override;
    void moveElements(float offsetX, float offsetY) override;
    void resizeElements(float amount) override;
    void crop(const sf::IntRect& rect);
    sf::FloatRect getBounds();
};
