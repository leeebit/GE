#include "Square.h"
#include <algorithm>

Square::Square(const sf::Vector2f& position) {
  
    this->side = side; // Сохраняем длину стороны

    squareShape = new sf::RectangleShape();
    squareShape->setSize(sf::Vector2f(side, side)); // Задаем размер квадрата с использованием side
    squareShape->setFillColor(sf::Color::Blue); // Цвет заливки квадрата
    squareShape->setOutlineColor(sf::Color::Red); // Цвет обводки квадрата
    squareShape->setOutlineThickness(2); // Толщина обводки квадрата
    squareShape->setPosition(position); // Позиция квадрата на экране (можно изменить)
}

Square::~Square() {
	delete squareShape;
}

void Square::setfillColorFigure(const sf::Color& color){
	squareShape->setFillColor(color);
};

void Square::setfillColorOutlineFigure(const sf::Color& color){
	squareShape->setOutlineColor(color);
};

sf::RectangleShape& Square::getSquareShape() {
	return *squareShape;
}

sf::FloatRect Square::getBounds() {
    return squareShape->getGlobalBounds();
};

void Square::drawElements(sf::RenderWindow& window){
	window.draw(*squareShape);
};

void Square::moveElements(float offsetX, float offsetY){
	sf::Vector2f currentPos = squareShape->getPosition();

	// Изменяем координаты круга в соответствии с заданным смещением
	currentPos.x += offsetX;
	currentPos.y += offsetY;

	// Проверяем, не выходит ли круг за пределы слайда
	if (currentPos.x < 100) {
		currentPos.x = 100;
	}
	else if (currentPos.x + squareShape->getGlobalBounds().width > 900) {
		currentPos.x = 900 - squareShape->getGlobalBounds().width;
	}

	if (currentPos.y < 125) {
		currentPos.y = 125;
	}
	else if (currentPos.y + squareShape->getGlobalBounds().height > 575) {
		currentPos.y = 575 - squareShape->getGlobalBounds().height;
	}

	// Устанавливаем новые координаты круга
	squareShape->setPosition(currentPos);
};

void Square::resizeElements(float amount) {

    sf::Vector2f size = squareShape->getSize();
    sf::Vector2f currentPos = squareShape->getPosition();

    if (amount > 0) {
        // Увеличиваем размер
        size.x += amount;
        size.y += amount;
    }
    else if (amount < 0) {
        // Уменьшаем размер
        float absoluteAmount = std::abs(amount);
        size.x -= absoluteAmount;
        size.y -= absoluteAmount;
    }

    if (size.x > 150 || size.x < 10) {
        // Ограничиваем размер, если он превышает максимальное или минимальное значение
        size.x = std::max(10.0f, std::min(150.0f, size.x));
        size.y = std::max(10.0f, std::min(150.0f, size.y));
    }

    squareShape->setSize(size);

    // Пересчитываем позицию, если необходимо, чтобы элемент оставался в пределах окна
    // Пример проверки для квадрата
    if (currentPos.x + size.x > 800) {
        currentPos.x = 800 - size.x;
    }
    if (currentPos.y + size.y > 450) {
        currentPos.y = 450 - size.y;
    }

    squareShape->setPosition(currentPos);
};



