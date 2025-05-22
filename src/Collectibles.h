#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Collectibles {
    private:
        RectangleShape shape;
        bool collected = false;
    
    public:
        Collectibles(Vector2f position, Vector2f size);
        void draw(RenderWindow &window);
        bool checkCollision(const FloatRect& playerBounds);
        bool isCollected() const;
};