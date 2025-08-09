#include <stdio.h>

int main()
{
    int height = 8;
    int width = 4;
    int perimeter = 2 * (height + width);
    printf("Perimeter of the rectangle is: %d cm\n", perimeter);
    int area = height * width;
    printf("Area of the rectangles is: %d square cm\n", area);
    return 0;
}