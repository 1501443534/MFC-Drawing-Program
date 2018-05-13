// AttributeDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Drawing.h"
#include "AttributeDialog.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;

// AttributeDialog �Ի���

IMPLEMENT_DYNAMIC(AttributeDialog, CDialogEx)

AttributeDialog::AttributeDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(AttributeDialog::IDD, pParent)
	, orgX(0)
	, orgY(0)
	, width(200)
	, height(100)
	, textContent(_T(""))
	, textAngle(0)
	, borderWidth(10)
{

}

AttributeDialog::~AttributeDialog()
{
}

void AttributeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SHAPE_TYPE, shapeType);
	DDX_Text(pDX, IDC_EDIT_X, orgX);
	DDX_Text(pDX, IDC_EDIT_Y, orgY);
	DDX_Text(pDX, IDC_EDIT_WIDTH, width);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, height);
	DDX_Text(pDX, IDC_EDIT_TEXT, textContent);
	DDX_Text(pDX, IDC_EDIT_TEXT_ANGLE, textAngle);
	DDX_Text(pDX, IDC_EDIT_LINE_WIDTH, borderWidth);
	DDX_Control(pDX, IDC_LIST_BORDER_TYPE, borderType);
	DDX_Control(pDX, IDC_LIST_FILL_TYPE, fillType);
	DDX_Text(pDX, IDC_BUTTON_BORDER_COLOR, borderColor);
	DDX_Text(pDX, IDC_BUTTON_FILL_COLOR, fillColor);
	DDX_Control(pDX, IDC_BUTTON_BORDER_COLOR, borderColorButton);
	DDX_Control(pDX, IDC_BUTTON_FILL_COLOR, fillColorButton);
}


BEGIN_MESSAGE_MAP(AttributeDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_SHAPE_TYPE, &AttributeDialog::OnCbnSelchangeComboShapeType)
	ON_BN_CLICKED(IDOK, &AttributeDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCLE, &AttributeDialog::OnBnClickedCancle)
END_MESSAGE_MAP()


// AttributeDialog ��Ϣ�������


BOOL AttributeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	// ��ʼ�������б��е�����
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_SHAPE_TYPE);
	pComboBox->InsertString(0, L"������");
	pComboBox->InsertString(1, L"����");
	pComboBox->InsertString(2, L"Բ��");
	pComboBox->InsertString(3, L"��Բ��");
	pComboBox->InsertString(4, L"��������");
	pComboBox->InsertString(5, L"�ı�");
	pComboBox->SetCurSel(0); // ����һ����ΪĬ��ѡ��


	// ��ʼ���б���е�����
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_BORDER_TYPE);
	pListBox->InsertString(0, L"SOLID");
	pListBox->InsertString(1, L"DASH");
	pListBox->InsertString(2, L"DASHDOT");
	pListBox->SetCurSel(0);

	pListBox = (CListBox*)GetDlgItem(IDC_LIST_FILL_TYPE);
	pListBox->InsertString(0, L"SOLID");
	pListBox->InsertString(1, L"BDIALOGAL");
	pListBox->InsertString(2, L"CROSS");
	pListBox->SetCurSel(0);

	// �����ı��������ı��Ƕȿ�
	CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT);
	pStatic->ShowWindow(SW_HIDE);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT);
	pEdit->ShowWindow(SW_HIDE);

	pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT_ANGLE);
	pStatic->ShowWindow(SW_HIDE);
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT_ANGLE);
	pEdit->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

// �����������Ϣ�Ĵ�����
void AttributeDialog::OnCbnSelchangeComboShapeType()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = shapeType.GetCurSel(); // �����û�ѡ���������
	if (index == 5)
	{
		// ��ʾ�ı��������ı��Ƕȿ�
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT);
		pStatic->ShowWindow(SW_SHOW);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT);
		pEdit->ShowWindow(SW_SHOW);

		pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT_ANGLE);
		pStatic->ShowWindow(SW_SHOW);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT_ANGLE);
		pEdit->ShowWindow(SW_SHOW);
	}
}


void AttributeDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	comboxIndex = shapeType.GetCurSel(); // ��ȡͼ������ѡ��ֵ
	borderTypeIndex = borderType.GetCurSel(); // ��ȡ�߿�����ѡ��ֵ
	filltypeIndex = fillType.GetCurSel(); //��ȡ�������ѡ��ֵ
	borderColor = borderColorButton.GetColor(); // ��ȡ�߿���ɫֵ
	fillColor = fillColorButton.GetColor(); // ��ȡ�����ɫֵ
}


void AttributeDialog::OnBnClickedCancle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}
