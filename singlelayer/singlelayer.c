#include "singlelayer.h"
#include <cblas.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int input_size;
int output_size;
double *bias;
double learn_rate;
double *weights;

static void initWeightandBiases()
{
    bias = (double *)malloc(sizeof(double) * output_size);
    weights = (double *)malloc(sizeof(double) * input_size * output_size);
}

void createNetwork(int input, int output, double learningrate)
{
    input_size = input;
    output_size = output;
    learn_rate = learningrate;
    initWeightandBiases();
}

double sigmoid(double z)
{
    return 1 / (1 + exp(-z));
}

double sigmoid_deriv(double z)
{
    return sigmoid(z) * (1 - sigmoid(z));
}

double error(double y, double p)
{
    return pow((p - y), 2) / 2;
}

double *sumfunction(double *x)
{
    int m = output_size;
    int n = 1;
    int k = input_size;
    double *z;
    z = (double *)malloc(sizeof(double) * output_size);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1.0, weights, k, x, n, 0.0, z, n);
    for (int i = 0; i < output_size; i++)
    {
        z[i] = z[i] + bias[i];
    }
    return z;
}

double *activation(double *z)
{
    double *a;
    a = (double *)malloc(sizeof(double) * output_size);
    for (int i = 0; i < output_size; i++)
    {
        a[i] = sigmoid(z[i]);
    }
    return a;
}

void learn(int numOfTrain, double x[numOfTrain][input_size], double y[numOfTrain][output_size], int loop)
{
    double *z, *a, delta_w, delta_b;
    for (int i = 0; i < loop; i++)
    {
        for (int j = 0; j < numOfTrain; j++)
        {
            z = sumfunction(x[j]);
            a = activation(z);
            for (int k = 0; k < output_size; k++)
            {
                for (int l = 0; l < input_size; l++)
                {
                    //printf("%f ",x[j][l]);
                    delta_w = (a[k] - y[j][k]) *sigmoid_deriv(z[k])* x[j][l];
                    weights[k * input_size + l] -= learn_rate * delta_w;
                }
                delta_b = (a[k] - y[j][k])*sigmoid_deriv(z[k]);
                bias[k] -= learn_rate * delta_b;
                double cost = error(y[j][k], a[k]);
                printf("cost : %f\n", cost);
            }
        }
    }
}

double *predict(double *z)
{
    double *res;
    res = activation(sumfunction(z));
    //printf("weight[0]: %f\n", weights[0]);
    //printf("weight[1]: %f\n", weights[1]);
    //printf("bias: %f\n", bias[0]);
    return res;
}