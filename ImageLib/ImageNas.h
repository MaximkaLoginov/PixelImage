#pragma once


#include "Image.h"
#include <fstream>


class ImageNas : public Image {
	ofstream fout;
	ifstream fin;

public:
	ImageNas(int _h, int _w);
	//ImageNas(const Image& a);
	void OutFile(); 
	void InFile();
};