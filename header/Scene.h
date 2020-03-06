//
// Created by adrien on 21/02/2020.
//

#include "Bmpfile.h"
#include "Object3d.h"
#include "Color.h"
#include <iostream>

#ifndef TD_IMAGE_SYNTH_SCENE_H
#define TD_IMAGE_SYNTH_SCENE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include "dirLight.h"



using namespace std;

class Scene {
protected:
    BMPFile scene;

    dirLight defaultLightDirection;

    dirLight secondLightDirection;

    vector<Object3d*> objectList;

    Color getPixelColor(int nearestDistanceCoeff, Vector3d pixelPoint, Ray& raycast);

public:
    Scene();

    Scene(Vector3d& otherDirLight, Color& colorLight, Vector3d& secondDL, Color& secondCL);

    unsigned char* Raytrace(unsigned int width, unsigned  int height, Vector3d ray_o, float k_vision);

    void addObject3d(Object3d* new_obj);

    void render(string fileName, unsigned int width, unsigned  int height, Vector3d ray_o, float k_vision);

    int getNearestDistance(Ray& raycast);
};


#endif //TD_IMAGE_SYNTH_SCENE_H
