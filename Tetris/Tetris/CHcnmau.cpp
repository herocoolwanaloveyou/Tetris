#include "pch.h"
#include "CHcnmau.h"

CHcnmau::CHcnmau(int mx1, int my1, int mx2, int my2, int mr, int mg, int mb): CHcn (mx1,my1,mx2,my2)
{
	r = mr;
	g = mg;
	b = mb;
}

CHcnmau::CHcnmau()
{


}

void CHcnmau::draw(CClientDC* pdc)
{
	CPen pen(PS_SOLID, 3, RGB(b, b, b));
	CPen* pOldPen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(r, g, b));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	pdc->Rectangle(x1, y1, x2, y2);
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
}
