#pragma once
#include "service.h"
class UI {
private:
	Service serv;
	void addCartea();
	void delCartea();
	void showAll();
	void updCarte();
	void prop1();
	void prop2();
public:
	UI();
	UI(Service&);
	void showUI();
};