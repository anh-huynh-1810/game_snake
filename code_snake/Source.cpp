#include<iostream>
#include "kmin_console.h"
#include<ctime>
#include<windows.h>
#define DAU_RAN 254
#define DOT_RAN 254
#define max 200
#define LEN 1
#define XUONG 2
#define TRAI 3
#define PHAI 4
#define TUONG_TREN 3
#define TUONG_DUOI 28
#define TUONG_TRAI 3
#define TUONG_PHAI 100
using namespace std;
struct ToaDo
{
	int x;
	int y;
};
ToaDo ran[max];
int soDot = 3;
int check;
void khoitaoran()
{
	ran[0].x = TUONG_TRAI + 3;
	ran[1].x = TUONG_TRAI + 2;
	ran[2].x = TUONG_TRAI + 1;
	ran[0].y = ran[1].y = ran[2].y = TUONG_TREN + 1;
}
void hienthiran(ToaDo dotcuoicu)
{
	setTextColor(10);
	gotoXY(ran[0].x, ran[0].y);
	cout << (char)DAU_RAN;
	setTextColor(15);
	for (int i = 1; i < soDot; i++)
	{
		gotoXY(ran[i].x, ran[i].y);
		cout << (char)DOT_RAN;
	}
	gotoXY(dotcuoicu.x, dotcuoicu.y);
	cout << " ";
}
void menu()
{

	cout << "\n\n     MINI GAME: \n\n";
	cout << "         .*****.   ***       **         ***         **   '*'    *.*.*.*.*   " << endl;
	cout << "        **'    '*  **'*      **        *' '*        **  '*'     **''''''*   " << endl;
	cout << "        **      '  ** *'     **       *'   '*       ** '*'      **          " << endl;
	cout << "         **        **  '*    **      '*     *'      **'*'       **.....     " << endl;
	cout << "           '**.    **   *.   **     .*'.....'*.     ***'        **.*.*.     " << endl;
	cout << "              '*   **    *'  **     *.*.*.*.*.*     **'*'       **          " << endl;
	cout << "        .      **  **     '* **    *'         '*    ** '*'      **          " << endl;
	cout << "        **.   .**  **      *'**   '*           *'   **  '*'     **......*   " << endl;
	cout << "         '*****'   **       ***  '*'           '*'  **   '*'.   *'*'*'*'*   " << endl;
	cout << "\n\t                                                   Coder: Van Anh \n\n\n";
}
ToaDo dichuyen(int huong)
{
	ToaDo dotcuoicu = ran[soDot - 1];
	for (int i = soDot - 1; i >= 1; i--)
	{
		ran[i] = ran[i - 1];
	}
	switch (huong)
	{
	case LEN:
		ran[0].y--; check = 0;
		break;
	case XUONG:
		ran[0].y++; check = 1;
		break;
	case TRAI:
		ran[0].x--; check = 2;
		break;
	case PHAI:
		ran[0].x++; check = 3;
		break;
	}
	return dotcuoicu;
}
void batsukien(int& huong)
{
	int key = inputKey();
	if (key == KEY_UP && check != 1)
	{
		huong = LEN;
	}
	else if (key == KEY_DOWN && check != 0)
	{
		huong = XUONG;
	}
	else if (key == KEY_LEFT && check != 3)
	{
		huong = TRAI;
	}
	else if (key == KEY_RIGHT && check != 2)
	{
		huong = PHAI;
	}
}
void batsukienluachon(int& luachon)
{
	int phim = inputKey();
	if (phim == '1')
	{
		luachon = 1;
	}
	else if (phim == '2')
	{
		luachon = 2;
	}
	else if (phim == '3')
	{
		luachon = 3;
	}
}
void vetuong()
{
	for (int i = TUONG_TRAI; i <= TUONG_PHAI; i++)
	{
		gotoXY(i, TUONG_TREN);
		cout << (char)220;
	}
	for (int i = TUONG_TREN + 1; i <= TUONG_DUOI; i++)
	{
		gotoXY(TUONG_TRAI, i);
		cout << (char)221;
	}
	for (int i = TUONG_TRAI; i <= TUONG_PHAI; i++)
	{
		gotoXY(i, TUONG_DUOI);
		cout << (char)223;
	}
	for (int i = TUONG_TREN + 1; i <= TUONG_DUOI - 1; i++)
	{
		gotoXY(TUONG_PHAI, i);
		cout << (char)222;
	}
}
bool kiemtrathua()
{
	if (ran[0].y == TUONG_TREN) return true;
	if (ran[0].y == TUONG_DUOI) return true;
	if (ran[0].x == TUONG_TRAI) return true;
	if (ran[0].x == TUONG_PHAI) return true;
	for (int i = 1; i < soDot; i++)
	{
		if (ran[0].x == ran[i].x && ran[0].y == ran[i].y)
			return true;
	}
}
void xulythua()
{
	soDot = 3;
	Sleep(200);
	clrscr();
	menu();
	cout << "\t\t\t\t Game over";
}
ToaDo hienthimoi(int diem)
{
	int color = diem % 16;
	srand(time(0));
	int x = TUONG_TRAI + 1 + rand() % (TUONG_PHAI - TUONG_TRAI - 1);
	int y = TUONG_TREN + 1 + rand() % (TUONG_DUOI - TUONG_TREN - 1);
	gotoXY(x, y);
	if (color != 0)
	{
		setTextColor(color);
	}
	cout << "*";
	return ToaDo{ x,y };
}
bool kiemtradaanmoi(ToaDo moi)
{
	if (ran[0].x == moi.x && ran[0].y == moi.y)
	{
		return true;
	}
	else return false;
}
void themdot(int level)
{
	ran[soDot] = ran[soDot - 1];
	soDot += level;
}
int main()
{
	noCursorType();//xóa con trỏ nháy
	int luachon;
	int level = 1;
	srand(time(0));
	int color;
	do
	{
		color = 1 + rand() % 15;
		system("cls");
		setTextColor(color);//màu
		menu();
		batsukienluachon(luachon);//bắt sự kiện phím 1,2,3
		setTextColor(15);
		cout << "\t\t\t\t     MENU    " << endl;
		cout << "\t\t\t\t 1.Start game" << endl;
		cout << "\t\t\t\t 2.Option level" << endl;
		cout << "\t\t\t\t 3.Exit game" << endl;
		Sleep(200);
	} while (luachon != 1 && luachon != 2 && luachon != 3);
	while (1)
	{
		system("cls");
		int x = 0, y = 0;
		int a = 300;
		int diem = 0;
		int TIME = 1;
		int huong = PHAI;
		switch (luachon)
		{
		case 1:
		{
			system("cls");
			khoitaoran();
			vetuong();
			ToaDo moi = hienthimoi(diem);
			while (1)
			{
				if (diem >= TIME * 5)
				{
					a -= 50;
					TIME++;
					//tăng 5 điểm rắn sẽ chạy nhanh hơn
				}
				ToaDo dotcuoicu = dichuyen(huong);
				batsukien(huong);//bắt  sự kiện phím lên, xuống, trái, phải
				hienthiran(dotcuoicu);
				gotoXY(TUONG_TRAI, TUONG_TREN - 1);
				cout << " Diem cua ban la: " << diem;
				gotoXY(TUONG_TRAI + 25, TUONG_TREN - 1);
				cout << " Level: " << level;
				if (kiemtradaanmoi(moi) == true)
				{
					moi = hienthimoi(diem);
					themdot(level);
					diem += level;
				}
				if (kiemtrathua() == true) break;
				Sleep(a);
			}
			xulythua();
			cout << endl;
			cout << "\t\t\t\t Diem cua ban la :" << diem << endl;
			diem = 0;//reset điểm 
			break;
		}
		case 2:
			cout << "\t\t\t\t Moi nhap level tu 2-5L: ";
			cin >> level;
			while (level <= 1 || level > 5)
			{
				cout << "\t\t\t\t Nhap sai. Moi nhap lai: ";
				cin >> level;
			}
			cout << "\t\t\t\t Level ban chon la: " << level;
			Sleep(500);
			luachon = 1;
			a = a / 5 * level;
			continue;
		case 3: break;
		}
		if (luachon == 3)
		{
			cout << "\t\t\t\t Goodbye! See you again";
			break;
		}
		cout << "\t\t\t\t      MENU    " << endl;
		cout << "\t\t\t\t 1. Play again" << endl;
		cout << "\t\t\t\t 2. Optison level" << endl;
		cout << "\t\t\t\t 3. Exit game" << endl;
		cin >> luachon;
	}
	_getwch();
	return 0;
}