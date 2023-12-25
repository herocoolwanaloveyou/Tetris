#pragma once
#include "CQuanco.h"
class CQuancoL :
    public CQuanco
{
public:
    CQuancoL(int mx, int my);
    void thietlap(int x, int y);
    void doiTrangThai();
    void veTrangThaicu();
    void rotate();
};

