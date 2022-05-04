#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu 
{
	class OuvertureDuCrabe : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		OuvertureDuCrabe();
		~OuvertureDuCrabe() override = default;

		static OuvertureDuCrabe instance_;
		inline static const string nomStrategie_;
	};
}
