#ifndef TD_IMAGE_SYNTH_VECTOR3D_H
#define TD_IMAGE_SYNTH_VECTOR3D_H
#include <iostream>
#include <cmath>
#pragma once

class Vector3d{
    public:
        // METHODS
        Vector3d(float x_p=0, float y_p=0, float z_p=0);
        Vector3d(const Vector3d &v);
        float dot(const Vector3d v);
        Vector3d cross(const Vector3d v);
        float getNorm();
        Vector3d normalize();

        // OPERATORS
        friend std::ostream &operator << (std::ostream &out, const Vector3d v);
        friend std::istream &operator >> (std::istream &in, Vector3d &v);
        Vector3d operator + (const Vector3d &v2);
        Vector3d operator - (const Vector3d &v2);
        Vector3d operator = (const Vector3d &v2);
        Vector3d operator += (const Vector3d &v2);
        Vector3d operator -= (const Vector3d &v2);
        Vector3d operator * (const float k);

        Vector3d operator * (const Vector3d& v2);
        bool operator == (const Vector3d &v2);
        bool operator != (const Vector3d &v2);

        // ATTRIBUTES
        float x;
        float y;
        float z;
};

#endif //TD_IMAGE_SYNTH_VECTOR3D_H