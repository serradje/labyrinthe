#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"
#include "ensemble.h"


Couple meilleur_case(ens e)
{
	int i;
	Couple min;
	min=e->Case[0];
	for(i=0;i<e->taille_elem;i++)
	{
		
		if(min.f_cost>e->Case[i].f_cost)
			min=e->Case[i];

	}

	return min;
}

int tailleFenetre(int h,int l)
{
    int i=1;
    while(((i+1)*h<=800) && ((i+1)*l<=1000))i++;
    return i;
}

     /* distance euclidienne */
float path(int x1, int x2, int y1, int y2){

    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); 

}

Couple construireCouple(int x,int y)
{
	Couple p={x,y};
	return p;
}

int compareCouple(Couple p1,Couple p2)
{
    return (p1.x==p2.x && p1.y==p2.y);
}

Couple SommeCouple(Couple p1,Couple p2)
{
    Couple p={p1.x+p2.x,p1.y+p2.y};
    return p;
}
