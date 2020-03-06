//
// Created by adrien on 21/02/2020.
//

#include "../header/Sphere.h"

Sphere::Sphere(): Object3d() {
    rayon = 0;
}

Sphere::Sphere(Vector3d& new_origin, Color& new_color,float new_rayon, float n_ks, float n_shiny
        , float n_kr): Object3d(new_origin, new_color, n_ks ,n_shiny , n_kr) {
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

Color Sphere::lightInfluenceLambert(Vector3d pixelPoint, Color colorLight,
        Vector3d directionLight, Color secondCL, Vector3d secondDL, Ray& raycast) {
    // TODO: Ne pas oublier de normaliser le vecteur Normal (via getNormalAt)
    // TODO: Normaliser les couleurs pour faire les calculs
    /* Idiffuse */
    Vector3d normalVector = getNormalAt(pixelPoint).normalize();
    Vector3d normalizeColorLight = colorLight.normalize().toVector();
    Vector3d normalizeColorObject = color.normalize().toVector();

    //Vector3d scalarProduct = normalVector.dot(directionLight.normalize());
    float scalarProduct =  - normalVector.dot(directionLight);
    if(scalarProduct < 0){
        scalarProduct = 0;
    }


    Vector3d normalizeSecondCL = secondCL.normalize().toVector();
    float secondScalarP =  - normalVector.dot(secondDL);
    if(secondScalarP < 0){
        secondScalarP = 0;
    }

    // cout << normalVector << normalizeColorLight << normalizeColorObject << colorLight << endl;

    Vector3d temp_res = normalizeColorObject * (normalizeColorLight * scalarProduct + normalizeSecondCL * secondScalarP);


    /* Ispecular */
    Vector3d toObservator = (raycast.getOrigin() - pixelPoint).normalize();
    Vector3d reflexion = normalVector * (-scalarProduct);
    reflexion = reflexion * 2;
    reflexion = reflexion - directionLight;
    reflexion = reflexion.normalize();
    float scalarProduct3 = - reflexion.dot(toObservator);
    if(scalarProduct3 < 0){
        scalarProduct3 = 0;
    }
    Vector3d Ispec = colorLight.normalize().toVector() * pow(scalarProduct3, m_shiny);
    Ispec = Ispec * m_ks;
    temp_res += Ispec;


    Vector3d toObservator2 = (raycast.getOrigin() - pixelPoint).normalize();
    Vector3d reflexion2 = normalVector * (-secondScalarP);
    reflexion2 = reflexion2 * 2;
    reflexion2 = reflexion2 - secondDL;
    reflexion2 = reflexion2.normalize();
    float scalarProduct4 =  reflexion2.dot(toObservator2);
    if(scalarProduct4 < 0){
        scalarProduct4 = 0;
    }

    Vector3d Ispec2 = secondCL.normalize().toVector() * pow(scalarProduct4, m_shiny);
    Ispec2 = Ispec2 * m_ks;
    temp_res += Ispec2;


    /* END */
    cout << scalarProduct4 << endl;
    // cout << temp_res << endl;
    Color res = Color(temp_res.x, temp_res.y, temp_res.z).unNormalize();

    return res;

}

Vector3d Sphere::getNormalAt(Vector3d pixelPoint) {
    Vector3d res;
    res = pixelPoint - origin;
    return res;
}



