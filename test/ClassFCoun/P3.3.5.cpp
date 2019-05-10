//
// Created by z16cn on 2019/5/6.
//

#include <stdio.h>
using namespace std;
class F{
public:
    double x=0;
    double y=0;
    double z=0;

    void jac(){
        double x_k_a_1=x;
        double y_k_a_1=y;
        double z_k_a_1=z;
        x_k_a_1=(11-8*y+z)/2;
        y_k_a_1=(10-5*x-z)/(-1);
        z_k_a_1=(3+x-y)/(4);
        x=x_k_a_1;
        y=y_k_a_1;
        z=z_k_a_1;
    }

    void Guass(){
        double x_k_a_1=x;
        double y_k_a_1=y;
        double z_k_a_1=z;
        x_k_a_1=(11-8*y+z)/2;
        y_k_a_1=(10-5*x_k_a_1-z)/(-1);
        z_k_a_1=(3+x_k_a_1-y_k_a_1)/(4);
        x=x_k_a_1;
        y=y_k_a_1;
        z=z_k_a_1;
    }
};


int main(){
    F j, g;
    for(int i=0; i<3; i++){
        j.jac();
        printf("X%d=(%lf,%lf,%lf)\n",i+1, j.x, j.y, j.z);
    }

    for(int i=0; i<3; i++){
        g.Guass();
        printf("X%d=(%lf,%lf,%lf)\n",i+1, g.x, g.y, g.z);
    }
}
