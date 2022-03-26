/*
 

*--------------------------------------------------------------------*
*             THIS IS SCRAP CODE USED FOR REFERENCE                  *
*                                                                    *
*--------------------------------------------------------------------*


#include <SFML/Graphics.hpp>
using namespace sf;
int main(int argc, char** argv) {
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game", Style::Default);

    sf::Event event;
    sf::Texture texture;
    texture.loadFromFile("World/Assets/FreeKnight_v1/Colour2/Outline/120x80_PNGSheets/_Idle.png");

    sf::IntRect rectSourceSprite(0, 0, 100, 80);
    sf::Sprite sprite(texture, rectSourceSprite);
    sf::Clock clock;

    while (renderWindow.isOpen()) {
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }

        if (clock.getElapsedTime().asSeconds() > 1.0f) {
            if (rectSourceSprite.left == 600)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 300;
            sprite.setTextureRect(rectSourceSprite);
            clock.restart();
        }


        renderWindow.clear();
        renderWindow.draw(sprite);
        renderWindow.display();
    }
}

void State_Idle() {
    Texture texture;
    texture.loadFromFile("World/Assets/FreeKnight_v1/Colour2/Outline/120x80_PNGSheets/_Idle.png");

    IntRect rectSourceSprite(0, 0, 120, 80);
    Sprite sprite(texture, rectSourceSprite);
    Clock clock;

    if (clock.getElapsedTime().asSeconds() > TIME) {
        if (rectSourceSprite.left == TOTAL)
            rectSourceSprite.left = RESET;
        else
            rectSourceSprite.left += SKIP;

        sprite.setTextureRect(rectSourceSprite);
        clock.restart();
    }
}
void State_Run() {
    Texture run_texture;
    run_texture.loadFromFile("World/Assets/FreeKnight_v1/Colour2/Outline/120x80_PNGSheets/_Run.png");

    IntRect runRectSourceSprite(0, 0, 120, 80);
    Sprite run_sprite(run_texture, runRectSourceSprite);
    Clock run_timer;

    if (run_timer.getElapsedTime().asSeconds() > RUN_TIME) {
        if (runRectSourceSprite.left == RUN_TOTAL) {
            runRectSourceSprite.left = RUN_RESET;
        }
        else {
            runRectSourceSprite.left += RUN_SKIP;
        }
       run_sprite.setTextureRect(runRectSourceSprite);
       run_timer.restart();
       }
}

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Header.h"
using namespace sf;

int main() {
    RenderWindow win(VideoMode(WIN_HEIGHT, WIN_WIDTH), NAME, STYLE);
    ContextSettings settings;
    settings.antialiasingLevel = 16;
    win.setVerticalSyncEnabled(true);

    Vector2f velocity;
    CircleShape player;
    RectangleShape grid;

    Texture text1;
    text1.loadFromFile("World/Assets/FreeKnight_v1/Colour2/Outline/120x80_PNGSheets/_Idle.png");
    IntRect rectSourceSprite(0, 0, WIDTH, HEIGHT);
    Sprite sprite(text1, rectSourceSprite);
    Clock clock;

    Event event;
    Clock deltaClock;

    win.setFramerateLimit(60);

    int gravity = 10;
    float speed = 10.0;
    float jump = 100;

    grid.setSize(Vector2f(100, 50));
    floor2.setPosition(Vector2f(300, 300));
    floor2.setFillColor(Color::Cyan);

    player.setRadius(10);
    player.setPosition(Vector2f(50, 50));
    player.setFillColor(Color::Red);

    bool canJump = true;

    while (win.isOpen()) {
        Time dt = deltaClock.restart();

        float dtAsSeconds = dt.asSeconds();

        while (win.pollEvent(event)) {
            if (event.type == Event::EventType::Closed) {
                win.close();
            }
        }

        if (clock.getElapsedTime().asSeconds() > TIME) {
            if (rectSourceSprite.left == TOTAL) {
                rectSourceSprite.left = RESET;
            }
            else {
                rectSourceSprite.left += SKIP;
            }
            sprite.setTextureRect(rectSourceSprite);
            clock.restart();
        }

        if (Keyboard::isKeyPressed(Keyboard::RUN_LEFT)){
            velocity.x -= speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::RUN_RIGHT)) {
            velocity.x += speed;
        }

        if (Keyboard::isKeyPressed(Keyboard::Up) && canJump == true) {
            canJump = false;
            velocity.y = -sqrt(2.0 * 981.0f * jump);
        }
        else {
            if (player.getGlobalBounds().intersects(floor.getGlobalBounds())){
                canJump = true;
                velocity.y = 0;
            }
            else if (player.getGlobalBounds().intersects(floor2.getGlobalBounds())) {
                canJump = true;
                velocity.y -= 100;
            }
            else {
                velocity.y += 981.0f * dtAsSeconds;
            }
        }

        if (velocity.x > 0 || velocity.x >= 50) {
            velocity.x -= 5;
        }
        else if (velocity.x < 0 || velocity.x <= -50) {
            velocity.x += 5;
        }
        else {
            velocity.x = 0;
        }

        deltaClock.restart();
        player.move(velocity * dtAsSeconds);

        win.clear();
        win.draw(floor);
        win.draw(floor2);
        win.draw(player); //- collision shape
        win.draw(sprite);
        win.display();
    }
}

* ------FUNCTIONAL USE OF ANIMATIONS--------

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Animations.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(200, 200), "Animations");
    sf::Clock delta;
    int x = 0;
    //Sprites
    sf::Sprite Left_Run;
    sf::Texture Left_Run_text;
    //Assign
    Left_Run_text.loadFromFile("a.png");
    Left_Run.setTexture(Left_Run_text);
    //Animation
    Animation LRun(Left_Run);

    while (window.isOpen()){
        sf::Event event;
        sf::Time dt = delta.restart();

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for (int i = 0; i < TOTAL; i++) {
            LRun.addFrame({ sf::IntRect(x,0,WIDTH,HEIGHT), DELAY });
            if (x <= MAX-END_EXTRA) {
                x = x + ADD;
            }
            else {
                x = 0;
            }
        }

        //mySprite.move(velocity * dt.AsSeconds());
        window.clear();
        window.draw(Left_Run);
        LRun.update(dt.asSeconds());
        window.display();
    }

    return 0;
}
*/