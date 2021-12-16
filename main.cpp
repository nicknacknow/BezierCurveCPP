#include <SFML/Graphics.hpp>
#include "MultiBezier.h"

using namespace sf;

// next : allow points to be added, moved and removed lol 
// change test length, and also current_time in program

int main() {
	RenderWindow window(VideoMode(1200, 800), "BezierCurve");

	std::vector<Vector2f> list = { {100,200}, {20,0}, {700, 45}, {50, 620} };

	RectangleShape rect;
	rect.setSize(Vector2f(10,10));
	rect.setFillColor(Color::White);

	float test_length = 5.f;
	float current_time = 0.f;
	Clock clock;

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed) window.close();

		window.clear(Color(50,50,50));

		float dt = clock.getElapsedTime().asSeconds();
		clock.restart().asSeconds();

		if (current_time < test_length) {
			current_time += dt;
			if (current_time > test_length) current_time = test_length; // clamp

			Vector2f vec = MutliBezier(current_time / test_length, list);
			rect.setPosition(vec.x, vec.y);
		}

		window.draw(rect);
		window.display();
	}

	return 1;
}