#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu
{
	class PlacementClassique : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		PlacementClassique();
		~PlacementClassique() override = default;

		static PlacementClassique instance_;
		inline static const string nomStrategie_ = "PlacementClassique";
	};
}