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

    if (amount > 0) {
        scale.x += amount;
        scale.y += amount;
    }
    else if (amount < 0) {
        float absoluteAmount = std::abs(amount);
        scale.x -= absoluteAmount;
        scale.y -= absoluteAmount;
    }

    if (scale.x > 1.5f || scale.x < 0.1f) {
        scale.x = std::max(0.1f, std::min(1.5f, scale.x));
        scale.y = std::max(0.1f, std::min(1.5f, scale.y));
    }

    sprite.setScale(scale);

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
