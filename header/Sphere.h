//
// Created by adrien on 21/02/2020.
//

#ifndef TD_IMAGE_SYNTH_SPHERE_H
#define TD_IMAGE_SYNTH_SPHERE_H

#include "Object3d.h"
#include <iostream>

using namespace std;

class Sphere: public Object3d{
protected:
    float rayon;
public:
    Sphere();

    Sphere(Vector3d& new_origin, Vector3d& new_color, float new_rayon);

    float intersect(Ray &ray) override;
};

#endif //TD_IMAGE_SYNTH_SPHERE_H
