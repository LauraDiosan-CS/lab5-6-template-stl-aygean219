#pragma once
#include "biblioteca.h"
#include <deque>
using namespace std;
template <class T>
class Repo {
protected:
	deque <T> carti;
public:
	Repo();
	~Repo();
	void addCarte(T);
	int updCarte(T, T);
	int deleteCarte(T);
	int findCarte(T);
	int get_size();
	T getCarte(int);
	deque<T> get_all();
};
template<class T>
Repo<T>::Repo()
{
}

template<class T>
void Repo<T>::addCarte(T carte)
{
	this->carti.push_back(carte);
}
//titlu,autor,status
template<class T>
int Repo<T>::updCarte(T carte, T newCarte)
{
	typename deque<T>::iterator it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end()) {
		*it = newCarte;
		return 0;
	}
	return -1;
}
template<class T>
int Repo<T>::deleteCarte(T carte)
{
	typename deque<T>::iterator it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end()) {
		carti.erase(it);
		return 0;
	}
	return - 1;
}
template<class T>
int Repo<T>::findCarte(T carte)
{
	typename deque<T>::iterator it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end())
		return distance(carti.begin(), it);
	return -1;

}

template<class T>
int Repo<T>::get_size()
{
	return this->carti.size();

}
template<class T>
T Repo<T>::getCarte(int pos)
{
	return this->carti[pos];

}
template<class T>
deque<T> Repo<T>::get_all()
{
	return this->carti;
}

template<class T>
Repo<T>::~Repo()
{
}
