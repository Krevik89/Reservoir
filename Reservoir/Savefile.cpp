#include "Savefile.h"

void Savefile::Savetxtfile(reservoir* p, int *size) {
	if (!fopen_s(&file, path, WRITE)) {
		for (int i{ 0 }; i < *size; i++) {
			fprintf_s(file, "%s ", p[i]._name, strlen(p[i]._name) * sizeof(char));
			fprintf_s(file, "%g ", p[i]._length, sizeof(double));
			fprintf_s(file, "%g ", p[i]._width, sizeof(double));
			fprintf_s(file, "%g", p[i]._depth, sizeof(double));
			fprintf_s(file, "%s\n ", p[i]._type, strlen(p[i]._type) * sizeof(char));
		}
	}
	fclose(file);
	printf("Сохранение в текстовый файл успешно \n");
}
void Savefile::Savebinfile(reservoir* p, int* size) {
	if (!fopen_s(&file, path, WRITEBIN)) {
		for (int i{ 0 }; i < *size; i++) {
			fwrite(&p[i]._length, sizeof(p[i]._length), *size, file);
			fwrite(&p[i]._width, sizeof(p[i]._width), *size, file);
			fwrite(&p[i]._depth, sizeof(p[i]._depth), *size, file);
		}
	}
	fclose(file);
	printf("Сохранение в бинарный файл успешно \n");
}