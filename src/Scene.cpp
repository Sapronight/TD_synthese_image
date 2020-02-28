//
// Created by adrien on 21/02/2020.
//

#include "../header/Scene.h"

unsigned char* Scene::Raytrace(unsigned int width, unsigned int height, Vector3d ray_o, float k_vision) {
    auto* buffer = new unsigned char[width * height * 3];

    for(unsigned int x = 0; x < width; x++){
        for(unsigned int y = 0; y < height; y++){
            // Vector3d ray_origin = Vector3d(0, 0, 20);
            Vector3d bufferPoint = Vector3d((float(x - width / 2.0 )),
                                            (float(y - height / 2.0)),
                    0.0);
            Vector3d ray_dir = bufferPoint-ray_o;

            Ray raycast = Ray(ray_o, ray_dir);

            Vector3d color = getPixelColor(raycast).toBGR();

            buffer[(y * width + x) * 3 + 0] = color.x;
            buffer[(y * width + x) * 3 + 1] = color.y;
            buffer[(y * width + x) * 3 + 2] = color.z;
        }
    }

    return buffer;
}

void Scene::addObject3d(Object3d *new_obj) {
    objectList.push_back(new_obj);
}

Color Scene::getPixelColor(Ray &raycast) {
    Color res = Color();
    for(unsigned int i = 0; i < objectList.size(); i++){
        if(objectList[i]->intersect(raycast) >= 2){
            res = objectList[i]->getColor();
        }
    }
    return res;
}

void Scene::render(string fileName, unsigned int width, unsigned int height, Vector3d ray_o, float k_vision) {
    scene.SaveBmp(fileName, Raytrace(width, height, ray_o, k_vision), width, height);
}
