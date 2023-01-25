#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>

class animatedText{
private:
    unsigned int m_duration;
    unsigned int m_interval;
    std::string m_text;
public:
    animatedText(unsigned int duration, const std::string& text);
    [[nodiscard]] unsigned int getInterval() const;
    [[nodiscard]] std::string getText() const;
};