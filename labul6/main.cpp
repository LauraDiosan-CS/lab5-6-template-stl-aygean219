#include<iostream>
#include"teste.h"
#include"biblioteca.h"
#include "repo.h"
#include "teste_repo.h"
#include "teste_service.h"
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
	cout << "Start.."<<endl;
	Service serv;
	UI ui;
	ui.showUI();
	cout << "Succes..";
	
	return 0;

}