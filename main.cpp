#include <iostream>
#include <fstream>
#include "INCLUDES/Vec3.h"
#include "INCLUDES/Ray.h"

Vec3 color(const Ray& r){
    Vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1 );
    return (1.0 -t) * Vec3(1.0,1.0,1.0) + t * Vec3(0.5,0.7,1.0);
}
int main(){
    int nx = 200;
    int ny = 100;
    std::ofstream image ;
    image.open("fristImage.ppm");
    image <<"P3\n" << nx << " " << ny << "\n255\n";
    Vec3 lower_left_corner(-2.0,-1.0,-1.0);
    Vec3 axis_0(4.0,0.0,0.0); //Horizontal axis
    Vec3 axis_1(0.0,2.0,0.0); //Vertical axis
    Vec3 origin (0.0,0.0,0.0);


    for (int j = ny-1; j >= 0 ; j--){
        for ( int i = 0; i < nx ; i++){
            // float r = float (i) / float(nx);
            // float g = float (j) / float(ny);
            // float b = 0.2;
            float u = float (i) / float(nx);
            float v = float (j) / float(ny);
            
            Ray r(origin, lower_left_corner + u*axis_0 + v*axis_1);

            
            Vec3 col = color(r);
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

            image << ir << " " << ig << " " << ib << "\n";

            
        }
    }
}