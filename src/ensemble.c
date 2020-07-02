#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"
#include "sort.h"
ens EnsAlloc()
{
    ens e=NULL;
    e=(ens)malloc(sizeof(strens));
    e->taille_elem=0;
    e->t_max=TAILLE_MAXI_ENS;
    e->Case=(ptr_Couple)malloc(TAILLE_MAXI_ENS  * sizeof(Couple));
    return e;
}

void EnsFree(ens e)
{
    free(e->Case);
    free(e);
}

int EnsEstVide(ens e)
{
    return (e->taille_elem==0);
}

ens EnsAjoute(ens e,Couple p)
{
    if(e->taille_elem==e->t_max)
    {
        e->Case=(ptr_Couple)realloc(e->Case,(e->t_max + TAILLE_MAXI_ENS)*sizeof(Couple));
        e->t_max+=TAILLE_MAXI_ENS;
    }
    e->Case[e->taille_elem]=p;
    e->taille_elem++;
    return e;
}

int EnsChercheCouple(ens e,Couple p)
{
    int i=0;
    while((i != e->taille_elem) && (compareCouple(p,e->Case[i]) != 1)) 
    {
		i++;
    }
    
    if(compareCouple(p,e->Case[i]) != 1)
      { 
		i=-1;
	  }
		return i;
   
}

ens SupprIeme(ens e,int i)
{
    if((0 <= i) && (i < e->taille_elem))
    {
        if(i != (e->taille_elem-1)) 
          e->Case[i]=e->Case[e->taille_elem-1];
          e->taille_elem--;
    }
    return e;
}

ens EnsSuppr2(ens e,Couple p)
{
	int i;
	int trouver=0;
	for(i=0;i<e->taille_elem-1;i++)
	{
		if(compareCouple(p,e->Case[i]))
			trouver=1;
		if(trouver==1)
			e->Case[i]=e->Case[i+1];
	}
		e->taille_elem--;
	return e;
}

ens EnsSupprPremier(ens e)
{
	int i;
       if(e->taille_elem>0)
       {
		   for(i=0; i<e->taille_elem-1;i++)
			e->Case[i]=e->Case[i+1];
		e->taille_elem--;
	   }
	   
	   return e;
}

ens EnsSuppr(ens e,Couple p)
{
    int i=EnsChercheCouple(e,p);
    e=SupprIeme(e,i);
    return e;
}

ens EnsSupprDernier(ens e)
{
    e=SupprIeme(e,e->taille_elem-1);
    return e;
}

int EnsEstDans(ens e,Couple p)
{
    int i = EnsChercheCouple(e,p);
    return (i!=-1);
}

int EnsTaille(ens e)
{
    return e->taille_elem;
}

Couple EnsTirage(ens e)
{
    int alea=(rand() % e->taille_elem);
    Couple p=e->Case[alea];
    e=SupprIeme(e,alea);
    return p;
}
