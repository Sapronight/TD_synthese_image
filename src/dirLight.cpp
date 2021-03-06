//
// Created by adrien on 28/02/2020.
//

#include "../header/dirLight.h"


dirLight::dirLight() : Light(){
    vectorDirLight = Vector3d(0, 0, 0);
}

dirLight::dirLight(dirLight& new_dirLight): Light(new_dirLight.getLightColor()) {
    vectorDirLight = new_dirLight.getVectorDirLight();
}

Vector3d dirLight::getVectorDirLight() const {
    return Vector3d(vectorDirLight.x, vectorDirLight.y, vectorDirLight.z);
}

void dirLight::setVectorDirLight(Vector3d& new_dirLight) {
    vectorDirLight = new_dirLight;
}

dirLight::dirLight(Vector3d &vectorLight, Color& lightColor): Light(Color(light_color.m_red, light_color.m_green, light_color.m_blue)) {
    vectorLight = vectorLight;
}


