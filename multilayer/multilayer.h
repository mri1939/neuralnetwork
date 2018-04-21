#ifndef MULTILAYER_H
#define MULTILAYER_H

extern int num_of_layer;
extern int *layer_sizes;

void createNetwork(int n, int *l, double learn_rate);
double *feedForward(double *input);
double *miniBatchSGD();
double updateMiniBatch();
#endif
