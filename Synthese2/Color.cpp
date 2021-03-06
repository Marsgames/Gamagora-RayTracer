//
//  Color.cpp
//  Synthese2
//
//  Created by Raphaël Daumas on 29/05/2019.
//  Copyright © 2019 Marsgames. All rights reserved.
//

#include "Color.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

double Color::GetR() const {
    return m_r;
}

double Color::GetG() const {
    return m_g;
}

double Color::GetB() const {
    return m_b;
}

void Color::Print() const
{
    cout << "Color(" << m_r << ", " << m_g << ", " << m_b << ")" << endl;
}

string Color::ToString() const
{
    return "Color(" + to_string(m_r) + ", " + to_string(m_g) + ", " + to_string(m_b) + ")";
}

Color Color::operator*(const Color& other) const
{
    return Color{m_r * other.m_r, m_g * other.m_g, m_b * other.m_b};
}
Color Color::operator*(const double other) const
{
    return Color{static_cast<double>(m_r * other), static_cast<double>(m_g * other), static_cast<double>(m_b * other)};
}
bool Color::operator==(const Color &other) const {
    return m_r == other.m_r && m_g == other.m_g && m_b == other.m_b;
}

void Color::SetColorName() {
    if (0 == m_r && 0 == m_g && 0 == m_b)
    {
        m_colorName = EColor::Black;
    }
    else if (1 == m_r && 0 == m_g && 0 == m_b)
    {
        m_colorName = EColor::Red;
    }
    else if (0 == m_r && 1 == m_g && 0 == m_b)
    {
        m_colorName = EColor::Green;
    }
    else if (0 == m_r && 0 == m_g && 1 == m_b)
    {
        m_colorName = EColor::Blue;
    }
    else if (1 == m_r && 1 == m_g && 1 == m_b)
    {
        m_colorName = EColor::White;
    }
    else
    {
        m_colorName = EColor::Other;
    }
}

EColor Color::GetColorName() const {
    return m_colorName;
}

Color Color::GetColor(const EColor& colorName) {
    switch (colorName) {
        case Black:
            return Color{0, 0, 0};
            break;
        case Red:
            return Color{1, 0, 0};
            break;
        case Green:
            return Color{0, 1, 0};
            break;
        case Blue:
            return Color{0, 0, 1};
            break;
        case White:
            return Color{1, 1, 1};
            break;
        case Pink:
            return Color{1, 0, 1};
            break;
        case Yellow:
            return Color{1, 1, 0};
            break;
            
        default:
            return Color{0, 0, 0};
            break;
    }
}

void Color::SetR(double value) {
    m_r = value;
}

void Color::SetG(double value) {
    m_g = value;
}

void Color::SetB(double value) {
    m_b = value;
}

void Color::operator+=(const Color &other) {
    m_r += other.m_r;
    m_g += other.m_g;
    m_b += other.m_b;
}

Color Color::operator/(const double value) const {
    return Color(m_r / value, m_g / value, m_b / value);
}

Color Color::operator+(const Color &other) const {
    return Color(m_r + other.m_r, m_g + other.m_g, m_b + other.m_b);
}

Color Color::operator-(const Color &other) const {
    return Color(m_r - other.m_r, m_g - other.m_g, m_b - other.m_b);
}



