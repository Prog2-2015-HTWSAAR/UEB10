#ifndef LEBENSMITTEL_H
#define LEBENSMITTEL_H
#include "Artikel.h"
namespace artikel {
	class Lebensmittel : Artikel
	{
	public:
		Lebensmittel();
		Lebensmittel(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, std::string bestBeforeDate)
			throw (ArtikelException);
		virtual ~Lebensmittel();
		void eingeben(std::istream&);
		void ausgeben(std::ostream&) const;
		void setBestBeforeDate(std::string bestBeforeDate);
		std::string getBestBeforeDate()    const;
	private:
		std::string bestBeforeDate;
	};
}
#endif