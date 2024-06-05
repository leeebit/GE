#include "Triangle.h"
#include <algorithm>

Triangle::Triangle(const sf::Vector2f& position, float baseLength, float height) {
    triangleShape.setPointCount(3);
    triangleShape.setPoint(0, sf::Vector2f(0, 0));
    triangleShape.setPoint(1, sf::Vector2f(baseLength / 2, -height));
    triangleShape.setPoint(2, sf::Vector2f(baseLength, 0));
   triangleShape.setFillColor(sf::Color::Blue); // ���� ������� ������������
    triangleShape.setOutlineColor(sf::Color::Red); // ���� ������� ������������
    triangleShape.setOutlineThickness(2); // ������� ������� ������������
    triangleShape.setPosition(position); // ������� ������������ �� ������ (����� ��������)
}

void Triangle::drawElements(sf::RenderWindow& window) {
    window.draw(triangleShape);
}

Triangle::~Triangle(){}

void Triangle::moveElements(float offsetX, float offsetY) {
    sf::Vector2f currentPos = triangleShape.getPosition();

    std::cout << currentPos.x << " " << currentPos.y << "\n";
    // �������� ���������� ������������ � ������������ � �������� ���������
    currentPos.x += offsetX;
    currentPos.y += offsetY;

    // ���������, �� ������� �� ����������� �� ������� ������
    if (currentPos.x < 100) {
        currentPos.x = 100;
    }
    else if (currentPos.x + triangleShape.getGlobalBounds().width > 900) {
        currentPos.x = 900 - triangleShape.getGlobalBounds().width;
    }

    int baseline = 576;
    if (currentPos.y - triangleShape.getGlobalBounds().height <= 125)
    {
        currentPos.y = 125 + triangleShape.getGlobalBounds().height;
    }
    else if (currentPos.y > baseline)
    {
        currentPos.y = baseline;
    }

    // ������������� ����� ���������� ������������
    triangleShape.setPosition(currentPos);
}

void Triangle::resizeElements(float amount) {
    sf::FloatRect bounds = triangleShape.getGlobalBounds();
    sf::Vector2f size(bounds.width, bounds.height);

    if (amount > 0) {
        // ����������� ������
        size.x += amount;
        size.y += amount;
    }
    else if (amount < 0) {
        // ��������� ������
        float absoluteAmount = std::abs(amount);
        size.x -= absoluteAmount;
        size.y -= absoluteAmount;
    }

    if (size.x > 150 || size.x < 10) {
        // ������������ ������, ���� �� ��������� ������������ ��� ����������� ��������
        size.x = std::max(10.0f, std::min(150.0f, size.x));
        size.y = std::max(10.0f, std::min(150.0f, size.y));
    }

    float baseLength = size.x;
    float height = size.y;

    triangleShape.setPoint(1, sf::Vector2f(baseLength / 2, -height));
    triangleShape.setPoint(2, sf::Vector2f(baseLength, 0));

    sf::Vector2f currentPos = triangleShape.getPosition();

    // ������������� �������, ���� ����������, ����� ������� ��������� � �������� ����
    if (currentPos.x + size.x > 900) {
        currentPos.x = 900 - size.x;
    }
    if (currentPos.y + size.y > 575) {
        currentPos.y = 575 - size.y;
    }

    triangleShape.setPosition(currentPos);
}

void Triangle::setfillColorFigure(const sf::Color& color) {
    triangleShape.setFillColor(color);
}

void Triangle::setfillColorOutlineFigure(const sf::Color& color) {
    triangleShape.setOutlineColor(color);
}

sf::FloatRect Triangle::getBounds(){
    return triangleShape.getGlobalBounds();
}
