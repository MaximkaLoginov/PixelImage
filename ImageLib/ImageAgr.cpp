#include "ImageAgr.h"

ImageAgr::ImageAgr() {

	img = nullptr;

}

void ImageAgr::OutFile() {

	fout.open("Pixel.bin", ios::binary | ios_base::out);
	if (!fout.is_open()) return;

	/*fout.write((char*)(img->getH()), sizeof(int));
	fout.write(" ", sizeof(char));
	fout.write((char*)img->getW(), sizeof(int));
	fout.write("\n", sizeof(char));*/
	int h = img->getH();
	int w = img->getW();

	//cout << img << "\n\n";

	fout << h << " " << w << "\n";

	
	/*unsigned char** arr = new unsigned char* [h];
	arr[0] = new unsigned char[h * w];

	for (int i = 1; i < h; i++) {
		arr[i] = arr[i - 1] + w;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			arr[i - 1][j - 1] = img->getPixel(i, j);
		}
	}*/


	//fout.write((char*)arr[0], sizeof(char) * h * w);


	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			fout.write((char*)&img->getPixel(i, j), sizeof(img->getPixel(i, j)));
		}
		fout << "\n";
	}

	fout.close();
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << img->getPixel(i,j);
		}
		cout << "\n";
	}

	/*for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << arr[i][j];
		}
	}*/

	/*delete arr[0];
	delete arr;*/

}
void ImageAgr::InFile() {

	fin.open("Pixel.bin", ios_base::binary | ios_base::in);

	if (!fin.is_open()) return;
	int _h = 0, _w = 0;
	fin.read((char*)&_h, sizeof(int));
	fin.read((char*)&_w, sizeof(int));
	
	delete img;
	img = new Image(_h, _w);

	int a = 0;

	/*int** arr = new int* [_h];
	arr[0] = new int [_h * _w];

	for (int i = 1; i < _h; i++) {
		arr[i] = arr[i - 1] + _w;
	}
	fin.read((char*)arr[0], sizeof(int) * _h * _w);

	for (int i = 1; i <= _h; i++) {
		for (int j = 1; j <= _w; j++) {
			img->getPixel(i, j) = arr[i - 1][j - 1];
		}
	}*/

	for (int i = 1; i <= _h; i++) {
		for (int j = 1; j <= _w; j++) {
			fin.read((char*)&a, sizeof(int));
			img->getPixel(i, j) = a;
		}
	}

	fin.close();
	cout << *(img) << "\n";
}

ImageAgr::~ImageAgr() {
	if (img == nullptr) {
		return;
	}
	delete img;
}