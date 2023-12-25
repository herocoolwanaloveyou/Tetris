#pragma once
#include "CQuanco.h"
class CQuancoH2 :
    public CQuanco
{
public:
    CQuancoH2(int mx, int my);
    void thietlap(int x, int y);
    void doiTrangThai();
    void veTrangThaicu();
    void rotate();
};

