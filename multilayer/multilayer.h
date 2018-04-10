#ifndef MULTILAYER_H
#define MULTILAYER_H

typedef struct layer{
    int numOfNode;
    int layernum;
    double *activations;
    double *sums;
} layer;

typedef struct weights{
    int layernum;
    int inputSize;
    int outputSize;
    double *weights;
} weights;

extern int numOfLayer;
extern int *layerSizes;

void createNetwork(int numOfLayer, int *layerSizes, double learn_rate);
double *feedForward(double *input);
#endif
