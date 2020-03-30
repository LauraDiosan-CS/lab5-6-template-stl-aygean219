#pragma once
#include <ostream>
#include <string>
using namespace std;
class Carte {
private:
	char* titlu;
	char* autor;
	bool status;
public:
	Carte();
	Carte(const char* titlu, const char* autor, bool status);
	Carte(const Carte& c);
	~Carte();
	char* getTitlu();
	char* getAutor();
	bool getStatus();
	void setTitlu(const char* titlu);
	void setAutor(const char* autor);
	void setStatus(bool status);
	Carte& operator=(const Carte& c);
	bool operator==(const Carte& c);
	friend ostream& operator<<(ostream& os, const Carte& c);
	friend istream& operator>>(istream&, Carte&);

};
