#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

typedef struct point{
    int x;
    int y;
}Point;

float Min(float a, float b) {
    return a<b?a:b;
}

int cmpX(const void *a, const void *b) {
    return ((Point *)a)->x - ((Point *)b)->x;
}


int cmpY(const void *a, const void *b) {
    return ((Point *)a)->y - ((Point *)b)->y;
}

float dist(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + 
                (p1.y - p2.y)*(p1.y-p2.y));
}

float BruteForce(Point *p, int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (min > dist(p[i], p[j])) min = dist(p[i], p[j]);
        }
    }

    return min;
}

float stripClosest(Point *p, int n, float d) {
    qsort(p, n, sizeof(Point), cmpY); 

    float min = d;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n && (p[j].y-p[i].y) < d; j++) {
            if (min > dist(p[i], p[j])) min = dist(p[i], p[j]);
        }
    }

    return min;
}

float Closest(Point *p, int left, int right) {
    int n = right-left+1;
    if (n <= 3) {
        return BruteForce(p, right-left+1);
    }

    int mid = (right+left) / 2;

    float ld = Closest(p, left, mid);
    float lr = Closest(p, mid+1, right);
    float d = Min(ld, lr);

    Point strip[n];

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(p[i].x-p[mid].x) < d) strip[j++] = p[i];
    }

    return Min(d, stripClosest(strip, j, d));
}

// Driver program to test above functions
int main()
{
    /*Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};*/
    Point P[] = {{15, 4}, {1, 18}, {11, 16}, {9, 1}, {3, 5}, {17, 14}, {7, 11}, {12, 19}};
    int n = sizeof(P) / sizeof(P[0]);
    qsort(P, n, sizeof(Point), cmpX);
    printf("The smallest distance is %f\n", Closest(P, 0, n-1));
    /*printf("The smallest distance is %f\n", BruteForce(P, n));*/
    return 0;
}
