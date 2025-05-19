#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main(){

    RenderWindow gameWindow(VideoMode(800,600) , "Dash-Runner");
    Clock dtClock;

    while(gameWindow.isOpen()){
        Event userEvent;
        while(gameWindow.pollEvent(userEvent)){
            if(userEvent.type == Event::Closed){
                gameWindow.close();
            }
        }

        Time dt = dtClock.restart();
        float deltaSeconds = dt.asSeconds();

        if(deltaSeconds > 0.f){
            float fps = 1.f / deltaSeconds;
            cout << "FPS: " << fps << endl;
        }
        gameWindow.clear();
        gameWindow.setFramerateLimit(60);
        gameWindow.display();
    }

    return 0;
}