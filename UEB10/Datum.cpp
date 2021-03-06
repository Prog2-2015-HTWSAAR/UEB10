/*
 * Date.cpp
 *
 *  Created on: 04.07.2015
 *      Author: Simon
 */
#include <ctime>
#include "Datum.h"
namespace artikel {
const char* Datum::meldungTag = "Ungueltiger Tag!";
const char* Datum::meldungMonat = "Ungueltiger Monat!";
const char* Datum::meldungJahr = "Ungueltiges Jahr! (<1900)";

Datum::Datum(int tag, int monat, int jahr) throw (DatumException){
	checkDate(tag, monat, jahr);
	this->tag = tag;
	this->monat = monat;
	this->jahr = jahr;

}

Datum::~Datum() {
	// Nothing to do here!
}

void Datum::setJahr(int jahr){
	checkYear(jahr);
	this->jahr = jahr;
}
void Datum::setMonat(int monat){
	checkMonth(monat);
	this->monat = monat;
}
void Datum::setTag(int tag){
	checkDay(tag, monat, jahr);
	this->tag = tag;
}
Datum* Datum::calcCurrentDate(){
	int tag = 0;
	int monat = 0;
	int jahr = 0;
	std::time_t time = std::time(NULL);
	struct tm * now = localtime(&time);
	tag = now->tm_mday;
	monat = (now->tm_mon) + 1;
	jahr = (now->tm_year) + 1900;
	return (new Datum(tag, monat, jahr));
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

std::istream& operator>> (std::istream& i, Datum& datum)throw (DatumException){
	int tag = 0;
	int monat = 0;
	int jahr = 0;
	i >> tag;
	i.ignore(1, '.');
	i >> monat;
	i.ignore(1, '.');
	i >> jahr;
	if(jahr < 100){ //assume 20xx
		jahr += 2000;
	}
	datum.checkDate(tag, monat, jahr);
	datum.setTag(tag);
	datum.setMonat(monat);
	datum.setJahr(jahr);
	return i;
}


bool Datum::checkYear(int jahr){
	return (jahr >= 1900);
}

bool Datum::checkMonth(int monat){
	return (monat > 0 && monat < 13);
}
bool Datum::checkDay(int tag, int monat, int jahr){
	if(tag < 1 || tag >31){
		return false;
	}
	if(monat < 8){
		if(tag > 30){
			return (monat % 2 == 0);
		}
		if(leapYear(jahr)){
			if(monat == 2){
				if(tag > 29){
					return false;
				}
			}
		}else{
			if(monat == 2){
				if(tag > 28){
					return false;
				}
			}
		}
	} else {
		if(tag > 30){
			return (monat % 2 == 1);
		}
	}
	return true;
}

bool Datum::leapYear(int jahr){
	if(jahr % 400 == 0){
		return true;
	}
	if(jahr % 100 == 0){
		return false;
	}
	if(jahr % 4 == 0){
		return true;
	}
	return false;
}
void Datum::checkDate(int tag, int monat, int jahr) throw (DatumException){
	if(!checkYear(jahr)){
		throw DatumException(meldungJahr);
	}
	if(!checkMonth(monat)){
		throw DatumException(meldungMonat);
	}
	if(!checkDay(tag, monat, jahr)){
		throw DatumException(meldungTag);
	}
}
} /* namespace artikel */
