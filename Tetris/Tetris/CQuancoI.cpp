#include "pch.h"
#include "CQuancoI.h"

CQuancoI::CQuancoI(int mx, int my)
{
	x = mx;
	y = my;
    oco[0] = CHcnmau(x , y,             x + RONG,    y + RONG, 0, 255, 0);
    oco[1] = CHcnmau(x , y + RONG,      x + RONG,    y + 2 *RONG, 0, 255, 0);
    oco[2] = CHcnmau(x , y + 2 * RONG,  x + RONG,    y + 3 *RONG, 0, 255, 0);
    oco[3] = CHcnmau(x , y + 3 * RONG,  x + RONG,    y + 4 * RONG, 0, 255, 0);
    trangthai = 0;
}

void CQuancoI::thietlap(int x, int y)
{
    this->x = x;
    this->y = y;
    if (trangthai == 0) {
        oco[0].thietlap(x, y, x + RONG, y + RONG);
        oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
        oco[2].thietlap(x, y + 2 * RONG, x + RONG, y + 3 * RONG);
        oco[3].thietlap(x, y + 3 * RONG, x + RONG, y + 4 * RONG);
    }
    else {
        oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
        oco[0].thietlap(x - RONG, y + RONG, x, y + 2 * RONG);
        oco[2].thietlap(x + RONG, y +  RONG, x +  2* RONG, y + 2 * RONG);
        oco[3].thietlap(x + 2 * RONG, y + RONG, x + 3 * RONG, y + 2 * RONG);
    }
}

void CQuancoI::doiTrangThai()
{
    trangthai += 1;
    trangthai = trangthai % 2;
    thietlap(x, y);
}

void CQuancoI::veTrangThaicu()
{
    trangthai += 1;
    trangthai = trangthai % 2;
    thietlap(x, y);
}

void CQuancoI::rotate()
{
    doiTrangThai();
    thietlap(x, y);
}
