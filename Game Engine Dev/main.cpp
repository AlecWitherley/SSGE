#include "Win.h"
#include "Definitions.h"
#include "Animations.h"

sf::Clock delta;

sf::Sprite SRun;
sf::Texture TRun;

sf::Sprite SIdle;
sf::Texture TIdle;

sf::Sprite SFlip;
sf::Texture TFlip;

int x = 0;

int main(){
    Win window(WIN_NAME);

    TRun.loadFromFile(RUN_PATH);
    SRun.setTexture(TRun);

    TIdle.loadFromFile(IDLE_PATH);
    SIdle.setTexture(TIdle);

    TFlip.loadFromFile(RUN_FLIP_PATH);
    SFlip.setTexture(TFlip);

    SRun.setPosition(sf::Vector2f(200,200));
    SIdle.setPosition(sf::Vector2f(200, 200));
    SFlip.setPosition(sf::Vector2f(200, 200));

    //Uses animation class assigning a sprite to it
    Animation Run(SRun);
    Animation Idle(SIdle);
    Animation Run_Flip(SFlip);

    //Splash screan boolien
    bool _SS = true;

    //WIndow check if open
    while (window.IsOpen()) {
        //Delta time
        sf::Time dt = delta.restart();
        //Updates windows using delta time
        window.Update(dt.asSeconds());

        //Loads Sprites for Idle
        for (int i = 0; i < IDLE_TOTAL; i++) {
            Idle.addFrame({ sf::IntRect(x,0,IDLE_WIDTH,IDLE_HEIGHT), IDLE_DELAY });
            if (x <= IDLE_MAX - IDLE_END_EXTRA) {
                x = x + IDLE_ADD;
            }
            else {
                x = 0;
            }
        }
        //Loads Sprites for Run
        for (int i = 0; i < RUN_TOTAL; i++) {
            Run.addFrame({ sf::IntRect(x,0,RUN_WIDTH,RUN_HEIGHT), RUN_DELAY });
            if (x <= RUN_MAX - RUN_END_EXTRA) {
                x = x + RUN_ADD;
            }
            else {
                x = 0;
            }
        }
        //Loads Sprites for Flipped Run
        for (int i = 0; i < RUN_FLIP_TOTAL; i++) {
            Run_Flip.addFrame({ sf::IntRect(x,0,RUN_FLIP_WIDTH,RUN_FLIP_HEIGHT), RUN_FLIP_DELAY });
            if (x <= RUN_FLIP_MAX - RUN_FLIP_END_EXTRA) {
                x = x + RUN_FLIP_ADD;
            }
            else {
                x = 0;
            }
        }
        //Clear
        window.BeginDraw();
        //Splash Screan
        if (_SS == true) {
            window.SplashScreen();
            //Keyboard space
            if (SPACE_PRESSED) {
                _SS = false;
            }
        }
        //Game
        else {
            //Right Arrow or D
            if (RIGHT_PRESSED) {
                window.Draw(SRun);
                Run.update(dt.asSeconds());
            }
            //"else if" defined to be "elif" and Left Arrow key or A
            elif(LEFT_PRESSED) {
                window.Draw(SFlip);
                Run_Flip.update(dt.asSeconds());
            }
            else {
                window.Draw(SIdle);
                //Updates animation using delta time
                Idle.update(dt.asSeconds());
            }
        }
        //Display
        window.EndDraw();
    }
    return 0;
}