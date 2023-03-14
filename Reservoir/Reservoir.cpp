#include <iostream>
#include "reservoir.h"
#include "Savefile.h"

using namespace std;

int main()
{
	setlocale(0, "");
	int size = 3;
	reservoir* p = new reservoir[size];

	for (int i = 0; i < size; i++)
	{
		p[i].print();
		cout << endl;
	}

	p->Add(p, &size);

	for (int i = 0; i < size; i++)
	{
		p[i].print();
		cout << endl;
	}

	p->Add(p, &size);

	for (int i = 0; i < size; i++)
	{
		p[i].print();
		cout << endl;
	}
	int n = 0;
	cout << "какой удалить "; cin >> n;
	p->del(p,&size,n);
	for (int i = 0; i < size; i++)
	{
		p[i].print();
		cout << endl;
	}
	Savefile f{ (char*)"reservoir.txt" };
	Savefile fb{ (char*)"reservoir.bin" };
	f.Savetxtfile(p, &size);
	fb.Savebinfile(p, &size);
}
