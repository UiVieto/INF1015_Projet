#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu
{
	class OuvertureRhanmouniNguyen : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		OuvertureRhanmouniNguyen();
		~OuvertureRhanmouniNguyen() override = default;

		static OuvertureRhanmouniNguyen instance_;
		inline static const string nomStrategie_;
	};
}
