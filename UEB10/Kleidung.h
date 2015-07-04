#ifndef KLEIDUNG_H
#define KLEIDUNG_H
#include "Artikel.h"
namespace artikel {
	class Kleidung : Artikel
	{
	public:
		Kleidung();
		Kleidung(int artikelNr, std::string bezeichnung, double artikelPreis, int bestand, double size, std::string colour)
			throw (ArtikelException);
		~Kleidung();
		void eingeben(std::istream&);
		void ausgeben(std::ostream&) const;
		double getSize();
		void setSize(double size);
		std::string getColour();
		void setColour(std::string colour);
	private:
		double size;
		std::string colour;
	};
}
#endif