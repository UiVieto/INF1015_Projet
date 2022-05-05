/* TD6 : Programme avec l'utilisation de namespaces, d'un compteur d'instances de rois et
 * de pointeur intelligents pour implémenter le RAII.
 * Fichier : main.cpp
 * Auteurs : Reda Rhanmouni,	2087548,
 *			 Huy Viet Nguyen,	2136378
 * Date : 25 avril 2022
 */

#include "roi.h"
#include "reine.h"
#include "tour.h"
#include "fou.h"
#include "cavalier.h"
#include "pion.h"

#include "interfaceGraphique.h"
#include "echiquier.h"

#include <iostream>
#include <QApplication>
#include <QPushButton>
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
	//QApplication jeu(argc, argv);
	//Affichage::InterfaceGraphique interface(nullptr);

	//interface.show();

	//Test Exception
	//try {
		//cout << "Creation d'un deuxieme roi" << endl;
		//unique_ptr<LogiqueJeu::Roi> roi2 = make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc));
		//cout << "Tentative de creation d'un troisieme roi" << endl;
		//unique_ptr<LogiqueJeu::Roi> roi3 = make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Noir));
	//}

	//catch (logic_error& e) {
		//cout << "Erreur " << e.what() << endl;
	//}

	//test prisePiece

	//test VerificationMouvement

	//test Roi échec



	return jeu.exec();
}


Test()
{
	//Test creation et ajout Piece
	cout << "Creation d'une reine noir" << endl;
	unique_ptr<LogiqueJeu::Reine> reine1 = make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Noir));
	
	cout << "Ajout reine noir à l'échiquier" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(reine1)), pair<int, int> {4, 4});

	cout << "Creation d'un roi noir" << endl;
	unique_ptr<LogiqueJeu::Roi> roi1 = make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Noir));
	cout << "Ajout roi noir à l'échiquier" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(roi1)), pair<int, int> {3, 1});

	cout << "Creation d'une tour noir" << endl;
	unique_ptr<LogiqueJeu::Tour> tour1 = make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Noir));
	cout << "Ajout tour noir à l'échiquier" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(reine1)), pair<int, int> {2, 1});

	cout << "Creation d'une tour noir" << endl;
	unique_ptr<LogiqueJeu::Tour> tour2 = make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Noir));
	cout << "Ajout tour  noir à l'échiquier" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(reine1)), pair<int, int> {6, 1});

	//Pieces blanches
	cout << "Creation d'une reine blanche" << endl;
	unique_ptr<LogiqueJeu::Reine> reine2 = make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Blanc));
	cout << "Ajout reine blanche à l'échiquier" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(reine2)), pair<int, int> {3, 8});

	cout << "Creation d'un roi blanc" << endl;
	unique_ptr<LogiqueJeu::Roi> roi2 = make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc));
	cout << "Ajout roi blanc à l'échiquier" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(roi2)), pair<int, int> {5, 8});

	cout << "Creation d'une tour blanche " << endl;
	unique_ptr<LogiqueJeu::Tour> tour3 = make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc));
	cout << "Ajout tour blanche à l'échiquier" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(reine1)), pair<int, int> {7, 1});

	cout << "Creation d'une tour blanche" << endl;
	unique_ptr<LogiqueJeu::Tour> tour4 = make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc));
	cout << "Ajout tour blanche à l'échiquier, ne devrait pas être possible car deja une piece présente" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(reine1)), pair<int, int> {7, 1}); 
	
	//test déplacement piece sans prise

	cout << "Déplacement Tour blanche en A4, aucune restriction" << endl;
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(pair<int, int> {7, 1}, pair<int, int> {7, 4});

	cout << "Déplacement Roi noir en D1, aucune restriction" << endl;
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(pair<int, int> {3, 1}, pair<int, int> {4, 1});

	cout << "Déplacement reine blanche en B8, aucune restriction" << endl;
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(pair<int, int> {3, 8}, pair<int, int> {4, 8});

	//test deplacement impossible 
	cout << "Déplacement illicite tour blanche a la case 9,2" << endl;
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(pair<int, int> {7, 4}, pair<int, int> {9, 2});

	cout << "Déplacement illicite Roi noir a la case F8 " << endl;
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(pair<int, int> {4, 1}, pair<int, int> {6,8});

	cout << "Déplacement illicite reine blanche en A1  " << endl;
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(pair<int, int> {4, 8}, pair<int, int> {1, 1});

	// test deplacement illicite du roi à cause de mise en échec
	cout << "Déplacement illicite roi blanc en D8, mise en échec par la reine noire" << endl;
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(pair<int, int> {5, 8}, pair<int, int> {4, 8});

	// test prise de pièce 
	cout << "Prise de la reine noir par la tour Blanche " << endl;
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(pair<int, int> {7, 4}, pair<int, int> {4, 4});
}