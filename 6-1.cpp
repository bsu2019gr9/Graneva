//горизонтальный градиент
#include<iostream>
#include<fstream>  
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	setlocale(LC_ALL, "Russian");

	ifstream fff("d:\\1.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream ggg("d:\\rez.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)

	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];// куда читать байты
	color c;
	unsigned int w, h;//надеемся. что тут 4 байта

	double r1, g1, b1;
	double r2, g2, b2;
	double step=0;
	cout<<"Введите параметры первого цвета:\n";
	cin>>r1>>g1>>b1;
	cout<<"Введите параметры второго цвета:\n";
	cin>>r2>>g2>>b2;
	cout<<"Введите количество шагов\n";
	cin>>step;

	fff.read((char*)&buf, 18);   //чтение 18 байт заголовка bmp
	ggg.write((char*)&buf, 18);    //запись 18 байт заголовка bmp
	fff.read((char*)&w, 4); cout << "width=" << w;   //чтение width из заголовка bmp
	fff.read((char*)&h, 4); cout << ", height=" << h; //чтение height из заголовка bmp

	w = 400; ggg.write((char*)&w, 4);    //запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	h = 400; ggg.write((char*)&h, 4);    //запись height в заголовок bmp
	fff.read((char*)&buf, 28);   //чтение 28 байт заголовка bmp
	ggg.write((char*)&buf, 28);    //запись 28 байт заголовка bmp

	double step_r, step_g, step_b;
	step_r = (double)((r2 - r1) / step);
	step_g = (double)((g2 - g1) / step);
	step_b = (double)((b2 - b1) / step);
	double tmp_r, tmp_g, tmp_b;
	tmp_r = r1; tmp_g = g1; tmp_b = b1;
	c.r = r1; c.g = g1; c.b = b1;
		double newstep = w / step;
		double tmp_step = newstep;
		for (unsigned int i = 1; i <= h; ++i)
		{
			for (unsigned int j = 1; j <= w; ++j)
			{
				if (j == newstep)
				{
					newstep += tmp_step;
					tmp_r += step_r;
					tmp_g += step_g;
					tmp_b += step_b;
				}
				c.r = (unsigned char)tmp_r;
				c.g = (unsigned char)tmp_g;
				c.b = (unsigned char)tmp_b;
				ggg.write((char*)&c.b, 1);// запись 28 байт
				ggg.write((char*)&c.g, 1);// запись 28 байт
				ggg.write((char*)&c.r, 1);// запись 28 байт
			}
			tmp_r = r1;
			tmp_g = g1;
			tmp_b = b1;
			newstep = tmp_step;
		}

	fff.close();//закрыли файл
	ggg.close();//закрыли файл
	return 1;
}