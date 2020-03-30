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
	void insert(T);
	int get_len();
	deque<T> get_all();
};
template<typename T>
Repo<T>::Repo()
{
}

template<typename T>
void Repo<T>::insert(T carte)
{
	this->carti.push_back(carte);
}
template<typename T>
int Repo<T>::get_len()
{
	return this->carti.size();

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