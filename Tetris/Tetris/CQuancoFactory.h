#pragma once
#include "CQuanco.h"
#include "CQuancoI.h"
#include "CQuancoV.h"
#include "CQuancoT.h"
#include "CQuancoH1.h"
#include "CQuancoH2.h"
#include "CQuancoL.h"
//#include <stdlib.h>
#include "pch.h"

class CQuancoFactory
{
public:
	static CQuanco* create_quanco( int x, int y) {
		srand(time(0));
		int loai = 0;
		loai = rand() % 6;
		CQuanco* p;
		 //loai = 4;
		if (loai == 0) {
			p = new CQuancoI(x, y);
			return p;
		}
		if (loai == 1) {
			p = new CQuancoV(x, y);
			return p;
		}
		if (loai == 2) {
			p = new CQuancoL(x, y);
			return p;
		}
		if (loai == 3) {
			p = new CQuancoT(x, y);
			return p;
		}
		if (loai == 4) {
			p = new CQuancoH1(x, y);
			return p;
		}
		if (loai == 5) {
			p = new CQuancoH2(x, y);
			return p;
		}
	}
};

