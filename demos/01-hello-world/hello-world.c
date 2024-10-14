#include <stdio.h>

typedef struct shape_t
{
    /* data */
    int x, y;
    void (* draw) (int, int);
} shape_t;

void drawShape(int x, int y) {
    printf("drawing shape at (%d, %d)\n", x, y);
}

void drawSquare(int x, int y) {
    printf("drawing square at (%d, %d)\n", x, y);
}

int main(void * args) {
    printf("Hello World Advanced C Programming!\n");
    shape_t myShape = { 0, 0, drawShape };
    myShape.draw(myShape.x, myShape.y);

    shape_t mySquare = { 10, 10, drawSquare };
    mySquare.draw(mySquare.x, mySquare.y);
    return 0;
}