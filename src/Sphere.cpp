//
// Created by adrien on 21/02/2020.
//

#include "../header/Sphere.h"

Sphere::Sphere(): Object3d() {
    rayon = 0;
}

Sphere::Sphere(Vector3d& new_origin, Color& new_color, float new_rayon): Object3d(new_origin, new_color) {
    rayon = new_rayon;
}

float Sphere::intersect(Ray &ray) {
    Vector3d dir = ray.getDirection().normalize();
    Vector3d origin_to_point = (ray.getOrigin() - origin);
    // cout << ray.getOrigin() << origin << endl;
    // cout << "Origin_to_point :" << origin_to_point << endl;

    float a = 1;
    float b = 2 * dir.dot(origin_to_point);
    float c = origin_to_point.dot(origin_to_point) - pow(rayon, 2);

    float delta = pow(b, 2) - (4 * a * c);

    float t1, t2;
    float t = -1;
    if(delta >= 0){
        t1 = (- b + sqrt(delta)) / (2 * a);
        t2 = (- b - sqrt(delta)) / (2 * a);
        if(t1 >= 0 && t2 >= 0){
            t = min(t1, t2);
        }
        else if(t1 < 0  && t2 >= 0){
            t = t2;
        }
        else if(t2 < 0  && t1 >= 0){
            t = t1;
        }
        //cout << "Intersection : " << t << endl;
    }
    else{
        //cout << "No intersections" << endl;
        t = -1;
    }

    return t;
}

Color Sphere::lightInfluenceLambert(Vector3d pixelPoint, Color colorLight, Vector3d directionLight) {
    // TODO: Ne pas oublier de normaliser le vecteur Normal (via getNormalAt)
    // TODO: Normaliser les couleurs pour faire les calculs

    Vector3d normalVector = getNormalAt(pixelPoint).normalize();
    Vector3d normalizeColorLight = colorLight.normalize().toBGR();
    Vector3d normalizeColorObject = color.normalize().toBGR();

    //Vector3d scalarProduct = normalVector.dot(directionLight.normalize());
    float scalarProduct = normalVector.dot(directionLight.normalize());
    if(scalarProduct < 0){
        scalarProduct = 0;
    }

    // cout << normalVector << normalizeColorLight << normalizeColorObject << colorLight << endl;

    Vector3d temp_res = normalizeColorObject * normalizeColorLight * scalarProduct;
    Color res = Color(temp_res.z, temp_res.y, temp_res.x).unNormalize();
    return res;
}

Vector3d Sphere::getNormalAt(Vector3d pixelPoint) {
    Vector3d res;
    res = pixelPoint - origin;
    return res;
}



