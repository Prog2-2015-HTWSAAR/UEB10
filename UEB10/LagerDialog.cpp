/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb06 *.o
* @file LagerDialog.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 01.06.2015
*
* LagerDialog implementation
*
*/
#include "LagerDialog.h"
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
const char* LagerDialog::LAGERDIALOGOPTIONTHREE = "(3) Artikel Bearbeiten";
const char* LagerDialog::LAGERDIALOGOPTIONFOUR = "(4) Artikel Loeschen";
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
LagerDialog::LagerDialog(){}
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
	string name = STANDARDLAGERNAME;
	do {
		cout << SEPERATOR << endl << DIALOGOPTIONONE << endl << DIALOGOPTIONTWO
			<< endl << DIALOGOPTIONTHREE << endl << DIALOGOPTIONFOUR << endl << STANDARDEXITOPTION << endl
			<< endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
		try {
			switch (answer){
			case EXITCL:
				break;
			case SIZENAME:
				cout << SEPERATORCREATELAGER << endl << ENTERSIZEPHRASE;
				cin >> anzahl;
				leereEingabe();
				cout << ENTERNAMEPHRASE;
				cin >> name;
				leereEingabe();
				lager = new Lager(anzahl, name);
				startLagerDialog(lager);
				delete lager;
				break;
			case NAME:
				cout << SEPERATORCREATELAGER << endl << ENTERSIZEPHRASE;
				cin >> anzahl;
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
				cout << INPUTERRORPHRASE << endl;
			}
		}
		catch (LagerException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}

	} while (answer != 0);
}
/**
* @brief startLagerDialog Dialog Lagermanagementdialog
* @param lager
*/
void LagerDialog::startLagerDialog(Lager* lager) {
	int answer = EXITML;
	string wirklichLoeschen = "n";
	int artikelNr = 0000;
	int bestand = 0;
	double preis;
	string bezeichnung;
	do {
		cout << *lager << endl;
		cout << SEPERATOR << endl << LAGERDIALOGOPTIONONE << endl << LAGERDIALOGOPTIONTWO
			<< endl << LAGERDIALOGOPTIONTHREE << endl << LAGERDIALOGOPTIONFOUR
			<< endl << LAGERDIALOGOPTIONEXIT << endl << endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
		try {
			switch (answer){
			case EXITML:
				cout << SEPERATORDELETEARTIKEL << endl << LAGERWIRKLICHLOESCHEN;
				cin >> wirklichLoeschen;
				leereEingabe();
				if (wirklichLoeschen != "j"){
					answer = ABORT;
				}
				cout << endl;
				break;
			case CREATEARTIKEL:
				cout << SEPERATORCREATEARTIKEL << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << BEZEICHNUNG;
				cin >> bezeichnung;
				leereEingabe();
				cout << ARTIKELPREIS;
				cin >> preis;
				leereEingabe();
				cout << BESTAND;
				cin >> bestand;
				leereEingabe();
				cout << endl;
				lager->createArtikel(artikelNr, bezeichnung, preis, bestand);
				break;
			case CREATEARTIKELOHNEBESTAND:
				cout << SEPERATORCREATEARTIKEL << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << BEZEICHNUNG;
				cin >> bezeichnung;
				leereEingabe();
				cout << ARTIKELPREIS;
				cin >> preis;
				leereEingabe();
				cout << endl;
				lager->createArtikel(artikelNr, bezeichnung, preis);
				break;
			case EDITARTIKEL:
				artikelEditDialog(lager);
				break;
			case DELETEARTIKEL:
				cout << SEPERATORDELETEARTIKEL << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << ARTIKELWIRKLICHLOESCHEN;
				cin >> wirklichLoeschen;
				leereEingabe();
				if (wirklichLoeschen == "j"){
					lager->deleteArtikel(artikelNr);
				}
				break;
			case ABORT:
				//Do nothing if Artikeldeleting was aborted
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}

		}
		catch (LagerException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}
		catch (ArtikelException& e) {
			cout << ERRORPHRASE << e.what() << endl;
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
		cout << endl << *lager << endl;
		cout << SEPERATOR << endl << EDITDIALOGOPTIONONE << endl << EDITDIALOGOPTIONTWO
			<< endl << EDITDIALOGOPTIONTHREE << endl << STANDARDBACKOPTION << endl
			<< endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
		try {
			switch (answer){
			case EXITMA:
				break;
			case ZUGANGL:
				cout << SEPERATORBUCHEZUGANG << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << ZUGANG;
				cin >> bestandAenderung;
				leereEingabe();
				lager->bucheZugang(artikelNr, bestandAenderung);
				break;
			case ABGANGL:
				cout << SEPERATORBUCHEABGANG << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << ABGANG;
				cin >> bestandAenderung;
				leereEingabe();
				lager->bucheAbgang(artikelNr, bestandAenderung);
				break;
			case CHANGEPRICES:
				cout << SEPERATORAENDEREPREIS << endl << PRICECHANGEPHRASE;
				cin >> preisAenderung;
				leereEingabe();
				lager->preiseAendern(preisAenderung);
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}
		}
		catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
	} while (answer != 0);
}
/**
* @brief Eingabeleerung
* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
*/
void LagerDialog::leereEingabe(){
	cin.clear();
	cin.ignore(BIGNUMBER, '\n');
}
void LagerDialog::automatischerLagerTest(){
	Lager* lager = NULL;
	lager = new Lager(TESTLAGERSIZEFUERAUTO, TESTLAGERNAME); //Lager Erzeugen size 3
	int testNummer = 0;
	while (testNummer != 15){
		try{
			cout << *lager << endl;
			switch (testNummer){
			case 0: 
				cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERWRONG << ", " << TESTARTIKELBEZEICHNUNGONE 
					<< ", " << TESTARTIKELPREISONE << ", " << TESTARTIKELBESTANDONE << endl;
				lager->createArtikel(TESTARTIKELNUMMERWRONG, TESTARTIKELBEZEICHNUNGONE, TESTARTIKELPREISONE, TESTARTIKELBESTANDONE); //test 1 Falsche ArtNr
				break;
			case 1:
				cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGONE 
					<< ", " << TESTARTIKELPREISONE << ", " << TESTARTIKELBESTANDNEGATIVE << endl;
				lager->createArtikel(TESTARTIKELNUMMERONE, TESTARTIKELBEZEICHNUNGONE, TESTARTIKELPREISONE, TESTARTIKELBESTANDNEGATIVE); //test 2 NEGATIVER BESTAND
				break;
			case 2:
				cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGONE 
					<< ", " << TESTARTIKELPREISNEGATIVE << ", " << TESTARTIKELBESTANDONE << endl;
				lager->createArtikel(TESTARTIKELNUMMERONE, TESTARTIKELBEZEICHNUNGONE, TESTARTIKELPREISNEGATIVE, TESTARTIKELBESTANDONE); //test 3 NEGATIVER PREIS
				break;
			case 3:
				cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGONE 
					<< ", " << TESTARTIKELPREISONE << ", " << TESTARTIKELBESTANDONE << endl;
				lager->createArtikel(TESTARTIKELNUMMERONE, TESTARTIKELBEZEICHNUNGONE, TESTARTIKELPREISONE, TESTARTIKELBESTANDONE); //Artikel 1 Erzeugen
				break;
			case 4:
				cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGTWO 
					<< ", " << TESTARTIKELPREISTWO << ", " << TESTARTIKELBESTANDTWO << endl;
				lager->createArtikel(TESTARTIKELNUMMERONE, TESTARTIKELBEZEICHNUNGTWO, TESTARTIKELPREISTWO, TESTARTIKELBESTANDTWO); //test 4 Artikel 2 mit gleicher ArtNr wie Artikel 1
				break;
			case 5:
				cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERTWO << ", " << TESTARTIKELBEZEICHNUNGTWO 
					<< ", " << TESTARTIKELPREISTWO << ", " << TESTARTIKELBESTANDTWO << endl;
				lager->createArtikel(TESTARTIKELNUMMERTWO, TESTARTIKELBEZEICHNUNGTWO, TESTARTIKELPREISTWO, TESTARTIKELBESTANDTWO); //Artikel 2 Erzeugen
				break;
			case 6:
				cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERTHREE << ", " << TESTARTIKELBEZEICHNUNGTHREE 
					<< ", " << TESTARTIKELPREISTHREE << ", " << TESTARTIKELBESTANDTHREE << endl;
				lager->createArtikel(TESTARTIKELNUMMERTHREE, TESTARTIKELBEZEICHNUNGTHREE, TESTARTIKELPREISTHREE, TESTARTIKELBESTANDTHREE); //Artikel 3 Erzeugen
				break;
			case 7:
				cout << AUTOTESTERZEUGEARTIKEL << TESTARTIKELNUMMERFOUR << ", " << TESTARTIKELBEZEICHNUNGTHREE 
					<< ", " << TESTARTIKELPREISTHREE << ", " << TESTARTIKELBESTANDTHREE << endl;
				lager->createArtikel(TESTARTIKELNUMMERFOUR, TESTARTIKELBEZEICHNUNGTHREE, TESTARTIKELPREISTHREE, TESTARTIKELBESTANDTHREE); //test 5 Artikel 4 Erzeugen
				break;
			case 8:
				cout << AUTOTESTLOESCHEARTIKEL << TESTARTIKELNUMMERONE << ", " << TESTARTIKELBEZEICHNUNGONE 
					<< ", " << TESTARTIKELPREISONE << ", " << TESTARTIKELBESTANDONE << endl;
				lager->deleteArtikel(TESTARTIKELNUMMERONE); //test 6 Loesche Artikel 1
				break;
			case 9:
				cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << endl << AUTOTESTZUBUCHEN << TESTARTIKELBESTANDAENDERUNGONE << endl;
				lager->bucheZugang(TESTARTIKELNUMMERTWO, TESTARTIKELBESTANDAENDERUNGONE); // test 6.1 Bestang Zugang
				break;
			case 10:
				cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << endl << AUTOTESTABBUCHEN << TESTARTIKELBESTANDAENDERUNGONE << endl;
				lager->bucheAbgang(TESTARTIKELNUMMERTWO, TESTARTIKELBESTANDAENDERUNGONE);  // test 6.2 Bestang Abgang
				break;
			case 11:
				cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << endl << AUTOTESTABBUCHEN << TESTARTIKELBESTANDAENDERUNGTWO << endl;
				lager->bucheAbgang(TESTARTIKELNUMMERTWO, TESTARTIKELBESTANDAENDERUNGTWO);  // test 6.3 Bestang Abgang Negative
				break;
			case 12:
				cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << endl << AUTOTESTPREISAENDERN << TESTARTIKELPREISAENDERUNGONE << "%" << endl;
				lager->preiseAendern(TESTARTIKELPREISAENDERUNGONE); //test 7.1 Preiserhoehen
				break;
			case 13:
				cout << ARTIKELNUMMER << TESTARTIKELNUMMERTWO << endl << AUTOTESTPREISAENDERN << TESTARTIKELPREISAENDERUNGTWO << "%" << endl;
				lager->preiseAendern(TESTARTIKELPREISAENDERUNGTWO); //test 7.2 Preisverringern
				break;
			case 14:
				delete lager;
				break;
			}
		}
		catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
		catch (LagerException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}
		catch (ArtikelException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}
		testNummer++;
	}
	cout << "ENDE";
}
