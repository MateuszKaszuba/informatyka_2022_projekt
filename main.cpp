/*Gra Arcnoid*/


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;

class pilka {
private:
	sf::Vector2f position;
	float xVel = 10;
	float yVel = 10;
	sf::CircleShape ball;
public:
	pilka(float x_in, float y_in);
	void przesun(float x_in, float y_in);
	sf::CircleShape getPilka() { return ball; }
	sf::Vector2f getPos() { return ball.getPosition(); }
};
pilka::pilka(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	ball.setRadius(20);
	ball.setFillColor(sf::Color(150, 50, 250));
	ball.setOutlineThickness(2);
	ball.setOutlineColor(sf::Color(250, 150, 100));
	ball.setPosition(position);
}
void pilka::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	ball.move(pos);
}
int main()
{
	RenderWindow window(VideoMode{ 800, 600 }, "Gra");
	pilka p1(400, 300);
	int dx = 10, dy = 10;
	sf::Clock zegar;


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (zegar.getElapsedTime().asMilliseconds() > 100.0f) {

			if (p1.getPos().x > window.getSize().x || p1.getPos().x < 0)

				dx = -dx;
			if (p1.getPos().y > window.getSize().y || p1.getPos().y < 0)
				dy = -dy;
			p1.przesun(dx, dy);
			zegar.restart();
		}


		window.clear(sf::Color::White);
		window.draw(p1.getPilka());
		window.display();
	}
}


