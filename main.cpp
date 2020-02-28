#include "./header/main.h"

using namespace std;

int intersection_test(){
    // Points
    Vector3d src_point(3, 5, 2);
    Vector3d dst_point(35, 47, 6);

    //Vectors
    Vector3d dir = (dst_point - src_point).normalize();

    //Sphere
    float R_sphere = 1;
    Vector3d c_sphere(12, 15, 8);

    //t-Computing
    Vector3d sphere_to_point = src_point - c_sphere;

    float a = 1;
    float b = 2 * (dir.dot(sphere_to_point));
    float c = sphere_to_point.dot(sphere_to_point) - pow(R_sphere, 2);

    float delta = pow(b, 2) - (4 * a * c);

    float t1, t2, t;
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
        cout << "Intersection : " << t << endl;
    }
    else{
        cout << "No intersections" << endl;
    }
    return 0;
}

int main(){
    //    unsigned int width, height;
    //	unsigned char *bmp = BMPFile::LoadBmp("../images/earth.bmp", width, height);
    //	BMPFile::SaveBmp("../images/earth_copy.bmp", bmp,width,height);

	// Test Scene :

	Scene test1;
	// test1.Raytrace("../images/rouge.png", 1080, 720);

	// Test GameObject

    Sphere *pSphere;
    Vector3d c_sphere = Vector3d(0, 0, -10);
    Color c_color = Color(255, 0, 0);
    pSphere = new Sphere(c_sphere, c_color , 10);
    test1.addObject3d(pSphere);

    Sphere *p2Sphere;
    Vector3d c2_sphere = Vector3d(-30, -30, -10);
    Color c2_color = Color(0, 255, 0);
    p2Sphere = new Sphere(c2_sphere, c2_color, 50);
    test1.addObject3d(p2Sphere);



    //DirectionalLight *pLight = new DirectionalLight(Vector3d(1, 0, 0));
    //scene.AddLight(pLight);

    test1.render("../images/output.bmp", 200, 200, Vector3d(0, 0, 100), 0.1);

    //intersection_test();
    return 0;
}
