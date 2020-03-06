//
// Created by adrien on 28/02/2020.
//
#include "Light.h"

#ifndef TD_IMAGE_SYNTH_DIRLIGHT_H
#define TD_IMAGE_SYNTH_DIRLIGHT_H

class dirLight : public Light{
public:
    //METHODS
    dirLight();

    dirLight(Vector3d& vectorLight, Color& lightColor);

    dirLight(dirLight& new_dirLight);

    /* -- getters -- */
    Vector3d getVectorDirLight() const;

    /* -- setters -- */

    void setVectorDirLight(Vector3d& new_dirLight);

private:
    // ATTRIBUTES
    Vector3d vectorDirLight;
};



#endif //TD_IMAGE_SYNTH_DIRLIGHT_H
