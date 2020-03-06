//
// Created by adrien on 28/02/2020.
//

#include "../header/Light.h"


Light::Light() {
    light_color = Color();
}

Light::Light(Light& otherLight) {
    light_color = otherLight.getLightColor();
}

Color Light::getLightColor() const {
    return Color(light_color.m_red, light_color.m_green, light_color.m_blue);
}

Light::Light(Color new_LightColor) {
    light_color = new_LightColor;
}

void Light::setLightColor(Color &otherLightColor) {
    light_color = otherLightColor;
}
