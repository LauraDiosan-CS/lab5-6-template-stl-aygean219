#include "teste_service.h"
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;
void TestService::testAddCarte()
{
	RepoFile<Carte> repo;
	Service serv;
	serv.setRepo(repo);
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	strcpy_s(autor2, sizeof "ccc", "ccc");
	strcpy_s(titlu2, sizeof "ddd", "ddd");
	serv.addC(titlu1, autor1, true);
	serv.addC(titlu2, autor2, false);
	assert(serv.get_sizeC() == 2);
}
void TestService::testUpdCarte() {
	RepoFile<Carte> repo;
	Service serv;
	serv.setRepo(repo);
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	strcpy_s(autor2, sizeof "ccc", "ccc");
	strcpy_s(titlu2, sizeof "ddd", "ddd");
	Carte c1(titlu1, autor1, true);
	serv.addC(titlu1, autor1, true);
	serv.updateC(c1, titlu2, autor2, false);
	assert(serv.getC(0).getStatus() == false);
	assert(strcmp(serv.getC(0).getTitlu(), "ddd") == 0);
	assert(strcmp(serv.getC(0).getAutor(), "ccc") == 0);
}
void TestService::testDelCarte() {
	RepoFile<Carte> repo;
	Service serv;
	serv.setRepo(repo);
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	strcpy_s(autor2, sizeof "ccc", "ccc");
	strcpy_s(titlu2, sizeof "ddd", "ddd");
	serv.addC(titlu1, autor1, true);
	serv.addC(titlu2, autor2, false);
	Carte c1(titlu1, autor1, true);
	assert(serv.get_sizeC() == 2);
	serv.deleteC(titlu1);
	assert(serv.get_sizeC() == 1);
}
void TestService::testImprumutCarte() {
	RepoFile<Carte> repo;
	Service serv;
	serv.setRepo(repo);
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "cc", "cc");
	strcpy_s(titlu1, sizeof "aa", "aa");
	strcpy_s(autor2, sizeof "cc", "cc");
	strcpy_s(titlu2, sizeof "bb", "bb");
	serv.addC(titlu1, autor1, true);
	serv.addC(titlu2, autor2, false);
	deque<Carte> carti = serv.getAll();
	int ok=serv.prop1(carti, titlu1);
	assert(ok == 1);
	assert(serv.getAll()[0].getStatus() == true);
	int o = serv.prop1(carti, titlu2);
	assert(o == 2);
	assert(serv.getAll()[1].getStatus() == true);
}
void TestService::testReturCarte() {
	RepoFile<Carte> repo;
	Service serv;
	serv.setRepo(repo);
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "cc", "cc");
	strcpy_s(titlu1, sizeof "aa", "aa");
	strcpy_s(autor2, sizeof "cc", "cc");
	strcpy_s(titlu2, sizeof "bb", "bb");
	serv.addC(titlu1, autor1, true);
	serv.addC(titlu2, autor2, false);
	deque<Carte> carti = serv.getAll();
	int ok = serv.prop2(carti, titlu1);
	assert(ok == 2);
	assert(serv.getAll()[0].getStatus() == false);
	int o = serv.prop2(carti, titlu2);
	assert(o == 1);
	assert(serv.getAll()[1].getStatus() == false);
}
void TestService::testAll2()
{
	testReturCarte();
	testImprumutCarte();
	testAddCarte();
	testUpdCarte();
	testDelCarte();
}