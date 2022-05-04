#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu
{
	class FinDePartieCohnRubinstein : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		FinDePartieCohnRubinstein();
		~FinDePartieCohnRubinstein() override = default;

		static FinDePartieCohnRubinstein instance_;
		inline static const string nomStrategie_ = "FinDePartieCohnRubinstein";
	};
}
