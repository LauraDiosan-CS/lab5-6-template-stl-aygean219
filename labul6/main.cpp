#include<iostream>
#include"teste.h"
#include"biblioteca.h"
#include "repo.h"
#include "repo_file.h"
#include "teste_repo.h"
#include "teste_service.h"
#include "teste_repo_file.h"
#include "ui.h"
using namespace std;
int main()
{
	teste();
	testerepo();
	TestRepo testrepo;
	testrepo.testAll();
	TestService testservice;
	testservice.testAll2();
	TestRepoFile testrepofile;
	testrepofile.testAll3();
	cout << "Start.."<<endl;
	RepoFile<Carte> repo("Carti.txt");
	Service serv(repo);
	UI ui(serv);
	ui.showUI();
	cout << "Succes..";
	
	return 0;

}