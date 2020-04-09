#include "teste_repo.h"
#include <assert.h>
#include <iostream>
using namespace std;
void TestRepo::testAddCarte()
{
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	strcpy_s(autor2, sizeof "ccc", "ccc");
	strcpy_s(titlu2, sizeof "ddd", "ddd");
	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);
	repo.addCarte(c1);
	repo.addCarte(c2);
	assert(repo.get_size() == 2);
}
void TestRepo::testGetSize()
{
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	Carte c1(titlu1, autor1, true);
	repo.addCarte(c1);
	assert(repo.get_size() == 1);
}

void TestRepo::testUpdateCarte() {
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	strcpy_s(autor2, sizeof "ccc", "ccc");
	strcpy_s(titlu2, sizeof "ddd", "ddd");
	Carte c1(titlu1, autor1, true);
	repo.addCarte(c1);
	repo.updCarte(c1, Carte(titlu2, autor2, false));
	assert(strcmp(repo.get_all()[0].getAutor(), "ccc") == 0);
	assert(strcmp(repo.get_all()[0].getTitlu(), "ddd") == 0);
	assert(repo.get_all()[0].getStatus() == false);
	assert(repo.getCarte(0).getStatus() == false);

}
void TestRepo::testDeleteCarte() {
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	strcpy_s(autor2, sizeof "ccc", "ccc");
	strcpy_s(titlu2, sizeof "ddd", "ddd");
	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);
	repo.addCarte(c1);
	repo.addCarte(c2);
	assert(repo.get_size() == 2);
	repo.deleteCarte(c2);
	assert(repo.get_size() == 1);
}
void TestRepo::testGetAll() {

	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	strcpy_s(autor2, sizeof "ccc", "ccc");
	strcpy_s(titlu2, sizeof "ddd", "ddd");
	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);
	repo.addCarte(c1);
	repo.addCarte(c2);
	assert( repo.findCarte(c2)==1);
	assert(repo.findCarte(c1) == 0);
}
void TestRepo::testAll() {
	this->testAddCarte();
	this->testUpdateCarte();
	this->testGetSize();
	this->testDeleteCarte();
	this->testGetAll();
}