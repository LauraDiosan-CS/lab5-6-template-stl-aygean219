#include "ui.h"
#include <iostream>
using namespace std;
void UI::addCartea() {
	cout << "Dati cartea:  ";
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
	Carte carte;
	cout << "Dati cartea pe care doriti sa o stergeti: ";
	cin >> carte;
	int rez = serv.deleteC(carte);
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
	Carte carte;
	cout << "Dati cartea pe care doriti sa o schimbati: ";
	cin >> carte;
	cout << "Noul titlu: ";
	cin >> titlu;
	cout << "Nouyl autor: ";
	cin >> autor;
	cout << "Noul status: ";
	cin >> status;
	serv.updateC(carte, titlu, autor, status);
	cout << "Update realizat cu succes!!";
	delete[] titlu;
	delete[] autor;
}
void UI::prop1()
{
	char* titlu = new char[10];
	cout << "Dati titlul dorit: ";
	cin >> titlu;
	deque<Carte> carti = serv.getAll();
	serv.prop1(carti, titlu);
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
		case 0: {gata = true; cout << "La revedere :) !" << endl; }
		}
	}
}