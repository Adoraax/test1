#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <memory>
#include <vector>

class AssignmentShape
{
private:
    sf::CircleShape circle;
    sf::RectangleShape rect;
    float speedX;
    float speedY;
    bool isCircle;

public:

    AssignmentShape(float circleRadius, const sf::Vector2f position, float speedX, float speedY)
        : speedX(speedX), speedY(speedY), isCircle(true)
        {
        circle.setRadius(circleRadius);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(position);
        }

    AssignmentShape(const sf::Vector2f& rectSize, const sf::Vector2f position, float speedX, float speedY)
        : speedX(speedX), speedY(speedY), isCircle(false)
        {
        rect.setSize(rectSize);
        rect.setFillColor(sf::Color::Blue);
        rect.setPosition(position);
        }

    void AssignmentShape::draw(sf::RenderWindow& window)
        {
            if (isCircle)
            {
                window.draw(circle);
            }
            else
            {
                window.draw(rect);
            }
        }

        // Update the shape's position
    void AssignmentShape::update()
        {
            if (isCircle)
            {
                circle.move(speedX, speedY);
            }
            else
            {
                rect.move(speedX, speedY);
            }
        }

};

int main(int argc, char *argv[])
{
    // Print working directory
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Create new window
    const int wWidth = 1280;
    const int wHeight = 720;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
    window.setFramerateLimit(60);   // Setting max frames at 60fps

/*
    std::vector<sf::RectangleShape> rectangles;
    std::vector<sf::CircleShape> circles;

    std::vector<std::shared_ptr<sf::Shape>> shapes;

    std::shared_ptr<sf::Shape> circ = std::make_shared<sf::CircleShape>(20);
    std::shared_ptr<sf::Shape> rect = std::make_shared<sf::RectangleShape>(sf::Vector2f(40,60));
    rect->setPosition(400,400);

    shapes.push_back(circ);

    shapes.push_back(rect);
*/



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


    //Create and initiazlize shapes
    //std::vector<std::shared_ptr<AssignmentShape>> shapes;
    std::vector<AssignmentShape> shapes;
    shapes.emplace_back(50.0f, sf::Vector2f(300.0f, 300.0f), 0.5f, 0.5f);
    shapes.emplace_back(sf::Vector2f(40,60), sf::Vector2f(40,60), 0.5f, -0.5f);


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
                    //circleMoveSpeed *= -1.0f;
                    window.close();
                }
            }
        }

        for (auto& shape : shapes)
        {
            shape.update();
        }
        
        window.clear();
        window.draw(text);

        for (auto& shape : shapes)
        {
            shape.draw(window);
        }

        window.display();
    }

    return 0;
}
