#pragma once
#include "CQuanco.h"

class CQuancoT :
    public CQuanco
{
public:
    CQuancoT(int mx, int my);
    void thietlap(int x, int y);
    void doiTrangThai();
    void veTrangThaicu();
    void rotate();
};

