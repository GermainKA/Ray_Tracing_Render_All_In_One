#ifndef __VEC3_H__
#define __VEC3_H__

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vec3 {
public :
    Vec3(){}
    Vec3(float e0,float e1, float e2){e[0] = e0 ; e[1] = e1 ; e[2]= e2;}

    inline float x() const {return e[0];}
    inline float y() const {return e[1];}
    inline float z() const {return e[2];}
    inline float r() const {return e[0];}
    inline float g() const {return e[1];}
    inline float b() const {return e[2];}

    inline const Vec3& operator+() const {return *this;}
    inline Vec3 operator-() {return Vec3(-e[0], -e[1], -e[2]);}
    inline float operator[](int i) const {return e[i];}
    inline float& operator[](int i) {return e[i]; }

    inline Vec3& operator+=(const Vec3& v2);
    inline Vec3& operator-=(const Vec3& v2);
    inline Vec3& operator*=(const Vec3& v2);
    inline Vec3& operator/=(const Vec3& v2);
    inline Vec3& operator*=(const float t);
    inline Vec3& operator/=(const float t);

    inline float length(){ return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);}
    inline float squared_length(){ return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];}
    void make_unit_vector();
    
    float e[3];

};

inline Vec3& Vec3::operator+=(const Vec3& v2) {
    e[0] += v2.e[0];
    e[1] += v2.e[1];
    e[2] += v2.e[2];
    return *this; // Retourne l'objet modifié pour permettre l'enchaînement.
}

inline void Vec3::make_unit_vector(){
    float len = length(); 
    if (len > 0) {
        e[0] /= len;
        e[1] /= len;
        e[2] /= len;
    }
}


inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0]+v2.e[0] , v1.e[1] + v2.e[1] , v1.e[2] + v2.e[2]);
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] -v2.e[0] , v1.e[1] -v2.e[1] , v1.e[2] -v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] *v2.e[0] , v1.e[1] *v2.e[1] , v1.e[2] *v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v1, float t) {
    return Vec3(v1.e[0] *t , v1.e[1] *t , v1.e[2] *t);
}
inline Vec3 operator*(float t ,const Vec3 &v1) {
    return v1 * t;
}

inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] /v2.e[0] , v1.e[1] /v2.e[1] , v1.e[2] /v2.e[2]);
}

inline Vec3 operator/(const Vec3 &v1, float t) {
    return Vec3(v1.e[0] /t , v1.e[1] /t , v1.e[2] /t);
}

inline float dot(const Vec3 &v1, const Vec3 &v2){
    return v1.e[0] *v2.e[0] + v1.e[1] *v2.e[1] + v1.e[2] * v2.e[2] ;
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2){
    return Vec3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
                (v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2]),
                (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}

inline Vec3 unit_vector( Vec3 v){
    return v / v.length();
}


#endif // __VEC3_H__