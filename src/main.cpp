#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <memory>
#include <vector>
#include <random>
#include <ctime>

// Class to handle shapes (circle and rectangle) and their movement
class AssignmentShape
{
public:
    // Constructor to initialize shapes with parameters
    AssignmentShape(float circleRadius, const sf::Vector2f& rectSize, const sf::Vector2f& position, float speedX, float speedY, bool isCircle)
        : speedX(speedX), speedY(speedY), isCircle(isCircle)
    {
        // Initialize shapes based on the specified type
        if (isCircle)
        {
            int r = (1+ rand() % 255);
            int g = (1+ rand() % 255);
            int b = (1+ rand() % 255);
            circle.setRadius(circleRadius);
            circle.setFillColor(sf::Color(r,g,b));
            circle.setPosition(position);
        }
        else
        {
            int r = (1+ rand() % 255);
            int g = (1+ rand() % 255);
            int b = (1+ rand() % 255);
            rect.setSize(rectSize);
            rect.setFillColor(sf::Color(r,g,b));
            rect.setPosition(position);
        }
    }

    // Update shape positions based on their speed
    void update()
    {
        if (isCircle)
            circle.move(speedX, speedY);
        else
            rect.move(speedX, speedY);
    }

    // Draw shapes to the provided window
    void draw(sf::RenderWindow& window)
    {
        if (isCircle)
            window.draw(circle);
        else
            window.draw(rect);
    }

private:
    sf::CircleShape circle;     // Circle shape
    sf::RectangleShape rect;    // Rectangle shape
    float speedX, speedY;       // Speed of movement in X and Y directions
    bool isCircle;              // Flag to determine the type of shape
    int r;
    int g;
    int b;

};

// Function to create and add a circle to the list of shapes
void addCircle(std::vector<std::shared_ptr<AssignmentShape>>& shapes, float radius, const sf::Vector2f& position, float speedX, float speedY)
{
    shapes.push_back(std::make_shared<AssignmentShape>(radius, sf::Vector2f(0, 0), position, speedX, speedY, true));
}

// Function to create and add a rectangle to the list of shapes
void addRectangle(std::vector<std::shared_ptr<AssignmentShape>>& shapes, const sf::Vector2f& size, const sf::Vector2f& position, float speedX, float speedY)
{
    shapes.push_back(std::make_shared<AssignmentShape>(0, size, position, speedX, speedY, false));
}

int main(int argc, char* argv[])
{
    // Print current working directory
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Create new window with specified dimensions
    const int wWidth = 1280;
    const int wHeight = 720;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
    sf::Vector2u windowSize = window.getSize();
    float centerX = windowSize.x / 2.0f;
    float centerY = windowSize.y / 2.0f;
    window.setFramerateLimit(60); // Setting max frames at 60fps

    // Load font for text display
    sf::Font myFont;
    std::string fontPath = "assets/fonts/Gondola_SD.ttf"; // Adjusted path to the font file

    // Check if the font loads successfully
    if (!myFont.loadFromFile(fontPath))
    {
        std::cerr << "Could not load font: " << fontPath << "\n";
        exit(-1);
    }

    // Create text object with loaded font
    sf::Text text("Sample text", myFont, 24);
    text.setPosition(0, wHeight - static_cast<float>(text.getCharacterSize()));

    // Create and initialize shapes with random paramter values for position and speed
    std::vector<std::shared_ptr<AssignmentShape>> shapes;
    srand(static_cast<unsigned int>(time(nullptr))); 
    int rNumShapes;
    int rNumCircles;
    int rNumRectangles;
    rNumShapes = (1+ rand() % 100);
    std::cout << "Number of shapes = " << rNumShapes << "\n";
    rNumCircles = (1+ rand() % rNumShapes);
    std::cout << "Number of circles = " << rNumCircles << "\n";
    rNumRectangles = rNumShapes - rNumCircles;
    std::cout << "Number of rectangles = " << rNumRectangles << "\n";

    /*
    for (int i = shapes.size(); i < rNumShapes; i++)
    {
        //int rNumCircles;   
        for (int i = 0; i < rNumCircles; i++)
        {
            float randX = static_cast<float>(0.0f + (rand() % wWidth));
            float randY = static_cast<float>(0.0f + (rand() % wHeight));

            float centreScreenX = static_cast<float>(wWidth/2);
            float centreScreenY = static_cast<float>(wHeight/2);

            float randSpeedX = -1.0f + static_cast<float>(rand() / (RAND_MAX / 2.0f));
            float randSpeedY = -1.0f + static_cast<float>(rand() / (RAND_MAX / 2.0f));

            float randRadius = static_cast<float>(rand() % 100 + 20);

            addCircle(shapes, randRadius, sf::Vector2f(randX, randY), randSpeedX, randSpeedY);
        }
        //int rNumRectangles;
        for (int i = 0; i < rNumRectangles; i++)
        {
            float randX = static_cast<float>(0.0f + (rand() % wWidth));
            float randY = static_cast<float>(0.0f + (rand() % wHeight));

            float centreScreenX = static_cast<float>(wWidth/2);
            float centreScreenY = static_cast<float>(wHeight/2);

            float randSpeedX = -1.0f + static_cast<float>(rand() / (RAND_MAX / 2.0f));
            float randSpeedY = -1.0f + static_cast<float>(rand() / (RAND_MAX / 2.0f));

            float randXSize = static_cast<float>(40 + rand() % 120);
            float randYSize = static_cast<float>(40 + rand() % 120);


            addRectangle(shapes, sf::Vector2f(randXSize, randYSize), sf::Vector2f(randX, randY), randSpeedX, randSpeedY);
        }
    }
    */
        //int rNumCircles;   
    for (int i = 0; i < rNumCircles; i++)
    {
        float randX = static_cast<float>(0.0f + (rand() % wWidth));
        float randY = static_cast<float>(0.0f + (rand() % wHeight));

        float centreScreenX = static_cast<float>(wWidth/2);
        float centreScreenY = static_cast<float>(wHeight/2);

        float randSpeedX = -1.0f + static_cast<float>(rand() / (RAND_MAX / 2.0f));
        float randSpeedY = -1.0f + static_cast<float>(rand() / (RAND_MAX / 2.0f));

        float randRadius = static_cast<float>(rand() % 100 + 20);

        addCircle(shapes, randRadius, sf::Vector2f(randX, randY), randSpeedX, randSpeedY);
    }

        //int rNumRectangles;
    for (int i = 0; i < rNumRectangles; i++)
        {
        float randX = static_cast<float>(0.0f + (rand() % wWidth));
        float randY = static_cast<float>(0.0f + (rand() % wHeight));

        float centreScreenX = static_cast<float>(wWidth/2);
        float centreScreenY = static_cast<float>(wHeight/2);

        float randSpeedX = -1.0f + static_cast<float>(rand() / (RAND_MAX / 2.0f));
        float randSpeedY = -1.0f + static_cast<float>(rand() / (RAND_MAX / 2.0f));

        float randXSize = static_cast<float>(40 + rand() % 120);
        float randYSize = static_cast<float>(40 + rand() % 120);


        addRectangle(shapes, sf::Vector2f(randXSize, randYSize), sf::Vector2f(randX, randY), randSpeedX, randSpeedY);
    }

    //addCircle(shapes, 20.0f, sf::Vector2f(300.0f, 300.0f), 0.5f, 0.5f);  // Adding a circle
    //addRectangle(shapes, sf::Vector2f(40.0f, 60.0f), sf::Vector2f(400.0f, 400.0f), -0.5f, -0.5f); // Adding a rectangle

    // Main loop - continues for each frame while window is open
    while (window.isOpen())
    {
        sf::Event event;
        // Poll and handle events
        while (window.pollEvent(event))
        {
            // Close window if the close event is triggered
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Handle key press events
            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "Key pressed with code = " << event.key.code << "\n";
            }
        }

        // Update all shapes
        for (auto& shape : shapes)
        {
            shape->update();
        }

        // Clear the window and draw updated shapes
        window.clear();
        window.draw(text);

        for (auto& shape : shapes)
        {
            shape->draw(window);
        }

        // Display the updated content on the window
        window.display();
    }

    return 0;
}
