
#pragma once
#include "wshape.h"
class WCircle :public WShape
{
public:
	int Radius;//Բ�İ뾶
public:
	WCircle();
	WCircle(int orgX, int orgY, int radius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WCircle();
	DECLARE_SERIAL(WCircle); //������WCircle��֧�����л�
};

