#include "CArbre.h"
#include <iostream>

using namespace std;

int main() {
	Arbre arbre;

	noeud n1;
	n1.n_data = 5;
	n1.fg = nullptr;
	n1.fd = nullptr;

	noeud n2;
	n2.n_data = 3;
	n2.fg = nullptr;
	n2.fd = nullptr;

	noeud n3;
	n3.n_data = 4;
	n3.fg = nullptr;
	n3.fd = nullptr;

	noeud n4;
	n4.n_data = 2;
	n4.fg = nullptr;
	n4.fd = nullptr;

	noeud n5;
	n5.n_data = 1;
	n5.fg = nullptr;
	n5.fd = nullptr;

	noeud n6;
	n6.n_data = 8;
	n6.fg = nullptr;
	n6.fd = nullptr;


	//Insertion
	arbre.insertNoeud(&n1, arbre.getRacine());
	arbre.insertNoeud(&n2, arbre.getRacine());
	arbre.insertNoeud(&n3, arbre.getRacine());
	arbre.insertNoeud(&n4, arbre.getRacine());
	arbre.insertNoeud(&n5, arbre.getRacine());
	arbre.insertNoeud(&n6, arbre.getRacine());

	//Affichage
	cout << "Traitement prefixe" << endl;
	arbre.traiteNoeudPre(arbre.getRacine());
	cout << "Traitement postfixe" << endl;
	arbre.traiteNoeudPost(arbre.getRacine());

	//Supprimer
	arbre.supNoeud(arbre.getRacine(), 2);

	//Rechercher
	int foundN = 10;
	noeud* n7 = arbre.rechercheNoeud(arbre.getRacine(), foundN);
	if (n7 != nullptr) {
		cout << "Le noeud avec pour valeur: " << foundN << " est bien present dans l'arbre." << endl;
	}
	else {
		cout << "Le noeud avec pour valeur: " << foundN << " n'est pas present dans l'arbre." << endl;
	}

	//Hauteur
	cout << "Hauteur de l'arbre" << endl;
	cout << arbre.getHeight(arbre.getRacine()) - 1 << endl;

	//Nombre de noeud
	cout << "Nombre de noeud" << endl;
	cout << arbre.getNbNoeud(arbre.getRacine()) - 1 << endl;

	//Equilibré l'arbre
	arbre.balance();


	return 0;
}