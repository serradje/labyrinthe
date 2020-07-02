
#ifndef __ENSEMBLE_H
#define __ENSEMBLE_H

#include <stdio.h>
#include <stdlib.h>



#define TAILLE_MAXI_ENS 100

typedef struct
{
	int a;
	int b;
}Parent;

typedef struct
{
	int x;
	int y;
	float distance;
	float g_cost;
	float f_cost;
	Parent p;
} Couple, * ptr_Couple;


typedef struct
{
	ptr_Couple Case; /*pointeur pour uune case de Couple*/
	int taille_elem; /* Nombre d'élément dans l'ensemble */
	int t_max; 		/*taille maximum de l'ensemble */
} strens, *ens;

#define vrai 1
#define faux 0


/** fonction ens EnsAlloc() création d’un nouvel ensemble
 * \return un ensemble alloué
 * \pre
 */
ens EnsAlloc();

/** fonction  EnsFree(ens e)  Désalloue un ensemble
 * @param  e : un pointeur sur un strens
 * @return
 * @pre
 */
void EnsFree(ens e);

/** fonction EnsEstVide(ens e) Test de vacuité sur e
 * @param e: un pointeur sur un ensemble
 * @return 0 si l'ensemble est vide, 1 sinon
 * @pre 
 */
int EnsEstVide(ens e);

/** fonction EnsAjoute(ens e,Couple c) Ajoute un couple à l'ensemble
 * @param e : un ensemble
 * @param p : le couple à ajouter
 * @return un ensemble dont on a ajouté le Couple c
 */
ens EnsAjoute(ens e,Couple p);

/** fonction EnsChercheCouple(ens e,Couple p) Recherche un Couple dans un ensemble
 * @param e : l'ensemble dans lequel on doit chercher le couple p
 * @param p : le Couple à chercher
 * @return -1 si le couple ne trouve pas le Couple dans l'ensemble donné,sinon on retourne la position de ce Couple
 * @pre e!= NULL
 */
int EnsChercheCouple(ens e,Couple p);

/** fonction ens SupprIeme(ens e,int i)  Suprimme le ième élément de l'ensemble
 * @param e :  l'ensemble dans lequel on doit supprimer l'élément
 * @param i : la position de l'élément à supprimer
 * @return l'ensemble e privé du  ième élément
 * @pre   e!= NULL
 */
ens SupprIeme(ens e,int i);

/**  fonction ens EnsSuppr(ens e,Couple p) Supprime de l'ensemble le Couple passé en argument
 * @param  e : l'ensemble dans lequel on va supprimer le couple
 * @param p : Couple, le Couple à supprimer
 * @return L'ensemble privé du couple p supprimé 
 */

ens EnsSuppr(ens e,Couple p);

/** fonction ens EnsSupprPremier(ens e) Supprime le premier élément d'ensemble
 * @param e :l'ensemble dont on va supprimer le premier élément
 * @return l'ensemble privé du premier élément
 * @pre e!=NULL
 */
ens EnsSupprPremier(ens e);


/** fonction ens EnsSupprDernier(ens e) Supprime le dernier élément d'ensemble
 * @param e :l'ensemble dont on va supprimer le dernier élément
 * @return l'ensemble privé du dernier élément
 * @pre e!=NULL
 */
ens EnsSupprDernier(ens e);
ens EnsSuppr2(ens e,Couple p);
/**fonction int EnsEstDans(ens e,Couple c) Teste si un Couple appartient à l'ensemble passé en paramètre
 * @param [in] e :l'ensemble à tester
 * @param p : le couple à chercher
 * @return 1 si  p est dans e, 0 sinon
 */
int EnsEstDans(ens e,Couple p);

/** fonction int EnsTaille(ens e) donne le nombre d'élément dans un ensemble donné
 * @param e : ensemble
 * @return le nombre d'element (la taille) de l'ensemble
 * @pre e!= NULL
 */
int EnsTaille(ens e);

/** fonction Couple EnsTirage(ens e) Tire un couple aléatoirement dans l'ensemble, le retire de l'ensemble
 * @param e : ensemble
 * @return le Couple aleatoirement tiré
 * @pre e!= NULL
 */
Couple EnsTirage(ens e);



#endif
