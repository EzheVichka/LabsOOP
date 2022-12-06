#include <Windows.h>
#include <iostream>
#include <tchar.h>
//#include <stdafx.h>
#include <windowsx.h>
using namespace std;

HWND hWnd = GetConsoleWindow();
HDC hDC = GetDC(hWnd);

void CrossShow(COLORREF Color,
	int iCenterX, /*iCenterX, iCenterY точки отсчета для рисования*/
	int iCenterY,
	int x, /* Перемещение по координате x */
	int y) /* Перемещение по координате y */
{
	HPEN hPen = CreatePen(PS_SOLID, 10, Color);//установка пера
	HBRUSH hBrush = GetStockBrush(NULL_BRUSH);//установка кисти
	SelectObject(hDC, hPen);
	SelectObject(hDC, hBrush);
	POINT p;

	MoveToEx(hDC, iCenterX, iCenterY, &p);//объявление текущей позиции данной точки
	LineTo(hDC, iCenterX + x, iCenterY + y);//рисование линии
	MoveToEx(hDC, iCenterX + x, iCenterY, &p);
	LineTo(hDC, iCenterX, iCenterY + y);

	DeleteObject(hBrush);
	DeleteObject(hPen);
}



int main()
{
	// Начальное положение крестов на плоскости
	int ix = 50;
	int iy = 50;
	int ix1 = 1500;
	int iy1 = 50;

	int x = 50; // Размеры кресты в ширину
	int y = 50; // Размеры креста в высоту

	int red = 153;
	int green = 204;
	int blue = 255;

	int counter = 0;

	CrossShow(RGB(red, green, blue), ix, iy, x, y); // Обращение к функции для отображения фигуры с передаванием параметров
	std::cin.get();

	// Движение с горизонтальным и вертикальным увеличением равномерно
	for (; ix < 500 && iy < 500; )
	{
		/*
		Сначала мы делаем крест "прозрачным" - не передаем никакой цвет
		Затем перемещаем по "x" и "y"
		Увеличиваем размер
		Отображаем фигуру на плоскости, передавая её изначальный цвет
		*/
		if (counter % 2 == 0) {
			CrossShow(RGB(11, 11, 11), ix, iy, x, y);
			ix += 10;
			iy += 10;

			x += 10;
			y += 10;
			CrossShow(RGB(red, green, blue), ix, iy, x, y);
			counter++;
		}
		else {
			CrossShow(RGB(11, 11, 11), ix, iy, x, y);
			ix += 10;
			iy += 10;

			x += 10;
			y += 10;
			CrossShow(RGB(108, 70, 117), ix, iy, x, y);
			counter++;
		}
		Sleep(50); //остановка действия программы на опр. кол-во времени
	}


	counter = 0;
	// Движение с горизонтальным уменьшением
	for (; ix > 50 && iy > 50; ) {

		if (counter % 2 == 0) {

			CrossShow(RGB(11, 11, 11), ix, iy, x, y); // скрытие фона
			ix -= 10;
			iy -= 10;

			x -= 10;
			y -= 10;
			CrossShow(RGB(red, green, blue), ix, iy, x, y);
			counter++;
		}
		else {
			CrossShow(RGB(11, 11, 11), ix, iy, x, y);
			ix -= 10;
			iy -= 10;

			x -= 10;
			y -= 10;
			CrossShow(RGB(200, 56, 90), ix, iy, x, y);
			counter++;
		}
		Sleep(50);
	}
	CrossShow(RGB(11, 11, 11), ix, iy, x, y);

	std::cin.get();


//Создание другого креста и движение по другой диагонали

	// Движение с горизонтальным и вертикальным увеличением равномерно
	for (; ix1 > 50 && iy1 < 500; )
	{
		/*
		Сначала мы делаем крест "прозрачным" - не передаем никакой цвет
		Затем перемещаем по "x" и "y"
		Увеличиваем размер
		Отображаем фигуру на плоскости, передавая её изначальный цвет
		*/
		if (counter % 2 == 0) {
			CrossShow(RGB(11, 11, 11), ix1, iy1, x, y);
			ix1 -= 20;
			iy1 += 10;

			x += 10;
			y += 10;
			CrossShow(RGB(red, green, blue), ix1, iy1, x, y);
			counter++;
		}
		else {
			CrossShow(RGB(11, 11, 11), ix1, iy1, x, y);
			ix1 -= 20;
			iy1 += 10;

			x += 10;
			y += 10;
			CrossShow(RGB(108, 70, 117), ix1, iy1, x, y);
			counter++;
		}
		Sleep(50);
	}



	//std::cin.get();
	counter = 0;
	// Движение с горизонтальным уменьшением
	for (; ix1 < 1500 && iy1 > 50; ) {

		if (counter % 2 == 0) {

			CrossShow(RGB(11, 11, 11), ix1, iy1, x, y); // скрытие фона
			ix1 += 20;
			iy1 -= 10;

			x -= 10;
			y -= 10;
			CrossShow(RGB(red, green, blue), ix1, iy1, x, y);
			counter++;
		}
		else {
			CrossShow(RGB(11, 11, 11), ix1, iy1, x, y);
			ix1 += 20;
			iy1 -= 10;

			x -= 10;
			y -= 10;
			CrossShow(RGB(200, 56, 90), ix1, iy1, x, y);
			counter++;
		}
		Sleep(50);
	}
	std::cin.get();
	return 0;
}