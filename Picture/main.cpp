#include "Image.cpp"
#include "ImageNas.cpp"
#include "ImageAgr.h"
int main() {

	/*Image a(2, 2);

	try {
		a.getPixel(1, 1) = 1;
		a.getPixel(1, 2) = 101;
		a.getPixel(2, 1) = 2;
		a.getPixel(2, 2) = 100;
	}
	catch (...) {
		cout << "Uncorrecat valiable" << "\n";
		return -1;
	}*/

	/*cout << a;
	a.extension();
	cout << endl;
	cout << a;*/
	/*ImageNas d(0,0);

	try {
		d.InFile();
	}
	catch (...) {
		cout << "lox" << "\n";
		return -100;
	}
	cout << d;*/
	
	//ImageNas c(2,2);
	//try {
	//	c.getPixel(1, 1) = 1;
	//	c.getPixel(1, 2) = 101;
	//	c.getPixel(2, 1) = 2;
	//	c.getPixel(2, 2) = 100;
	//}
	//catch (...) {
	//	cout << "Uncorrecat valiable" << "\n";
	//	return -1;
	//}
	//c.OutFile();
	///*cout << c;*/
	////c.OutFile();
	//c.extension();
	////c.OutFile();
	//
	//c.InFile();
	//cout << c;
	//c.OutFile();







	cout << "inheritance\n";
	ofstream fout("Pixel.txt");
	if (!fout.is_open()) {
		return -2;
	}
	int q = 2, b = 2;
	fout << q << " " << b << endl;
	fout << 1 << " " << 101 << endl
		<< 2 << " " << 100 << endl;
	fout.close();

	ImageNas v(0, 0);

	//try {
	//	v.InFile();
	//}
	//catch (...) {
	//	cout << "err" << "\n";
	//	return -1231232;
	//}
	v.InFile();
	cout << v;
	//v.OutFile();
	v.extension();
	cout << endl;
	cout << v;
	v.OutFile();
	

	cout << "Aggregation\n";
	ofstream ofile("Pixel.bin", ios_base::binary | ios_base::out);
	int a = 2;
	ofile.write((char*)&a, sizeof(int));
	//fout.write(" ", sizeof(char));
	ofile.write((char*)&a, sizeof(int));
	//fout.write("\n", sizeof(char));
	a = 1;
	ofile.write((char*)&a, sizeof(int));
	//fout.write(" ", sizeof(char));
	a = 101;
	ofile.write((char*)&a, sizeof(int));
	//fout.write("\n", sizeof(char));
	a = 2;
	ofile.write((char*)&a, sizeof(int));
	//fout.write(" ", sizeof(char));
	a = 100;
	ofile.write((char*)&a, sizeof(int));
	//fout.write("\n ", sizeof(char));
	ofile.close();

	ImageAgr z;

	z.InFile();
	z.OutFile();

	return 0;
}