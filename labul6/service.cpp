#include "service.h"
#include <iostream>
using namespace std;

Service::Service()
{

}
Service::Service(RepoFile<Carte>& r)
{
	repo = r;
}
void Service::setRepo(RepoFile<Carte>& r)
{
	repo = r;
}
void Service::addC(char* titlu, char* autor, bool status)
{
	Carte c(titlu, autor, status);
	repo.addCarteF(c);
}
int Service::deleteC(char* titlu)
{
	deque<Carte> carti = repo.get_all();
	for (Carte current : carti) {
		if (strcmp(current.getTitlu(), titlu) == 0)
		{
			Carte c(titlu, current.getAutor(), current.getStatus());
			return repo.deleteCarteF(c);
		}
	}
}
void Service::updateC(Carte c, char* titlu, char* autor, bool status)
{	
	repo.updCarteF(c,Carte( titlu, autor, status));

}
void Service::updateT(char* titlu, char* newTitlu, char* newAutor, bool newStatus)
{
	deque<Carte> carti = repo.get_all();
	for (Carte current : carti) {
		if (strcmp(current.getTitlu(), titlu) == 0)
		{
			Carte c(titlu, current.getAutor(), current.getStatus());
			repo.updCarteF(c, Carte(newTitlu, newAutor, newStatus));
		}
	}
}
Carte Service::getC(int pos)
{
	return repo.getCarte(pos);
}
int Service::getCarteAtPos(Carte c)
{
	return this->repo.findCarte(c);
}
deque <Carte> Service::getAll()
{
	deque<Carte> rez = repo.get_all();
	deque<Carte> v(rez.begin(),rez.end());
	return v;
}
int Service::get_sizeC() {
	return this->repo.get_size();
}
/*void Service::prop1(deque<Carte> carti, char* titlu)
{
	deque<Carte>::iterator it = find(carti.begin(), carti.end(), carti);
	if (it != carti.end())
	{
		if ((strcmp((*it).getTitlu(), titlu) == 0) && ((*it).getStatus() == 0))
			it->setStatus(true);
		//if ((strcmp(carti[i].getTitlu(), titlu) == 0) && carti[i].getStatus() == 0)
		//	carti[i].setStatus(true);

	}
}*/
int Service::titlul(Carte carte, char* titlu)
{
	if (strcmp(carte.getTitlu(), titlu) == 0)
		return 1;
	return 0;
}
int Service::prop1(deque<Carte> carti,char* titlu)
{
	int ok;
	for (Carte current : carti) {
		ok = titlul(current, titlu);
		if ((current.getStatus() == false) && (ok == 1))
		{	repo.updCarteF(current, Carte(titlu, current.getAutor(), 1));
			ok = 2;//daca titlul este gasit si este disponibil
		}
		if (ok!=0)
		{
			return ok;//l a gasit ,s-a realizat opresc programu si returnez=2 sau ==1 a gasit dar nu e disponibil
		}
		
		}
	return 0;//daca nu este gasit titlul ok==0
}
int Service::prop2(deque<Carte> carti, char* titlu)
{
	int ok;
	for (Carte current : carti) {
		ok = titlul(current, titlu);
		if ((current.getStatus() == true) && (ok == 1))
		{
			repo.updCarteF(current, Carte(titlu, current.getAutor(), 0));
			ok = 2;//daca titlul este gasit si este imprumutat
		}
		if (ok != 0)
		{
			return ok;//l a gasit ,s-a realizat opresc programu si returnez=2 sau ==1 a gasit dar nu e imprumutat
		}

	}
	return 0;//daca nu este gasit titlul ok==0
}
deque <Carte> Service::filterByAutor(deque<Carte> carti,char* autor)
{
	deque<Carte> rez;
	for (Carte current : carti) {
		if ((strcmp(current.getAutor(), autor) == 0)&&(current.getStatus()==0) ){
			rez.push_back(current);
		}
	}
	return rez;
}