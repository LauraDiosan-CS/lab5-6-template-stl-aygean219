#pragma once
#include "biblioteca.h"
#include "repo.h"
#include <deque>
#include <string.h>
#include <fstream>
using namespace std;
template <class T>
class RepoFile: public Repo<T> {
private:
	const char* fis;
	//const char* fes;
public:
	RepoFile();
	RepoFile(const char*);
	void addCarteF(T);
	int updCarteF(T, T);
	int deleteCarteF(T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepoFile();
	
};
template<class T>
RepoFile<T>::RepoFile()
{
	fis = NULL;
	//fes = NULL;
}
template<class T>
RepoFile<T>::~RepoFile()
{
}
template<class T>
RepoFile<T>::RepoFile(const char *fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* titlu = new char[10];
	char* autor = new char[10];
	//bool status;
	this->loadFromFile(fis);
	/*while (!f.eof()) {
		f >> titlu >> autor >> status;
		if ((titlu != "") && (autor != "")) {
			carte c(titlu, autor, status);
			carti.push_back(c);
		}
	}
		delete[] titlu;
		delete[] autor;
		f.close();*/
}
/*template <class T>
void RepoFile<T>::setFileNameIn(char* fis)
{
	if (this->fis != NULL)
	{
		delete[]this->fis;
	}
	this->fis= new char[strlen(fis) + 1];
	strcpy_s(this->fis, strlen(fis) + 1, fis);
}

template <class T>
void RepoFile<T>::setFileNameOut( char* fes)
{
	if (this->fes != NULL)
	{
		delete[]this->fes;
	}
	this->fes= new char[strlen(fes) + 1];
	strcpy_s(this->fes, strlen(fes) + 1, fes);
}
template<class T>
void RepoFile<T>::loadFromFile()
{
	Repo<T>::carti.clear();
	ifstream f(this->fis);
	string linie;
	char* titlu = new char[10];
	char* autor = new char[10];
	bool status;
	if (fis != NULL) {
		Repo<T>::carti.clear();
		while (!f.eof()) {
			f >> titlu >> autor >> status;
			//f >> element;
			if (strlen(titlu) != 0) {
				//this->addCarte(Carte (titlu, autor, status));
				Carte c(titlu, autor, status);
				Repo<T>::carti.push_back(c);
			}
		}

		delete[] titlu;
		delete[] autor;
		f.close();

	}
}
*/
template<class T>
void RepoFile<T>::loadFromFile(const char* fileName)
{
	Repo<T>::carti.clear();
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* titlu = new char[10];
	char* autor = new char[10];
	bool status; 
		if (fis != NULL) {
			//T element;
			while (!f.eof()) {
				f >> titlu >> autor >> status;
				//f >> element;
				if (strlen(titlu) != 0) {
					//this->addCarte(Carte (titlu, autor, status));
					Carte c(titlu, autor, status);
				Repo<T>::carti.push_back(c);
			}
			}

			delete[] titlu;
			delete[] autor;
			f.close();

		}
}////////////////
/*
	if (this->fis != NULL)
	{
		this->Repo<T>::carti.clear();
		ifstream f(this->fis);
		T element;
		while (f >> element)
		{
			
			Repo<T>::carti.push_back(element);
		}
		f.close();
/	}
//}
*/
template <class T>
void RepoFile<T>::saveToFile()
{
	if (this->fis != NULL)
	{
		ofstream f(this->fis);
		for (size_t i = 0; i < Repo<T>::carti.size(); i++)
		{
			f << Repo<T>::carti [i]<< endl;
		}
		f.close();
	}
}
template<class T>
void RepoFile<T>::addCarteF(T carte)
{
	Repo<T>::addCarte(carte);
	this->saveToFile();
}
template<class T>
int RepoFile<T>::updCarteF(T carte, T newCarte)
{
	int rez=Repo<T>::updCarte(carte, newCarte);
	this->saveToFile();
	return rez;
}
template<class T>
int RepoFile<T>::deleteCarteF(T carte)
{
	int rez= Repo<T>::deleteCarte(carte);
	this->saveToFile();
	return rez;
}