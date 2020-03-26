//
// Created by Prasana Guthy on 3/24/20.
// main.cpp: Testing file for cone objects.
//
#include"cone.h"
#include <getopt.h>
#include<math.h>
#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>


// Default seed for rand() used to generate cones.
#define DEF_SEED 200
// Command-line options macro
#define OPTIONS "r:"
// Enumerated type for setting command-line options.
enum {SET_SEED, N_OPTS};
bool option_flags[N_OPTS];

// Number of cones to generate
#define NUM_CONES 2
// Number of randomly generated parameters for each cone.
#define CONE_PARAM 7

int main(int argc, char **argv) {
    // Test print statement
    printf("Hello, world!\n");

    for(int i = 0; i < N_OPTS; i++) {
        option_flags[i] = false;
    }
    int opt = -1;
    int seed = DEF_SEED;
    double cone_in[CONE_PARAM];
    ConeObj *rand_cones[NUM_CONES];
    // Evaluate user arguments.
    while((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch(opt) {
            case 'r':
                option_flags[SET_SEED] = true;
                seed = atoi(optarg);
        }
    }

    // Set the seed and generate random elements.
    srand(seed);

    // Generate Cones.
    for(int i  = 0 ; i < NUM_CONES; i++) {
        for(int j = 0 ; j < CONE_PARAM - 1; j++) {
            cone_in[j] = (double)(rand());
        }
        cone_in[CONE_PARAM - 1] = fmod((double)(rand()), 90); // Generates valid theta.

        rand_cones[i] = create_cone(cone_in[0], cone_in[1], cone_in[2],
                                    cone_in[3], cone_in[4], cone_in[5],
                                    cone_in[6]);
        print_cone(rand_cones[i]);
    }

    // Delete Cones.
    for(int i  = 0 ; i < NUM_CONES; i++) {
        delete_cone(&rand_cones[i]);
        rand_cones[i] = 0;
    }
    return 0;
}
