#include "CArbre.h"
#include <iostream>

using namespace std;

Arbre::Arbre()
{
	racine = nullptr;
}

Arbre::~Arbre()
{
}

int Arbre::traiteNoeudPre(noeud* n)
{
	if (n != nullptr) {
		cout << n->n_data << endl;
		traiteNoeudPre(n->fg);
		traiteNoeudPre(n->fd);
	}

	return 0;
}

int Arbre::traiteNoeudPost(noeud* n)
{
	if (n != nullptr) {
		traiteNoeudPost(n->fg);
		traiteNoeudPost(n->fd);
		cout << n->n_data << endl;
	}

	return 0;
}

noeud* Arbre::getRacine()
{
	return racine;
}

int Arbre::insertNoeud(noeud* n, noeud* p_racine)
{
	if (p_racine == nullptr) {
		racine = n;
	}
	else {
		if (n->n_data <= p_racine->n_data) {
			if (p_racine->fg == nullptr) {
				p_racine->fg = n;
				balance();
			}
			else {
				insertNoeud(n, p_racine->fg);
			}
		}
		else {
			if (p_racine->fd == nullptr) {
				p_racine->fd = n;
				balance();
			}
			else {
				insertNoeud(n, p_racine->fd);
			}
		}
	}

	return 0;
}

noeud* Arbre::supNoeud(noeud* n, int n_val)
{
	if (n == nullptr) {
		return nullptr;
	}

	if (!isBalance()) {
		balance();
		return nullptr;
	}

	if (n_val < n->n_data) {
		n->fg = supNoeud(n->fg, n_val);
	}
	else if (n_val > n->n_data) {
		n->fd = supNoeud(n->fd, n_val);
	}
	else {
		if (n->fg == nullptr) {
			noeud* temp = n->fd;
			n = nullptr;
			return temp;
		}
		else if (n->fd == nullptr) {
			noeud* temp = n->fg;
			n = nullptr;
			return temp;
		}

		noeud* succ = Successeur(n->fd);

		n->n_data = succ->n_data;

		n->fd = supNoeud(n->fd, succ->n_data);
	}

	if (!isBalance()) {
		balance();
		return nullptr;
	}

	return n;
}

noeud* Arbre::Successeur(noeud* n)
{
	noeud* courant = n;
	while (courant->fg != nullptr) {
		courant = courant->fg;
	}
	return courant;
}

noeud* Arbre::rechercheNoeud(noeud* n, int n_val)
{
	if (n == nullptr) {
		return nullptr;
	}

	noeud* n_temp = nullptr;

	if (n_val < n->n_data) {
		n_temp = rechercheNoeud(n->fg, n_val);
	}
	else if (n_val > n->n_data) {
		n_temp = rechercheNoeud(n->fd, n_val);
	}
	else {
		n_temp = n;
	}

	return n_temp;
}

bool Arbre::isBalance()
{
	if (racine == nullptr) {
		return true;
	}
	int nbNoeudL = getNbNoeud(racine->fg);
	int nbNoeudR = getNbNoeud(racine->fd);

	if (abs(nbNoeudR - nbNoeudL) <= 1) {
		return true;
	}

	return false;
}

int Arbre::getHeight(noeud* n)
{
	if (!n) return 0;

	return 1 + max(getHeight(n->fg), getHeight(n->fd));
}

int Arbre::getNbNoeud(noeud* n)
{
	if (!n) return 0;

	return 1 + getNbNoeud(n->fg) + getNbNoeud(n->fd);
}

int Arbre::balance()
{
	while (isBalance() == false) {
		if (getNbNoeud(racine->fd) > getNbNoeud(racine->fg)) {
			noeud* temp = racine;
			racine = racine->fd;
			temp->fd = nullptr;
			insertNoeud(temp, racine);
		}
		else if (getNbNoeud(racine->fd) < getNbNoeud(racine->fg)) {
			noeud* temp = racine;
			racine = racine->fg;
			temp->fg = nullptr;
			insertNoeud(temp, racine);
		}
	}

	return 0;
}
