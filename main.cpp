#include <iostream>
#include <SFML/Graphics.hpp>


// min_length and min_height have to be considered as float values instead of just integer numbers
//last check if everything works


int main() {
    int WIDTH = 500;
    int HEIGHT = 500;
    int REC_WIDTH = 120;
    int REC_HEIGHT= 50;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    sf::RectangleShape rec(sf::Vector2f(REC_WIDTH, REC_HEIGHT));
    rec.setFillColor(sf::Color::Green);
    rec.setPosition(10, 10);
    bool movingRight = false;
    bool movingLeft= false;
    bool movingUp= false;
    bool movingDown= false;
    float one_step = 1;
    float gravity_one_step = 5;
    float gravity_one_step_init = 5;
    float decrimator = 0.01f;
    int temp = 1;
    float y_pos = 0.0f;
    float x_pos = 0.0f;
    while (window.isOpen())
    {
        sf::Event event;
        if (movingRight == true)
        {
            sf::Vector2f pos = rec.getPosition();
            rec.setPosition(sf::Vector2f(pos.x + one_step * decrimator, pos.y));
        }
        if (movingLeft== true)
        {
            sf::Vector2f pos = rec.getPosition();
            rec.setPosition(sf::Vector2f(pos.x - one_step * decrimator, pos.y));
        }
        if (movingUp== true)
        {
            sf::Vector2f pos = rec.getPosition();
            rec.setPosition(sf::Vector2f(pos.x, pos.y - one_step * decrimator));
        }
        if (movingDown== true)
        {
            sf::Vector2f pos = rec.getPosition();
            rec.setPosition(sf::Vector2f(pos.x, pos.y + one_step * decrimator));
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    gravity_one_step = gravity_one_step_init;
                    rec.setPosition(sf::Vector2f(50, 50));
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    movingRight = true;
                }
                 if (event.key.code == sf::Keyboard::A)
                {
                    movingLeft = true;
                }
                if (event.key.code == sf::Keyboard::W)
                {
                    movingUp= true;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    movingDown= true;
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::D)
                {
                    movingRight = false;
                }
                 if (event.key.code == sf::Keyboard::A)
                {
                    movingLeft = false;
                }

                if (event.key.code == sf::Keyboard::W)
                {
                    movingUp= false;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    movingDown= false;
                }
            }


           
            if (event.type == sf::Event::Closed)
                window.close();
        }
            y_pos = rec.getPosition().y;
            x_pos = rec.getPosition().x;
            //while (temp < 500)
            if ( y_pos < HEIGHT - REC_HEIGHT)
            {
                std::cout << "y_pos: " << y_pos << std::endl;
                rec.setPosition(sf::Vector2f(x_pos, y_pos + gravity_one_step * decrimator));
                gravity_one_step += 0.05;
            }


        window.clear();
        window.draw(rec);
        window.display();
    }

}