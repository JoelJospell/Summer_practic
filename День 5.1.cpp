#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct image 
{
	int mx;
	int my;
	int* points;

	void createlmage(int tmx, int tmy) 
	{
		mx = tmx;
		my = tmy;
		points = new int[tmy * tmx];
		for (int i = 0; i < tmy * tmx; i++) 
		{
			points[i] = 1;
		}
	}

	void showimage() {
		for (int i = 0; i < my; i++) 
		{
			for (int j = 0; j < mx; j++) 
			{
				cout << points[(i * mx) + j];
			}
			cout << endl;
		}
	}

	void getPointImage(int x, int y) 
	{
		points[(y - 1) * my + x - 1];
	}

	void setPointImage(int x, int y, int color) 
	{
		points[(y - 1) * mx + x - 1] = color;
	}

	void saveToPnmFile(const string filename)
	{
		fstream out;
		out.open(filename, fstream::out);
		out << "P1" << endl;
		out << mx << " " << my << endl;

		for (int i = 0; i < mx; i++)
		{
			for (int j = 0; j < my; j++)
			{
				out << points[i * my + j] << " ";
			}
			out << endl;
		}

		out.close();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	image img;
	int mx, my, x, y, color;
	cout << "¬ведите ширину картинки по x: ";
	cin >> mx;
	cout << "¬ведите ширину картинки по y: ";
	cin >> my;
	img.createlmage(mx, my);
	img.showimage();
	cout << "¬ведите координаты точки по x и по y, которую хотите добавить: " << endl;
	cin >> x;
	cin >> y;
	cout << "¬ведите код цвета добавленной точки: ";
	cin >> color;
	img.setPointImage(x, y, color);
	img.showimage();
	img.saveToPnmFile("fount");
}