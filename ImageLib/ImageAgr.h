#pragma once

#include "Image.h"

#include "fstream"

class ImageAgr{

	Image* img;
	ofstream fout;
	ifstream fin;

public:

	ImageAgr();

	void OutFile();
	void InFile();

	~ImageAgr();
};