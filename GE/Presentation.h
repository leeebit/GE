#pragma once
#include "Slide.h"
#include <vector>
class Presentation
{
private:
	std::vector<Slide*> slides;
	int slideCount;
public:
	Presentation();
	~Presentation();
	int CreateSlide();
	int DeleteSlide();
	std::vector<Slide*> getSlides(); // Геттер для slides
	
};

