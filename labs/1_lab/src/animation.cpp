#include <animation.h>
#include <iostream>

#include <utility>


animatedText::animatedText(unsigned int duration, const std::string& text){
    m_duration = duration;
    // std::move насколько я понял, перемещает вместо копирования,
    // что в данном случае выгоднее
    m_text = std::move(text);
    m_interval = (m_text.length() * 1000000) / m_duration;
}

unsigned int animatedText::getInterval() const {
    return m_interval;
}

std::string animatedText::getText() const {
    return m_text;
}