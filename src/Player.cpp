#include "Player.h"
#include <iostream>
#include "Wall.h"

Player::Player(const string &userName) {
    this->userName = userName;
    std::cout << "(Player): " << userName << std::endl;

    position = Vector2f(100.f, 100.f);
    velocity = Vector2f(0.f, 0.f);
    acceleration = Vector2f(0.f, 0.f);
    speed = 500.f;
    friction = 0.9f;

    shape.setSize(Vector2f(50.f, 50.f));
    shape.setFillColor(Color::Cyan);
    shape.setPosition(position);
}

void Player::setUserName(const string &username) {
    userName = username;
}

void Player::handleInput() {
    acceleration = Vector2f(0.f, 0.f);

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        acceleration.y = -speed;
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        acceleration.y = speed;
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        acceleration.x = -speed;
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        acceleration.x = speed;
    }
}

void Player::update(float dt, const std::vector<Wall>& walls) {
    velocity += acceleration * dt;   // Apply acceleration to velocity

    // Predict next position
    Vector2f nextPosition = position + velocity * dt;

    // Get the bounding box of where the player "would" move
    FloatRect nextBounds = shape.getGlobalBounds();
    nextBounds.left = nextPosition.x;
    nextBounds.top = nextPosition.y;

    // Check for collision before committing to the move
    for (const Wall& wall : walls) {
        if (nextBounds.intersects(wall.getShape().getGlobalBounds())) {
            velocity = Vector2f(0.f, 0.f); // Stop all motion
            return; // Don't move this frame
        }
    }

    // No collision → apply the movement
    position = nextPosition;
    velocity *= friction; // Apply friction
    shape.setPosition(position);

    Vector2f size = shape.getSize();
    float maxX = 800 - size.x;
    float maxY = 600 - size.y;

    if(position.x > maxX){
        position.x = maxX;
    }

    if(position.x < 0){
        position.x = 0;
    }

    if(position.y > maxY){
        position.y = maxY;
    }

    if(position.y < 0){
        position.y = 0;
    }
}

void Player::draw(RenderWindow &window) {
    window.draw(shape);
}

const RectangleShape& Player::getShape() const {
    return shape;
}
