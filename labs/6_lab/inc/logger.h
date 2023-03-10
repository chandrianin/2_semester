#pragma once
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

namespace utils {
    enum class LEVELS{
        RELEASE,
        DEBUG
    };
    std::ostream& operator<< (std::ostream& out, LEVELS level){
        switch (level) {
            case LEVELS::RELEASE:
                out << "RELEASE";
                break;
            case LEVELS::DEBUG:
                out << "DEBUG";
                break;
            default:
                out << "Ошибка";
                break;
        }
        return out;
    }

    class logger {
    private:
        static std::ofstream m_out;
        static LEVELS m_level;
    public:
        static void setFile(const std::string& fileName){
            m_out.open(fileName);
        }
        static void setLevel(LEVELS level) {m_level = level;}
        static void write(const std::string& logText){
            if (m_level != LEVELS::RELEASE){
                std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now(); // текущее время в секундах
                std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime); // преобразование в тип time_t
                std::cerr << std::ctime(&currentTimeT) << m_level << " " << logText << std::endl; // компилятор ругается на ctime
                m_out << std::ctime(&currentTimeT) << m_level << " " << logText << std::endl;
            }
        }

    };
    std::ofstream logger::m_out;
    LEVELS logger::m_level = LEVELS::RELEASE;

}


