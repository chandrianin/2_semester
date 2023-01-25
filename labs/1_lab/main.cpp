#include <iostream>
#include <thread>
#include <animation.h>

void textOutput(const animatedText& obj){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lab_1");
    sf::Text SFMLText;
    sf::Font mainFont;
    if (mainFont.loadFromFile("..\\ext\\font\\GoogleSans-Regular.ttf")){
        SFMLText.setFont(mainFont);
        SFMLText.setCharacterSize(20);
        SFMLText.setFillColor(sf::Color::Black);
        SFMLText.setStyle(sf::Text::Regular);
        SFMLText.setPosition(0,0);
    }
    else{
        std::cout << "FontUploadFail" << std::endl;
    }
    unsigned short index = 0;
    std::string tempText;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        if (index < obj.getText().length()){
            for (int i = 0; i <= index; i++){
                tempText += obj.getText()[i];
            }
            SFMLText.setString(tempText);
            tempText = "";
            index++;
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(obj.getInterval()));
        window.draw(SFMLText);
        window.display();
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    animatedText test(10, "Hello!");
    textOutput(test);
    return 0;
}
