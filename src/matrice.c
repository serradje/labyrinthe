#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
 #include <stdarg.h>

#include "matrice.h"

matrice MatAlloc(int h,int l)
{
    int i=0,j=0;

    matrice m=NULL;
    m=(matrice)malloc(sizeof(strmatrice));
    m->h=h;
    m->l=l;
    m->Case=(Bool **)malloc(l * (sizeof(Bool *)));

    for(i=0;i<l;i++)
    {
        m->Case[i]=(Bool *)malloc(h * (sizeof(Bool)));
    }

    for(i=0;i<l;i++)
    {
        for(j=0;j<h;j++)
        {
            m->Case[i][j]=faux;
        }
    }

    return m;
}

void MatFree(matrice m)
{
    int i;
    for(i=0;i < (m->l);i++)
    {
        free(m->Case[i]);
    }
    free(m->Case);
    free(m);
}

Bool MatVal(matrice m,Couple p)
{
    return m->Case[p.x][p.y];
}


matrice MatSet(matrice m,Couple p,Bool val)
{
    m->Case[p.x][p.y]=val;
    return m;
}

int Compte_nbrMur(matrice m)
{
    int i,j,k=0;
    for(j=0;j<m->h;j++)
    {
        for(i=0;i<m->l;i++)
        {
            if(m->Case[i][j]==vrai)
            k++;
        }
    }
    return k;
}

int MatSauve(matrice m, const char * file)
{
    FILE * fd=NULL;
    fd=fopen(file,"w");
    if(fd != NULL)
    {
        //Ecrit dans le fichier la hauteur et largeur
        fprintf(fd, "%d %d\n",m->l, m->h);
     int i,j;
        for(i=0;i<m->h;i++)
        {
            for(j=0;j<m->l;j++)
            {
				/*Parcourir toute la matrice, 
				on ecrit la case dans le fichier */
               
                fprintf(fd,"%d ",m->Case[j][i]);
            }
             fputc('\n',fd);
        }
       
        fclose(fd);

    }
    else
    {
        perror("fopen");
        return 0;
    }
    return 1;
}


matrice MatLit( const char *file)
{   
	matrice m=NULL;
    FILE * fd=NULL;
    fd=fopen(file,"r");
    if(fd !=NULL)
    {
        int i,j=0;
        int l,h;
		if(fscanf(fd,"%d %d",&h,&l)); //lecture de la hauteur,latgeur


        m=MatAlloc(l,h);//Allocation de la matrice h*l

        for(i=0;i<l;i++)
        {
			for(j=0;j<h;j++)
			{
			if(fscanf(fd,"%d ",&m->Case[j][i]));
			
			}
		}
    }
    else
    {
       perror("fopen");
    }
    fclose(fd);
    return m;
}


