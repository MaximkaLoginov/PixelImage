#pragma once
#include <iostream>
#include <stdio.h>

// функции позвол€ющие открыть текстовый файл и закрыть
// fopen - открыть
// fclose - закрыть

//fprints - позвол€ет что-то щаписывать в файл
//fscans - позвол€ет что-то читать из файла


// бинарный файл 
// 
// fwrite 
// fread

// чтобы все работало нужно подключить библиотеку <stdio.h>

/*
int main() {

	int n  = 5;
	int * a = new int[n];

	for(int i = 0;i < n;i++) {
		a[i] = rand() % 10;
	}

	FILE *file;
	file = fopen("vec.txt , "w");

	//w - писать в файле
	//a - открываете файл на запись, но прдеполагает что будете добавл€ть в конец файла
	//r - читать файл
	//w[b][+]

	//[+] - можно читать (если читал, можно писать, если писал, можно читать)
	//[b] - открываешь бинарный файл

	if (file == NULL) {
		printf("can't open file\n);
		return 0;
	}

	fprintf(file, "%d\n",n);

	for(int i =0;i < n;i++) {
		frintf(size,"%d ",a[i];
	}

	fclose(file);

	//fflush - записывать данные из буфера в файл(сброс временного буфера на жесткий диск\
	//fseek - перемещение по файлу

	int M;
	int *b;
	file = fopen("vec.txt","r");
	if(file == NULL) {
		printf("can't read file");
		return 0;
	}

	fscanf(file, "%d", &M);

	b = new int[M];

	for(int i =0;i < M; i++) {

		fscanf(file, "%d",b+i);
	}





	*/
using namespace std;

class Image {
protected:
	int h;
	int w;
	unsigned char** arr;

public:

	Image(int _h = 0, int _w = 0);
	Image(const Image& a);
	Image& operator=(const Image& a);
	int getH();
	int getW();
	void setH(int _h = 0);
	void setW(int _w = 0);
	unsigned char& getPixel(int _h = 0, int _w = 0);
	void extension();
	friend ostream& operator<<(ostream& out, Image& a);
	void allocateMemory(int _h = 0, int _w = 0);


};