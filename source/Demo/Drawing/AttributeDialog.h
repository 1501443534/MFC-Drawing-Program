#pragma once
#include "afxwin.h"
#include "afxcolorbutton.h"


// AttributeDialog �Ի���

class AttributeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AttributeDialog)

public:
	AttributeDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual BOOL OnInitDialog();
	virtual ~AttributeDialog();

// �Ի�������
	enum { IDD = IDD_ATTRIBUTE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()

// �Զ������Ϣӳ�亯��
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancle();
	afx_msg void OnCbnSelchangeComboShapeType();
// �Զ������
public:
	// ͼԪ����
	CComboBox shapeType;
	// ԭ��X
	int orgX;
	// ԭ��Y
	int orgY;
	// ���
	int width;
	// �߶�
	int height;
	// �ı�����
	CString textContent;
	// �ı��Ƕ�
	int textAngle;
	// �߿���
	int borderWidth;
	// �߿���ɫ��ť
	CMFCColorButton borderColorButton;
	// �߿���ɫ
	COLORREF borderColor;
	// �߿�����
	CListBox borderType;
	// �������
	CListBox fillType;
	// �����ɫ��ť
	CMFCColorButton fillColorButton;
	// ���ɫ
	COLORREF fillColor;

	// ѡ���������
	int comboxIndex;
	int borderTypeIndex;
	int filltypeIndex;
};
