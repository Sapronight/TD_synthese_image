//
// Created by adrien on 28/02/2020.
//
#include "Vector3d.h"

#ifndef TD_IMAGE_SYNTH_COLOR_H
#define TD_IMAGE_SYNTH_COLOR_H
# pragma once

class Color {
public:
    // METHODS
    /* -- Constructor */
    Color();
    Color(float red, float green, float blue);
    Color(Color& new_color);
    /* -- Other -- */

    Vector3d toBGR();
    Vector3d toVector();

    /* -- Operators -- */

    friend std::ostream &operator << (std::ostream &out, const Color c);
    friend std::istream &operator >> (std::istream &in, Color &c);

    Color operator + (const Color &c2);
    Color operator - (const Color &c2);
    Color operator = (const Color &c2);
    Color operator += (const Color &c2);
    Color operator -= (const Color &c2);
    Color operator * (const float k);
    bool operator == (const Color &c2);
    bool operator != (const Color &c2);

    /* -- Other function -- */

    Color normalize();

    Color unNormalize();


    //ATTRIBUTES
    float m_red;
    float m_green;
    float m_blue;
};

#endif //TD_IMAGE_SYNTH_COLOR_H
