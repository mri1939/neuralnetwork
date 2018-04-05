#include "singlelayer.h"
#include <stdio.h>
#include <math.h>

int main()
{
    /**
     * Training data for AND logic
    */
    double x[4][2] = {
        {1.0, 0.0}, 
        {0.0, 1.0}, 
        {0.0, 0.0}, 
        {1.0, 1.0}};
    double y[4][1] = {
        {0.0}, 
        {0.0}, 
        {0.0}, 
        {1.0}};
    createNetwork(2, 1, 0.03);
    learn(4, x, y, 500000);
    printf("1 : %f \n", predict(x[0])[0]);
    printf("2 : %f \n", predict(x[1])[0]);
    printf("3 : %f \n", predict(x[2])[0]);
    printf("4 : %f \n", predict(x[3])[0]);
    return 0;
}