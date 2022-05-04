#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu
{
	class FinDePartieAlekhineCapablanca : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		FinDePartieAlekhineCapablanca();
		~FinDePartieAlekhineCapablanca() override = default;

		static FinDePartieAlekhineCapablanca instance_;
		inline static const string nomStrategie_ = "FinDePartieAlekhineCapablanca";
	};
}
