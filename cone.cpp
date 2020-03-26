// ----------------------------------------------------------------------------
// cone.cpp
// Created by Prasana Guthy on 3/24/20.
// Implements the ConeObj specification found in cone.h
// ----------------------------------------------------------------------------
#include "cone.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


// create_cone: constructor of a ConeObj struct that takes
// two points of a vector as input. The second point will be
// the tip of the cone.
//
// x1, y1, z1 : the Cartesian coordinates of a point on a vector.
// x2, y2, z2 : the Cartesian coordinates of a second point on the vector.
// theta: angle of the cone from an edge to the line through the cone's tip and
// base (expressed in radians)
//
ConeObj* create_cone(double x1, double y1, double z1,
                     double x2, double y2, double z2,
                     double theta)
{
    ConeObj *new_cone = (ConeObj *)(malloc(sizeof(ConeObj)));
    new_cone->h = sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0) + pow(z2 - z1, 2.0));
    // Checking that the cone has a valid height
    if(new_cone->h == 0) {
        printf("Cone input has invalid dimensions");
        exit(1);
    }
    new_cone->r = new_cone->h * tan(theta);

    // Checking that theta is valid
    if(theta <= 0  || theta >= 90.0) {
        printf("Cone input has invalid dimensions");
        exit(1);
    }
    new_cone->theta = theta;
    return new_cone;
}


//
// delete_cone: Deletes a given ConeObj.
// cone: Pointer to cone object that needs to be deleted.
//
void delete_cone(ConeObj **cone) {
    if(*cone == 0) {
        fprintf(stderr, "Invalid cone passed to destructor.\n");
        exit(1);
    }
    free(*cone);
    return;
}
//
// print_cone: Evaluates and outputs various properties of the given ConeObj,
// including the radius (r), length of an edge (s), height of the cone (h),
// cone: ConeObj that we want to evaluate.
//
void print_cone(ConeObj *cone)
{
    printf("radius r: %.4f\n", cone->r);
    printf("edge length s: %.4f\n", (cone->h / cos(cone->theta)));
    printf("T: %.4f\n", (2 * M_PI * sin(cone->theta)));
    return;
}
