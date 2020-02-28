//
// Created by adrien on 21/02/2020.
//

#include "../header/Object3d.h"

Object3d::Object3d() {
    origin =  Vector3d(0, 0, 0);
    color = Color();
}

Object3d::Object3d(Vector3d& new_origin, Color& new_color) {
    origin = new_origin;
    color = new_color;
}

Color Object3d::getColor() const {
    return Color(color.m_red, color.m_green, color.m_blue);
}

