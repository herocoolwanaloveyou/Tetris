#include "pch.h"
#include "CBanco.h"
#include "CQuancoFactory.h"

CBanco::CBanco()
{
	x = 50;
	y = 80;
	pc = nullptr;
	CQuancoFactory factory = CQuancoFactory();
	pnext = factory.create_quanco(x + (WIDTH * RONG) + 50, y);
	control = 0;
	level = 1;
	diem = 0;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			oco[i][j] = OCoMau(x + j * RONG, y + i * RONG, x + (j + 1) * RONG, y + (i + 1) * RONG, 255, 0, 0, 0);
		}
	}
}
void CBanco::draw(CClientDC* pdc) {

	CPen pen();
	pdc->Rectangle(0, 0, x + 3000, y + 3000);
	pdc->Rectangle(x, y, x+ RONG * WIDTH, y + RONG * HEIGHT);

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			oco[i][j].draw(pdc);
		}
	}
	CString strLevel;

	// xuat Level: level=1
	strLevel.Format(_T("Level: % d"), level);
	CRect rect1(50, 0, WIDTH * RONG, 40);
	pdc->DrawText(strLevel, rect1, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	// Xuat Point: diem=0
	strLevel.Format(_T("Point: % d"), diem);
	CRect rect2(50, 40, WIDTH * RONG, 80);
	pdc->DrawText(strLevel, rect2, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	//draw quanco
	if (pc != nullptr) {
		pc->draw(pdc, y);
	}
	if (pnext != nullptr) {
		pnext->draw(pdc, y);
	}
}

void CBanco::start()
{
	CQuancoFactory factory = CQuancoFactory();
	control = 1;
	diem = 0;
	level = 1;
	pc = factory.create_quanco(x + int(WIDTH / 2) * RONG - RONG, y - 4 * RONG);
	
	
}

int CBanco::kiemtra_dixuong()
{
	pc->goDown();
	int kq = 0;// 0 la ko di dc , 1 la di dc
	int dem = 0;
	for (int i = 0; i < 4; i++) {
		if (pc->oco[i].y2 > y) {
			toado vitri = timIJ(pc->oco[i]);
			if (vitri.i >= HEIGHT) {
				dem = 1;
				break;
			}
			else {
				dem += oco[vitri.i][vitri.j].gt;
			}
		}
	}
	if (dem > 0) {
		kq = 0;
	}
	else {
		kq = 1;
	}
	pc->goUp();
	return kq;	
}

int CBanco::kiemtra_quatrai()
{
	pc->goLeft();
	int kq = 1; // di chuyen dc
	int i = 0;
	toado vitri;
	while (i < 4 && kq == 1)
	{
		if (pc->oco[i].x1 < x)
			kq = 0;
		//kiemtraocotren ban co bi chiem hay chua
		vitri = timIJ(pc->oco[i]);
		if (vitri.i > 0 && oco[vitri.i][vitri.j].gt == 1)
			kq = 0;

		i++;
		if (kq == 0) {
			i++;
		}
	}
	pc->goRight();
	return kq;
}

int CBanco::kiemtra_quaphai()
{
	int x2 = x + WIDTH * RONG;
	pc->goRight();
	int kq = 1; // di chuyen dc
	int i = 0;
	while (i < 4 && pc->oco[i].x2 <= x2 && kq == 1)
	{
		toado vitri = timIJ(pc->oco[i]);
		if (vitri.j > WIDTH) {
			kq = 0;
		}
		else {
			if (vitri.i > 0 && oco[vitri.i][vitri.j].gt == 1)
			kq = 0;
		}
		i++;
	}if (i < 4) {
		kq = 0;
	}
	pc->goLeft();
	return kq;
}

int CBanco::kiemtra_xoay()
{
	pc->doiTrangThai();
	int kq = 1;
	int x2 = x + WIDTH * RONG;
	int y2 = y + HEIGHT * RONG;
	int i = 0;
	while (i < 4 && kq == 1) {
		if (pc->oco[i].x1 < x || pc->oco[i].x2 > x2 || pc->oco[i].y2 > y2)
			kq = 0;
		toado vitri = timIJ(pc->oco[i]);
		if(oco[vitri.i][vitri.j].gt == 1)
			kq = 0;
		i++;
	}
	pc->veTrangThaicu();
	return kq;
}

void CBanco::play(CClientDC* pdc)
{
	int tam = 0;
	do {
		while (kiemtra_dixuong()) {
			pc->goDown();
			draw(pdc);
			Sleep(1000);
		}
		transfer_banco(pdc);
		spawn_quanco();
		tam++;
	} while (kiemtra_dixuong());
	
}

toado CBanco::timIJ(CHcnmau oco)
{
	toado kq = toado();
	kq.j = (oco.x1 - x) / RONG;
	kq.i = (oco.y1 - y) / RONG;

	return kq;
}

void CBanco::clear_banco(int mi) {
	int i = mi;
	int j = 0;
	while (i > 0) {
		for (int j = 0; j < WIDTH; j++) {
			oco[i][j].gt = oco[i - 1][j].gt;
			oco[i][j].r = oco[i - 1][j].r;
			oco[i][j].g = oco[i - 1][j].g;
			oco[i][j].b = oco[i - 1][j].b;
		}
		i--;
	}
	for (int j = 0; j < WIDTH; j++) {
		oco[0][j].gt = 0;
		
	}
}

void CBanco::transfer_banco(CClientDC* pdc)
{
	for (int i = 0; i < 4; i++) {
		toado vitri = timIJ(pc->oco[i]);
		oco[vitri.i][vitri.j].gt = 1;
		oco[vitri.i][vitri.j].r = pc->oco[i].r;
		oco[vitri.i][vitri.j].g = pc->oco[i].g;
		oco[vitri.i][vitri.j].b = pc->oco[i].b;
	}
	int i = HEIGHT - 1;
	int j = 0;
	int tong = 0;
	int dem = 0;
	while (i > 0) {
		tong = 0;
		for (int j = 0; j < WIDTH; j++) {
			tong += oco[i][j].gt;
		}
		if (tong == WIDTH) {
			diem += 10;
			clear_banco(i);
			draw(pdc);
			Sleep(500);
			dem++;
		}else
			i--;
	}
	if (dem == 4) {
		diem += 60;
	}
}

void CBanco::spawn_quanco()
{
	CQuancoFactory factory = CQuancoFactory();
	delete pc;
	pc = pnext;
	pc->thietlap(x + int(WIDTH / 2)* RONG - RONG, y - 4 * RONG);
	pnext = factory.create_quanco(x + (WIDTH * RONG) + 50, y);
	//pnext = factory.create_quanco(x + (WIDTH * RONG) + 50, y);
	//pc = factory.create_quanco(x + (WIDTH * RONG) / 2 - RONG, y);

}

void CBanco::goDown(CClientDC* pdc)
{
	int tam = 0;
		if (kiemtra_dixuong()) {
			pc->goDown();
			draw(pdc);
		}
}

void CBanco::goLeft(CClientDC* pdc)
{
	if (kiemtra_quatrai()) {
		pc->goLeft();
		draw(pdc);
	}
}

void CBanco::goRight(CClientDC* pdc)
{
	if(kiemtra_quaphai()) {
		pc->goRight();
		draw(pdc);
	}
}

void CBanco::rotate(CClientDC* pdc)
{
	if (kiemtra_xoay()) {
		pc->rotate();
		draw(pdc);
	}
}
