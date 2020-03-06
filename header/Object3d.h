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

    float ks;

    float shiny;

    float kr;

public:
    /* -- Constructor -- */

    Object3d();

    Object3d(Vector3d& new_origin, Color& new_color, float n_shiny, float n_kr);

    /* -- Getters -- */

    Color getColor() const;

    float getShiny() const;

    float getkr() const;


    /* -- Other -- */

    virtual float intersect(Ray& ray) = 0;

    virtual Color lightInfluenceLambert(Vector3d pixelPoint, Color colorLight, Vector3d directionLight,
            Color secondCL, Vector3d secondDL) = 0;

    virtual Vector3d getNormalAt(Vector3d pixelPoint) = 0;
};

#endif //TD_IMAGE_SYNTH_OBJECT3D_H
