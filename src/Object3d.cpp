//
// Created by adrien on 21/02/2020.
//

#include "../header/Object3d.h"

Object3d::Object3d() {
    origin =  Vector3d(0, 0, 0);
    color = Color();
    shiny = 1.0;
    kr = 1.0;
}

Object3d::Object3d(Vector3d& new_origin, Color& new_color, float n_shiny, float n_kr) {
    origin = new_origin;
    color = new_color;
    shiny = n_shiny;
    kr = n_kr;
}

Color Object3d::getColor() const {
    return Color(color.m_red, color.m_green, color.m_blue);
}

float Object3d::getShiny() const {
    return shiny;
}

float Object3d::getkr() const {
    return kr;
}

