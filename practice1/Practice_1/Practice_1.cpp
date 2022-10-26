﻿//табличные значения для ДСП: 650 кг/м^3, ДВП: 800 кг/м^3, дерева 550 кг/м^3
#include <stdio.h>
//h - высота задней стенки и высота боковины. w - ширина задней стенки. k - толщина накладной задней стенки
//d - глубина боковины
int main()
{
	double h, w, d, BackWall, SideWall, WallUp, hg, doors, shelves;
	int a = 0;
	double k = 0.005;
	printf("Enter the heiht,width and depth of the cabinet in centimeters\n");
	scanf_s("%lf %lf %lf", &h, &w, &d);//ввод габаритов шкафа
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
	{
		printf("You have entered incorrect data");
		return 1;
	}//проверка ввода 
	hg = h;
	while (hg >= 40)
	{
		hg = hg - 40;
		a++;
	}// количество полок  
	w = w * 0.01;
	h = h * 0.01;
	d = d * 0.01;
	BackWall = h * w * k * 800;
	SideWall = 2 * (h-0.03) * d * 0.015 * 650;
	WallUp = 2 * w * d * 0.015 * 650;
	doors =  h * w * 0.010 * 550;
	shelves = a * d * (w - (0.015 * 2)) * 0.015 * 650;
	printf("Total Cabinet weight %lf Kilograms\n", BackWall + SideWall + WallUp + shelves + doors);
	return 0;
}
