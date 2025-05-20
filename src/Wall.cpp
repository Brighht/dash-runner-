#include "Wall.h"

Wall::Wall(Vector2f position, Vector2f size){
    shape.setSize(size);
    shape.setFillColor(Color::White);
    shape.setPosition(position);
}

void Wall::draw(RenderWindow &window){
    window.draw(shape);
}

const RectangleShape& Wall::getShape() const{
    return shape;
}