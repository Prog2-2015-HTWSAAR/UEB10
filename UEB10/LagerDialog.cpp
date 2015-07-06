/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb10 *.o
* @file LagerDialog.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 01.06.2015
*
* LagerDialog implementation
*
*/
#include "LagerDialog.h"
namespace artikel {

	const char* LagerDialog::TESTARTIKELBEZEICHNUNGONE = "TESTARTIKEL1";
	const char* LagerDialog::TESTARTIKELBEZEICHNUNGTWO = "TESTARTIKEL2";
	const char* LagerDialog::TESTARTIKELBEZEICHNUNGTHREE = "TESTARTIKEL3";
	const char* LagerDialog::TESTLAGERNAME = "LAGERTEST";
	const char* LagerDialog::AUTOTESTERZEUGEARTIKEL = "ERZEUGE Artikel mit folgenden Werten: ";
	const char* LagerDialog::AUTOTESTLOESCHEARTIKEL = "LOESCHE Artikel mit folgenden Werten: ";
	const char* LagerDialog::AUTOTESTZUBUCHEN = "ERHOHE Bestand um: ";
	const char* LagerDialog::AUTOTESTABBUCHEN = "VERRINGERE Bestand um: ";
	const char* LagerDialog::AUTOTESTPREISAENDERN = "AENDERE Preise um: ";
	const int LagerDialog::TESTARTIKELNUMMERWRONG = 123;
	const int LagerDialog::TESTARTIKELNUMMERONE = 1111;
	const int LagerDialog::TESTARTIKELNUMMERTWO = 2222;
	const int LagerDialog::TESTARTIKELNUMMERTHREE = 3333;
	const int LagerDialog::TESTARTIKELNUMMERFOUR = 3323;
	const int LagerDialog::TESTARTIKELBESTANDONE = 1;
	const int LagerDialog::TESTARTIKELBESTANDTWO = 2;
	const int LagerDialog::TESTARTIKELBESTANDTHREE = 3;
	const int LagerDialog::TESTARTIKELBESTANDNEGATIVE = -1;
	const int LagerDialog::TESTARTIKELBESTANDAENDERUNGONE = 4;
	const int LagerDialog::TESTARTIKELBESTANDAENDERUNGTWO = 19;
	const double LagerDialog::TESTARTIKELPREISONE = 1.0;
	const double LagerDialog::TESTARTIKELPREISTWO = 2.4;
	const double LagerDialog::TESTARTIKELPREISTHREE = 44.3;
	const double LagerDialog::TESTARTIKELPREISAENDERUNGONE = 10;
	const double LagerDialog::TESTARTIKELPREISAENDERUNGTWO = -12;
	const double LagerDialog::TESTARTIKELPREISNEGATIVE = -1;
	const int LagerDialog::TESTLAGERSIZEFUERAUTO = 3;
	const char* LagerDialog::LAGERWIRKLICHLOESCHEN = "Lager wirklich Loeschen (j)=Ja: ";
	const char* LagerDialog::ARTIKELWIRKLICHLOESCHEN = "Artikel wirklich Loeschen (j)=Ja: ";
	const char* LagerDialog::ARTIKELNUMMER = "Artikelnummer: ";
	const char* LagerDialog::BEZEICHNUNG = "Bezeichnung: ";
	const char* LagerDialog::ARTIKELPREIS = "Artikelpreis: ";
	const char* LagerDialog::BESTAND = "Bestand: ";
	const char* LagerDialog::ZUGANG = "Zugang: ";
	const char* LagerDialog::ABGANG = "Abgang: ";
	const char* LagerDialog::PRICECHANGEPHRASE = "Preisaenderung (%): ";
	const char* LagerDialog::EDITDIALOGOPTIONONE = "(1) BUCHE - Zugang";
	const char* LagerDialog::EDITDIALOGOPTIONTWO = "(2) BUCHE - Abgang";
	const char* LagerDialog::EDITDIALOGOPTIONTHREE = "(3) Aendere Preis (%)";
	const char* LagerDialog::SEPERATOR = "-L-----------------------------";
	const char* LagerDialog::SEPERATORCREATELAGER = "-L-------CREATE-LAGER----------";
	const char* LagerDialog::SEPERATORDELETELAGER = "-L-------DELETE-LAGER----------";
	const char* LagerDialog::SEPERATORBUCHEZUGANG = "-L-------BUCHE-ZUGANG----------";
	const char* LagerDialog::SEPERATORBUCHEABGANG = "-L-------BUCHE-ABGANG----------";
	const char* LagerDialog::SEPERATORAENDEREPREIS = "-L-------AENDERE-PREIS---------";
	const char* LagerDialog::SEPERATORDELETEARTIKEL = "-L-------DELETE-ARTIKEL--------";
	const char* LagerDialog::SEPERATORCREATEARTIKEL = "-L-------CREATE-ARTIKEL--------";
	const char* LagerDialog::DIALOGOPTIONONE = "(1) Groesse und Name festlegen";
	const char* LagerDialog::DIALOGOPTIONTWO = "(2) Groesse festlegen";
	const char* LagerDialog::DIALOGOPTIONTHREE = "(3) Standardlager";
	const char* LagerDialog::DIALOGOPTIONFOUR = "(4) Automatischer Test";
	const char* LagerDialog::STANDARDEXITOPTION = "(0) -EXIT/BACK-";
	const char* LagerDialog::STANDARDBACKOPTION = "(0) -BACK-";
	const char* LagerDialog::LAGERDIALOGOPTIONONE = "(1) Artikel Anlegen";
	const char* LagerDialog::LAGERDIALOGOPTIONTWO = "(2) Artikel Anlegen ohne Bestand";
	const char* LagerDialog::LAGERDIALOGOPTIONTHREE = "(3) Elektrogeraet Anlegen";
	const char* LagerDialog::LAGERDIALOGOPTIONFOUR = "(4) Kleidung Anlegen";
	const char* LagerDialog::LAGERDIALOGOPTIONFIVE = "(5) Lebensmittel Anlegen";
	const char* LagerDialog::LAGERDIALOGOPTIONSIX = "(6) Artikel Bearbeiten";
	const char* LagerDialog::LAGERDIALOGOPTIONSEVEN = "(7) Artikel Loeschen";
	const char* LagerDialog::LAGERDIALOGOPTIONEXIT = "(0) Lager Loeschen";
	const char* LagerDialog::STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
	const char* LagerDialog::INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
	const char* LagerDialog::ERRORPHRASE = "Fehler: ";
	const char* LagerDialog::STANDARDLAGERNAME = "Lager";
	const char* LagerDialog::ENTERNAMEPHRASE = "Bitte geben sie den Lagernamen ein: ";
	const char* LagerDialog::ENTERSIZEPHRASE = "Bitte geben sie die Lagergroesse ein: ";

	/**
	* @brief Konstructor
	*/
	LagerDialog::LagerDialog(){
		aktuellesDatum = new Datum(1, 1, 2000);
		updateDatum();
	}
	/**
	* @brief Destructor
	*/
	LagerDialog::~LagerDialog(){}
	/**
	* @brief Dialog zur Erstellung des Lagers
	*/
	void LagerDialog::createLagerDialog(){
		Lager* lager = NULL;
		int answer = EXITCL;
		int anzahl = -1;
		std::string name = STANDARDLAGERNAME;
		do {
			std::cout << SEPERATOR << std::endl << DIALOGOPTIONONE << std::endl << DIALOGOPTIONTWO
				<< std::endl << DIALOGOPTIONTHREE << std::endl << DIALOGOPTIONFOUR << std::endl << STANDARDEXITOPTION << std::endl
				<< std::endl << STANDARDCHOICEPHRASE;
			answer = readIntegerInput();
			try {
				switch (answer){
				case EXITCL:
					break;
				case SIZENAME:
					std::cout << SEPERATORCREATELAGER << std::endl << ENTERSIZEPHRASE;
					std::cin >> anzahl;
					leereEingabe();
					std::cout << ENTERNAMEPHRASE;
					std::cin >> name;
					leereEingabe();
					lager = new Lager(anzahl, name);
					startLagerDialog(lager);
					delete lager;
					break;
				case NAME:
					std::cout << SEPERATORCREATELAGER << std::endl << ENTERSIZEPHRASE;
					std::cin >> anzahl;
					leereEingabe();
					lager = new Lager(anzahl);
					startLagerDialog(lager);
					delete lager;
					break;
				case STANDARD:
					lager = new Lager();
					startLagerDialog(lager);
					delete lager;
					break;
				case LAGERAUTOTST:
					automatischerLagerTest();
					delete lager;
					break;
				default:
					std::cout << INPUTERRORPHRASE << std::endl;
				}
			}
			catch (LagerException& e) {
				std::cout << ERRORPHRASE << e.what() << std::endl;
			}

		} while (answer != 0);
	}
	/**
	* @brief startLagerDialog Dialog Lagermanagementdialog
	* @param lager
	*/
	void LagerDialog::startLagerDialog(Lager* lager) {
		int answer = EXITML;
		std::string wirklichLoeschen = "n";
		int artikelNr = 0000;
		int bestand = 0;
		double preis = 0.0;
		double leistung = 0.0;
		double groesse = 0.0;
		std::string farbe;
		std::string bezeichnung;
		Datum datum = Datum(0,0,0);
		do {
			std::cout << "Heutiges Datum: " << aktuellesDatum << std::endl;
			std::cout << *lager << std::endl;
			std::cout << SEPERATOR << std::endl << LAGERDIALOGOPTIONONE << std::endl << LAGERDIALOGOPTIONTWO
				<< std::endl << LAGERDIALOGOPTIONTHREE << std::endl << LAGERDIALOGOPTIONFOUR
				<< std::endl << LAGERDIALOGOPTIONFIVE << std::endl << LAGERDIALOGOPTIONSIX
				<< std::endl << LAGERDIALOGOPTIONSEVEN << std::endl << LAGERDIALOGOPTIONEXIT
				<< std::endl << std::endl << STANDARDCHOICEPHRASE;
			answer = readIntegerInput();
			try {
				switch (answer){
				case EXITML:
					std::cout << SEPERATORDELETEARTIKEL << std::endl << LAGERWIRKLICHLOESCHEN;
					std::cin >> wirklichLoeschen;
					leereEingabe();
					if (wirklichLoeschen != "j"){
						answer = ABORT;
					}
					std::cout << std::endl;
					break;
				case CREATEARTIKEL:
					std::cout << SEPERATORCREATEARTIKEL << std::endl << ARTIKELNUMMER;
					std::cin >> artikelNr;
					leereEingabe();
					std::cout << BEZEICHNUNG;
					std::cin >> bezeichnung;
					leereEingabe();
					std::cout << ARTIKELPREIS;
					std::cin >> preis;
					leereEingabe();
					std::cout << BESTAND;
					std::cin >> bestand;
					leereEingabe();
					std::cout << std::endl;
					lager->createArtikel(artikelNr, bezeichnung, preis, bestand);
					break;
				case CREATEARTIKELOHNEBESTAND:
					std::cout << SEPERATORCREATEARTIKEL << std::endl << ARTIKELNUMMER;
					std::cin >> artikelNr;
					leereEingabe();
					std::cout << BEZEICHNUNG;
					std::cin >> bezeichnung;
					leereEingabe();
					std::cout << ARTIKELPREIS;
					std::cin >> preis;
					leereEingabe();
					std::cout << std::endl;
					lager->createArtikel(artikelNr, bezeichnung, preis);
					break;
				case CREATEELEKTROGERAET:
					std::cout << SEPERATORCREATEARTIKEL << std::endl << ARTIKELNUMMER;
					std::cin >> artikelNr;
					leereEingabe();
					std::cout << BEZEICHNUNG;
					std::cin >> bezeichnung;
					leereEingabe();
					std::cout << ARTIKELPREIS;
					std::cin >> preis;
					leereEingabe();
					std::cout << BESTAND;
					std::cin >> bestand;
					leereEingabe();
					std::cout << "Leistung: ";
					leistung = readDoubleInput();
					std::cout << std::endl;
					lager->createElektrogeraet(artikelNr, bezeichnung, preis, bestand, leistung);
					break;
				case CREATEKLEIDUNG:
					std::cout << SEPERATORCREATEARTIKEL << std::endl << ARTIKELNUMMER;
					std::cin >> artikelNr;
					leereEingabe();
					std::cout << BEZEICHNUNG;
					std::cin >> bezeichnung;
					leereEingabe();
					std::cout << ARTIKELPREIS;
					std::cin >> preis;
					leereEingabe();
					std::cout << BESTAND;
					std::cin >> bestand;
					leereEingabe();
					std::cout << "Groesse: ";
					groesse = readDoubleInput();
					std::cout << "Farbe: ";
					std::cin >> farbe;
					leereEingabe();
					std::cout << std::endl;
					lager->createKleidung(artikelNr, bezeichnung, preis, bestand, groesse, farbe);
					break;
				case CREATELEBENSMITTEL:
					std::cout << SEPERATORCREATEARTIKEL << std::endl << ARTIKELNUMMER;
					std::cin >> artikelNr;
					leereEingabe();
					std::cout << BEZEICHNUNG;
					std::cin >> bezeichnung;
					leereEingabe();
					std::cout << ARTIKELPREIS;
					std::cin >> preis;
					leereEingabe();
					std::cout << BESTAND;
					std::cin >> bestand;
					leereEingabe();
					std::cout << "Mindeshaltbarkeitsdatum: ";
					std::cin >> datum;
					leereEingabe();
					std::cout << std::endl;
					lager->createLebensmittel(artikelNr, bezeichnung, preis, bestand, datum, *aktuellesDatum);
					break;
				case EDITARTIKEL:
					artikelEditDialog(lager);
					break;
				case DELETEARTIKEL:
					std::cout << SEPERATORDELETEARTIKEL << std::endl << ARTIKELNUMMER;
					std::cin >> artikelNr;
					leereEingabe();
					std::cout << ARTIKELWIRKLICHLOESCHEN;
					std::cin >> wirklichLoeschen;
					leereEingabe();
					if (wirklichLoeschen == "j"){
						lager->deleteArtikel(artikelNr);
					}
					break;
				case ABORT:
					//Do nothing if Artikeldeleting was aborted
					break;
				default:
					std::cout << INPUTERRORPHRASE << std::endl;
				}

			}
			catch (LagerException& e) {
				std::cout << ERRORPHRASE << e.what() << std::endl;
			}
			catch (ArtikelException& e) {
				std::cout << ERRORPHRASE << e.what() << std::endl;
			}
		} while (answer != EXITML);

	}
	/**
	* @brief artikelEditDialog Dialog zum Aendern von Artikeln
	* @param lager
	*/
	void LagerDialog::artikelEditDialog(Lager* lager){
		int artikelNr = 0000;
		int bestandAenderung = 0;
		double preisAenderung = 0.0;
		int answer = -1;
		do {
			std::cout << std::endl << *lager << std::endl;
			std::cout << SEPERATOR << std::endl << EDITDIALOGOPTIONONE << std::endl << EDITDIALOGOPTIONTWO
				<< std::endl << EDITDIALOGOPTIONTHREE << std::endl << STANDARDBACKOPTION << std::endl
				<< std::endl << STANDARDCHOICEPHRASE;
			std::cin >> answer;
			leereEingabe();
			try {
				switch (answer){
				case EXITMA:
					break;
				case ZUGANGL:
					std::cout << SEPERATORBUCHEZUGANG << std::endl << ARTIKELNUMMER;
					std::cin >> artikelNr;
					leereEingabe();
					std::cout << ZUGANG;
					std::cin >> bestandAenderung;
					leereEingabe();
					lager->bucheZugang(artikelNr, bestandAenderung);
					break;
				case ABGANGL:
					std::cout << SEPERATORBUCHEABGANG << std::endl << ARTIKELNUMMER;
					std::cin >> artikelNr;
					leereEingabe();
					std::cout << ABGANG;
					std::cin >> bestandAenderung;
					leereEingabe();
					lager->bucheAbgang(artikelNr, bestandAenderung);
					break;
				case CHANGEPRICES:
					std::cout << SEPERATORAENDEREPREIS << std::endl << PRICECHANGEPHRASE;
					std::cin >> preisAenderung;
					leereEingabe();
					lager->preiseAendern(preisAenderung);
					break;
				default:
					std::cout << INPUTERRORPHRASE << std::endl;
				}
			}
			catch (const char* e) {
				std::cout << ERRORPHRASE << e << std::endl;
			}
		} while (answer != 0);
	}
	/**
	* @brief Eingabeleerung
	* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	*/
	void LagerDialog::leereEingabe(){
		std::cin.clear();
		std::cin.ignore(BIGNUMBER, '\n');
	}
	void LagerDialog::automatischerLagerTest(){
		Lager* lager = NULL;
		lager = new Lager(TESTLAGERSIZEFUERAUTO, TESTLAGERNAME); //Lager Erzeugen size 3
		int testNummer = 0;
		while (testNummer != 15){
			try{
				std::cout << *lager << std::endl;
				switch (testNummer){
				case 0:
					std::cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERWRONG << ", " << TESTARTIKELBEZEICHNUNGONE
						<< ", " << TESTARTIKELPREISONE << ", " << TESTARTIKELBESTANDONE << std::endl;
					lager->createArtikel(TESTARTIKELNUMMERWRONG, TESTARTIKELBEZEICHNUNGONE, TESTARTIKELPREISONE, TESTARTIKELBESTANDONE); //test 1 Falsche ArtNr
					break;
				case 1:
					std::cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGONE
						<< ", " << TESTARTIKELPREISONE << ", " << TESTARTIKELBESTANDNEGATIVE << std::endl;
					lager->createArtikel(TESTARTIKELNUMMERONE, TESTARTIKELBEZEICHNUNGONE, TESTARTIKELPREISONE, TESTARTIKELBESTANDNEGATIVE); //test 2 NEGATIVER BESTAND
					break;
				case 2:
					std::cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGONE
						<< ", " << TESTARTIKELPREISNEGATIVE << ", " << TESTARTIKELBESTANDONE << std::endl;
					lager->createArtikel(TESTARTIKELNUMMERONE, TESTARTIKELBEZEICHNUNGONE, TESTARTIKELPREISNEGATIVE, TESTARTIKELBESTANDONE); //test 3 NEGATIVER PREIS
					break;
				case 3:
					std::cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGONE
						<< ", " << TESTARTIKELPREISONE << ", " << TESTARTIKELBESTANDONE << std::endl;
					lager->createArtikel(TESTARTIKELNUMMERONE, TESTARTIKELBEZEICHNUNGONE, TESTARTIKELPREISONE, TESTARTIKELBESTANDONE); //Artikel 1 Erzeugen
					break;
				case 4:
					std::cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGTWO
						<< ", " << TESTARTIKELPREISTWO << ", " << TESTARTIKELBESTANDTWO << std::endl;
					lager->createArtikel(TESTARTIKELNUMMERONE, TESTARTIKELBEZEICHNUNGTWO, TESTARTIKELPREISTWO, TESTARTIKELBESTANDTWO); //test 4 Artikel 2 mit gleicher ArtNr wie Artikel 1
					break;
				case 5:
					std::cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERTWO << ", " << TESTARTIKELBEZEICHNUNGTWO
						<< ", " << TESTARTIKELPREISTWO << ", " << TESTARTIKELBESTANDTWO << std::endl;
					lager->createArtikel(TESTARTIKELNUMMERTWO, TESTARTIKELBEZEICHNUNGTWO, TESTARTIKELPREISTWO, TESTARTIKELBESTANDTWO); //Artikel 2 Erzeugen
					break;
				case 6:
					std::cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERTHREE << ", " << TESTARTIKELBEZEICHNUNGTHREE
						<< ", " << TESTARTIKELPREISTHREE << ", " << TESTARTIKELBESTANDTHREE << std::endl;
					lager->createArtikel(TESTARTIKELNUMMERTHREE, TESTARTIKELBEZEICHNUNGTHREE, TESTARTIKELPREISTHREE, TESTARTIKELBESTANDTHREE); //Artikel 3 Erzeugen
					break;
				case 7:
					std::cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERFOUR << ", " << TESTARTIKELBEZEICHNUNGTHREE
						<< ", " << TESTARTIKELPREISTHREE << ", " << TESTARTIKELBESTANDTHREE << std::endl;
					lager->createArtikel(TESTARTIKELNUMMERFOUR, TESTARTIKELBEZEICHNUNGTHREE, TESTARTIKELPREISTHREE, TESTARTIKELBESTANDTHREE); //test 5 Artikel 4 Erzeugen
					break;
				case 8:
					std::cout << AUTOTESTLOESCHEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGONE
						<< ", " << TESTARTIKELPREISONE << ", " << TESTARTIKELBESTANDONE << std::endl;
					lager->deleteArtikel(TESTARTIKELNUMMERONE); //test 6 Loesche Artikel 1
					break;
				case 9:
					std::cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << std::endl << AUTOTESTZUBUCHEN << TESTARTIKELBESTANDAENDERUNGONE << std::endl;
					lager->bucheZugang(TESTARTIKELNUMMERTWO, TESTARTIKELBESTANDAENDERUNGONE); // test 6.1 Bestang Zugang
					break;
				case 10:
					std::cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << std::endl << AUTOTESTABBUCHEN << TESTARTIKELBESTANDAENDERUNGONE << std::endl;
					lager->bucheAbgang(TESTARTIKELNUMMERTWO, TESTARTIKELBESTANDAENDERUNGONE);  // test 6.2 Bestang Abgang
					break;
				case 11:
					std::cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << std::endl << AUTOTESTABBUCHEN << TESTARTIKELBESTANDAENDERUNGTWO << std::endl;
					lager->bucheAbgang(TESTARTIKELNUMMERTWO, TESTARTIKELBESTANDAENDERUNGTWO);  // test 6.3 Bestang Abgang Negative
					break;
				case 12:
					std::cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << std::endl << AUTOTESTPREISAENDERN << TESTARTIKELPREISAENDERUNGONE << "%" << std::endl;
					lager->preiseAendern(TESTARTIKELPREISAENDERUNGONE); //test 7.1 Preiserhoehen
					break;
				case 13:
					std::cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << std::endl << AUTOTESTPREISAENDERN << TESTARTIKELPREISAENDERUNGTWO << "%" << std::endl;
					lager->preiseAendern(TESTARTIKELPREISAENDERUNGTWO); //test 7.2 Preisverringern
					break;
				case 14:
					delete lager;
					break;
				}
			}
			catch (const char* e) {
				std::cout << ERRORPHRASE << e << std::endl;
			}
			catch (LagerException& e) {
				std::cout << ERRORPHRASE << e.what() << std::endl;
			}
			catch (ArtikelException& e) {
				std::cout << ERRORPHRASE << e.what() << std::endl;
			}
			testNummer++;
		}
		std::cout << "ENDE";
	}
	void LagerDialog::updateDatum(){
		std::time_t time = std::time(NULL);
		struct tm * now = localtime(&time);
		aktuellesDatum->setTag(now->tm_mday);
		aktuellesDatum->setMonat((now->tm_mon) + 1);
		aktuellesDatum->setJahr((now->tm_year) + 1900);
	}
	int LagerDialog::readIntegerInput(){
		double number = readDoubleInput();
		if (!(fmod(number, 1) == 0)){
			number = -1;
		}
		return (int)number;
	}
	double LagerDialog::readDoubleInput(){
		double number;
		if (std::cin >> number){
		}
		else {
			number = -1;
		}
		clearInput();
		return number;
	}
	std::string LagerDialog::readStringInput(){
		std::string input;
		std::cin >> input;
		clearInput();
		return input;
	}
	void LagerDialog::clearInput(){
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}

