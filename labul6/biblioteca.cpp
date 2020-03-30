#include "biblioteca.h"
#include <cstddef>
#include <string.h>
#include <sstream>
#include <ostream>
#include <iostream>
using namespace std;
Carte::Carte() {
	this->titlu = NULL;
	this->autor = NULL;
	this->status = false;
}
Carte::Carte(const char* titlu, const char* autor, bool status)
{
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(titlu), titlu);
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, 1 + strlen(autor), autor);
	this->status = status;
}
Carte::Carte(const Carte& c)
{
	//cout << "Copy constructor" << endl;
	
	if (c.autor != NULL)
	{
		this->autor= new char[strlen(c.autor) + 1];
		strcpy_s(this->autor, 1 + strlen(c.autor), c.autor);
	}
	else
	{
		this->autor= NULL;
	}
	if (c.titlu != NULL)
	{
		this->titlu = new char[strlen(c.titlu) + 1];
		strcpy_s(this->titlu, 1 + strlen(c.titlu), c.titlu);
	}
	else
	{
		this->titlu = NULL;
	}
	this->status = c.status;

}
Carte::~Carte() {
	if (this->titlu) {
		delete[] this->titlu;
		this->titlu = NULL;
	}
	if (this->autor) {
		delete[] this->autor;
		this->autor = NULL;
	}
}
char* Carte::getAutor() {
	return this->autor;
}
char* Carte::getTitlu() {
	return this->titlu;
}
bool Carte::getStatus() {
	return this->status;
}
void Carte::setAutor(const char* a) {
	if (autor) delete[]autor;
	if (a != NULL)
	{
		autor = new char[strlen(a) + 1];
		strcpy_s(autor, strlen(a) + 1, a);
	}
	else
	{
		autor = NULL;
	}
}
void Carte::setTitlu(const char* t) {
	if (titlu) delete[]titlu;
	if (t != NULL)
	{
		titlu = new char[strlen(t) + 1];
		strcpy_s(titlu, strlen(t) + 1, t);
	}
	else
	{
		titlu= NULL;
	}
}
void Carte::setStatus(bool status) {
	this->status = status;
}
Carte& Carte::operator=(const Carte& c) {
	this->setAutor(c.autor);
	this->setStatus(c.status);
	this->setTitlu(c.titlu);
	return *this;
}
bool Carte::operator==(const Carte& c) {
	return(this->status == c.status) && (strcmp(this->titlu, c.titlu) == 0) && (strcmp(this->autor, c.autor) == 0);
}
ostream& operator<<(ostream& os, const Carte& c) {
	os << "Cartea--->Titlu: " << c.titlu << ",Autor: " << c.autor << ",Status: " << c.status << " ;" << endl;
	return os;
}
istream& operator>>(istream& is, Carte& c) {
	cout << "Dati titlul: ";
	char* titlu= new char[10];
	is >> titlu;
	cout << "Dati autor: ";
	char* autor = new char[10];
	is >> autor;
	cout << "Dati status: ";
	bool status;
	is >> status;
	c.setTitlu(titlu);
	c.setAutor(autor);
	c.setStatus(status);
	delete[] titlu;
	delete[] autor;
	return is;

}