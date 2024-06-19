#define SFML_STATIC
#include <SFML/Graphics.hpp>

int main(){

    int left=0,right=0,up=0,down=0;

    sf::RenderWindow window(sf::VideoMode(1000,800), "Window", sf::Style::Close);
    sf::Event event;

    sf::RectangleShape rectangle(sf::Vector2f(100,100));

    sf::RectangleShape hexagon(sf::Vector2f(100,100));

    sf::RectangleShape quadrado(sf::Vector2f(100,100));

    hexagon.setFillColor(sf::Color(255,0,0));
    quadrado.setFillColor(sf::Color(0,0,255));

    hexagon.setOrigin(50,50);
    hexagon.setPosition(500,400);

    quadrado.setOrigin(50,50);
    quadrado.setPosition(500,500);

    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            rectangle.move(-0.1,0.f);
            left++;
            right--;
        } if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            rectangle.move(0.1,0.f);
            right++;
            left--;
        } if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            rectangle.move(0.f,-0.1);
            up++;
            down--;
        } if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            rectangle.move(0.f,0.1);
            down++;
            up--;
        }

        if(rectangle.getGlobalBounds().intersects(hexagon.getGlobalBounds())){
            hexagon.setFillColor(sf::Color(0,255,0));
            if(left > right){
                rectangle.move(0.11,0.f);
                left = 0;
                right = 0;
            }
            if(right > left){
                rectangle.move(-0.11,0.f);
                right =0;
                left = 0;
            }
            if(up > down){
                rectangle.move(0.f,0.11);
                up = 0;
                down = 0;
            }
            if(down > up){
                rectangle.move(0.f,-0.11);
                down = 0;
                up = 0;
            }
        }else{
            hexagon.setFillColor(sf::Color(255,0,0));
            }

        if(rectangle.getGlobalBounds().intersects(quadrado.getGlobalBounds())){
            quadrado.setFillColor(sf::Color(0,255,0));
            if(left > right){
                rectangle.move(0.11,0.f);
                left = 0;
                right = 0;
            }
            if(right > left){
                rectangle.move(-0.11,0.f);
                right =0;
                left = 0;
            }
            if(up > down){
                rectangle.move(0.f,0.11);
                up = 0;
                down = 0;
            }
            if(down > up){
                rectangle.move(0.f,-0.11);
                down = 0;
                up = 0;
            }

        }else{
            quadrado.setFillColor(sf::Color(0,0,255));
        }

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.draw(hexagon);
        window.draw(quadrado);
        window.display();
    }

    return 0;
}
