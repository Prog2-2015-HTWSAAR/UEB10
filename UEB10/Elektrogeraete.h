#ifndef ELEKTROGERAETE_H
#define ELEKTROGERAETE_H
#include "Artikel.h"
namespace artikel {
	class Elektrogeraete : public Artikel
	{
	public:
		Elektrogeraete();
		Elektrogeraete(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, double leistung)
			throw (ArtikelException);
	//	~Elektrogeraete();
		void eingeben(std::istream&);
		void ausgeben(std::ostream&) const;
		double getLeistung() const;
		void setLeistung(long leist);
	private:
		double leistung;
	};
}
#endif
