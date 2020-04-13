#include "ui.h"
#include <iostream>
using namespace std;
void UI::addCartea() {
	cout << "Dati cartea:  " << endl;
	char* titlu = new char[10];
	char* autor = new char[10];
	cout << "Dati titlu: ";
	cin >> titlu;
	cout << "Dati autor: ";
	cin >> autor;
	cout << "Dati statusul ,daca este imprumutat--->True,daca este neimprumutat--->False: ";
	bool status;
	cin >> status;
	serv.addC(titlu, autor, status);
	cout << "Cartea a fost adaugata cu succes!!" << endl;
	delete[] titlu;
	delete[] autor;
}

void UI::delCartea() {
	char* titlu = new char[10];
	cout << "Dati titlul cartii pe care doriti sa o stergeti: ";
	cin >> titlu;
	
	int rez = serv.deleteC(titlu);
	if (rez == 0) cout << "Cartea a fost stearsa cu succes!!" << endl;
	else cout << "Cartea nu a fost stearsa!!" << endl;
}
void UI::showAll()
{
	cout << endl;
	cout << "Elementele cozii sunt: ";
	cout << endl;
	for (int i = 0; i < serv.get_sizeC(); i++)
	{
		cout << serv.getAll()[i] ;
	}

}
void UI::updCarte()
{
	char* titlu = new char[10];
	char* autor = new char[10];
	bool status;
	char* titluVechi=new char[10];
	cout << "Dati titlu cartea pe care doriti sa o schimbati: ";
	cin >> titluVechi;
	cout << "Noul titlu: ";
	cin >> titlu;
	cout << "Nouyl autor: ";
	cin >> autor;
	cout << "Noul status: ";
	cin >> status;
	serv.updateT(titluVechi, titlu, autor, status);
	cout << "Update realizat cu succes!!";
	delete[] titlu;
	delete[] autor;
}
void UI::prop1()
{
	char* titlu = new char[10];
	char* autor= new char[10];
	//deque<Carte> carti = serv.getAll();
	deque<Carte> rez;
	//int ok = serv.prop1(carti, titlu);
	bool gata = true;
	while (gata) {
		deque<Carte> carti = serv.getAll();
		cout << "Dati titlul dorit: ";
		cin >> titlu;
		int ok = serv.prop1(carti, titlu);
		if (ok == 1)
		{
			cout << "Cartea nu este disponibila" << endl;
			cout << "Autorul acestei carti ,mai are urmatoarele exemplare in sistem:  " << endl;
			for (int i = 0; i < serv.get_sizeC(); i++)
			{
				if (strcmp(serv.getAll()[i].getTitlu(), titlu) == 0)
				{
					autor = new char[strlen(serv.getAll()[i].getAutor()) + 1];
					strcpy_s(autor, 1 + strlen(serv.getAll()[i].getAutor()), serv.getAll()[i].getAutor());
				}
			}
			for (int i = 0; i < serv.get_sizeC(); i++)
			{
				if (strcmp(serv.getAll()[i].getAutor(), autor) == 0)
					cout << serv.getAll()[i];
			}
	
		}
		if (ok == 2)
		{
			cout << "Cartea este disponibila,s-a realizat procesul de imprumutare!" << endl;
		}
		if (ok == 0)
		{
			cout << "Titlul nu a fost gasit,ne pare rau.." << endl;
		}
		cout << "Daca doriti sa incercati din nou apasati 1,daca nu apasati 0: ";
		cin >> gata;
	}
}
void UI::prop2()
{
	char* titlu = new char[10];
	char* autor = new char[10];
	deque<Carte> rez;
	bool gata = true;
	while (gata) {
		deque<Carte> carti = serv.getAll();
		cout << "Dati titlul dorit: ";
		cin >> titlu;
		int ok = serv.prop2(carti, titlu);
		if (ok == 1)
		{
			cout << "Cartea nu este imprumutata" << endl;
		}
		if (ok == 2)
		{
			cout << "Cartea s-a gasit si s-a realizat procesul de returnare cu SUCCES!" << endl;
		}
		if (ok == 0)
		{
			cout << "Titlul nu a fost gasit,ne pare rau.." << endl;
		}
		cout << "Daca doriti sa incercati din nou apasati 1,daca nu apasati 0: ";
		cin >> gata;
	}
}
UI::UI()
{
}
UI::UI(Service& serv)
{
	this->serv = serv;
}
void UI::showUI()
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << " 1.Adauga carte: " << endl;
		cout << " 2.Sterge carte: " << endl;
		cout << " 3.Update carte: " << endl;
		cout << " 4.Afisare carte:  " << endl;
		cout << " 5.Imprumutare carte: " << endl;
		cout << " 6.Returnare carte: " << endl;
		cout << " 0.Exit" << endl;
		cout << " Introduceti optiunea(numar): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addCartea(); break; }
		case 2: {delCartea(); break; }
		case 3: {updCarte(); break; }
		case 4: {showAll(); break; }
		case 5: {prop1(); break; }
		case 6: {prop2(); break; }
		case 0: {gata = true; cout << "La revedere :) !" << endl; }
		}
	}
}