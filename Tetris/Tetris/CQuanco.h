#pragma once
#include"CHcnmau.h"
#define RONG  50
class CQuanco
{
public:
	CQuanco() {
		x = 0;
		y = 0;
		trangthai = 0;
	}

	CHcnmau oco[4];
	int x, y;
	int trangthai;
	void draw(CClientDC* pdc,int value);
	void goLeft();
	void goRight();
	void goUp();
	void goDown();
	virtual void thietlap(int x, int y){}
	virtual void doiTrangThai(){}
	virtual void veTrangThaicu(){}
	virtual void rotate(){}
};