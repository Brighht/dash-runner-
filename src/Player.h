#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

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

    public: 
        Player(const string & userName){
            this->userName = userName;
            cout << "(Player): " << userName << endl;

            position = Vector2f(100.f, 100.f); // Starting position
            velocity = Vector2f(0.f, 0.f);
            acceleration = Vector2f(0.f, 0.f);
            speed = 500.f;
            friction = 0.9f;

            shape.setSize(Vector2f(50.f, 50.f));
            shape.setFillColor(Color::Cyan);
            shape.setPosition(position);
        }

        void setUserName(const string &username){
            userName = username;
        }
        void handleInput(){

        }

        void update(float dt){

        }

        void draw(RenderWindow &window){

        }
};