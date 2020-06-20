/*
    15.21选择图形基本单元
 */

#include <iostream>

using namespace std;

class GraphX{

public:
    GraphX() = default;
    GraphX(const string g_name, const double den):
        GraphX_name(g_name), density(den){}
    
    virtual double compute_volume(){return 0;};
    virtual double compute_surface_area(){return 0;};
    virtual double compute_weight(){return 0;};
    virtual ~GraphX(){};
protected:
    string GraphX_name;
    double density;

};

class AttrGraphX:public GraphX{

public:
    AttrGraphX() = default;
    AttrGraphX(const string g_name, const double den, const double v = 0, const double s = 0, const double w = 0):
        GraphX(g_name, den), volume(v), surface_area(s), weight(w){};
    double compute_volume() = 0;
    double compute_surface_area() = 0;
    double compute_weight() = 0;  
protected:
    double volume;
    double surface_area;
    double weight;

};


class Cube: public AttrGraphX{

public:
    Cube() = default;
    Cube(const string name, const double den, double wid):
        AttrGraphX(name, den), width(wid){};
    double compute_volume(){
        return volume = width*width*width;
    }
    double compute_surface_area(){
        return surface_area = width*width*6;
    }
    double compute_weight(){
        return weight = compute_volume() * density;
    }
protected:
    double width;

};

class Sphere: public AttrGraphX{

public:
    Sphere() = default;
    Sphere(const string name, const double den, const double r):
        AttrGraphX(name, den), radius(r){};

    double compute_volume(){
        return volume = 4/3*(3.14159)*radius*radius*radius;
    }
    double compute_surface_area(){
        return surface_area = 4*(3.14159)*radius*radius;
    }
    double compute_weight(){
        return weight = compute_volume() * density;
    }
protected:
    double radius;

};

int main(){

    Cube cube1("cube1", 1.2, 15.6);
    Sphere sphere1("sphere1", 1.2, 15.6/2);
    cout<<"the cube1 surface area is:"<<cube1.compute_surface_area()<<endl;
    cout<<"the cube1 volume is:"<<cube1.compute_volume()<<endl;
    cout<<"the cube1 weight is:"<<cube1.compute_weight()<<endl;
    
    cout<<"the sphere1 surface area is:"<<sphere1.compute_surface_area()<<endl;
    cout<<"the sphere1 volume is:"<<sphere1.compute_volume()<<endl;
    cout<<"the sphere1 weight is:"<<sphere1.compute_weight()<<endl;
    

}
