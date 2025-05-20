#include <SFML/Graphics.hpp>>

using namespace sf;

class Wall {
    private:
        RectangleShape shape;

    public: 
        Wall(Vector2f position, Vector2f size);
        void draw(RenderWindow &window);
        const RectangleShape& getShape() const;
};