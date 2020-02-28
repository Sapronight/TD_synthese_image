//
// Created by adrien on 21/02/2020.
//

#ifndef TD_IMAGE_SYNTH_RAY_H
#define TD_IMAGE_SYNTH_RAY_H

#include "Vector3d.h"

class Ray {
private:
    Vector3d origin, direction;
public:
    Ray();

    Ray(Vector3d& new_origin, Vector3d& new_direction);

    //Getters
    Vector3d getOrigin() const;
    Vector3d getDirection() const;

    //Setters
    void setOrigin(Vector3d& new_origin);
    void setDirection(Vector3d& new_direction);
};

#endif //TD_IMAGE_SYNTH_RAY_H
