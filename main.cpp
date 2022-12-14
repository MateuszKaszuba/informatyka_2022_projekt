#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;

class pilka {
private:
	sf::Vector2f position;
	float xVel = 20;
	float yVel = 20;
	sf::CircleShape ball;
	sf::RectangleShape HB;

public:
	pilka(float x_in, float y_in);
	void przesun(float x_in, float y_in);
	sf::CircleShape getPilka() { return ball; }
	sf::RectangleShape gethitbox() { return HB; }
	sf::Vector2f getPos() { return ball.getPosition(); }

};
class podloga {
private:
	sf::Vector2f position;
	sf::RectangleShape Odbijacz;
public:
	podloga(float x_in, float y_in);
	void przesun1(float x_in, float y_in);
	sf::RectangleShape getPodloga() { return Odbijacz; }
	sf::Vector2f getPos() { return Odbijacz.getPosition(); }

};
pilka::pilka(float x_in, float y_in)
{	position.x = x_in;
	position.y = y_in;
	ball.setRadius(20);
	ball.setFillColor(sf::Color(150, 50, 250));
	ball.setOutlineThickness(2);
	ball.setOutlineColor(sf::Color(250, 150, 100));
	ball.setPosition(position);
	HB.setSize(sf::Vector2f(40, 40));


	HB.setPosition(position);
}

podloga::podloga(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	sf::FloatRect box1(Odbijacz.getGlobalBounds());
	sf::Vector2f(100, 100);
	Odbijacz.setSize(sf::Vector2f(100, 20));
	Odbijacz.setFillColor(sf::Color::Black);
	Odbijacz.setPosition(position);
	Odbijacz.setOutlineThickness(2);
	Odbijacz.setOutlineColor(sf::Color(250, 150, 100));

}
void pilka::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	ball.move(pos);
}
void podloga::przesun1(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	Odbijacz.move(pos);
}
int main()
{
	RenderWindow window(VideoMode{ 800, 600 }, "Gra");
	pilka p1(400, 300);
	podloga d1(350, 500);
	int dx = 10, dy = 10;
	int dx1 = 5, dy1 = 0;
	
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
		if (zegar.getElapsedTime().asMilliseconds() > 30.0f) {

			if (zegar.getElapsedTime().asMilliseconds() > 30.0f)
 {

			
					if (p1.getPos().x > window.getSize().x -30 || p1.getPos().x  < 0)

						dx = -dx;
			
					if (p1.getPos().y > window.getSize().y -40|| p1.getPos().y  < 0)
						dy = -dy;
				p1.przesun(dx, dy);
				zegar.restart();
			}
	
				
					if (sf::Keyboard::isKeyPressed (sf::Keyboard::Key::A))
					{
						d1.przesun1(-dx1, dy1);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
					{
						d1.przesun1(dx1, dy1);
					}
					
			
				
					if (box1.intersects(pilka))
			{
				dx = -dx;
				dy = dy;
			}
		
		


			window.clear(sf::Color::White);
			window.clear(sf::Color::Black);
			window.draw(p1.getPilka());
			window.draw(d1.getPodloga());
			window.display();
		}
	}
}