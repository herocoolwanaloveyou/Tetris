#pragma once
#include "Chcn.h"
class CHcnmau :public CHcn
{
public:
	int r, g, b;
	CHcnmau();
	CHcnmau(int mx1, int my1, int mx2, int my2, int mr, int mg, int mb);
	void draw(CClientDC* pdc);
};

