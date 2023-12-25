#pragma once
#include "CQuanco.h"
class CQuancoH1 :
    public CQuanco
{
public:
    CQuancoH1(int mx, int my);
    void thietlap(int x, int y);
    void doiTrangThai();
    void veTrangThaicu();
    void rotate();
};

