#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace std;
using namespace sf;

int main(){

    RenderWindow gameWindow(VideoMode(800,600) , "Dash-Runner");
    gameWindow.setFramerateLimit(60);

    //debug
    // RectangleShape testRect(Vector2f(100.f, 100.f));
    // testRect.setFillColor(Color::Red);
    // testRect.setPosition(300.f, 200.f);

    Clock dtClock;

    Player player1("Brrrp");

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
        player1.update(deltaSeconds);

        // if(deltaSeconds > 0.f){
        //     float fps = 1.f / deltaSeconds;
        //     cout << "FPS: " << fps << endl;
        // }
        gameWindow.clear();
        player1.draw(gameWindow);
        // gameWindow.draw(testRect);
        gameWindow.display();
    }

    return 0;
}