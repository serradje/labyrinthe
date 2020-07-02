
#ifndef __LABYRINTHE_H
#define __LABYRINTHE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ensemble.h"
#include "matrice.h"
#include "graph.h"
#include "sort.h"

#define GLOBAL 45

int PIXEL;
int affichage;
int affiche_case;


/** foncion GenLab(matrice m) de generation du labyrinthe 
 * \param  m : matrice, la matrice dans laquelle on va construire le labyrinthe
 * \return m : le labyrinthe construit à partir de la matrice 
 * \pre m initialisée par MatAlloc()
 * \post les murs de la matrcie sont a 1 et tout le reste est 0
 */
matrice GenLab(matrice m);

/** fonction Creer_Bord(matrice m, ens e) qui construit des murs "1" sur les bords de la matrice
 * \param m : matrice sur laquelle on va construire les murs bords
 * \param e : ensemble de murs ou l'on stockera les coordonnées 
 * \pre : m  initalisée par MatAlloc()
 * \return :une matrice avec des murs sur les bords
 */
ens Creer_Bord(matrice m,ens e);


/** fonction Check_Graine  qui recherche la graine responsable d'une case constructible
 * \param  m : la matrice du labyrinthe
 * \param  p:  le couple p (coordonnées de la case constructible)
 * \return le Couple p (cordonnees) de la graine  
 * \pre : p doit obligatoirement être constructible
 * \post : m=MatAlloc()
 */
Couple Check_Graine(matrice m,Couple p);

/** fonction EstConstructible qui verifie si une case est constructible ou non
 * \param [in] p : coordonnée de la case à tester
 * \param [in] m :  matrice du labyrinthe qu'on va construire
 * \pre m   initialisé par MatAlloc()
 * \return  0 si  p n'est pas constructible, 1 sinon
 */
int EstConstructible(matrice m,Couple p);

/** fonction qui initialise un ensemble de mur constructible à partir d'un ensemble de graine
 * \param  e : ensemble de graine
 * \param m : matrice du labyrinthe
 * \return un ens qui contient les coordonnées des murs constructibles
 * \pre : m  initalisée par MatAlloc()
 * \pre : e  initialisée par EnsAlloc()
 */

ens Construire_Mur(ens e,matrice m);


/** fonction pose_Graine qui initialise un ensemble e de graine et les construit dans le labyrinthe 
 * \param  m :  matrice du labyrinthe
 * \return : e l'ensemble contenant les coordonnees des graines 
 * \pre : m initialisée par MatAlloc()
 */
ens Pose_Graine(matrice m);

/**
 * Supprime de l'ensemble de mur constructible les cases autours d'un mur nouvellement construit, et les effaces(dessine en blanc) de l'affichage(si affichage activé)
 * \param  p: Couple, Coordonnées du mur construit
 * \param m : matrice du labyrinthe
 * \return l'ensemble des murs constructibles
 * \pre m=MatAlloc() et e=EnsAlloc()
 */
ens Suppr_Mur(Couple p,ens e,matrice m);

/**
 * Ajoute les murs constructibles générées par un mur nouvellement construit à l'ensemble des murs constructibles, dessine(si affichage activé) ces murs de la couleur passé en parametre
 * \param p : Couple, les coordonnées du mur construit
 * \param e : ensemble de murs constructibles
 * \param m : matrice du labyrinthe en construction
 * \param couleur : long, couleur dans laquelle on doit afficher les nouvelles cases constructibles
 * \return ensemble des murs constructibles mis à jour
 * \pre  m=MatAlloc() et e=EnsAlloc()
 */
ens Ajout_Mur(Couple p,ens e,matrice m,long couleur);

/**fonction afficheCouple(Couple p,long couleur) qui affiche un couple dans la couleur donnée
 * \param p : coordonnée de la case à afficher
 * \param  couleur : 
 * \return
 * \pre : 
 */
void DessineCouple(Couple p,long couleur);

/** fonction afficheEns(ens e,long couleur ) qui affiche tous les couple contenus dans un ensemble
 * \param  e : un ensemble de couple
 * \param  couleur : 
 * \return
 * \pre :
 */

void DessineEns(ens e,long couleur);


/** fonction effaceCouple(Couple p) qui efface un couple de l'affichage 
 * \param p :  coordonnée de la case 
 * \param couleur : 
 * \return
 * \prec
 */
void SupprCouple(Couple p);

/** effaceEns(ens e) qui efface tous les couples de l'ensemble de l'affichage 
 * \param e : ensemble de point
 * \param couleur :
 * \return
 * \pre
 */
void SupprEns(ens e);

#endif

