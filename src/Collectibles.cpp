#include "Collectibles.h"

Collectibles::Collectibles(Vector2f position, Vector2f size){
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(Color::Yellow);
}

void Collectibles::draw(RenderWindow &window){
    if(!collected)
        window.draw(shape);
}

bool Collectibles::checkCollision(const FloatRect& playerBounds){
    if(!collected && shape.getGlobalBounds().intersects(playerBounds)){
        collected = true;
        return true;
    }
    return false;
}

bool Collectibles::isCollected() const {
    return collected;
}