#include "Image.h"
#include "ImageAgr.h"
#include "ImageNas.h"
#include <gtest.h>


TEST(test_lib, test_1) {
	Image a(2, 2);
	a.getPixel(1, 1) = 1;
	a.getPixel(1, 2) = 101;
	a.getPixel(2, 1) = 2;
	a.getPixel(2, 2) = 100;

	a.extension();
	int b = a.getPixel(4, 4);

	EXPECT_EQ(100, b);
}

TEST(test_lib, test_2) {
	Image a(2, 2);
	a.getPixel(1, 1) = 1;
	a.getPixel(1, 2) = 101;
	a.getPixel(2, 1) = 2;
	a.getPixel(2, 2) = 100;

	a.extension();
	int b = a.getPixel(1, 1);

	EXPECT_EQ(1, b);
}

TEST(test_lib, test_3) {
	ImageNas a(2, 2);

	a.getPixel(1, 1) = 1;
	a.getPixel(1, 2) = 101;
	a.getPixel(2, 1) = 2;
	a.getPixel(2, 2) = 100;

	a.OutFile();

	ifstream ifile("Pixel.txt");
	int v = 0;
	int q = 0;
	ifile >> v >> q;

	ifile.close();

	EXPECT_EQ(v, 2);
	EXPECT_EQ(q, 2);
	
}
TEST(test_lib, test_4) {
	ImageNas a(2, 2);

	a.getPixel(1, 1) = 1;
	a.getPixel(1, 2) = 101;
	a.getPixel(2, 1) = 2;
	a.getPixel(2, 2) = 100;

	a.OutFile();

	a.extension();
	a.OutFile();

	ifstream ifile("Pixel.txt");
	int v = 0;
	int q = 0;
	ifile >> v >> q;

	ifile.close();

	EXPECT_EQ(v, 4);
	EXPECT_EQ(q, 4);

}