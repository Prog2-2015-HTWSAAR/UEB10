#ifndef LEBENSMITTEL_H
#define LEBENSMITTEL_H
#include "Artikel.h"
#include "Datum.h"
namespace artikel {
	class Lebensmittel : public Artikel
	{
	public:
		static const char* meldungMHD;
		Lebensmittel();
		Lebensmittel(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, Datum bestBeforeDate)
			throw (ArtikelException);
	//	virtual ~Lebensmittel();
		void eingeben(std::istream&);
		void ausgeben(std::ostream&) const;
		void setBestBeforeDate(Datum bbd);
		Datum getBestBeforeDate()    const;
	private:
		Datum& bestBeforeDate;
	};
}
#endif
