#include "Slide.h"

Slide::Slide() {
    background.setSize(sf::Vector2f(800, 450));
    background.setFillColor(sf::Color::White);
    background.setOutlineColor(sf::Color::Red);
    background.setOutlineThickness(2);
    background.setPosition(100, 125);
}

Slide::~Slide() {
    for (auto element : elements) {
        delete element;
    }
    elements.clear();
}

void Slide::setElementType(int type) {
    elementType = type;
}

int Slide::getElementType() const {
    return elementType;
}

std::vector<Elements*>& Slide::getElements() {
    return elements;
}

int Slide::getChosenColorIndexElement() {
    return chosenColorIndexElement;
}

void Slide::setChosenColorIndexElement(int index) {
    chosenColorIndexElement = index;
}

int Slide::getElementCount() {
    return elements.size();
}

void Slide::setCurrentElement(Elements* element) {
    currentElement = element;
}

Elements* Slide::getCurrentElement() {
    return currentElement;
}

void Slide::createElements(const sf::Vector2f& clickPosition) {
    Elements* newElement = nullptr;
    if (elementType == CIRCLE) {
        newElement = new Circle(clickPosition);
    }
    else if (elementType == SQUARE) {
        newElement = new Square(clickPosition);
    }
    else if (elementType == TRIANGLE) {
        newElement = new Triangle(clickPosition);
    }
    else if (elementType == IMAGE) {
        newElement = new ImageElement(clickPosition);
        const char* filterPatterns[1] = { "*.png;*.jpg;*.jpeg;*.bmp" };
        const char* imagePath = tinyfd_openFileDialog(
            "Open Image",
            "",
            1,
            filterPatterns,
            NULL,
            0
        );
        if (imagePath != NULL) {
            if (!static_cast<ImageElement*>(newElement)->loadFromFile(imagePath)) {
                delete newElement;
                return;
            }
        }
        else {
            delete newElement;
            return;
        }
    }
    if (newElement != nullptr) {
        elements.push_back(newElement);
        setCurrentElement(newElement);
        std::cout << "Create Element index is " << elements.size() - 1 << " added to the slide!" << std::endl;
    }
}

void Slide::SetBackgroundColor(const sf::Color& color) {
    background.setFillColor(color);
}

sf::RectangleShape& Slide::getBackground() {
    return background;
}

void Slide::Draw(sf::RenderWindow& window) {
    window.draw(background);
    for (auto element : elements) {
        element->drawElements(window);
    }
}
