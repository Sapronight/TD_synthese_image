//
// Created by adrien on 21/02/2020.
//

#include "../header/Sphere.h"

Sphere::Sphere(): Object3d() {
    rayon = 0;
}

Sphere::Sphere(Vector3d& new_origin, Vector3d& new_color, float new_rayon): Object3d(new_origin, new_color) {
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



