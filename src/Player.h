#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Wall.h"

using namespace std;
using namespace sf;

class Player {
private:
    string userName;
    RectangleShape shape;
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;
    float friction;
    float speed;
    int score = 0;


public:
    Player(const string &userName);
    void setUserName(const string &username);
    void handleInput();
    void update(float dt , const std::vector<Wall>& walls);
    void draw(RenderWindow &window);
    const RectangleShape& getShape() const;
    void increaseScore(int amount);
    int getScore() const;

};
