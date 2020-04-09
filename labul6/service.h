#pragma once
#include "repo.h"
#include "biblioteca.h"
#include <deque>
using namespace std;
class Service
{
private:
	Repo<Carte> repo;
public:
	Service();
	Service(Repo<Carte>&);
	void addC(char*, char*, bool);
	int deleteC(Carte );
	Carte getC(int);
	void updateC(Carte, char*, char*, bool);
	void setRepo(Repo<Carte>&);
	int getCarteAtPos(Carte);
	int get_sizeC();
	void prop1(deque<Carte>, char*);
	deque <Carte> getAll();
	
};