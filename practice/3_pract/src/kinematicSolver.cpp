#include <kinematicSolver.h>
#include <iostream>

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
        float x1 = static_cast<float>((-b1 + std::sqrt(D)) / (2 * a1));
        float y1 = static_cast<float>(sqrt(m_L1 * m_L1 - x1 * x1));
        float x2 = static_cast<float>((-b1 - std::sqrt(D)) / (2 * a1));
        float y2 = static_cast<float>(-sqrt(m_L1 * m_L1 - x2 * x2));
        if (sqrt((m_Mx - x1) * (m_Mx - x1) + (m_My - y1) * (m_My - y1)) < sqrt((m_Mx - x2) * (m_Mx - x2) + (m_My - y2) * (m_My - y2))){
            m_Px = x1;
            m_Py = y1;
        }
        else{
            m_Px = x2;
            m_Py = y2;
        }
        auto newAlpha = static_cast<float>(fmod(abs(static_cast<float>(acos(m_Px / m_L1) * (180 / acos(-1)))), 90));
        newAlpha = m_Px * m_Py > 0 ? newAlpha : -newAlpha;
        auto newBeta = static_cast<float>(fmod(abs(static_cast<float>(acos((m_Mx - m_Px) / m_L2) * (180 / acos(-1)))), 90));
        newBeta = m_Mx < m_Px && m_My > m_Py || m_Mx > m_Px && m_My < m_Py ? -newBeta : newBeta;
        visualization(newAlpha, newBeta);

    }


}

void kinematicSolver::visualization(float newAlpha, float newBeta) const {
    std::cout << newAlpha << std::endl;
    std::cout << newBeta << std::endl;
}
