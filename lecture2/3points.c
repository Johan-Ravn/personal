

#include <stdio.h>
#include <math.h>

int main(void){
    // first vector point
    int x1 = 0,
        y1 = 0;
    // second vector point
    int x2 = 0,
        y2 = 0;
    
    printf("Pick 2 vector points, to calculate the distance: ");
    scanf("%i %i %i %i", &x1, &y1, &x2, &y2);

    double distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))); //Distance with sqrt((x2 - x1)^2 + (y2 - y1)^2 formula)

    printf("The distance between point (%i, %i) and (%i, %i) is %lf", x1, y1, x2, y2, distance);
    
    return 0;
}