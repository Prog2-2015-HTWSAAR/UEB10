/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb10 *.o
* @file ueb10.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 26.05.2015
*
* Main Funktion
*

*/
#include <iostream>
#include "BasisDialog.h"
using namespace std;
	/**
	* @brief Main Function
	*/
	int main(){
		artikel::BasisDialog basisDialog;
		basisDialog.startDialog();
		return 0;
	}
