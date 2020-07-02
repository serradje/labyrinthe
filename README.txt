# labyrinthe
============


#mode d'uitlisation
pour générer le labyrinthe : 
=============================
./bin/genlab -v -d -l 250 -h 250 -p 4 fichier.txt.
ou sans le pixel:
./bin/genlab -v -d -l 250 -h 250 fichier.txt.


#pour trouver le chemin:
=========================

./bin/cheminlab -v -d -c [option] fichier.txt.
 exemple:.
./bin/cheminlab -v -d -c a fichier.txt.

ou avec pixel:
./bin/cheminlab -v -d -c a -p 4 fichier.txt.

#les option:
============
a -> pour chemin aleatoire.
h -> pour chemin heuristique.
d -> dijkstra.
* ou A -> A star.
