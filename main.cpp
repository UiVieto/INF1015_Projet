#include "vue.h"
#include "echiquier.h"
#include <iostream>
#include <QApplication>
#include <QPushButton>
using namespace std;

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char* argv[])
{
	cout << "Creation d'un echiquier" << endl;
	Echiquier echiquier;

	cout << "Ajout d'un roi blanc a la position (1, 1) : a1" << endl;
	echiquier.ajouterPiece(make_shared<Roi>(Roi(Couleur::Blanc)), pair<int, int> {1, 1});
	cout << "Ajout d'un fou blanc a la position (1, 2) : a2" << endl;
	echiquier.ajouterPiece(make_shared<Fou>(Fou(Couleur::Blanc)), pair<int, int> {1, 2});

	cout << "Deplacement du fou de a2 (1, 2) à d5 (4, 5)" << endl;
	pair<int, int> positionInitiale(1, 2);
	pair<int, int> nouvellePosition(4, 5);
	echiquier.deplacerPiece(positionInitiale, nouvellePosition);
	positionInitiale = { 4, 5 };
	nouvellePosition = { 6, 6 };
	cout << "Tentative de deplacement du fou de d5 à f6" << endl;
	echiquier.deplacerPiece(positionInitiale, nouvellePosition);

	cout << "La piece en (4, 5) est un ";
	cout << (dynamic_cast<Fou*>(echiquier.prendrePiece(pair<int, int>{4, 5}).get()) ? "Fou" : "Autre") << endl;
	cout << "Il y a" << ((echiquier.prendrePiece(nouvellePosition).get() == nullptr) ? " aucune piece " : " une piece ");
	cout << "en f6 (6, 6)" << endl;

	echiquier.ajouterPiece(make_shared<Tour>(Tour(Couleur::Blanc)), pair<int, int> {3, 6});

	QApplication jeu(argc, argv);
	InterfaceGraphique interface(&echiquier);

	interface.show();

	return jeu.exec();
}
