#include "Enemy.h"

Enemy::Enemy(Vector2f startPosition, float patrolRange){
    position = startPosition;
    speed = 100.f;
    movingRight = true;

    leftMovement = startPosition.x;
    rightMovement = startPosition.x + patrolRange;


    shape.setFillColor(Color::Magenta);
    shape.setSize(Vector2f(50.f,50.f));
    shape.setPosition(position);

}

void Enemy::update(float dt) {
    if (movingRight) {
        position.x += speed * dt;
        if (position.x >= rightMovement) {
            position.x = rightMovement;
            movingRight = false;
        }
    } else {
        position.x -= speed * dt;
        if (position.x <= leftMovement) {
            position.x = leftMovement;
            movingRight = true;
        }
    }
}

void Enemy::draw(RenderWindow &window){
    window.draw(shape);
}

const RectangleShape& Enemy::getShape() const {
    return shape;
}