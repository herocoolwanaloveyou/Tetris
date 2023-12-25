#include "pch.h"
#include "CHcn.h"

CHcn::CHcn()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;

}

CHcn::CHcn(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void CHcn::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void CHcn::goDown(int d)
{
	y1 += d;
	y2 += d;
}

void CHcn::goUp(int d)
{
	y1 -= d;
	y2 -= d;
}

void CHcn::goLeft(int d)
{
	x1 -= d;
	x2 -= d;
}

void CHcn::goRight(int d)
{
	x1 += d;
	x2 += d;
}

void CHcn::draw(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}