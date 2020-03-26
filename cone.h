//-----------------------------------------------------------------------------
// cone.h
// Created by Prasana Guthy on 3/24/20.
// Defines ConeObj and prototypes its related functions.
//-----------------------------------------------------------------------------

#ifndef CONESPROJECT_CONE_H
#define CONESPROJECT_CONE_H
typedef struct ConeObj {
    double h;
    double r;
    double theta;
}ConeObj;

//
// create_cone: constructor of a ConeObj struct that takes
// two points of a vector as input. The second point will be
// the tip of the cone.
//
// x1, y1, z1 : the Cartesian coordinates of a point on a vector.
// x2, y2, z2 : the Cartesian coordinates of a second point on the vector.
// theta: angle of the cone from an edge to the line through the cone's tip and
// base.
//
ConeObj* create_cone(double x1, double y1, double z1,
                     double x2, double y2, double z2,
                     double theta);
//
// delete_cone: Deletes a given ConeObj.
// cone: Pointer to cone object that needs to be deleted.
//
void delete_cone(ConeObj **cone);

//
// print_cone: Evaluates and outputs various properties of the given ConeObj,
// including the radius (r), length of an edge (s), height of the cone (h),
// cone: ConeObj that we want to evaluate.
//
void print_cone(ConeObj *cone);

#endif
