//
// Created by adrien on 21/02/2020.
//

#include "../header/Object3d.h"

Object3d::Object3d() {
    origin =  Vector3d(0, 0, 0);
    color = Vector3d(255, 0, 0);
}

Object3d::Object3d(Vector3d& new_origin, Vector3d& new_color) {
    origin = new_origin;
    color = new_color;
}

Vector3d Object3d::getColor() const {
    return color;
}

