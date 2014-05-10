// Artist3DDlg.h : ͷ�ļ�
//

#pragma once

#ifndef HJQ_UPPER
#define HJQ_UPPER 500
#endif
#include "Elements.h"
#include "CompatibleFile.h"
#include <float.h>
#include <cmath>
using namespace std;

// CArtist3DDlg �Ի���
class CArtist3DDlg : public CDialog
{
// ����
public:
	CArtist3DDlg(CWnd* pParent = NULL);		// ��׼���캯��
	CString LastPath;

	AET aet;
	double DistanceBetween(CPoint p1, CPoint p2);
	shape* CopyShape(shape s);
	void ClearShape();
	void SingleBuffer();

	void DrawImage(CDC& dc);
	bool CopyBitmap( const CBitmap &bmpSrc, CBitmap &bmpDest );
	CBitmap* GetBitmap(CDC& dc, int x1, int y1, int x2, int y2);
	void ReleaseBitmap(CBitmap* bitmap);

	// ����
	double xRota, yRota, zRota;
	int MaxRota;

	double IaR, IaG, IaB;
	double IpR, IpG, IpB;

	double KaR, KaG, KaB;
	double KdR, KdG, KdB;
	double KsR, KsG, KsB;

	double Lx, Ly, Lz;
	double Hx, Hy, Hz;
	int HolyN;


// �Ի�������
	enum { IDD = IDD_ARTIST3D_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	// additional data
	shape s;
	int version;
	// additional functions
	void ReadInFile(CString path);
	void OnBnClickedButtonZbuffer();
	void AdjustLxyz();
	void AdjustHxyz();
	void Prehandle(shape* s);
	void PrehandleElement_1(shape* s);
	void PrehandleElement_2(shape* s);
	void PrehandleElement_3(shape* s);
	
	byte PhongR(double para1, double para2);
	byte PhongG(double para1, double para2);
	byte PhongB(double para1, double para2);

	COLORREF** CB;

	int pattern;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonBrowse();
	afx_msg void OnNMCustomdrawSliderXrota(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderYrota(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderZrota(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonShow();
	afx_msg void OnNMCustomdrawSliderIar(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderIag(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderIab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderIpr(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderIpg(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderIpb(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderKar(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderKag(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderKab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderKdr(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderKdg(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderKdb(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderLx(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderLy(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderLz(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderHx(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderHy(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderHz(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderHolyn(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadioSimple();
	afx_msg void OnBnClickedRadioColor();
	afx_msg void OnBnClickedRadioVector();
};
