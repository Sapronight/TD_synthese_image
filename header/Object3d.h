//
// Created by adrien on 21/02/2020.
//
#include "Ray.h"
#include "Color.h"

#ifndef TD_IMAGE_SYNTH_OBJECT3D_H
#define TD_IMAGE_SYNTH_OBJECT3D_H

class Object3d{
protected:
    Vector3d origin;

    Color color;

public:
    /* -- Constructor -- */

    Object3d();

    Object3d(Vector3d& new_origin, Color& new_color);

    /* -- Getters -- */

    Color getColor() const;


    /* -- Other -- */

    virtual float intersect(Ray& ray) = 0;
};

#endif //TD_IMAGE_SYNTH_OBJECT3D_H
