#include "interfaceGraphique.h"
#include <QDebug>


namespace Affichage
{
	InterfaceGraphique::InterfaceGraphique(QWidget* parent) : QMainWindow(parent)
	{
		setWindowTitle("Jeu d'echec (prototype)");
		
		QWidget* menuPrincipal = new QWidget(this);
		QHBoxLayout* layoutPrincipal = new QHBoxLayout(menuPrincipal);
		menuPrincipal->setLayout(layoutPrincipal);
		menuPrincipal->setFixedSize(LONGUEUR_CASE * NOMBRE_CASES + 500, LONGUEUR_CASE * NOMBRE_CASES * 1.1);
		
		QWidget* menuDeSelection = new QWidget(this);
		QVBoxLayout* layoutDeSelection = new QVBoxLayout(menuDeSelection);

		layoutPrincipal->addWidget(menuDeSelection);

		for (int i = 0; i < 4; i++) {
			QPushButton* boutonDeSelection = new QPushButton(menuDeSelection);
			boutonDeSelection->setFixedSize(200, 200);
			boutonsDeSelection_.append(boutonDeSelection);
			layoutDeSelection->addWidget(boutonDeSelection);
		}
		
		setCentralWidget(menuPrincipal);
	}

	InterfaceGraphique::~InterfaceGraphique() {
		qDebug() << "Destruction de l'interface graphique" << Qt::endl;
	}

	void InterfaceGraphique::afficherEchiquier(QHBoxLayout*& layoutPrincipal)
	{
		vue = new QGraphicsView(this);
		echiquier = new InterfaceEchiquier(vue);
		vue->setFixedSize(LONGUEUR_CASE * NOMBRE_CASES, LONGUEUR_CASE * NOMBRE_CASES);

		vue->setScene(echiquier);
		vue->setAlignment(Qt::AlignLeft | Qt::AlignTop);
		vue->centerOn(0, 0);
		vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		
		layoutPrincipal->addWidget(vue);
	}
}
