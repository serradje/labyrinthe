#ifndef __SORT_H
#define __SORT_H

#include <stdio.h>
#include <stdlib.h>

#include "ensemble.h"
#include "matrice.h"
#include "graph.h"

/**fonction qui recherche la meilleur case a utiliser pour l'A*
 * @param e : ensemble
 * @return un Couple que l'on utilisera pour voir ses voisins
 */

Couple meilleur_case(ens e);

/**fonction int tailleFenetre(int h,int l) qui calcule la taille de pixel adequat pour l'affichage d'une fenetre 
 * @param l : la largeur 
 * @param h :la hauteur 
 * @return la taille en pixel pour l'affichage de la fenetre
 * @pre l>0 et h>0
 * @post
 */
int tailleFenetre(int h,int l);

/**fonction path(int x1, int x2, int y1, int y2) qui calcule la distance entre les points (x1,y1) et (x2,y2)
 * @param x1 : abssice
 * @param x2 : abssice
 * @param y1 : ordonnee
 * @param y2 : ordonnee
 * @return la distance entre les points (x1,y1) et (x2,y2)
 * @pre 
 * @post
 */
float path(int x1, int x2, int y1, int y2);

/**fonction Couple construireCouple(int x,int y) qui prend en parametres deux entiers, et construit  Couple
 * @param x : un entier (abscisse)
 * @param y : un entier (ordonneé)
 * @return un Couple
 */
Couple construireCouple(int x,int y);

/** fonction int compareCouple(Couple p1,Couple p2) qui prends en parametres deux couples et les compare
 * @param p1 : Couple
 * @param p2 : Couple
 * @return 0 si les couples sont identiques, 1 sinon
 */
int compareCouple(Couple p1,Couple p2);


/** :fonction Couple SommeCouple(Couple p1,Couple p2) qui fait la somme de deux couples
 * @param p1 : Couple
 * @param p2 : Couple
 * @return un Couple qui resulte de la somme des deux autres passés en parametre
 */
Couple SommeCouple(Couple p1,Couple p2);




#endif
