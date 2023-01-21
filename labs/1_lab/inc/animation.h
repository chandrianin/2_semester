#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>

class animatedText{
private:
    unsigned int m_duration;
    unsigned int m_interval;
    std::string m_text;
    sf::Text SFMLText;
    sf::Font mainFont;
public:
    animatedText(unsigned int duration, std::string text);

    void textOutput();
};