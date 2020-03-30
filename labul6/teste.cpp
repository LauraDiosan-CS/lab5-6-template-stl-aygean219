#include "teste.h"
#include "biblioteca.h"
#include <iostream>
#include <assert.h>
#include <string.h>
#include "repo.h"
void teste() {
	Carte* c1;
	c1 = new Carte();//implicit const
	assert((c1->getTitlu() == NULL) && (c1->getAutor() == NULL) && (c1->getStatus() == false));
	char* autor1 = new char[10];
	char* titlu1 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	Carte* c2 = new Carte(titlu1, autor1, true);
	assert((strcmp(c2->getTitlu(), "bbb") == 0) && (strcmp(c2->getAutor(), "aaa") == 0) && (c2->getStatus ()==true ));
	c2->setStatus(false);
	assert((strcmp(c2->getTitlu(), "bbb") == 0) && (strcmp(c2->getAutor(), "aaa") == 0) && (c2->getStatus() == false));
	if (c2 != NULL) {
		delete c2;//destructor
		c2 = NULL;
	}
	
}

void testerepo() {
	Repo<Carte> rep;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	strcpy_s(autor1, sizeof "aaa", "aaa");
	strcpy_s(titlu1, sizeof "bbb", "bbb");
	Carte c1(titlu1, autor1, true);
	rep.insert(c1);
	assert(rep.get_len() == 1);
}
