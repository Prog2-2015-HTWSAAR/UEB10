/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb06 *.o
 * @file Lager.h
 *
 * @date 23.05.2015
 * @author Andreas Schreiner & Simon Bastian
 *
 * Lager-Klasse und zugehoerige Ausnahmen
 */

#ifndef LAGER_H_
#define LAGER_H_
#include "Artikel.h"

/**
 * Standardausnahme fuer logische Fehler in der Lagerklasse
 */
class LagerException : public ArtikelException {
public:
    LagerException(const string& msg = "") : ArtikelException(msg) {}
};
/**
 * @brief Eine Lagerklasse
 */
class Lager {
public:

	/**
	 * @brief Konstruktor
	 * @param maxAnzArtikel (optional) muss positiv sein!
	 * @param name (optional) Name des Lagers darf nicht leer sein!
	 */
	Lager(int maxAnzArtikel = defaultSize, string name = defaultName);
	/**
	 * Expliziter Kopierkonstruktor
	 * @param lager Referenz auf zu kopierendes Objekt
	 */
	Lager(const Lager&);
	/**
	 * @brief Destructor loescht alle Artikel
	 */
	virtual ~Lager();
	/**
	 * Expliziter Zuweisungsoperator
	 *
	 * @param lager Referenz auf das zugewiesene Objekt
	 * @return Referenz auf das aktuelle Objekt
	 */
	Lager& operator=(const Lager&);
	/**
	 * @brief Eintragen eines neuen Artikels ohne Bestandsangabe
	 * @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelPreis
	 */
	void createArtikel(int artikelNr, string bezeichnung, double artikelPreis);
	/**
	 * @brief Eintragen eines neuen Artikels mit Bestandsangabe
	 * @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelPreis
	 * @param bestand
	 */
	void createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand);
	/**
	 * @brief deleteArtikel Entfernen eines Artikels aus dem Lager
	 * @param artikelNr
	 */
	void deleteArtikel(int artikelNr);
	/**
     * @brief bucheZugang erhoeht den bestand
	 * @param artikelNr
	 * @param menge
	 */
	void bucheZugang(int artikelNr, int menge);
	/**
	 * @brief bucheAbgang verringert den bestand
	 * @param artikelNr
	 * @param menge
	 */
	void bucheAbgang(int artikelNr, int menge);
	/**
	 * @brief preiseAendern aendert alle preise prozentual
	 * @param preisAenderung
	 */
	void preiseAendern(double preisAenderung);
	/**
	 * @brief toString gibt den Inhalt des Lagers als String zurueck
	 * @returns Stringrepresentation des Lager-Objekts
	 */
	string toString() const;
	/**
	 * @brief <<Operator zur ausgabe in einen stream
	 * @returns referenz auf stream mit angehaengtem LagerString
	 */
	friend ostream& operator<<(ostream&, const Lager&);
	static const char* meldungGroesse;
	static const char* meldungNameLeer;
	static const char* meldungArtNrVorhanden;
	static const char* meldungLagerVoll;
	static const char* defaultName;
	static const int defaultArtikelAnzahl = 0;
	static const int defaultSize = 100;
private:
	/**
	* @brief findeArtikel Findet einen Artikel
	* @param artikelNr
	* @returns index, falls Artikel gefunden, sonst -1
	*/
	int findeArtikel(int artikelNr);
	/**
	* @brief loescheAlleArtikel loesche alle artikel
	*/
	void loescheAlleArtikel();
	string name;
	Artikel** artikelTab;
	int anzArtikel;
	int maxAnzArtikel;
};

#endif /* LAGER_H_ */
