#include "Player.h"
#include <iostream>

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

void Player::update(float dt) {
    velocity += acceleration * dt;
    position += velocity * dt;
    velocity *= friction;
    shape.setPosition(position);
}

void Player::draw(RenderWindow &window) {
    window.draw(shape);
}
