#ifndef __RAY_H__
#define __RAY_H__

#include"Vec3.h"
class Ray {

    public:
    Ray(){}
    Ray(const Vec3& o, const Vec3& d):O(o),D(d){}
    Vec3 origin() const {return O;}
    Vec3 direction() const {return D;}
    Vec3 point_at_parameter(float t) const {return O + D*t;}


    Vec3 O;
    Vec3 D;

};


#endif //__RAY_H__