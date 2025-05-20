#include "Player.h"

void Player::draw(RenderWindow &window){
    window.draw(shape);
}

void Player::update(float dt){
    velocity += acceleration * dt;
    position += velocity * dt;
    velocity *= friction;
    shape.setPosition(position);
}