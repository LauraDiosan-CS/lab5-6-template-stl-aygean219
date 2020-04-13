#pragma once
#include "repo_file.h"
#include "biblioteca.h"
#include <deque>
using namespace std;
class Service
{
private:
	RepoFile<Carte> repo;
public:
	Service();
	Service(RepoFile<Carte>&);
	void addC(char*, char*, bool);
	int deleteC(char* );
	Carte getC(int);
	void updateC(Carte, char*, char*, bool);
	void updateT(char* titlu, char* newTitlu, char* newAutor, bool newStatus);
	void setRepo(RepoFile<Carte>&);
	int getCarteAtPos(Carte);
	int get_sizeC();
	int titlul(Carte carte, char* titlu);
	int prop1(deque<Carte>, char*);
	int prop2(deque<Carte>, char*);
	deque <Carte> filterByAutor(deque<Carte>,char*);
	deque <Carte> getAll();
	
};