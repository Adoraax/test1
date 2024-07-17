#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <memory>

int main(int argc, char *argv[])
{
    // Print working directory
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Create new window
    const int wWidth = 1280;
    const int wHeight = 720;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
    window.setFramerateLimit(60);   // Setting max frames at 60fps

    // Make a shape
    int r = 255;          // Specify color using RGB values
    int g = 0;
    int b = 0;

    //shapes
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color(r, g, b));
    circle.setPosition(300.0f, 300.0f);
    float circleMoveSpeed = 0.5f;

    /*
    float rx = 100;
    float ry = 50;
    sf::Vector2f rSize(rx, ry);
    sf::RectangleShape rect(rSize);
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition(200.0f, 200.0f);
    float rectMoveSpeed = 1.0f;
    rect.rotate(0.1);
    */

    std::vector<sf::RectangleShape> rectangles;
    std::vector<sf::CircleShape> circles;

    std::vector<std::shared_ptr<sf::Shape>> shapes;

    std::shared_ptr<sf::Shape> circ = std::make_shared<sf::CircleShape>(20);
    std::shared_ptr<sf::Shape> rect = std::make_shared<sf::RectangleShape>(sf::Vector2f(40,60));
    rect->setPosition(400,400);

    shapes.push_back(circ);

    shapes.push_back(rect);

    // Text - fonts
    sf::Font myFont;
    std::string fontPath = "assets/fonts/Gondola_SD.ttf"; // Adjusted path

    if (!myFont.loadFromFile(fontPath))
    {
        std::cerr << "Could not load font: " << fontPath << "\n";
        exit(-1);
    }

    sf::Text text("Sample text", myFont, 24);
    text.setPosition(0, wHeight - (float)text.getCharacterSize());

    /*//loading shapes from file ?
    std::vector<sf::CircleShape> circles;
    circles.push_back(circle);
    std::vector<sf::RectangleShape> rectangles;
    //rectangles.push_back(rect);
    for (int x = 0; x < 25; x++)
    {
        for (int y = 0; y < 15; y++)
        {
            sf::RectangleShape rect(sf::Vector2f(15, 15));
            rect.setFillColor(sf::Color(x * 10, y * 10, 0));
            rect.setPosition(x *20, y * 20);
            rectangles.push_back(rect);
        }
    }
    */

    // Main loop - continues for each frame while window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
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

        //circle.setPosition(circle.getPosition().x + circleMoveSpeed, circle.getPosition().y - circleMoveSpeed);
        //rect.setPosition(rect.getPosition().x - rectMoveSpeed, rect.getPosition().y - rectMoveSpeed);
        //rect.rotate(1.0);

        window.clear();
        //window.draw(circle);
        //window.draw(rect);

        /*
        for (auto& circle : circles)
        {
            window.draw(circle);
        }

        for (auto& rect : rectangles)
        {
            window.draw(rect);
        }
        */
        window.draw(text);


        for (auto& shape : shapes)
        {
            window.draw(*shape);
        }

        window.display();
    }

    return 0;
}
