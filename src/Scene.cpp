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
                                             - (float(y - height / 2.0)),
                    0.0);
            Vector3d ray_dir = bufferPoint-ray_o;

            Ray raycast = Ray(ray_o, ray_dir);

            Vector3d color = getPixelColor(getNearestDistance(raycast), bufferPoint).toBGR();

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

void Scene::render(string fileName, unsigned int width, unsigned int height, Vector3d ray_o, float k_vision) {
    scene.SaveBmp(fileName, Raytrace(width, height, ray_o, k_vision), width, height);
}

int Scene::getNearestDistance(Ray &raycast) {
    unsigned int minId = -1;
    vector<float> intersectList;
    vector<unsigned int> idList;

    for (unsigned int i = 0; i < objectList.size(); i++){
        float intersect_tmp = objectList[i]->intersect(raycast);
        if (intersect_tmp >= 0){
            intersectList.push_back(intersect_tmp);
            idList.push_back(i);
        }
    }

    if (!intersectList.empty()){
        int minElementIndex = min(intersectList.begin(),intersectList.end()) - intersectList.begin();
        minId = idList[minElementIndex];
    }

    return minId;
}

Color Scene::getPixelColor(int nearestDistanceCoeff, Vector3d pixelPoint) {
    Color res = Color();

    // TODO : Remplacement du getColor par la formule :
    if(nearestDistanceCoeff >= 0){
        // res = objectList[nearestDistanceCoeff]->getColor();
        res = objectList[nearestDistanceCoeff]->lightInfluenceLambert(pixelPoint,
                defaultLightDirection.getLightColor(), defaultLightDirection.getVectorDirLight(),
                secondLightDirection.getLightColor(), secondLightDirection.getVectorDirLight());
    }

    return res;
}

Scene::Scene() {
    defaultLightDirection = dirLight();
    secondLightDirection = dirLight();
}

Scene::Scene(Vector3d& otherDirLight, Color& colorLight, Vector3d& secondDL, Color& secondCL) {
    defaultLightDirection.setVectorDirLight(otherDirLight);
    defaultLightDirection.setLightColor(colorLight);

    secondLightDirection.setLightColor(secondCL);
    secondLightDirection.setVectorDirLight(secondDL);
}
