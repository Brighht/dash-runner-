#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy {
    private:
        Vector2f position;
        float speed;
        RectangleShape shape;
        float leftMovement;
        float rightMovement;
        bool movingRight;
        

    public: 
        Enemy(Vector2f startPosition, float patrolRange);
        void update(float dt);
        void draw(RenderWindow &window);
        const RectangleShape& getShape() const;
};