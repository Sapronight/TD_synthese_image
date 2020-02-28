//
// Created by adrien on 21/02/2020.
//

#ifndef TD_IMAGE_SYNTH_OBJECT3D_H
#define TD_IMAGE_SYNTH_OBJECT3D_H

#include "Ray.h"

class Object3d{
protected:
    Vector3d origin, color;

public:

    Object3d();

    Object3d(Vector3d& new_origin, Vector3d& new_color);

    virtual float intersect(Ray& ray) = 0;

    // Getters

    Vector3d getColor() const;
};

#endif //TD_IMAGE_SYNTH_OBJECT3D_H
