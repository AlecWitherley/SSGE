#include <SFML/Graphics.hpp>

class Win{
public:
    Win(const std::string& windowName);

    void Update(int dt);
    void BeginDraw();
    void Draw(const sf::Drawable& drawable);
    void EndDraw();
    void PreLoop();
    void SplashScreen();
    bool IsOpen() const;

private:
    sf::RenderWindow window;

    //Variables
    sf::Sprite SS;
    sf::Texture TSS;
};