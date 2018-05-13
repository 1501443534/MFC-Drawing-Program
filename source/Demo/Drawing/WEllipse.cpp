#include "StdAfx.h"
#include "WEllipse.h"

IMPLEMENT_SERIAL(WEllipse, CObject, 1)

WEllipse::WEllipse()
{
	Type = (ElementType)3;
}




WEllipse::WEllipse(int orgX, int orgY, int hRadius, int vRadius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)3;
	OrgX = orgX;
	OrgY = orgY;
	HRadius = hRadius;
	VRadius = vRadius;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}

void WEllipse::Draw(CDC*pDC)
{
	// �������ʼ���������ԭ���ʵ�ָ��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//����ˢ�Ӽ���������ԭˢ�ӵ�ָ��
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//����ͼ�Σ�ͨ�����þ���������Բ��
	pDC->Ellipse(OrgX - HRadius / 2, OrgY + VRadius / 2, OrgX + HRadius / 2, OrgY - VRadius / 2);

	//ʹ�õ�ǰ���ʺ�ˢ��
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool WEllipse::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateEllipticRgn(OrgX-HRadius/2,OrgY-VRadius/2,OrgX+HRadius/2,OrgY+VRadius/2);
	BOOL flag = rgn.PtInRegion(pnt);
	if (flag)
	{
		return true;
	}
	else
		return false;
}


void WEllipse::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//�����ļ�
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << HRadius << VRadius;
	}
	else
	{
		//��ȡ�ļ�
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;
		ar >> BorderColor >> BorderType >> BorderWidth;
		ar >> FillColor >> FillType;
		ar >> HRadius >> VRadius;
	}
}

WEllipse::~WEllipse()
{
}
