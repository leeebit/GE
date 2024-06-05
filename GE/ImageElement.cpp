#include "ImageElement.h"

ImageElement::ImageElement(const sf::Vector2f& position) {

    sprite.setPosition(position);
}

ImageElement::~ImageElement() {}

bool ImageElement::loadFromFile(const std::string& filename) {
    if (!texture.loadFromFile(filename)) {
        return false;
    }
    sprite.setTexture(texture);
    return true;
}

void ImageElement::drawElements(sf::RenderWindow& window) {
    window.draw(sprite);
}

void ImageElement::moveElements(float offsetX, float offsetY) {
    sf::Vector2f currentPos = sprite.getPosition();

    currentPos.x += offsetX;
    currentPos.y += offsetY;

    if (currentPos.x < 100) {
        currentPos.x = 100;
    }
    else if (currentPos.x + sprite.getGlobalBounds().width > 900) {
        currentPos.x = 900 - sprite.getGlobalBounds().width;
    }

    if (currentPos.y < 125) {
        currentPos.y = 125;
    }
    else if (currentPos.y + sprite.getGlobalBounds().height > 575) {
        currentPos.y = 575 - sprite.getGlobalBounds().height;
    }

    sprite.setPosition(currentPos);
}

void ImageElement::resizeElements(float amount) {
    sf::Vector2f scale = sprite.getScale();

    // Make the resizing more gradual by reducing the scaling factor
    float scaleFactor = 0.05f;
    float newScaleX = scale.x + amount * scaleFactor;
    float newScaleY = scale.y + amount * scaleFactor;

    // Limit the scale to a minimum and maximum value
    newScaleX = std::max(0.1f, std::min(3.0f, newScaleX));
    newScaleY = std::max(0.1f, std::min(3.0f, newScaleY));

    sprite.setScale(newScaleX, newScaleY);

    sf::Vector2f spriteSize(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
    sf::Vector2f currentPos = sprite.getPosition();
    if (currentPos.x + spriteSize.x > 900) {
        currentPos.x = 900 - spriteSize.x;
    }
    if (currentPos.y + spriteSize.y > 575) {
        currentPos.y = 575 - spriteSize.y;
    }

    sprite.setPosition(currentPos);
}


void ImageElement::crop(const sf::IntRect& rect) {
    sprite.setTextureRect(rect);
}

sf::FloatRect ImageElement::getBounds(){
    return sprite.getGlobalBounds();
}
