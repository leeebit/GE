#include "Main.h"
using namespace sf;
int main() {

	GraphicEditor editor;

	RenderWindow window(sf::VideoMode(1024, 600), "It's Editor", Style::Close);
	window.setVerticalSyncEnabled(true);

	editor.App(window);
	return 0;
}