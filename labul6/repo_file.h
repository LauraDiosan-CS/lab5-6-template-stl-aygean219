#pragma once
#include "biblioteca.h"
#include "repo.h"
#include <deque>
using namespace std;
template <typename T>
class RepoFile: public Repo {
private:
	deque <T> carti;
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	~RepoFile();
	
};
template<typename T>
RepoFile<T>::RepoFile()
{
}
template<typename T>
RepoFile<T>::~RepoFile()
{
}
template<typename T>
RepoFile<T>::RepoFile(const char *fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* titlu = new char[10];
	char* autor = new char[10];
	bool status;
	while (!f.eof()) {
		f >> titlu >> autor >> status;
		if ((titlu != "") && (autor != "")) {
			Carte c(titlu, autor, status);
			carti.push_back(c);
		}
	}
		delete[] titlu;
		delete[] autor;
		f.close();
}
template<typename T>
void RepoFile<T>::loadFromFile(const char* fileName)
{
	carti.clear();
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* titlu = new char[10];
	char* autor = new char[10];
	bool status;
	while (!f.eof()) {
		f >> titlu >> autor >> status;
		if ((titlu != "") && (autor != "")) {
			Carte c(titlu, autor, status);
			carti.push_back(c);
		}
	}
	delete[] titlu;
	delete[] autor;
	f.close();


}