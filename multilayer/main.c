#include "multilayer.h"
#include <stdio.h>

int main()
{
  int numOfLayer = 3;
  int layers[3] = {3,4,2};
  createNetwork(numOfLayer,layers,0.003);
  return 0;
}
