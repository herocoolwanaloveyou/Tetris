#include "pch.h"
#include "CQuanco.h"

void CQuanco::draw(CClientDC* pdc, int value)
{
	for (int i = 0; i < 4; i++)
	{
		if(oco[i].y2 > value)
		oco[i].draw(pdc);
	}
}

void  CQuanco::goDown()
{
	for (int i = 0; i < 4; i++) {
		oco[i].y1 += RONG;
		oco[i].y2 += RONG;
	}
	y += RONG;
}

void CQuanco::goLeft()
{
	for (int i = 0; i < 4; i++) {
		oco[i].x1 -= RONG;
		oco[i].x2 -= RONG;
	}
	x -= RONG;
}

void CQuanco::goRight()
{
	for (int i = 0; i < 4; i++) {
		oco[i].x1 += RONG;
		oco[i].x2 += RONG;
	}
	x += RONG;
}

void CQuanco::goUp()
{
	for (int i = 0; i < 4; i++) {
		oco[i].y1 -= RONG;
		oco[i].y2 -= RONG;
	}
}
