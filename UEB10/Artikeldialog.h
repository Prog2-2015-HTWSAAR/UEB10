/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb06 *.o
 * @file Artikeldialog.h
 * @author Andreas Schreiner & Simon Bastian
 *
 * @date 08.05.2015
 *
 * Artikeldialog Header
 *
 */
#ifndef ARTIKELDIALOG_H_
#define ARTIKELDIALOG_H_

#include <iostream>
#include "Artikel.h"

#define TESTNR 4711
#define TESTBEZ "Wasser"
#define NEUBEZ "Koelsch-Wasser"
#define TESTBESTAND 42
#define NEUBESTAND 40
#define TESTPREIS 13.37
#define NEUPREIS 137.70
#define TESTAENDERUNG 5
#define TESTABGANG 23
#define TESTZUGANG 21
#define BIGNUMBER 10000

enum ArtikelTstOption{EXITT, AUTOTEST, MITBESTAND, OHNEBESTAND};
enum ManuelleOption{EXITM, SETBEZ, SETPRICE, SETBESTAND, CHANGEPRICE, ABGANG, ZUGANG};
class Artikeldialog {
public:
	static const char* ARTIKELNUMMER;
	static const char* BEZEICHNUNG;
	static const char* ARTIKELPREIS;
	static const char* BESTAND;
	static const char* SEPERATOR;
	static const char* NEWPHRASE;
	static const char* DIALOGOPTIONONE;
	static const char* DIALOGOPTIONTWO;
	static const char* DIALOGOPTIONTHREE;
	static const char* STANDARDEXITOPTION;
	static const char* STANDARDCHOICEPHRASE;
	static const char* MANUELLDIALOGOPTIONONE;
	static const char* MANUELLDIALOGOPTIONTWO;
	static const char* MANUELLDIALOGOPTIONTHREE;
	static const char* MANUELLDIALOGOPTIONFOUR;
	static const char* MANUELLDIALOGOPTIONFIVE;
	static const char* MANUELLDIALOGOPTIONSIX;
	static const char* PRICECHANGEPHRASE;
	static const char* INPUTERRORPHRASE;
	static const char* WITHOUTPHRASE;
	static const char* RUNTESTCONSTRUCTORPHRASE;
	static const char* USEVALUESPHRASE;
	static const char* VALUEPHRASE;
	static const char* CREATEARTIKELPHRASE;
	static const char* ERRORPHRASE;
	/**
	 * @brief Konstruktor
	 */
	Artikeldialog();
	virtual ~Artikeldialog();
	/**
	 * @brief Ausgeben eines Artikels
	 * @param artikel
	 */
	void ausgeben(const Artikel& artikel);
	/**
	 * @brief Test des Konstruktors mit zwei Argumenten
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelpreis
	 */
	void testeConstructor1(int artikelNr, string bezeichnung, double artikelpreis);
	/**
	 * @brief Test des Konstruktors mit drei Argumenten
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelpreis
	 * @param bestand
	 */
	void testeConstructor2(int artikelNr, string bezeichnung, double artikelpreis, int bestand);
	/**
	 * @brief Test der Zugangsbuchung eines Artikels
	 * @param artikel
	 */
	void testeBucheZugang(Artikel *artikel);
	/**
	 * @brief Test der Abgangsbuchung eines Artikels
	 * @param artikel
	 */
	void testeBucheAbgang(Artikel *artikel);
	/**
     * @brief Test des Setzens der Bezeichnung eines Artikels
	 * @param artikel
	 */
	void testeSetBezeichnung(Artikel *artikel);
	/**
	 * @brief Test des Setzens des Bestands eines Artikels
	 * @param artikel
	 */
	void testeSetBestand(Artikel *artikel);
	/**
	 * @brief Test des Setzens des Preises eines Artikels
	 * @param artikel
	 */
	void testeSetPreis(Artikel *artikel);
	/**
	 * @brief Test der Aenderung eines Preises
	 * @param artikel
	 */
	void testeAenderePreis(Artikel *artikel);
	/**
	 * @brief Ausfuehrung aller Tests
	 */
	void testeAlles();
	/**
	 * @brief Benutzerdialog
	 * @details Dialog zur Auswahl zwischen automatischen Tests und manuellem Testen
	 */
	void chooseDialog();
	/**
	 * @brief Interaktiver Test eines Artikels
	 * @param artikel
	 */
	void testeManuell(Artikel* artikel);
	/**
	 * @brief Interaktives Erstellen eines Testartikels mit Bestand
	 * @details ruft testeManuell() auf
	 */
	void createArtikelMitBestand();
	/**
	 * @brief Interaktives Erstellen eines Testartikels ohne Bestand
	 * @details ruft testeManuell() auf
	 */
	void createArtikelOhneBestand();
	/**
	 * @brief Eingabeleerung
	 * @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	 */
	void leereEingabe();
};
#endif /* ARTIKELDIALOG_H_ */

