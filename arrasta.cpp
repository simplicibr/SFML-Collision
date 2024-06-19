#define SFML_STATIC
#include <SFML/Graphics.hpp>

void Colisao(sf::RectangleShape& colidindo, sf::RectangleShape& colisor, int& up, int& down, int& left, int& right, int r, int g, int b);
void Parede(sf::RectangleShape& colidindo, sf::RectangleShape& colisor, int& up, int& down, int& left, int& right);
void Movimento(sf::RectangleShape& player, int& up, int& down, int& left, int& right);

int main() {

    int left = 0, right = 0, up = 0, down = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Window", sf::Style::Close);
    sf::Event event;

    sf::RectangleShape rectangle(sf::Vector2f(100, 100));

    sf::RectangleShape hexagon(sf::Vector2f(100, 100));
    sf::RectangleShape quadrado(sf::Vector2f(100, 100));
    sf::RectangleShape cor(sf::Vector2f(100, 100));

    hexagon.setOrigin(50, 50);
    hexagon.setPosition(500, 400);

    quadrado.setOrigin(50, 50);
    quadrado.setPosition(500, 500);

    cor.setOrigin(50, 50);
    cor.setPosition(500, 600);

    sf::RectangleShape top(sf::Vector2f(1000, 5));
    top.setOrigin(500, 2.5);
    top.setPosition(500, -3);

    sf::RectangleShape bottom(sf::Vector2f(1000, 5));
    bottom.setOrigin(500, 2.5);
    bottom.setPosition(500, 803);

    sf::RectangleShape lSide(sf::Vector2f(5, 800));
    lSide.setOrigin(2.5, 400);
    lSide.setPosition(-3, 400);

    sf::RectangleShape rSide(sf::Vector2f(5, 800));
    rSide.setOrigin(2.5, 400);
    rSide.setPosition(1003, 400);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        Movimento(rectangle, up, down, left, right);

        //colisão com blocos
        int hr = 255, hg = 0, hb = 0, qr = 0, qg = 0, qb = 255, cr = 0, cg = 255, cb = 0;
        Colisao(rectangle, hexagon, up, down, left, right, hr, hg, hb);
        Colisao(rectangle, quadrado, up, down, left, right, qr, qg, qb);
        Colisao(rectangle, cor, up, down, left, right, cr, cg, cb);

        //impedir de sair da janela
        Parede(rectangle, top, up, down, left, right);
        Parede(rectangle, bottom, up, down, left, right);
        Parede(rectangle, lSide, up, down, left, right);
        Parede(rectangle, rSide, up, down, left, right);

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.draw(hexagon);
        window.draw(quadrado);
        window.draw(cor);
        window.display();
    }

    return 0;
}

void Movimento(sf::RectangleShape& player, int& up, int& down, int& left, int& right){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-0.1, 0.f);
            left++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(0.1, 0.f);
            right++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.move(0.f, -0.1);
            up++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.move(0.f, 0.1);
            down++;
        }
}

void Colisao(sf::RectangleShape& colidindo, sf::RectangleShape& colisor, int& up, int& down, int& left, int& right, int r, int g, int b) {
    if (colidindo.getGlobalBounds().intersects(colisor.getGlobalBounds())) {
        colisor.setFillColor(sf::Color(r, g, b));
        if (left > right) {
            colisor.move(-0.1, 0.f);
            colidindo.move(0.11, 0.f);
            left = 0;
            right = 0;
        }
        if (right > left) {
            colisor.move(0.1, 0.f);
            colidindo.move(-0.11, 0.f);
            right = 0;
            left = 0;
        }
        if (up > down) {
            colisor.move(0.f, -0.1);
            colidindo.move(0.f, 0.11);
            up = 0;
            down = 0;
        }
        if (down > up) {
            colisor.move(0.f, 0.1);
            colidindo.move(0.f, -0.11);
            down = 0;
            up = 0;
        }
    } else {
        colisor.setFillColor(sf::Color(r, g, b, 200));
    }
}

void Parede(sf::RectangleShape& colidindo, sf::RectangleShape& colisor, int& up, int& down, int& left, int& right) {
    if (colidindo.getGlobalBounds().intersects(colisor.getGlobalBounds())) {
        if (left > right) {
            colidindo.move(0.1, 0.f);
            left = 0;
            right = 0;
        }
        if (right > left) {
            colidindo.move(-0.1, 0.f);
            right = 0;
            left = 0;
        }
        if (up > down) {
            colidindo.move(0.f, 0.1);
            up = 0;
            down = 0;
        }
        if (down > up) {
            colidindo.move(0.f, -0.1);
            down = 0;
            up = 0;
        }
    }
}
