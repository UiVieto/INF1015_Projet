#include "Roi.h"



Roi::estUnMouvementValide(Position nouvellePos)
{
	return (pos.x + 1 == nouvellePos.x) || (pos.y + 1 == nouvellePos.y) || ((pos.x + 1 == nouvellePos.x) && (pos.y + 1 == nouvellePos.y))
}
