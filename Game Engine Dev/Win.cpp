#include "Win.h"
#include "Definitions.h"
#include "Animations.h"

Win::Win(const std::string& windowName) : window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), windowName, sf::WIN_STYLE){
    window.setVerticalSyncEnabled(WIN_V_SYNC);
    window.setFramerateLimit(WIN_FPS_CAP);
}

void Win::Update(int dt){
    sf::Event event;

    if (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
    }

}

void Win::BeginDraw(){
    window.clear(sf::Color::WIN_COLOUR);
}
void Win::Draw(const sf::Drawable& drawable){
    window.draw(drawable);
}
void Win::EndDraw(){
    window.display();
}
void Win::PreLoop() {

}
void Win::SplashScreen() {
    TSS.loadFromFile("SS.png");
    SS.setTexture(TSS);

    window.draw(SS);
}
bool Win::IsOpen() const{
    return window.isOpen();
}