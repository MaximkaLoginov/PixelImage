#include "Image.h"

Image::Image(int _h, int _w) {

	h = _h;
	w = _w;
	if (h == 0 && w == 0) {
		arr = nullptr;
		return;
	}
	arr = new unsigned char* [h];
	arr[0] = new unsigned char[h * w];
	

	for (int i = 1; i < h; i++) {

		arr[i] = arr[i - 1] + w;

		for (int j = 0; j < w; j++) {

			arr[i][j] = 0;

		}
	}



}

void Image::setH(int _h) {
	h = _h;
};
void Image::setW(int _w) {
	w = _w;
};
//void Image::allocateMemory(int _h, int _w) {
//	h = _h;
//	w = _w;
//	arr = new unsigned char* [h];
//	arr[0] = new unsigned char[h * w];
//
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			arr[i][j] = 0;
//		}
//	}
//
//};

Image::Image(const Image& a) {
	h = a.h;
	w = a.w;

	delete[]arr[0];
	delete[]arr;

	arr = new unsigned char* [h];
	arr[0] = new unsigned char[h * w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			arr[i][j] = a.arr[i][j];
		}
	}
}
Image& Image::operator=(const Image& a) {

	if (this == &a) {

		return *this;

	}
	if (arr != nullptr) {
		delete arr[0];
		delete[] arr;
	}

	h = a.h;
	w = a.w;

	arr = new unsigned char* [h];
	arr[0] = new unsigned char[h * w];

	for (int i = 0; i < h; i++) {

		arr[i] = arr[i] + i * w;

		for (int j = 0; j < w; j++) {

			arr[i][j] = a.arr[i][j];
		}

	}

	return *this;
}

unsigned char& Image::getPixel(int _h, int _w) {
	_h--;
	_w--;

	if (_h < 0 || _w < 0 || _h >= h || _w >= w) {

		throw 1;

	}

	return arr[_h][_w];
}

int Image::getH() {
	return h;
};
int Image::getW() {
	return w;
};
void Image::extension() {

	//unsigned char** arr2 = new unsigned char* [h];
	int exH = h * 2;
	int exW = w * 2;
	unsigned char** exArr = new unsigned char* [exH];
	exArr[0] = new unsigned char[exH * exW];


	for (int i = 1; i < exH; i++) {

		exArr[i] = exArr[0] + i * exW;

		for (int j = 0; j < exW; j++) {

			exArr[i][j] = 0;
		}
	}
	for (int i = 0; i < h; i++) {

		for (int j = 0; j < w; j++) {

			exArr[i * 2][j * 2] = arr[i][j];
		}
	}

	for (int i = 0; i < exH - 1; i += 2) {

		for (int j = 1; j < exW - 1; j += 2) {

			exArr[i][j] = (int)((exArr[i][j - 1] + exArr[i][j + 1]) / 2);
		}
		exArr[i][w * 2 - 1] = exArr[i][w * 2 - 2];
	}

	for (int i = 1; i < exH - 1; i += 2) {

		for (int j = 0; j < exW; j++) {

			exArr[i][j] = (int)((exArr[i - 1][j] + exArr[i + 1][j]) / 2);
		}
	}

	for (int j = 0; j < exW; j++) {
		exArr[exH - 1][j] = exArr[exH - 2][j];
	}
	delete[]arr[0];
	delete[]arr;

	h = exH;
	w = exW;
	arr = exArr;

}
ostream& operator<<(ostream& out, Image& a) {

	for (int i = 0; i < a.h; i++) {

		for (int j = 0; j < a.w; j++) {

			cout << a.arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return out;

}