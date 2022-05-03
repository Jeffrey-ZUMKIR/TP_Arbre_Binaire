#pragma once

typedef struct noeud {
	int n_data;
	noeud* fg;
	noeud* fd;
}noeud;

class Arbre {
private:
	noeud* racine;

public:
	Arbre();
	~Arbre();

	int traiteNoeudPre(noeud* n);
	int traiteNoeudPost(noeud* n);

	noeud* getRacine();

	int insertNoeud(noeud* n, noeud* p_racine);
	noeud* supNoeud(noeud* n, int n_val);

	noeud* Successeur(noeud* n);

	noeud* rechercheNoeud(noeud* n, int n_val);

	bool isBalance();

	int getHeight(noeud* n);

	int getNbNoeud(noeud* n);

	int balance();
};