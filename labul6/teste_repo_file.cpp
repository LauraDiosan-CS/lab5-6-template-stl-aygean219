#include "teste_repo_file.h"
#include <assert.h>
#include <iostream>
using namespace std;
void TestRepoFile::testLoadFromFile()
{
	RepoFile<Carte> repo;
	assert(repo.get_size() == 0);
	repo.loadFromFile("carti_teste.txt");
	//add carte
	repo.addCarte(Carte("mm", "nn", 1));
	//delete carte
	assert(repo.deleteCarte(Carte("aa", "bb", 1)) == 0);
	//size
	assert(repo.get_size() == 1);
	//get_all
	assert(repo.get_all()[0].getStatus() == true);// mm nn 1
	//update carte
	repo.addCarte(Carte("aa", "bb", 1));
	repo.updCarte(Carte("aa", "bb", 1), Carte("oo", "ss", 0));
	assert(repo.get_all()[1].getStatus() == false);
	//find carte
	assert(repo.findCarte(Carte("oo", "ss", 0)) == 1);

}
void TestRepoFile::testAll3()
{
	testLoadFromFile();
}