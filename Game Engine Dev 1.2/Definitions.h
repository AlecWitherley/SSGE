#pragma once

//WINDOWS
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define WIN_NAME "SSGE"
#define WIN_STYLE Style::Default
#define WIN_COLOUR Black
#define WIN_AA_LEVEL 16
#define WIN_FPS_CAP 60
#define WIN_V_SYNC true

//KEY PRESSED
#define LEFT_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
#define RIGHT_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
#define UP_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
#define DOWN_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::Down)

#define W_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::W)
#define S_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::S)
#define A_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::A)
#define D_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::D)

#define SPACE_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
#define ENTER_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)
#define SHIFT_PRESSED sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)

//Code Chnages
#define elif else if

//Animations - Idle
#define IDLE_TOTAL 10
#define IDLE_ADD 120
#define IDLE_HEIGHT 80
#define IDLE_WIDTH 100
#define IDLE_DELAY 0.1
#define IDLE_MAX 1200
#define IDLE_END_EXTRA 200
#define IDLE_PATH "Idle.png"
//Animations - Run
#define RUN_TOTAL 10
#define RUN_ADD 120
#define RUN_HEIGHT 80
#define RUN_WIDTH 80
#define RUN_DELAY 0.1
#define RUN_MAX 1200
#define RUN_END_EXTRA 200
#define RUN_PATH "Run.png"
//Animations - Run Flip
#define RUN_FLIP_TOTAL 10
#define RUN_FLIP_ADD 120
#define RUN_FLIP_HEIGHT 80
#define RUN_FLIP_WIDTH 80
#define RUN_FLIP_DELAY 0.1
#define RUN_FLIP_MAX 1200
#define RUN_FLIP_END_EXTRA 200
#define RUN_FLIP_PATH "Flip.png"
//Animations - Idle Flip
#define IDLE_FLIP_TOTAL 10
#define IDLE_FLIP_ADD 120
#define IDLE_FLIP_HEIGHT 80
#define IDLE_FLIP_WIDTH 80
#define IDLE_FLIP_DELAY 0.1
#define IDLE_FLIP_MAX 1200
#define IDLE_FLIP_END_EXTRA 200
#define IDLE_FLIP_PATH "Idle Flip.png"