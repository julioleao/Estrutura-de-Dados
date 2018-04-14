#include <math.h>


typedef struct point{
    float x;
    float y;
} Point;



Point * point_create(float x, float y);

void point_free(Point * p);

void point_print(Point * p);

void point_distance(Point * a, Point *b);


Point * point_create(float x, float y){
    Point * p = (Point*) malloc(sizeof(Point));
    if(p == NULL){
        printf("Houve um erro na criação do ponto.\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

void point_free(Point * p){
    free(p);
    printf("Ponto removido com sucesso.\n");
}

void point_print(Point * p){
    printf("X: %f, Y: %f\n", p->x, p->y);
}

void point_distance(Point * a, Point *b){
    float dab, sumX, sumY, sum;
    sumX = a->x - b->x;
    sumY = a->y - b->y;
    sumX = pow(sumX,2);
    sumY = pow(sumY,2);
    sum = sumX + sumY;
    dab = sqrt(sum);
    if(dab < 0){
      dab = dab *(-1);
    }
    printf("A distância entre os pontos é: %f\n", dab);
}