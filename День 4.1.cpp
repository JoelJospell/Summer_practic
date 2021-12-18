#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct image 
{
	int mx;
	int my;
	int* points;
};

void createlmage(image* img, int tmx, int tmy) 
{
	img->mx = tmx;
	img->my = tmy;
	img->points = new int[tmy * tmx];
	for (int i = 0; i < tmy * tmx; i++) 
	{
		img->points[i] = 0;
	}
}

void showimage(image* img) 
{
	for (int i = 0; i < img->mx; i++) 
	{
		for (int j = 0; j < img->my; j++) 
		{
			cout << img->points[(i * (img->my)) + j];
		}
		cout << endl;
	}
}

void getPointImage(image* img, int x, int y) 
{
	img->points[(y - 1) * (img->my) + x - 1];
}

void setPointImage(image* img, int x, int y, int color) 
{
	img->points[(y - 1) * (img->my) + x - 1] = color;
}

void saveToPnmFile(image* img, ofstream& fileName) 
{
	for (int i = 0; i < img->mx; i++) 
	{
		for (int j = 0; j < img->my; j++) 
		{
			fileName << img->points[(i * (img->mx + 1)) + j];
		}
		fileName << endl;
	}
}

int testcreatelmage() 
{
	image img;
	createlmage(&img, 3, 4);
	for (int i = 0; i < 3 * 4; i++) 
	{
		if (img.points[i] != 0) return -1;
	}
	return 0;
}

int testsetPointImage() 
{
	image* img = new image;
	createlmage(img, 4, 4);
	setPointImage(img, 3, 3, 4);
	if (img->points[10] != 4) return -1;
	return 0;
}

int testgetPointImage() 
{
	image img;
	img.points = new int[4 * 4];
	for (int i = 0; i < 4 * 4; i++) 
	{
		img.points[i] = 0;
	}
	getPointImage(&img, 4, 4);
	if (img.points[(2 - 1) * (2) + 2 - 1] != 0) 
	{
		return -1;
	}
	return 0;
}

int testsaveToPnmFile() 
{
	image* img = new image;
	createlmage(img, 2, 2);
	ofstream fount;
	fount.open("F1.txt");
	saveToPnmFile(img, fount);
	fstream f;
	f.open("F1.txt", ios::in);
	long file_size;
	f.seekg(0, ios::end);
	file_size = f.tellg();
	if (file_size == 0) 
	{
		f.close();
		return -1;
	}
	f.close();
	return 0;
}

void runTest(int (*testfunction)(), string testname) 
{
	if (testfunction() == 0)
		cout << "TEST " << testname << " COMPLETED SUCCSESSFULLY " << endl;
	else
		cout << "TEST " << testname << " FAILD" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	image img;
	int mx, my, x, y, color;
	ofstream fount;
	fount.open("F1.txt");
	runTest(testcreatelmage, "testcreatelmage");
	runTest(testsetPointImage, "testsetPointImage");
	runTest(testgetPointImage, "testgetPointImage");
	runTest(testsaveToPnmFile, "testsaveToPnmFile");
	cout << "¬ведите ширину картинки по x: ";
	cin >> mx;
	cout << "¬ведите ширину картинки по y: ";
	cin >> my;
	createlmage(&img, mx, my);
	showimage(&img);
	cout << "¬ведите координаты точки по x и по y, которую хотите добавить: " << endl;
	cin >> x;
	cin >> y;
	cout << "¬ведите код цвета добавленной точки: ";
	cin >> color;
	setPointImage(&img, x, y, color);
	showimage(&img);
	saveToPnmFile(&img, fount);
}