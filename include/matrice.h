#ifndef __MATRICE_H
#define __MATRICE_H

#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"

typedef unsigned int Bool;


typedef struct
{
	Bool ** Case;
	int h;    // hauteur de la matrice
	int l;    //largeur de la matrice
} strmatrice, * matrice;


typedef matrice (*fct_matrice) (matrice);

/**fonction matrice MatAlloc(int h,int l); création d'une nouvelle matrice l*h
 *  initialisée à False
 * @param h : la hauteur de la matrice
 * @param l : la largeur de la matrice
 * @return une matrice
 * @pre 0<l , 0<h
 */
matrice MatAlloc(int h,int l);

/** fonction void MatFree(matrice m) Libération de la mémoire utilisé par 
 * la matrice
 * @param m : matrice
 * @return
 * @pre
 * @post m ne doit plus être utilisé, car il a été désalloué
 */
void MatFree(matrice m);

/**fonction Bool MatVal(Matrice m,Couple p)qui Renvoie la valeur booléenne
 *  de la matrice aux coordonnées passé par le Couple en argument
 * @param m : matrice
 * @param p : coordoonné de p
 * @return vrai ou faux, selon la valeur contenant dans la matrice
 * @pre 0<=p.x< m->l , 0<=p.y< m->h
 * @post
 */
Bool MatVal(matrice m,Couple p);

/** fonction matrice MatSet(matrice m,Couple p,Bool val) qui Stocke
 *  une valeur booléenne dans la matrice aux coordonnées données 
 * par le Couple passé en argument
 * @param  m : matrice
 * @param  p : coordoonnée de p
 * @param val : la valeur booléenne à enregistrer
 * @return la matrice dont on a modifiée la cellule de coordonnée p
 * @pre 0<=p.x< m->l ,0<=p.y< m->h
 * @post
 */
matrice MatSet(matrice m,Couple p,Bool val);

/** fonction int Compte_nbrMur(matrice m) qui compte le nombre de mur 
 * d'un labyrinthe
 * @param [in] m : la matrice dont on va compter les murs
 * @return le nombre de mur de  m
 * @pre m!=NULL
 * @post
 */
int Compte_nbrMur(matrice m);

/**fonction int MatSauve(matrice m, char * nom_fichier) Enregistre une matrice
 *  dans un fichier, attention, si on lui donne le même nom à chaque fois
 * il ecrasera ce fichier pour ecrire le nouveau
 * @param  m : la matrice à enregistrer
 * @param [in] filename :nom du fichier 
 * @return 1 si l'enregistrement s'est bien passé, 0 sinon
 * @pre m!=NULL et filename != NULL
 * @post
 */
int MatSauve(matrice m,const char * file);

/** fonction matrice MatLit(char * file) qui lit une matrice depuis un fichier
 * \param file : nom du fichier duquel on va lire la matrice
 * \return une matrice créée depuis le fichier file
 * \pre  file!= NULL
 * @post
 */
matrice MatLit(const char * file);


#endif
