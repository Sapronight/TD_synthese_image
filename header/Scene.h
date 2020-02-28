//
// Created by adrien on 21/02/2020.
//

#include "Bmpfile.h"
#include "Object3d.h"
#include "Color.h"

#ifndef TD_IMAGE_SYNTH_SCENE_H
#define TD_IMAGE_SYNTH_SCENE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>


using namespace std;

class Scene {
protected:
    BMPFile scene;

    vector<Object3d*> objectList;

    Color getPixelColor(Ray& raycast);
public:
    unsigned char* Raytrace(unsigned int width, unsigned  int height, Vector3d ray_o, float k_vision);

    void addObject3d(Object3d* new_obj);

    void render(string fileName, unsigned int width, unsigned  int height, Vector3d ray_o, float k_vision);
};


#endif //TD_IMAGE_SYNTH_SCENE_H
