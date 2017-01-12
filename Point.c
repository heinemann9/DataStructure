#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double x;
	double y;
}Point;

int get_distance(Point *p);

int main(int argc, char* argv[]){

	int result;
	Point p[2];
	p[0].x = 1;
	p[0].y = 2;
	p[1].x = 9;
	p[1].y = 8;
	
	result = get_distance(p);
	printf("distance[(%.1f, %.1f)-(%.1f, %.1f)] = %d\n",p[0].x, p[0].y, p[1].x, p[1].y,  result);
	return 0;
}

int get_distance(Point *p){
	return (int)sqrt(pow((p[1].x-p[0].x), 2)+pow((p[1].y-p[0].y), 2));
}
