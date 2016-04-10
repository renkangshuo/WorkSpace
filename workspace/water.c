#include<stdio.h>
#define QUART 950.0
#define MOLECULE 3.0e-23
#define WEIGHT 1000.0

int main() {
    float number_quart;
    float number_molecule;
    float water_weight;
    water_weight = 0;
    number_quart = 0;
    number_molecule = 0;
    printf("Please input the weight of water\n");
    scanf("%f", &water_weight);
    
    number_quart = water_weight / QUART;
    number_molecule = water_weight / MOLECULE;

    printf("The number of water molecule: %f \n", number_molecule);
    printf("The number of quart%f\n", number_quart);

}
