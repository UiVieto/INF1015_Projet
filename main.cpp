#include "vue.h"
#include "echiquier.h"
#include <iostream>
#include <QApplication>
#include <QPushButton>
using namespace std;
#include <stdexcept>

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

	cout << "Ajout d'un roi blanc a la position (1, 1) : a1" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<Roi>(Roi(Couleur::Blanc)), pair<int, int> {1, 1});

	cout << "Ajout d'une reine en b1" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<Reine>(Reine(Couleur::Noir)), pair<int, int> {2, 1});

	QApplication jeu(argc, argv);
	Affichage::InterfaceGraphique interface(nullptr);

	interface.show();

	return jeu.exec();

	//Test Exception
	try {
		unique_ptr<Roi> Roi = make_unique<Roi>(Roi(Couleur::Blanc));
		unique_ptr<Roi> Roi = make_unique<Roi>(Roi(Couleur::Noir));
		unique_ptr<Roi> Roi = make_unique<Roi>(Roi(Couleur::Blanc));
	}
	catch (logic_error& e)
	{
		cout << "Erreur " << e.what() << endl;
	}

}
