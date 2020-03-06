//
// Created by adrien on 21/02/2020.
//
#include "Color.h"
#include "Object3d.h"
#ifndef TD_IMAGE_SYNTH_SPHERE_H
#define TD_IMAGE_SYNTH_SPHERE_H
#include <iostream>

using namespace std;

class Sphere: public Object3d{
protected:
    float rayon;
public:
    Sphere();

    Sphere(Vector3d& new_origin, Color& new_color, float new_rayon, float n_ks, float n_shiny, float n_kr);

    float intersect(Ray &ray) override;

    Color lightInfluenceLambert(Vector3d pixelPoint, Color colorLight, Vector3d directionLight
            , Color secondCL, Vector3d secondDL, Ray& raycast) override ;

    Vector3d getNormalAt(Vector3d pixelPoint) override ;
};

#endif //TD_IMAGE_SYNTH_SPHERE_H
