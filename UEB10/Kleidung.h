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
	//	~Kleidung();
		void eingeben(std::istream&);
		void ausgeben(std::ostream&) const;

		void setSize(double newSize);
		double getSize() const;

		void setColour(std::string newColour);
		std::string getColour() const;
	private:
		double size;
		std::string colour;
	};
}
#endif
