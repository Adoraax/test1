#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char * argv[])
{
    //create new window
    const int wWidth = 1280;
    const int wHeight = 720;
    sf:: RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
    window.setFramerateLimit(60);   //setting max frames at 60fps
    //make a shape
    int r = 255;          //specify color using rgb values
    int g = 0;
    int b = 0;

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color(r,g,b));
    circle.setPosition(300.0f, 300.0f);
    float circleMoveSpeed = 0.5f;


    //main loop - continues for each frame while window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "Key pressed with code = " << event.key.code << "\n";

                if (event.key.code == sf::Keyboard::X)
                {
                    circleMoveSpeed *= -1.0f;
                }
            }
        }

        //float sx = 0.5f;
        //float sy = 0.5f;
        circle.setPosition(circle.getPosition().x - circleMoveSpeed, circle.getPosition().y - circleMoveSpeed);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
} //making changes here i guess