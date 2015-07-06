/*
 * Date.cpp
 *
 *  Created on: 04.07.2015
 *      Author: Simon
 */
#include <ctime>
#include "Datum.h"
namespace artikel {
	const char* meldingBBD = "Das Mindesthaltbarkeitsdatum ist bereits abgelaufen!";

Datum::Datum(int tag, int monat, int jahr) {
	this->tag = tag;
	this->monat = monat;
	this->jahr = jahr;
}

Datum::~Datum() {
	// Nothing to do here!
}

bool Datum::operator >(Datum& datum){
	bool ergebnis = (jahr > datum.getJahr() && monat > datum.getMonat() && tag > datum.getTag());
	return ergebnis;
}

std::string Datum::toString() const {
	std::ostringstream o;
	if(tag < 10){
		o << "0";
	}
	o << tag << ".";
	if(monat < 10){
		o << "0";
	}
	o << monat << "." << jahr;
	return o.str();
}
int dateCMP(Datum& datumA, Datum& datumB){
	int cmp = 0;
	if (datumA.tag > datumB.tag){
		cmp++;
	}
	if (datumA.tag < datumB.tag){
		cmp--;
	}
	if (datumA.monat > datumB.monat){
		cmp = cmp + 10;
	}
	if (datumA.monat < datumB.monat){
		cmp = cmp - 10;
	}
	if (datumA.jahr > datumB.jahr){
		cmp = cmp + 100;
	}
	if (datumA.jahr < datumB.jahr){
		cmp = cmp - 100;
	}
	return cmp;
}
std::ostream& operator<< (std::ostream& o, Datum& datum){
	o << datum.toString();
	return o;
}

std::istream& operator>> (std::istream& i, Datum& datum){
	i >> datum.tag;
	i.ignore(1, '.');
	i >> datum.monat;
	i.ignore(1, '.');
	i >> datum.jahr;
	return i;
}
} /* namespace artikel */
