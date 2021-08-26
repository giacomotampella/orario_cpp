#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

struct Orario {
	int ore;
	int minuti;
	int secondi;
};

Orario imposta_ora (Orario o) {	
	do {
		cout << "Ore: ";
		cin >> o.ore;
	} while (o.ore > 24 || o.ore < 0);
	if (o.ore == 24) {
		o.ore = 0;
	}
	do {
		cout << "Minuti: ";
		cin >> o.minuti;
	} while (o.minuti > 60 || o.minuti < 0);
	if (o.minuti == 60) {
		o.ore++;
		o.minuti = 0;
	}
	do {
		cout << "Secondi: ";
		cin >> o.secondi;
	} while (o.secondi > 60 || o.secondi < 0);
	if (o.secondi == 60) {
		o.minuti++;
		o.secondi = 0;
	}
	cout << endl << "Orario" << endl;
	cout << o.ore << ":" << o.minuti << ":" << o.secondi << endl << endl;
	return o;
}

Orario somma_orario (Orario o1, Orario o2) {
	int diffs;
	int diffm;
	int diffo;
	
	Orario o3;
	
	o3.secondi = o2.secondi + o1.secondi;
		
	o3.minuti = o2.minuti + o1.minuti;
		
	o3.ore = o2.ore + o1.ore;
	
	diffs = o3.secondi - 60;
	if (diffs >= 0) {
		o3.secondi = diffs;
		o3.minuti++;
	}

	diffm = o3.minuti - 60;
	if (diffm >= 0) {
		o3.minuti = diffm;
		o3.ore++;
	}

	diffo = o3.ore - 24;
	if (diffo >= 0) {
		o3.ore = diffo;
	}
	
	cout << endl << "SOMMA ORARIO" << endl;
	cout << o3.ore << ":" << o3.minuti << ":" << o3.secondi << endl << endl;
//	cout << endl << endl << diffo << " " << diffm << " " << diffs;
	return o3;
}

Orario sottrazione_orario (Orario o1, Orario o2) {
	int diffs;
	int diffm;
	int diffo;
	
	Orario o3;
	
	o3.secondi = o1.secondi - o2.secondi;
		
	o3.minuti = o1.minuti - o2.minuti;
		
	o3.ore = o1.ore - o2.ore;
	
	diffs = 60 + o3.secondi;
	if (o3.secondi <= 0) {
		o3.secondi = diffs;
		o3.minuti--;
	}

	diffm = 60 + o3.minuti;
	if (o3.minuti <= 0) {
		o3.minuti = diffm;
		o3.ore--;
	}

	diffo = 24 + o3.ore;
	if (o3.ore <= 0) {
		o3.ore = diffo;
	}
	
	cout << endl << "SOTTRAZIONE ORARIO (Orario 1 - Orario 2)" << endl;
	cout << o3.ore << ":" << o3.minuti << ":" << o3.secondi << endl << endl;
//	cout << endl << endl << diffo << " " << diffm << " " << diffs;
	return o3;
}

int main () {
	Orario o1;
	Orario o2;
	o1 = imposta_ora(o1);
	o2 = imposta_ora(o2);
	somma_orario(o1, o2);
	sottrazione_orario(o1, o2);
}
