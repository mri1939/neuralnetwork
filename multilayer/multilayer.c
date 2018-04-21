#include "multilayer.h"
#include <stdlib.h>
#include <stdio.h>
#include <cblas.h>

typedef struct layer{
  int num_of_node;
  double *biases;
  double *weights;
  double *activations;
  double *sums;
} layer;

typedef struct weights{
    int layernum;
    int inputSize;
    int outputSize;
    double *weights;
} weights;

int num_of_layer;
int *layer_sizes;
layer *layers;
int eta;

void createNetwork(int n, int *l, double learn_rate)
{
  num_of_layer = n;
  layer_sizes = l;
  eta = learn_rate;
  layers = malloc(sizeof(layer)*n);
  for(int i=0;i<n-1;i++){
    layer lyr;
    lyr.num_of_node = layer_sizes[i+1];
    lyr.weights = malloc(sizeof(double)*(layer_sizes[i]*layer_sizes[i+1]));
    lyr.biases = malloc(sizeof(double)*layer_sizes[i+1]);
    lyr.activations = malloc(sizeof(double)*layer_sizes[i+1]);
    lyr.sums = malloc(sizeof(double)*layer_sizes[i+1]);
    layers[i] = lyr;
  }
  return;
}

double *feedForward(double *input)
{
  
  return 0;
}
