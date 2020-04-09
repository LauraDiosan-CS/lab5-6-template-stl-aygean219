#include "service.h"
#include <iostream>
using namespace std;

Service::Service()
{

}
Service::Service(Repo<Carte>& r)
{
	repo = r;
}
void Service::setRepo(Repo<Carte>& r)
{
	repo = r;
}
void Service::addC(char* titlu, char* autor, bool status)
{
	Carte c(titlu, autor, status);
	repo.addCarte(c);
}
int Service::deleteC(Carte c)
{
	return repo.deleteCarte(c);
}
void Service::updateC(Carte c, char* titlu, char* autor, bool status)
{	
	repo.updCarte(c,Carte( titlu, autor, status));

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
void Service::prop1(deque<Carte> carti,char* titlu)
{
	for (Carte current : carti) {
		
		if ((strcmp(current.getTitlu(), titlu) == 0) && (current.getStatus() == false))
		{
			
			repo.updCarte(current, Carte(titlu, current.getAutor(), 1));
			
		}
	}

}