#include "Main.h"
using namespace sf;
int main() {


	RenderWindow window(sf::VideoMode(1024, 600), "It's Editor", Style::Close);
	window.setVerticalSyncEnabled(true);

	GraphicEditor editor;
	editor.App(window);
	return 0;
}