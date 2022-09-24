#pragma once
#include <iostream>
#include <stdio.h>

// ������� ����������� ������� ��������� ���� � �������
// fopen - �������
// fclose - �������

//fprints - ��������� ���-�� ���������� � ����
//fscans - ��������� ���-�� ������ �� �����


// �������� ���� 
// 
// fwrite 
// fread

// ����� ��� �������� ����� ���������� ���������� <stdio.h>

/*
int main() {

	int n  = 5;
	int * a = new int[n];

	for(int i = 0;i < n;i++) {
		a[i] = rand() % 10;
	}

	FILE *file;
	file = fopen("vec.txt , "w");

	//w - ������ � �����
	//a - ���������� ���� �� ������, �� ������������ ��� ������ ��������� � ����� �����
	//r - ������ ����
	//w[b][+]

	//[+] - ����� ������ (���� �����, ����� ������, ���� �����, ����� ������)
	//[b] - ���������� �������� ����

	if (file == NULL) {
		printf("can't open file\n);
		return 0;
	}

	fprintf(file, "%d\n",n);

	for(int i =0;i < n;i++) {
		frintf(size,"%d ",a[i];
	}

	fclose(file);

	//fflush - ���������� ������ �� ������ � ����(����� ���������� ������ �� ������� ����\
	//fseek - ����������� �� �����

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