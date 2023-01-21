#include <animation.h>
#include <iostream>
#include <thread>
#include <utility>

animatedText::animatedText(unsigned int duration, std::string text){
    m_duration = duration;
    // std::move насколько я понял, перемещает вместо копирования,
    // что в данном случае выгоднее
    m_text = std::move(text);
    m_interval = (m_text.length() * 1000000) / m_duration;

}
void animatedText::textOutput() const{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lab_1");
    sf::Text SFMLText;
    sf::Font mainFont;
    if (mainFont.loadFromFile("/ext/font/GoogleSans-Regular.ttf")){
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
        if (index < m_text.length()){
            for (int i = 0; i <= index; i++){
                tempText += m_text[i];
            }
            SFMLText.setString(tempText);
            tempText = "";
            index++;
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(m_interval));
        window.draw(SFMLText);
        window.display();
    }
}