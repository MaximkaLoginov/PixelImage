#include  "ImageNas.h"

ImageNas::ImageNas(int _h, int _w) :Image(_h, _w) {}
//ImageNas::ImageNas(const Image& a) : Image(a) {}

void ImageNas::OutFile() {

	fout.open("Pixel.txt");

	if (!fout.is_open()) {
		return;
	}

	fout << getH() << " " << getW() << "\n";

	for (int i = 1; i <= getH(); i++) {

		for (int j = 1; j <= getW(); j++) {

			fout << getPixel(i, j) << " ";
		}

		fout << endl;

	}
	fout << endl;

	fout.close();
};
void ImageNas::InFile() {

	fin.open("Pixel.txt", ios_base::in);

	if (!fin.is_open()) {
		return;
	}

	int _h, _w;

	fin >> _h >> _w;
	h = _h;
	w = _w;

	if (arr != nullptr) {
		delete arr[0];
		delete arr;
	}

	arr = new unsigned char* [_h];
	arr[0] = new unsigned char[_h * _w];

	for (int i = 1; i < _h; i++) {
		arr[i] = arr[i - 1] + _w;
	}

	int num = 0;
	for (int i = 1; i <= _h; i++) {

		for (int j = 1; j <= _w; j++) {

			fin >> num;
			getPixel(i,j) = (unsigned char)num;
		}
	}


	fin.close();
};