#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(400, 400), "12");
	RectangleShape pr;
	pr.setSize(Vector2f(20, 30));
	pr.setFillColor(Color::Green);
	pr.setPosition(0, 0);
	int i = 20;
	int k = 0;
	bool m = 1;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed) 
			{
				k = 1;
			}

			else if (event.key.code == Mouse::Right)
				k = 0;
		}
		window.clear(Color::White);
		if (k == 1) 
		{
			if (i == 200) m = 0;
			if (i == 20) m = 1;
			if (m == 1) i = i + 10;
			if (m == 0) i = i - 10;
			pr.setSize(Vector2f(20, i));
		}
		window.draw(pr);
		sleep(sf::milliseconds(50));
		window.display();
	}
	return 0;
}