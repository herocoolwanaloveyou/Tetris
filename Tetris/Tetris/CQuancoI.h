#pragma once
#include "CQuanco.h"
class CQuancoI :
    public CQuanco
{
public:
    CQuancoI(int mx, int my);
    void thietlap(int x, int y);
    void doiTrangThai();
    void veTrangThaicu();
    void rotate();
};

