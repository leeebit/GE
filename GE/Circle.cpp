#include "Circle.h"

Circle::Circle(const sf::Vector2f& position) {

	// Создание квадрата
	//squareShape = new sf::RectangleShape(sf::Vector2f(100, 100));
	//squareShape->setFillColor(sf::Color::Transparent);
	//squareShape->setOutlineColor(sf::Color::Green);
	//squareShape->setOutlineThickness(2);
	//squareShape->setPosition(position); // Позиция квадрата

	// Создание круга
	circleShape = new sf::CircleShape(50); // Радиус круга по умолчанию
	circleShape->setFillColor(sf::Color::Blue); // Цвет заливки круга
	circleShape->setOutlineColor(sf::Color::Red); // Цвет обводки круга
	circleShape->setOutlineThickness(2); // Толщина обводки круга
	circleShape->setPosition(position);
	// Устанавливаем позицию круга внутри квадрата (в центре квадрата)
	/*sf::FloatRect circleBounds = circleShape->getGlobalBounds();
	sf::FloatRect squareBounds = squareShape->getGlobalBounds();

	float circleX = squareBounds.left + (squareBounds.width - circleBounds.width) / 2;
	float circleY = squareBounds.top + (squareBounds.height - circleBounds.height) / 2;

	circleShape->setPosition(circleX, circleY);*/
}

Circle::~Circle() {
	delete circleShape;
}

void Circle::setfillColorFigure(const sf::Color& color) {
	circleShape->setFillColor(color);
};

void Circle::setfillColorOutlineFigure(const sf::Color& color) {
	std::cout << "1";
	circleShape->setOutlineColor(color);
};

void Circle::getfillColorFigure(const sf::Color& color) {
	circleShape->getFillColor();
};

void Circle::getfillColorOutlineFigure(const sf::Color& color) {
	circleShape->getOutlineColor();
};

sf::CircleShape& Circle::getCircleShape() {
	return *circleShape;
}

void Circle::drawElements(sf::RenderWindow& window) {
	/*window.draw(*squareShape);*/
	window.draw(*circleShape);
};

sf::FloatRect Circle::getBounds() {
	return circleShape->getGlobalBounds();
};

void Circle::moveElements(float offsetX, float offsetY) {
	sf::Vector2f currentPos = circleShape->getPosition();

	// Изменяем координаты круга в соответствии с заданным смещением
	currentPos.x += offsetX;
	currentPos.y += offsetY;
	
	std::cout << currentPos.x << " " << currentPos.y << "\n";
	// Ограничиваем координаты элемента в пределах слайда
	if (currentPos.x < 100) {
		currentPos.x = 100;
	}
	else if (currentPos.x + circleShape->getGlobalBounds().width > 900) {
		currentPos.x = 900 - circleShape->getGlobalBounds().width;
	}

	if (currentPos.y < 126) {
		currentPos.y = 126;
	}
	else if (currentPos.y + circleShape->getGlobalBounds().height > 575) {
		currentPos.y = 575 - circleShape->getGlobalBounds().height;
	}

	circleShape->setPosition(currentPos);
};

void Circle::resizeElements(float amount) {
	float currentRadius = circleShape->getRadius();
	sf::Vector2f currentPos = circleShape->getPosition();

	float newRadius = currentRadius + amount;

	// Ограничение размера, чтобы он оставался в заданных пределах
	if (newRadius > 100) {
		newRadius = 100;
	}
	else if (newRadius < 10) {
		newRadius = 10;
	}

	// Определение знака и изменение размера в зависимости от этого
	if (amount > 0) {
		// Увеличение размера
		circleShape->setRadius(newRadius);

		// Пересчет позиции, чтобы элемент оставался в пределах окна
		if (currentPos.x + newRadius > 800) {
			currentPos.x = 800 - newRadius;
		}
		if (currentPos.y + newRadius > 450) {
			currentPos.y = 450 - newRadius;
		}
	}
	else if (amount < 0) {
		// Уменьшение размера
		circleShape->setRadius(newRadius);
	}

	circleShape->setPosition(currentPos);
}




