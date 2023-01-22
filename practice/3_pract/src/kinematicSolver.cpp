#include <kinematicSolver.h>
#include <iostream>
#include <SFML/Graphics.hpp>

void kinematicSolver::solve() {
    // Сначала находим одну из двух точек пересечения
    float a1 = 4 * (m_Mx * m_Mx + m_My * m_My);
    float b1 = -4 * m_Mx * (m_L1 * m_L1 - m_L2 * m_L2 + m_Mx * m_Mx + m_My * m_My);
    float c1 = (m_L1 * m_L1 - m_L2 * m_L2 + m_Mx * m_Mx + m_My * m_My) * (m_L1 * m_L1 - m_L2 * m_L2 + m_Mx * m_Mx + m_My * m_My) - 4 * m_My * m_My * m_L1 * m_L1;
    float D = b1 * b1 - 4 * a1 * c1;
    if (D < 0){
        std::cout << "Точка слишком далеко!" <<std::endl;
    }
    else{
        auto x1 = static_cast<float>((-b1 + std::sqrt(D)) / (2 * a1));
        auto y1 = static_cast<float>(sqrt(m_L1 * m_L1 - x1 * x1));
        auto x2 = static_cast<float>((-b1 - std::sqrt(D)) / (2 * a1));
        auto y2 = static_cast<float>(sqrt(m_L1 * m_L1 - x2 * x2));
        if (this->checkFirstFormula(x1, -y1) && this->checkSecondFormula(x1, -y1)){
            m_Px = x1;
            m_Py = -y1;
        }
        else if (this->checkFirstFormula(x2, -y2) && this->checkSecondFormula(x2, -y2)){
            m_Px = x2;
            m_Py = -y2;
        }
        else if (this->checkFirstFormula(x1, y1) && this->checkSecondFormula(x1, y1)){
            m_Px = x1;
            m_Py = y1;
        }
        else if (this->checkFirstFormula(x2, y2) && this->checkSecondFormula(x2, y2)){
            m_Px = x2;
            m_Py = y2;
        }

//        if (sqrt((m_Mx - x1) * (m_Mx - x1) + (m_My - y1) * (m_My - y1)) < sqrt((m_Mx - x2) * (m_Mx - x2) + (m_My - y2) * (m_My - y2))){
//            m_Px = x1;
//            m_Py = y1;
//        }
//        else{
//            m_Px = x2;
//            m_Py = y2;
//        }
//        auto newAlpha = static_cast<float>(fmod(abs(static_cast<float>(acos(m_Px / m_L1) * (180 / acos(-1)))), 90));
//        auto newBeta = static_cast<float>(fmod(abs(static_cast<float>(acos((m_Mx - m_Px) / m_L2) * (180 / acos(-1)))), 90));
//        newAlpha = m_Px * m_Py > 0 ? newAlpha : -newAlpha;
//        newBeta = m_Mx < m_Px && m_My > m_Py || m_Mx > m_Px && m_My < m_Py ? -newBeta : newBeta;
        auto newAlpha = static_cast<float>(acos(m_Px / m_L1) * (180 / acos(-1)));
        if (m_Px < 0 && m_Py < 0 || m_Px > 0 && m_Py < 0){
            newAlpha = -newAlpha;
        }
        auto newBeta = static_cast<float>(acos((m_Mx - m_Px) / m_L2) * (180 / acos(-1)));
//        if (m_Px < 0 && m_Py > 0 || m_Px > 0 && m_Py < 0){
//            newBeta = - newBeta;
//        }
        visualization(newAlpha, newBeta);

    }


}

void kinematicSolver::visualization(float newAlpha, float newBeta) const {
    std::cout << "Alpha: " << newAlpha << std::endl;
    std::cout << "Beta: " << newBeta << std::endl;
    std::cout << "P: " << m_Px << " " << m_Py << std::endl;
    std::cout << "M: " << m_Mx << " " << m_My << std::endl;
    sf::RenderWindow window(sf::VideoMode(1600,900), "practice_3"/*, sf::Style::Fullscreen*/);
    float x = static_cast<float>(window.getSize().x);
    float y = static_cast<float>(window.getSize().y);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 100;

    // Искомая точка
    sf::CircleShape M(10);
    M.setPosition((x / 2) + m_Mx - 10,(y / 2) - m_My - 10);
    M.setFillColor(sf::Color::Red);

    // Точка соединения
    sf::CircleShape P(10);
    P.setPosition((x / 2) + m_Px - 10,(y / 2) - m_Py - 10);
    P.setFillColor(sf::Color (255, 160, 00));

    // Точка начала
    sf::CircleShape O(10);
    O.setPosition((x / 2) - 10, (y / 2) - 10);
    O.setFillColor(sf::Color (0, 255, 00));

    // Первое звено
    sf::RectangleShape line1(sf::Vector2f(m_L1, 7));
    line1.setFillColor(sf::Color::Black);
    line1.setRotation(-newAlpha);
    line1.setPosition(x / 2, y / 2);

    // Второе звено
    sf::RectangleShape line2(sf::Vector2f(m_L2, 7));
    line2.setFillColor(sf::Color (140, 140, 140));
    line2.setRotation(-newBeta);
    line2.setPosition((x / 2) + m_Px,(y / 2) - m_Py);

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        window.draw(line1);
        window.draw(line2);
        window.draw(O);
        window.draw(M);
        window.draw(P);

        window.display();
    }
}

bool kinematicSolver::checkFirstFormula(float x, float y) const {
    return abs((x - m_Mx) * (x - m_Mx) + (y - m_My) * (y - m_My) - m_L2 * m_L2) < 1;
}

bool kinematicSolver::checkSecondFormula(float x, float y) const {
    return abs(x * x + y * y - m_L1 * m_L1) < 1;
}
