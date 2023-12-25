#pragma once
class CHcn
{
    int r, g, b;
public:
	int x1, y1, x2, y2;
	CHcn();
    CHcn(int mx1, int my1, int mx2, int my2);
    void thietlap(int mx1, int my1, int mx2, int my2);
    void goDown(int d);
    void goUp(int d);
    void goLeft(int d);
    void goRight(int d);
    void draw(CClientDC* pdc);
};

