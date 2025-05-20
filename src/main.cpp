#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"
#include <vector>

using namespace std;
using namespace sf;

int main(){

    RenderWindow gameWindow(VideoMode(800,600) , "Dash-Runner");
    gameWindow.setFramerateLimit(60);

    Clock dtClock;

    Player player1("Brrrp");
    Wall wall1(Vector2f(200, 300), Vector2f(150, 30));
    Wall wall2(Vector2f(400, 100), Vector2f(100, 100));
    vector<Wall> walls = { wall1, wall2 };


    while(gameWindow.isOpen()){
        Event userEvent;
        while(gameWindow.pollEvent(userEvent)){
            if(userEvent.type == Event::Closed){
                gameWindow.close();
            }
        }

        Time dt = dtClock.restart();
        float deltaSeconds = dt.asSeconds();

        player1.handleInput();
        player1.update(deltaSeconds,walls);

        
        gameWindow.clear();
        player1.draw(gameWindow);
        wall1.draw(gameWindow);
        wall2.draw(gameWindow);
        gameWindow.display();
    }

    return 0;
}