#ifndef SINGLELAYER_H
#define SINGLELAYER_H

extern int input_size;
extern int output_size;

void createNetwork(int input, int output, double learningrate);
double sigmoid(double z);
double sigmoid_deriv(double z);
double error(double *y, double *prediction);
double *sumfunction(double *x);
double *activation(double *z);
void learn(int numOfTrain, double x[numOfTrain][input_size], double y[numOfTrain][output_size], int loop);
double *predict(double *x);
#endif
