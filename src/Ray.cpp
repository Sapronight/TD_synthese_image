//
// Created by adrien on 21/02/2020.
//

#include "../header/Ray.h"

Ray::Ray() {
    origin = Vector3d(0, 0, 0);
    direction = Vector3d(0, 0, 0);
}

Vector3d Ray::getOrigin() const {
    return origin;
}

Vector3d Ray::getDirection() const {
    return direction;
}

void Ray::setOrigin(Vector3d& new_origin) {
    origin = new_origin;
}

void Ray::setDirection(Vector3d& new_direction) {
    direction = new_direction;
}

Ray::Ray(Vector3d& new_origin, Vector3d& new_direction) {
    origin = new_origin;
    direction = new_direction;
}
