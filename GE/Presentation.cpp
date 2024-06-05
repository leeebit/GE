#include "Presentation.h"
Presentation::Presentation() {
   
}

Presentation::~Presentation() {
 
}

int Presentation::CreateSlide() {
    Slide* newSlide = new Slide();
    slides.push_back(newSlide);
    slideCount = slides.size();
    std::cout << "Slide created. Total slides: " << slideCount << std::endl;
    return slideCount-1;
}

int Presentation::DeleteSlide() {
    if (!slides.empty()) {
        delete slides.back();
        slides.pop_back();
    }
    slideCount = slides.size();
    std::cout << "Slide deleted. Total slides: " << slideCount << std::endl;
    return slideCount;
}

std::vector<Slide*> Presentation::getSlides() {
    return slides;
}