#include <SFML/Graphics.hpp>
#include <iostream>

int map(float s, float a1, float a2, float b1, float b2)
{
    return b1 + ((s - a1) * (b2 - b1) / (a2 - a1));
}

int main(int argc, char* argv[])
{
    if (argc > 1)
        std::cout << argv[1] << std::endl;
    else
        return 0;

    std::string density[29] = { "Ñ", "@", "#", "W", "$", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0", "?", "!", "a", "b", "c", ";", ":", "+", "=", "-", ",", ".", "_", " " };
    int densityL = 29;

    sf::Image image;
    image.loadFromFile(argv[1]);

    for (int j = 0; j < image.getSize().y; j++)
    {
        for (int i = 0; i < image.getSize().x; i++)
        {
            sf::Color color = image.getPixel(i, j);
            int r = color.r, g = color.g, b = color.b;
            int avg = (r + g + b) / 3;

            std::string out = density[map(avg, 0, 255, densityL - 1, 0)];
            std::cout << out;
        }
        std::cout << std::endl;
    }
        
    std::cin.get();

    return 0;
}