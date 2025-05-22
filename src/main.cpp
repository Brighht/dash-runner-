#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"
#include <vector>
#include "Enemy.h"

using namespace std;
using namespace sf;

enum class GameState {
    Playing,
    GameOver
};

int main(){

    RenderWindow gameWindow(VideoMode(800,600) , "Dash-Runner");
    gameWindow.setFramerateLimit(60);

    Clock dtClock;

    Player player1("Brrrp");

    Wall wall1(Vector2f(200, 300), Vector2f(150, 30));
    Wall wall2(Vector2f(400, 100), Vector2f(100, 100));
    vector<Wall> walls = { wall1, wall2 };

    Enemy enemy1(Vector2f(300, 200), 200.f);

    Font font;
    if(!font.loadFromFile("assets/arial.ttf")){
        cout << "Failed to load font" << endl;
    }

    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER\nPress R to Restart or Q to Quit\n");
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(50.f, 50.f);

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(Color::Yellow);
    scoreText.setPosition(20.f,20.f);

    GameState state = GameState::Playing;

    while(gameWindow.isOpen()){
        Event userEvent;
        while(gameWindow.pollEvent(userEvent)){
            if(userEvent.type == Event::Closed){
                gameWindow.close();
            }
        }

        Time dt = dtClock.restart();
        float deltaSeconds = dt.asSeconds();

        if(state == GameState::Playing){
            player1.handleInput();
            enemy1.update(deltaSeconds);
            player1.update(deltaSeconds,walls);

            if (player1.getShape().getGlobalBounds().intersects(enemy1.getShape().getGlobalBounds())){
                cout << "GAME OVER: Player touched enemy!" << endl;
                state = GameState::GameOver;
            }

        }

        if(Keyboard::isKeyPressed(Keyboard::Space)){
            player1.increaseScore(1);
        }

        if(state == GameState::GameOver){
            if(Keyboard::isKeyPressed(Keyboard::R)){
                //reset game
                player1 = Player("Bright");
                enemy1 = Enemy(Vector2f(300, 200), 200.f);
                state = GameState::Playing;
            }

            if(Keyboard::isKeyPressed(Keyboard::Q)){
                gameWindow.close();
            }
        }

        gameWindow.clear();

        if(state == GameState::Playing){
            player1.draw(gameWindow);
            wall1.draw(gameWindow);
            wall2.draw(gameWindow);
            enemy1.draw(gameWindow);
            scoreText.setString("Score: " + std::to_string(player1.getScore()));
            gameWindow.draw(scoreText);

        }
        else {
            gameWindow.draw(gameOverText);
        }
        
        gameWindow.display();
    }

    return 0;
}