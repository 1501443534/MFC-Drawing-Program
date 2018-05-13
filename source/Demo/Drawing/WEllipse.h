#pragma once
#include "wshape.h"
class WEllipse :public WShape
{
public:
	int HRadius;//��Բ��ˮƽ����
	int VRadius;//��Բ�Ĵ�ֱ����
public:
	WEllipse();
	WEllipse(int orgX, int orgY, int hRadius, int vRadius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WEllipse();
	DECLARE_SERIAL(WEllipse); //������WEllipse��֧�����л�
};

