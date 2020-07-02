#ifndef __CHEMIN_H
#define __CHEMIN_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "ensemble.h"
#include "matrice.h"
#include "sort.h"

extern int affiche;
extern int PIXEL;
extern char * move;

/**fonction recherche avec une heuristique (choix du voisin avec la plus faible distance à vol d’oiseau avec l’arrivée
 * @param e1 : ensemble
 * @param e2 : ensemble
 * @param m  :  matrice du labyrinthe
 * @return un Couple indiquant la direction suivant laquelle il faut se depacler 
 */
Couple heuristique(ens e1,ens e2,matrice m);

/** fonction recherche du plus court chemin Dijkstra
 * @param e1 : ensemble
 * @param m  :  matrice du labyrinthe
 * @return : 
 */
void dijkstra(ens e1,matrice m);

/**trois fonctions principales de recherche du chemin dans le labyrinthe
 * @param m : matrice
 * @return la matrice m
 * @pre m doit avoir été initialisé et doit contenir un véritable labyrinthe
 * @post Affichage de la recherche (si activé)
 */
matrice mat_Alea_Heuri(matrice m);
matrice mat_Dij(matrice m);
matrice mat_Astar(matrice m);

/** fonction Couple chemin(ens e1,ens e2,matrice m) qui cherche le chemin du labyrinthe
 * @param e1 : ensemble
 * @param e2 : ensemble
 * @param m  :  matrice du labyrinthe
 * @return un Couple indiquant la direction suivant laquelle il faut se depacler 
 */
Couple chemin_alea(ens e1,ens e2,matrice m);


/** fonction afficheEns(ens e,long couleur ) qui affiche tous les couples contenus dans un ensemble
 * @param e : un ensemble de couple
 * @param couleur : long, une couleur créée par la fonction newcolor()
 * @return
 * @pre :
 */
void DessineEns(ens e,long couleur);

/**fonction afficheCouple(Couple p,long couleur) qui affiche un couple avec une couleur donnée
 * @param p : coordonnée de la case à afficher
 * @param  couleur : long, couleur dans laquel on doit afficher la case
 * @return
 */
void DessineCouple(Couple p,long couleur);

/** fonction qui Parcours et dessine les murs d'un labyrinthe avec une couleur donnée
 * @param m : matrice du labyrinthe 
 * @param couleur :  couleur avec laquelle les murs vont etre dessiner
 * @return
 */
void DessineLab(matrice m,long couleur);

/** EffaceEns(ens e) qui efface tous les couples de l'ensemble de l'affichage 
 * @param  e : ensemble de point
 * @param  couleur :couleur faite par la fonction newcolor()
 * @return
 * @pre
 */
void SupprEns(ens e);


/** fonction effaceCouple(Couple p) qui efface un couple de l'affichage 
 * @param p :  coordonnée de la case 
 * @param couleur :
 * @return
 * @pre
 */
void SupprCouple(Couple p);

#endif
