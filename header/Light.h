//
// Created by adrien on 28/02/2020.
//

#ifndef TD_IMAGE_SYNTH_LIGHT_H
#define TD_IMAGE_SYNTH_LIGHT_H
#pragma once

#include "Color.h"

class Light {
protected:
    // ATTRIBUTES
    Color light_color;

public:
    // METHODES
    /* -- Constructor -- */
    Light();

    Light(Color new_LightColor);

    Light(Light& otherLight);


    /* -- Getters -- */

    Color getLightColor() const;

    /* -- Setters -- */

    void setLightColor(Color& otherLightColor);

};

#endif //TD_IMAGE_SYNTH_LIGHT_H
