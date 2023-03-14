#pragma once
#include <iostream>
#include"reservoir.h"
using namespace std;
#define WRITE	"w"
#define WRITEBIN "wb"

class Savefile
{
	FILE* file;
	char* path;
	friend class reservoir;
public:
	Savefile(char* p) :path{ new char[100] } {
		strcpy_s(path, 100, p);
	}
	~Savefile() {
		delete[] path;
		fclose(file);
	}

	void Savetxtfile(reservoir*, int *s);
	void Savebinfile(reservoir*, int *s);
};

