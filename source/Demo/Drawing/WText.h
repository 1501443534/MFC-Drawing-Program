#pragma once
#include "wshape.h"
class WText :public WShape
{
public:
	CString TextContent; // �ı�������
	int TextAngle; // �ı�����ת�Ƕ�
public:
	WText();
	WText(int orgX, int orgY, CString textContent, int textAngle, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC* pDC);//�����ı�����
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WText();
};

