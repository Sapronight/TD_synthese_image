//
// Created by adrien on 28/02/2020.
//

#include "../header/Color.h"

Color::Color() {
    m_red = 0;
    m_green = 0;
    m_blue = 0;
}


Color::Color(float red, float green, float blue) {
    m_red = red;
    m_blue = blue;
    m_green = green;
}

Color::Color(Color& new_color) {
    m_red = new_color.m_red;
    m_blue = new_color.m_blue;
    m_green = new_color.m_green;
}

std::ostream &operator<<(std::ostream &out, const Color c) {
    out << "(red : " << c.m_red << ", blue :" << c.m_blue << ", green :" << c.m_green << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Color &c) {
    in >> c.m_red >> c.m_blue >> c.m_green;
    return in;
}

Color Color::operator+(const Color &c2) {
    float red = m_red + c2.m_red;
    if (red > 255) red = 255;
    float blue = m_blue + c2.m_blue;
    if (blue > 255) blue = 255;
    float green = m_green + c2.m_green;
    if (green > 255) green = 255;

    return Color(red, green, blue);
}

Color Color::operator-(const Color &c2) {
    float red = m_red - c2.m_red;
    if (red < 0) red = 0;
    float blue = m_blue - c2.m_blue;
    if (blue < 0) blue = 0;
    float green = m_green - c2.m_green;
    if (green < 0) green = 0;

    return Color(red, green, blue);
}

Color Color::operator=(const Color &c2) {
    m_red = c2.m_red;
    m_green = c2.m_green;
    m_blue = c2.m_blue;
    return *this;
}

Color Color::operator+=(const Color &c2) {
    m_red = m_red + c2.m_red;
    if (m_red > 255) m_red = 255;

    m_green = m_green + c2.m_green;
    if(m_green > 255) m_green = 255;

    m_blue = m_blue + c2.m_blue;
    if(m_blue > 255) m_blue = 255;

    return *this;
}

Color Color::operator-=(const Color &c2) {
    m_red = m_red - c2.m_red;
    if (m_red < 0) m_red = 0;

    m_green = m_green - c2.m_green;
    if(m_green < 0) m_green = 0;

    m_blue = m_blue - c2.m_blue;
    if(m_blue < 0) m_blue = 0;

    return *this;
}

Color Color::operator*(const float k) {
    float red = m_red * k;
    if (red > 255) red = 255;

    float green = m_green * k;
    if (green > 255) green = 255;

    float blue = m_blue * k;
    if (blue > 255) blue = 255;

    m_red = red;
    m_green = green;
    m_blue = blue;

    return *this;
}

bool Color::operator==(const Color &c2) {
    if (m_red == c2.m_red && m_green == c2.m_green && m_blue == c2.m_blue){
        return true;
    }
    return false;
}

bool Color::operator!=(const Color &c2) {
    if (m_red != c2.m_red || m_green != c2.m_green || m_blue != c2.m_blue){
        return true;
    }
    return false;
}

Vector3d Color::toBGR() {
    return Vector3d(m_blue, m_green, m_red);
}

Color Color::normalize() {
    float other_red = m_red / 255;
    float other_green = m_green / 255;
    float other_blue = m_blue / 255;

    return Color(other_red, other_green, other_blue);
}

Color Color::unNormalize() {
    m_red = m_red * 255;
    m_green = m_green * 255;
    m_blue = m_blue * 255;

    return *this;
}



