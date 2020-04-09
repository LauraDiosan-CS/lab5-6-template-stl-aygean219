#pragma once
#include "biblioteca.h"
#include <deque>
using namespace std;
template <typename T>
class Repo {
private: 
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
template<typename T>
Repo<T>::Repo()
{
}

template<typename T>
void Repo<T>::addCarte(T carte)
{
	this->carti.push_back(carte);
}
//titlu,autor,status
template<typename T>
int Repo<T>::updCarte(T carte, T newCarte)
{
	typename deque<T>::iterator it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end()) {
		*it = newCarte;
		return 0;
	}
	return -1;
}
template<typename T>
int Repo<T>::deleteCarte(T carte)
{
	typename deque<T>::iterator it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end()) {
		carti.erase(it);
		return 0;
	}
	return - 1;
}
template<typename T>
int Repo<T>::findCarte(T carte)
{
	deque<Carte>::iterator it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end())
		return distance(carti.begin(), it);
	return -1;

}

template<typename T>
int Repo<T>::get_size()
{
	return this->carti.size();

}
template<typename T>
T Repo<T>::getCarte(int pos)
{
	return this->carti[pos];

}
template<typename T>
deque<T> Repo<T>::get_all()
{
	return this->carti;
}

template<typename T>
Repo<T>::~Repo()
{
}
