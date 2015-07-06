/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb10 *.o
 * @file Artikeldialog.h
 * @author Andreas Schreiner & Simon Bastian
 *
 * @date 01.06.2015
 *
 * BasisDialog Implementation
 *
 */
#include "BasisDialog.h"
namespace artikel {
	const char* BasisDialog::SEPERATOR = "-B-----------------------------";
	const char* BasisDialog::DIALOGOPTIONONE = "(1) Artikeldialog";
	const char* BasisDialog::DIALOGOPTIONTWO = "(2) Lagerdialog";
	const char* BasisDialog::STANDARDEXITOPTION = "(0) -EXIT/BACK-";
	const char* BasisDialog::STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
	const char* BasisDialog::INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
	const char* BasisDialog::ERRORPHRASE = "Fehler: ";
	/**
	 * @brief Konstruktor
	 */
	BasisDialog::BasisDialog(){
		//Nothing to do here
	}
	/**
	 * @brief Dekonstruktor
	 */
	BasisDialog::~BasisDialog(){
		//Nothing to do here
	}
	/**
	 * @brief Initiiert den StartDialog
	 * @details Auswahl zwischen Artikel- und Lagerdialog
	 */
	void BasisDialog::startDialog(){
		int answer = -1;
		do {
			try {
				std::cout << std::endl << SEPERATOR << std::endl << DIALOGOPTIONONE << std::endl
					<< DIALOGOPTIONTWO << std::endl << STANDARDEXITOPTION << std::endl
					<< std::endl << STANDARDCHOICEPHRASE;
				answer = readIntegerInput();
				switch (answer) {
				case EXITB:
					break;
				case ARTIKELDIALOG:
					enterArtikelDialog();
					break;
				case LAGERDIALOG:
					enterLagerDialog();
					break;
				default:
					std::cout << INPUTERRORPHRASE << std::endl;
					break;
				}
			}
			catch (const char* e) {
				std::cout << ERRORPHRASE << e << std::endl;
			}

		} while (answer != EXITB);
	}

	int BasisDialog::readIntegerInput(){
		double number = readDoubleInput();
		if (!(fmod(number, 1) == 0)){
			number = -1;
		}
		return (int)number;
	}
	double BasisDialog::readDoubleInput(){
		double number;
		if (std::cin >> number){
		}
		else {
			number = -1;
		}
		clearInput();
		return number;
	}
	std::string BasisDialog::readStringInput(){
		std::string input;
		std::cin >> input;
		clearInput();
		return input;
	}
	/**
	* @brief Eingabeleerung
	* @details Im Falle einer falschen Eingabe leert dies den Eingabepuffer.
	*/
	void BasisDialog::clearInput(){
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	/**
	 * @brief Initiiert den ArtikelDialog
	 */
	void BasisDialog::enterArtikelDialog(){
		Artikeldialog artikelDialog;
		artikelDialog.chooseDialog();
	}
	/**
	 * @brief Initiiert den LagerDialog
	 */
	void BasisDialog::enterLagerDialog(){
		LagerDialog lagerDialog;
		lagerDialog.createLagerDialog();
	}
}
