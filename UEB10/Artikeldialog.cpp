/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb10 *.o
 * @file Artikeldialog.cpp
 * @author Andreas Schreiner & Simon Bastian
 *
 * @date 16.05.2015
 *
 * Artikeldialog Funktionen
 */
#include "Artikeldialog.h"

#include <iostream>
#include "Artikel.h"
namespace artikel {
	const char* Artikeldialog::ARTIKELNUMMER = "Artikelnummer: ";
	const char* Artikeldialog::BEZEICHNUNG = "\nBezeichnung: ";
	const char* Artikeldialog::ARTIKELPREIS = "\nArtikelpreis: ";
	const char* Artikeldialog::BESTAND = "\naktl. Bestand: ";
	const char* Artikeldialog::SEPERATOR = "-A-----------------------------";
	const char* Artikeldialog::NEWPHRASE = "Neuer";
	const char* Artikeldialog::DIALOGOPTIONONE = "(1) Automatischer Test";
	const char* Artikeldialog::DIALOGOPTIONTWO = "(2) Manueller Test mit Bestandsangabe";
	const char* Artikeldialog::DIALOGOPTIONTHREE = "(3) Manueller Test ohne Bestandsangabe";
	const char* Artikeldialog::STANDARDEXITOPTION = "(0) -EXIT/BACK-";
	const char* Artikeldialog::STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
	const char* Artikeldialog::MANUELLDIALOGOPTIONONE = "(1) SET - Bezeichnung";
	const char* Artikeldialog::MANUELLDIALOGOPTIONTWO = "(2) SET - ArtikelPreis";
	const char* Artikeldialog::MANUELLDIALOGOPTIONTHREE = "(3) SET - Bestand";
	const char* Artikeldialog::MANUELLDIALOGOPTIONFOUR = "(4) Aendere Preis (%)";
	const char* Artikeldialog::MANUELLDIALOGOPTIONFIVE = "(5) BUCHE - Abgang";
	const char* Artikeldialog::MANUELLDIALOGOPTIONSIX = "(6) BUCHE - Zugang";
	const char* Artikeldialog::PRICECHANGEPHRASE = "Preisaenderung (%): ";
	const char* Artikeldialog::INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
	const char* Artikeldialog::WITHOUTPHRASE = "ohne Bestand...";
	const char* Artikeldialog::RUNTESTCONSTRUCTORPHRASE = "Starte Test zum Erstellen eines Artikels";
	const char* Artikeldialog::USEVALUESPHRASE = "Nutze folgende Werte : ";
	const char* Artikeldialog::VALUEPHRASE = "Wert: ";
	const char* Artikeldialog::CREATEARTIKELPHRASE = "Erstellter Artikel:";
	const char* Artikeldialog::ERRORPHRASE = "Fehler: ";
	/**
	 * @brief Konstruktor
	 */
	Artikeldialog::Artikeldialog(){
		// Nothing to do here
	}
	/**
	 * @brief Destruktor
	 */
	Artikeldialog::~Artikeldialog(){
		// Nothing to do here
	}
	/**
	 * @brief ausgeben
	 * @details Ausgabe fkt
	 * @param artikel Artikelreferenz
	 */
	void Artikeldialog::ausgeben(const Artikel& artikel){
		std::cout << ARTIKELNUMMER << artikel.getArtikelNr()
			<< BEZEICHNUNG << artikel.getBezeichnung()
			<< ARTIKELPREIS << artikel.getArtikelPreis()
			<< BESTAND << artikel.getBestand() << std::endl;
	}

	/**
	 * @brief testeConstructor1 mit 2 Parameter(Artikelnummer. Bezeichnung)
	 * @param artikelNr Artikelnummer des neuen Obj
	 * @param bezeichnung Bezeichnung des neuen Obj
	 * @param artikelpreis
	 */
	void Artikeldialog::testeConstructor1(int artikelNr, std::string bezeichnung, double artikelpreis){
		std::cout << std::endl << RUNTESTCONSTRUCTORPHRASE << WITHOUTPHRASE << std::endl
			<< USEVALUESPHRASE << std::endl << ARTIKELNUMMER << artikelNr << std::endl
			<< BEZEICHNUNG << bezeichnung << std::endl << ARTIKELPREIS
			<< artikelpreis << std::endl;
		try{
			Artikel artikel(artikelNr, bezeichnung, artikelpreis);
			std::cout << std::endl << CREATEARTIKELPHRASE << std::endl;
			ausgeben(artikel);
		}
		catch (ArtikelException& e) {
			std::cout << ERRORPHRASE << e.what() << std::endl;
		}

	}
	/**
	 * @brief testeConstructor2 mit 3 Parameter(Artikelnummer.Bezeichnung, Bestand)
	 * @param artikelNr Artikelnummer
	 * @param bezeichnung Bezeichnung
	 * @param bestand Lagerbestand
	 */
	void Artikeldialog::testeConstructor2(int artikelNr, std::string bezeichnung, double artikelpreis, int bestand){

		std::cout << std::endl << RUNTESTCONSTRUCTORPHRASE << std::endl << USEVALUESPHRASE
			<< std::endl << ARTIKELNUMMER << artikelNr << std::endl << BEZEICHNUNG
			<< bezeichnung << std::endl << ARTIKELPREIS << artikelpreis << std::endl
			<< BESTAND << bestand << std::endl;

		try {
			Artikel artikel(artikelNr, bezeichnung, artikelpreis, bestand);
			std::cout << std::endl << CREATEARTIKELPHRASE << std::endl;
			ausgeben(artikel);
		}
		catch (ArtikelException& e) {
			std::cout << ERRORPHRASE << e.what() << std::endl;
		}

	}
	/**
	 * @brief testeBucheAbgang
	 * @details Autom Test Buche Abgang Bestand
	 * @param artikel Artikel obj
	 */
	void Artikeldialog::testeBucheAbgang(Artikel *artikel){
		int menge = TESTABGANG;

		std::cout << std::endl << "Starte Test zur Buchung eines Abgangs..." << std::endl;

		std::cout << "Der Abgang umfasst " << menge << " Artikel!" << std::endl;

		std::cout << "Artikel vor Abgang:" << std::endl;
		ausgeben(*artikel);

		try {
			artikel->bucheAbgang(menge);
			std::cout << std::endl << "Artikel nach Abgang:" << std::endl;
			ausgeben(*artikel);
		}
		catch (ArtikelException& e) {
			std::cout << ERRORPHRASE << e.what() << std::endl;
		}
	}

	/**
	 * @brief testeBucheZugang
	 * @details Autom Test Buche Zugang Bestand
	 * @param artikel Artikel obj
	 */
	void Artikeldialog::testeBucheZugang(Artikel *artikel){
		int menge = TESTZUGANG;

		std::cout << std::endl << "Starte Test zur Buchung eines Zugangs..." << std::endl;

		std::cout << "Der Zugang umfasst " << menge << " Artikel!" << std::endl;

		std::cout << "Artikel vor Zugang:" << std::endl;
		ausgeben(*artikel);

		try {
			artikel->bucheZugang(menge);
			std::cout << std::endl << "Artikel nach Zugang:" << std::endl;
			ausgeben(*artikel);
		}
		catch (ArtikelException& e) {
			std::cout << ERRORPHRASE << e.what() << std::endl;
		}

	}

	/**
	 * @brief testeSetBezeichnung
	 * @details Autom Test Setze Bezeichnung
	 * @param artikel Artikel obj
	 */
	void Artikeldialog::testeSetBezeichnung(Artikel *artikel){
		std::string bezeichnung = NEUBEZ;
		std::cout << std::endl << "Starte Test zum Setzen der Bezeichnung eines Artikels..." << std::endl;

		std::cout << "Die neue Bezeichnung soll " << bezeichnung << " sein!" << std::endl;

		std::cout << "Artikel vorher:" << std::endl;
		ausgeben(*artikel);

		try {
			artikel->setBezeichnung(bezeichnung);
			std::cout << std::endl << "Artikel nachher:" << std::endl;
			ausgeben(*artikel);
		}
		catch (ArtikelException& e) {
			std::cout << ERRORPHRASE << e.what() << std::endl;
		}

	}

	/**
	 * @brief testeSetBestand
	 * @details Autom Test Setze Bestand
	 * @param artikel Artikel obj
	 */
	void Artikeldialog::testeSetBestand(Artikel *artikel){
		int bestand = NEUBESTAND;
		std::cout << std::endl << "Starte Test zum Setzen des Bestands eines Artikels..." << std::endl;

		std::cout << "Der neue Bestand soll " << bestand << " sein!" << std::endl;

		std::cout << "Artikel vorher:" << std::endl;
		ausgeben(*artikel);

		try {
			artikel->setBestand(bestand);
			std::cout << std::endl << "Artikel nachher:" << std::endl;
			ausgeben(*artikel);
		}
		catch (ArtikelException& e) {
			std::cout << ERRORPHRASE << e.what() << std::endl;
		}

	}
	/**
	 * @brief Test des Setzens des Preises eines Artikels
	 * @param artikel
	 */
	void Artikeldialog::testeSetPreis(Artikel *artikel){
		double preis = NEUPREIS;
		std::cout << std::endl << "Starte Test zum Setzen des Preises eines Artikels..." << std::endl;

		std::cout << "Der neue Preis soll " << preis << " sein!" << std::endl;

		std::cout << "Artikel vorher:" << std::endl;
		ausgeben(*artikel);

		try {
			artikel->setPreis(preis);
			std::cout << std::endl << "Artikel nachher:" << std::endl;
			ausgeben(*artikel);
		}
		catch (ArtikelException& e) {
			std::cout << ERRORPHRASE << e.what() << std::endl;
		}

	}
	/**
	 * @brief Test der Aenderung eines Preises
	 * @param artikel
	 */
	void Artikeldialog::testeAenderePreis(Artikel *artikel){
		double preisaenderung = TESTAENDERUNG;

		std::cout << std::endl << "Starte Test zur Aenderung des Preises..." << std::endl;

		std::cout << "Der Preis aendert sich um " << preisaenderung << " Prozent!" << std::endl;

		std::cout << "Artikel vor Zugang:" << std::endl;
		ausgeben(*artikel);

		try {
			artikel->aenderePreis(preisaenderung);
			std::cout << std::endl << "Artikel nach Zugang:" << std::endl;
			ausgeben(*artikel);
		}
		catch (ArtikelException& e) {
			std::cout << ERRORPHRASE << e.what() << std::endl;
		}
	}
	/**
	* @brief testeAlles
	* @details Autom Test Fkt
	*/
	void Artikeldialog::testeAlles(){
		int artikelNr = TESTNR;
		std::string beschreibung = TESTBEZ;
		int bestand = TESTBESTAND;
		double preis = TESTPREIS;
		Artikel* artikel = new Artikel(artikelNr, beschreibung, preis, bestand);

		std::cout << std::endl << "Starte alle Tests..." << std::endl;

		testeConstructor1(artikelNr, beschreibung, preis);
		testeConstructor2(artikelNr, beschreibung, preis, bestand);
		testeBucheAbgang(artikel);
		testeBucheZugang(artikel);
		testeSetBezeichnung(artikel);
		testeSetBestand(artikel);
		testeSetPreis(artikel);
		testeAenderePreis(artikel);
	}
	/**
	 * @brief Benutzerdialog
	 * @details Dialog zur Auswahl zwischen automatischen Tests und manuellem Testen
	 */
	void Artikeldialog::chooseDialog(){
		int answer = -1;
		do {
			std::cout << SEPERATOR << std::endl << DIALOGOPTIONONE << std::endl << DIALOGOPTIONTWO
				<< std::endl << DIALOGOPTIONTHREE << std::endl << STANDARDEXITOPTION << std::endl
				<< std::endl << STANDARDCHOICEPHRASE;
			std::cin >> answer;
			try {
				switch (answer){
				case EXITT:
					break;
				case AUTOTEST:
					testeAlles();
					break;
				case MITBESTAND:
					createArtikelMitBestand();
					break;
				case OHNEBESTAND:
					createArtikelOhneBestand();
					break;
				default:
					std::cout << INPUTERRORPHRASE << std::endl;
				}
			}
			catch (ArtikelException& e) {
				std::cout << ERRORPHRASE << e.what() << std::endl;
			}
		} while (answer != EXITT);
	}

	/**
	 * @brief createArtikelComplete
	 * @details Artikel Erstellung mit 4 parametern
	 */
	void Artikeldialog::createArtikelMitBestand(){
		int artikelNr = 0;
		std::string bezeichnung = "";
		double artikelPreis = 0.0;
		int bestand = 0;
		std::cout << CREATEARTIKELPHRASE << std::endl << ARTIKELNUMMER;
		std::cin >> artikelNr;
		leereEingabe();
		std::cout << BEZEICHNUNG;
		std::cin >> bezeichnung;
		std::cout << ARTIKELPREIS;
		std::cin >> artikelPreis;
		leereEingabe();
		std::cout << BESTAND;
		std::cin >> bestand;
		leereEingabe();
		Artikel* artikel = new Artikel(artikelNr, bezeichnung, artikelPreis, bestand);
		testeManuell(artikel);

	}
	/**
	 * @brief createArtikelTwoParam
	 * @details Artikel Erstellung mit 3 parametern wobei bestand=0
	 */
	void Artikeldialog::createArtikelOhneBestand(){
		int artikelNr = 0;
		std::string bezeichnung = "";
		int artikelPreis = 0;
		std::cout << CREATEARTIKELPHRASE << std::endl << ARTIKELNUMMER;
		std::cin >> artikelNr;
		leereEingabe();
		std::cout << BEZEICHNUNG;
		std::cin >> bezeichnung;
		std::cout << ARTIKELPREIS;
		std::cin >> artikelPreis;
		leereEingabe();
		Artikel* artikel = new Artikel(artikelNr, bezeichnung, artikelPreis);
		testeManuell(artikel);
	}

	/**
	 * @brief Interaktiver Test eines Artikels
	 * @param artikel
	 */
	void Artikeldialog::testeManuell(Artikel* artikel){
		int answer = -1;
		double preis = 0.0;
		int menge = 0;
		std::string bezeichnung;
		do {
			std::cout << SEPERATOR << std::endl << ARTIKELNUMMER << artikel->getArtikelNr()
				<< std::endl << BEZEICHNUNG << artikel->getBezeichnung() << std::endl
				<< ARTIKELPREIS << artikel->getArtikelPreis() << std::endl << BESTAND
				<< artikel->getBestand() << std::endl << SEPERATOR << std::endl
				<< MANUELLDIALOGOPTIONONE << std::endl << MANUELLDIALOGOPTIONTWO
				<< std::endl << MANUELLDIALOGOPTIONTHREE << std::endl << std::endl
				<< MANUELLDIALOGOPTIONFOUR << std::endl << MANUELLDIALOGOPTIONFIVE
				<< std::endl << MANUELLDIALOGOPTIONSIX << std::endl << std::endl
				<< STANDARDEXITOPTION << std::endl << std::endl << STANDARDCHOICEPHRASE;
			std::cin >> answer;
			try {
				switch (answer){
				case EXITM:
					break;
				case SETBEZ:
					std::cout << BEZEICHNUNG;
					std::cin >> bezeichnung;
					artikel->setBezeichnung(bezeichnung);
					break;
				case SETPRICE:
					std::cout << NEWPHRASE << ARTIKELPREIS;
					std::cin >> preis;
					artikel->setPreis(preis);
					break;
				case SETBESTAND:
					std::cout << NEWPHRASE << BESTAND;
					std::cin >> menge;
					artikel->setBestand(menge);
					break;
				case CHANGEPRICE:
					std::cout << PRICECHANGEPHRASE;
					std::cin >> preis;
					artikel->aenderePreis(preis);
					break;
				case ABGANG:
					std::cout << VALUEPHRASE;
					std::cin >> menge;
					artikel->bucheAbgang(menge);
					break;
				case ZUGANG:
					std::cout << VALUEPHRASE;
					std::cin >> menge;
					artikel->bucheZugang(menge);
					break;
				default:  std::cout << INPUTERRORPHRASE << std::endl;
				}
			}
			catch (ArtikelException& e) {
				std::cout << std::endl << ERRORPHRASE << e.what() << std::endl << std::endl;
			}
			leereEingabe();
		} while (answer != EXITM);
	}

	/**
	 * @brief Eingabeleerung
	 * @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	 */
	void Artikeldialog::leereEingabe(){
		std::cin.clear();
		std::cin.ignore(BIGNUMBER, '\n');
	}

}
