// Artist3DDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Artist3D.h"
#include "Artist3DDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CArtist3DDlg 对话框




CArtist3DDlg::CArtist3DDlg(CWnd* pParent /*=NULL*/)
: CDialog(CArtist3DDlg::IDD, pParent)
{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CArtist3DDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CArtist3DDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	//ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, &CArtist3DDlg::OnBnClickedButtonBrowse)
	ON_BN_CLICKED(IDC_BUTTON_FACEHIDDEN, &CArtist3DDlg::OnBnClickedButtonShow)

	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_XROTA, &CArtist3DDlg::OnNMCustomdrawSliderXrota)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_YROTA, &CArtist3DDlg::OnNMCustomdrawSliderYrota)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_ZROTA, &CArtist3DDlg::OnNMCustomdrawSliderZrota)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_IAR, &CArtist3DDlg::OnNMCustomdrawSliderIar)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_IAG, &CArtist3DDlg::OnNMCustomdrawSliderIag)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_IAB, &CArtist3DDlg::OnNMCustomdrawSliderIab)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_IPR, &CArtist3DDlg::OnNMCustomdrawSliderIpr)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_IPG, &CArtist3DDlg::OnNMCustomdrawSliderIpg)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_IPB, &CArtist3DDlg::OnNMCustomdrawSliderIpb)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_KAR, &CArtist3DDlg::OnNMCustomdrawSliderKar)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_KAG, &CArtist3DDlg::OnNMCustomdrawSliderKag)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_KAB, &CArtist3DDlg::OnNMCustomdrawSliderKab)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_KDR, &CArtist3DDlg::OnNMCustomdrawSliderKdr)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_KDG, &CArtist3DDlg::OnNMCustomdrawSliderKdg)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_KDB, &CArtist3DDlg::OnNMCustomdrawSliderKdb)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_LX, &CArtist3DDlg::OnNMCustomdrawSliderLx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_LY, &CArtist3DDlg::OnNMCustomdrawSliderLy)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_LZ, &CArtist3DDlg::OnNMCustomdrawSliderLz)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_HX, &CArtist3DDlg::OnNMCustomdrawSliderHx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_HY, &CArtist3DDlg::OnNMCustomdrawSliderHy)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_HZ, &CArtist3DDlg::OnNMCustomdrawSliderHz)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_HOLYN, &CArtist3DDlg::OnNMCustomdrawSliderHolyn)
	ON_BN_CLICKED(IDC_RADIO_SIMPLE, &CArtist3DDlg::OnBnClickedRadioSimple)
	ON_BN_CLICKED(IDC_RADIO_COLOR, &CArtist3DDlg::OnBnClickedRadioColor)
	ON_BN_CLICKED(IDC_RADIO_VECTOR, &CArtist3DDlg::OnBnClickedRadioVector)
END_MESSAGE_MAP()


// CArtist3DDlg 消息处理程序

BOOL CArtist3DDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 初始化参数及控制控件
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_XROTA))->SetRange(-180, 180, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_YROTA))->SetRange(-180, 180, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_ZROTA))->SetRange(-180, 180, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_XROTA))->SetPos(0);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_YROTA))->SetPos(0);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_ZROTA))->SetPos(0);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IAR))->SetRange(0, 255, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IAG))->SetRange(0, 255, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IAB))->SetRange(0, 255, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IAR))->SetPos(0);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IAG))->SetPos(0);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IAB))->SetPos(0);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IPR))->SetRange(0, 255, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IPG))->SetRange(0, 255, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IPB))->SetRange(0, 255, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IPR))->SetPos(0);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IPG))->SetPos(0);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_IPB))->SetPos(0);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KAR))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KAG))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KAB))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KAR))->SetPos(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KAG))->SetPos(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KAB))->SetPos(1);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KDR))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KDG))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KDB))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KDR))->SetPos(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KDG))->SetPos(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_KDB))->SetPos(1);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_LX))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_LY))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_LZ))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_LX))->SetPos(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_LY))->SetPos(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_LZ))->SetPos(1);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HX))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HY))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HZ))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HX))->SetPos(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HY))->SetPos(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HZ))->SetPos(1);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HOLYN))->SetRange(1, 1000, TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HOLYN))->SetPos(1);

	((CButton*)GetDlgItem(IDC_RADIO_SIMPLE))->SetCheck(TRUE);

	xRota = yRota = zRota = 0.0;
	MaxRota = 180;
	pattern = 0;
	HolyN = 1;

	CB = new COLORREF*[HJQ_UPPER + 1];
	for(int i = 0; i <= HJQ_UPPER; i++)
		CB[i] = new COLORREF[HJQ_UPPER + 1];

	LastPath = "";

	return TRUE;		// 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
// 来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
// 这将由框架自动完成。

void CArtist3DDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

			CRect ClientRect;
			CPaintDC dc(this);
			GetClientRect(ClientRect);

			CDC memDC;
			memDC.CreateCompatibleDC(&dc);

			CBitmap memBitmap, *oldmemBitmap;
			CBitmap* BackupCanvas = GetBitmap(dc , 0, 0, ClientRect.Width(), ClientRect.Height());
			CopyBitmap(*BackupCanvas, memBitmap);
			ReleaseBitmap(BackupCanvas);
			oldmemBitmap = memDC.SelectObject(&memBitmap);

			DrawImage(memDC);

			BitBlt(dc, 0, 0, ClientRect.Width(), ClientRect.Height(), memDC, 0, 0, SRCCOPY);

			memDC.SelectObject(oldmemBitmap);

		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。

// 位图相关
bool CArtist3DDlg::CopyBitmap(const CBitmap &bmpSrc, CBitmap &bmpDest )
{
	bool bResult = false;
	BITMAP bm;

	// Attempt to retrieve the existing bitmap structure.
	if ( 0 == bmpSrc.GetObject( sizeof(BITMAP), &bm ) )
	{
		return bResult;
	}

	// Get a handle to the current device context.
	HDC hDC = ::GetDC( NULL );

	// Prepare a new bitmap info structure.
	// Note this function allocates the memory for the structure,
	// so make sure that the memory gets freed.
	BITMAPINFO *pBmpInfo = new BITMAPINFO;
	::ZeroMemory( pBmpInfo, sizeof(BITMAPINFO) );

	pBmpInfo->bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
	pBmpInfo->bmiHeader.biWidth        = bm.bmWidth;
	pBmpInfo->bmiHeader.biHeight    = bm.bmHeight ;
	pBmpInfo->bmiHeader.biPlanes    = 1;
	pBmpInfo->bmiHeader.biBitCount    = 24;

	// This calculation was taken from Ivaylo Byalkov's article about smooth bitmap scaling.
	pBmpInfo->bmiHeader.biSizeImage    = ((3 * bm.bmWidth + 3) & ~3) * bm.bmHeight;

	// Don't try to use a NULL pointer.
	if ( NULL != pBmpInfo )
	{
		// Allocate a buffer to store the device independent bits from the source bitmap.
		BYTE *pData = new BYTE[pBmpInfo->bmiHeader.biSizeImage];

		if ( NULL != pData )
		{
			// Get the device independent bits from the source bitmap.
			::GetDIBits( hDC, (HBITMAP)bmpSrc, 0, bm.bmHeight, pData, pBmpInfo, DIB_RGB_COLORS );

			// Make sure that the destination bitmap is empty.
			bmpDest.DeleteObject();

			// Create a temporary bitmap handle with the same dimensions of the source bitmap.
			HBITMAP hTmpBmp = ::CreateCompatibleBitmap( hDC, bm.bmWidth, bm.bmHeight );

			// Set the device independent bits from the source bitmap into the temporary bitmap handle.
			::SetDIBits( hDC, hTmpBmp, 0, bm.bmHeight, pData, pBmpInfo, DIB_RGB_COLORS );

			// Detach the old bitmap.
			bmpDest.Detach();

			// Attach the temporary bitmap handle to the destination bitmap.
			bmpDest.Attach( hTmpBmp );

			// Set the dimensions of the bitmap so that they can be used later.
			// Otherwise, they will be invalid.
			bmpDest.SetBitmapDimension( bm.bmWidth, bm.bmHeight );

			// Free the buffer used to store the bits.
			delete [] pData;

			// The bitmap was successfully copied.
			bResult = true;
		}

		// Free the memory for the bitmap info structure.
		delete pBmpInfo;
	}

	// Release the device context.
	::ReleaseDC( NULL, hDC );

	return bResult;
}
CBitmap* CArtist3DDlg::GetBitmap(CDC& dc, int x1, int y1, int x2, int y2)
{
	CDC memDC;//内存DC
	memDC.CreateCompatibleDC(&dc);

	CBitmap *memBitmap, *oldmemBitmap;
	memBitmap = new CBitmap();
	memBitmap->CreateCompatibleBitmap(&dc, x2 - x1, y2 - y1);

	oldmemBitmap = memDC.SelectObject(memBitmap);
	memDC.BitBlt(0, 0, x2 - x1, y2 - y1, &dc, x1, y1, SRCCOPY);
	memDC.SelectObject(oldmemBitmap);

	return memBitmap;
}

void CArtist3DDlg::ReleaseBitmap(CBitmap* bitmap)
{
	delete bitmap;
}

// 复制图形
shape* CArtist3DDlg::CopyShape(shape s)
{
	shape* res = new shape;
	res->faceAmount = s.faceAmount;
	res->pointAmount = s.pointAmount;
	res->faces = new face[res->faceAmount];
	res->points = new point[res->pointAmount];

	res->minx = res->miny = res->minz = DBL_MAX;
	res->maxx = res->maxy = res->maxz = -DBL_MAX;
	for(int i = 0; i < res->pointAmount; i++)
	{
		double newx[3], newy[3], newz[3];
		//===
		newx[0] = s.points[i].x * cos(zRota) - s.points[i].y * sin(zRota);
		newy[0] = s.points[i].x * sin(zRota) + s.points[i].y * cos(zRota);
		newz[0] = s.points[i].z;

		newx[1] = newx[0] * cos(yRota) + newz[0] * sin(yRota);
		newy[1] = newy[0];
		newz[1] = -newx[0] * sin(yRota) + newz[0] * cos(yRota);

		newx[2] = newx[1];
		newy[2] = newy[1] * cos(xRota) + newz[1] * sin(xRota);
		newz[2] = newy[1] * sin(xRota) + newz[1] * cos(xRota);
		//===

		res->points[i].x = newx[2];
		res->points[i].y = newy[2];
		res->points[i].z = newz[2];

		res->points[i].IR = s.points[i].IR;
		res->points[i].IG = s.points[i].IG;
		res->points[i].IB = s.points[i].IB;

		//===
		newx[0] = s.points[i].nx * cos(zRota) - s.points[i].ny * sin(zRota);
		newy[0] = s.points[i].nx * sin(zRota) + s.points[i].ny * cos(zRota);
		newz[0] = s.points[i].nz;

		newx[1] = newx[0] * cos(yRota) + newz[0] * sin(yRota);
		newy[1] = newy[0];
		newz[1] = -newx[0] * sin(yRota) + newz[0] * cos(yRota);

		newx[2] = newx[1];
		newy[2] = newy[1] * cos(xRota) + newz[1] * sin(xRota);
		newz[2] = newy[1] * sin(xRota) + newz[1] * cos(xRota);
		//===

		res->points[i].nx = newx[2];
		res->points[i].ny = newy[2];
		res->points[i].nz = newz[2];

		if(res->points[i].x < res->minx) res->minx = res->points[i].x;
		if(res->points[i].y < res->miny) res->miny = res->points[i].y;
		if(res->points[i].z < res->minz) res->minz = res->points[i].z;

		if(res->points[i].x > res->maxx) res->maxx = res->points[i].x;
		if(res->points[i].y > res->maxy) res->maxy = res->points[i].y;
		if(res->points[i].z > res->maxz) res->maxz = res->points[i].z;

	}
	for (int i = 0; i < res->faceAmount; i++)
	{
		res->faces[i].maxx = s.faces[i].maxx;
		res->faces[i].maxy = s.faces[i].maxy;
		res->faces[i].maxz = s.faces[i].maxz;
		res->faces[i].minx = s.faces[i].minx;
		res->faces[i].miny = s.faces[i].miny;
		res->faces[i].minz = s.faces[i].minz;

		res->faces[i].p1 = s.faces[i].p1;
		res->faces[i].p2 = s.faces[i].p2;
		res->faces[i].p3 = s.faces[i].p3;

		res->faces[i].r = s.faces[i].r;
		res->faces[i].g = s.faces[i].g;
		res->faces[i].b = s.faces[i].b;

		res->faces[i].minx = res->faces[i].miny = res->faces[i].minz = DBL_MAX;
		res->faces[i].maxx = res->faces[i].maxy = res->faces[i].maxz = -DBL_MAX;
		if(res->points[res->faces[i].p1].x < res->faces[i].minx) res->faces[i].minx = res->points[res->faces[i].p1].x;
		if(res->points[res->faces[i].p2].x < res->faces[i].minx) res->faces[i].minx = res->points[res->faces[i].p2].x;
		if(res->points[res->faces[i].p3].x < res->faces[i].minx) res->faces[i].minx = res->points[res->faces[i].p3].x;
		if(res->points[res->faces[i].p1].y < res->faces[i].miny) res->faces[i].miny = res->points[res->faces[i].p1].y;
		if(res->points[res->faces[i].p2].y < res->faces[i].miny) res->faces[i].miny = res->points[res->faces[i].p2].y;
		if(res->points[res->faces[i].p3].y < res->faces[i].miny) res->faces[i].miny = res->points[res->faces[i].p3].y;
		if(res->points[res->faces[i].p1].z < res->faces[i].minz) res->faces[i].minz = res->points[res->faces[i].p1].z;
		if(res->points[res->faces[i].p2].z < res->faces[i].minz) res->faces[i].minz = res->points[res->faces[i].p2].z;
		if(res->points[res->faces[i].p3].z < res->faces[i].minz) res->faces[i].minz = res->points[res->faces[i].p3].z;

		if(res->points[res->faces[i].p1].x > res->faces[i].maxx) res->faces[i].maxx = res->points[res->faces[i].p1].x;
		if(res->points[res->faces[i].p2].x > res->faces[i].maxx) res->faces[i].maxx = res->points[res->faces[i].p2].x;
		if(res->points[res->faces[i].p3].x > res->faces[i].maxx) res->faces[i].maxx = res->points[res->faces[i].p3].x;
		if(res->points[res->faces[i].p1].y > res->faces[i].maxy) res->faces[i].maxy = res->points[res->faces[i].p1].y;
		if(res->points[res->faces[i].p2].y > res->faces[i].maxy) res->faces[i].maxy = res->points[res->faces[i].p2].y;
		if(res->points[res->faces[i].p3].y > res->faces[i].maxy) res->faces[i].maxy = res->points[res->faces[i].p3].y;
		if(res->points[res->faces[i].p1].z > res->faces[i].maxz) res->faces[i].maxz = res->points[res->faces[i].p1].z;
		if(res->points[res->faces[i].p2].z > res->faces[i].maxz) res->faces[i].maxz = res->points[res->faces[i].p2].z;
		if(res->points[res->faces[i].p3].z > res->faces[i].maxz) res->faces[i].maxz = res->points[res->faces[i].p3].z;

		res->faces[i].et.SetSize(s.faces[i].et.GetSize());
		for(int j = 0; j < res->faces[i].et.GetSize(); j++)
		{
			res->faces[i].et.SetAt(j, s.faces[i].et.GetAt(j));
		}
	}
	return res;
}
// 清除图形
void CArtist3DDlg::ClearShape()
{
	for(int i = 0; i < s.faceAmount; i++)
	{
		ET* et = &(s.faces[i].et);

		for(int j = et->GetCount() - 1; j >=0; j--)
		{
			CList<ETElement*>* ete = et->GetAt(j);
			for(int k = ete->GetCount() - 1; k >= 0; k--)
			{
				delete ete->GetAt(ete->FindIndex(k));
				ete->RemoveAt(ete->FindIndex(k));
			}
			delete ete;
			et->RemoveAt(j);
		}
	}
	s.faceAmount = 0;
	s.pointAmount = 0;
}
//
void CArtist3DDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ClearShape();
	delete[] s.faces;
	delete[] s.points;
	for(int i = 0; i <= HJQ_UPPER; i++)
		delete[] CB[i];
	
	delete[] CB;

	CDialog::OnClose();
}

HCURSOR CArtist3DDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CArtist3DDlg::ReadInFile(CString path)
{
	ClearShape();
	CompatibleFile file(path);
	CString line;

	line = file.ReadLine(); // 读入版本信息
	line = line.Mid(line.FindOneOf(" ") + 1).Trim();
	if(line == "1.0")
	{
		version = 0;
	}else if(line == "1.1")
	{
		version = 1;
	}
	line = file.ReadLine(); // 读入顶点数
	s.pointAmount = atoi(line.Mid(line.FindOneOf(" ") + 1).Trim());
	line = file.ReadLine(); // 读入平面数
	s.faceAmount = atoi(line.Mid(line.FindOneOf(" ") + 1).Trim());

	if(s.points)
		delete[] s.points;
	if(s.faces)
		delete[] s.faces;
	s.points = new point[s.pointAmount];
	s.faces = new face[s.faceAmount];
	s.maxx = s.maxy = s.maxz = -DBL_MAX;
	s.minx = s.miny = s.minz = DBL_MAX;
	for(int i = 0; i < s.faceAmount; i++)
	{
		s.faces[i].minx = s.faces[i].miny = s.faces[i].minz = DBL_MAX;
		s.faces[i].maxx = s.faces[i].maxy = s.faces[i].maxz = -DBL_MAX;
	}

	long pointi = 0;
	long facei = 0;

	while(!file.IsEOF())
	{
		line = file.ReadLine();
		line = line.Trim();
		if(line.IsEmpty())
			continue;

		switch (line[0])
		{
		case 'v':
			{
				line = line.Mid(line.FindOneOf(" ")).Trim();
				s.points[pointi].x = atof(line.Mid(0, line.FindOneOf(" ")).Trim());
				line = line.Mid(line.FindOneOf(" ")).Trim();
				s.points[pointi].y = atof(line.Mid(0, line.FindOneOf(" ")).Trim());
				line = line.Mid(line.FindOneOf(" ")).Trim();
				s.points[pointi].z = atof(line.Trim());

				pointi++;
			}
			break;
		case 'f':
			{
				line = line.Mid(line.FindOneOf(" ")).Trim();
				s.faces[facei].p1 = atoi(line.Mid(0, line.FindOneOf(" ")).Trim());
				line = line.Mid(line.FindOneOf(" ")).Trim();
				s.faces[facei].p2 = atoi(line.Mid(0, line.FindOneOf(" ")).Trim());
				line = line.Mid(line.FindOneOf(" ")).Trim();
				s.faces[facei].p3 = atoi(line.Trim());

				if(version == 1)
				{
					s.faces[facei].p1--;
					s.faces[facei].p2--;
					s.faces[facei].p3--;
				}

				s.faces[facei].et.SetSize(HJQ_UPPER + 1);
				for(int i = 0; i <= HJQ_UPPER; i++)
				{
					s.faces[facei].et.SetAt(i, new CList<ETElement*>);
					s.faces[facei].et.GetAt(i)->RemoveAll();
				}

				s.faces[facei].r = rand() % 256;
				s.faces[facei].g = rand() % 256;
				s.faces[facei].b = rand() % 256;

				facei++;
			}
			break;
		default:
			break;
		}
	}
	file.Close();
}

void CArtist3DDlg::OnBnClickedButtonBrowse()
{	
	CFileDialog cfd(TRUE);
	if(cfd.DoModal()==IDOK) 
	{
		SetDlgItemText(IDC_EDIT_PATH, cfd.GetPathName());
	}
}

void CArtist3DDlg::OnBnClickedButtonShow()
{
	// TODO: 在此添加控件通知处理程序代码
	CString path;
	GetDlgItemText(IDC_EDIT_PATH, path);
	if(path != LastPath)
		ReadInFile(path);
	OnBnClickedButtonZbuffer();
}


double CArtist3DDlg::DistanceBetween(CPoint p1, CPoint p2)
{
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;
	return sqrt(0.0f + dx * dx + dy * dy);
}


// 参数修改
void CArtist3DDlg::OnNMCustomdrawSliderXrota(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_XROTA));
	int pos = pSlider->GetPos();
	xRota = pos;
	xRota = xRota * 3.14159265359 / 180;

	*pResult = 0;
}
void CArtist3DDlg::OnNMCustomdrawSliderYrota(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_YROTA));
	int pos = pSlider->GetPos();
	yRota = yRota * 3.14159265359 / 180;

	*pResult = 0;
}
void CArtist3DDlg::OnNMCustomdrawSliderZrota(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_ZROTA));
	int pos = pSlider->GetPos();
	zRota = pos;
	zRota = zRota * 3.14159265359 / 180;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderIar(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_IAR));
	int pos = pSlider->GetPos();
	IaR = pos;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderIag(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_IAG));
	int pos = pSlider->GetPos();
	IaG = pos;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderIab(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_IAB));
	int pos = pSlider->GetPos();
	IaB = pos;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderIpr(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_IPR));
	int pos = pSlider->GetPos();
	IpR = pos;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderIpg(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_IPG));
	int pos = pSlider->GetPos();
	IpG = pos;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderIpb(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_IPB));
	int pos = pSlider->GetPos();
	IpB = pos;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderKar(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider1 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAR));
	CSliderCtrl* pSlider2 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAG));
	CSliderCtrl* pSlider3 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAB));
	int pos1 = pSlider1->GetPos();
	int pos2 = pSlider2->GetPos();
	int pos3 = pSlider3->GetPos();
	double total = pos1 + pos2 + pos3;

	KaR = pos1 / total;
	KaG = pos2 / total;
	KaB = pos3 / total;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderKag(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider1 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAR));
	CSliderCtrl* pSlider2 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAG));
	CSliderCtrl* pSlider3 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAB));
	int pos1 = pSlider1->GetPos();
	int pos2 = pSlider2->GetPos();
	int pos3 = pSlider3->GetPos();
	double total = pos1 + pos2 + pos3;

	KaR = pos1 / total;
	KaG = pos2 / total;
	KaB = pos3 / total;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderKab(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider1 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAR));
	CSliderCtrl* pSlider2 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAG));
	CSliderCtrl* pSlider3 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KAB));
	int pos1 = pSlider1->GetPos();
	int pos2 = pSlider2->GetPos();
	int pos3 = pSlider3->GetPos();
	double total = pos1 + pos2 + pos3;

	KaR = pos1 / total;
	KaG = pos2 / total;
	KaB = pos3 / total;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderKdr(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider1 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDR));
	CSliderCtrl* pSlider2 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDG));
	CSliderCtrl* pSlider3 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDB));
	int pos1 = pSlider1->GetPos();
	int pos2 = pSlider2->GetPos();
	int pos3 = pSlider3->GetPos();
	double total = pos1 + pos2 + pos3;

	KdR = pos1 / total;
	KdG = pos2 / total;
	KdB = pos3 / total;

	KsR = (1 - KdR) / 2;
	KsG = (1 - KdG) / 2;
	KsB = (1 - KdB) / 2;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderKdg(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider1 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDR));
	CSliderCtrl* pSlider2 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDG));
	CSliderCtrl* pSlider3 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDB));
	int pos1 = pSlider1->GetPos();
	int pos2 = pSlider2->GetPos();
	int pos3 = pSlider3->GetPos();
	double total = pos1 + pos2 + pos3;

	KdR = pos1 / total;
	KdG = pos2 / total;
	KdB = pos3 / total;

	KsR = (1 - KdR) / 2;
	KsG = (1 - KdG) / 2;
	KsB = (1 - KdB) / 2;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderKdb(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider1 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDR));
	CSliderCtrl* pSlider2 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDG));
	CSliderCtrl* pSlider3 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_KDB));
	int pos1 = pSlider1->GetPos();
	int pos2 = pSlider2->GetPos();
	int pos3 = pSlider3->GetPos();
	double total = pos1 + pos2 + pos3;

	KdR = pos1 / total;
	KdG = pos2 / total;
	KdB = pos3 / total;

	KsR = (1 - KdR) / 2;
	KsG = (1 - KdG) / 2;
	KsB = (1 - KdB) / 2;

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderLx(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	AdjustLxyz();

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderLy(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	AdjustLxyz();

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderLz(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	AdjustLxyz();

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderHx(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	AdjustHxyz();

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderHy(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	AdjustHxyz();

	*pResult = 0;
}

void CArtist3DDlg::OnNMCustomdrawSliderHz(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	AdjustHxyz();

	*pResult = 0;
}
void CArtist3DDlg::OnNMCustomdrawSliderHolyn(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlider = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_HOLYN));
	HolyN = pSlider->GetPos();

	*pResult = 0;
}
void CArtist3DDlg::OnBnClickedRadioSimple()
{
	// TODO: 在此添加控件通知处理程序代码
	pattern = 0;
}

void CArtist3DDlg::OnBnClickedRadioColor()
{
	// TODO: 在此添加控件通知处理程序代码
	pattern = 1;
}

void CArtist3DDlg::OnBnClickedRadioVector()
{
	// TODO: 在此添加控件通知处理程序代码
	pattern = 2;
}

// 
void CArtist3DDlg::OnBnClickedButtonZbuffer()
{
	SingleBuffer();
	CRect rect(20, 20, 20 + HJQ_UPPER, 20 + HJQ_UPPER);
	InvalidateRect(rect, FALSE);
}
void CArtist3DDlg::DrawImage(CDC& dc)
{
	int x0 = 20, y0 = 20;
	for(int i = 0; i <= HJQ_UPPER; i++)
	{
		for(int j = 0; j <= HJQ_UPPER; j++)
		{
			dc.SetPixel(CPoint(x0 + i, y0 + j), CB[i][j]);
		}
	}
}


void CArtist3DDlg::SingleBuffer()
{
	shape* ss = CopyShape(s);
// 恶搞s for z-buffer
	double xscale = HJQ_UPPER / (ss->maxx - ss->minx) * 1;
	double yscale = HJQ_UPPER / (ss->maxy - ss->miny) * 1;
	double scale = xscale > yscale ? yscale : xscale;
	for(int i = 0; i < ss->pointAmount; i++)
	{
		ss->points[i].x = (ss->points[i].x - ss->minx) * scale;
		ss->points[i].y = (ss->points[i].y - ss->miny) * scale;
		ss->points[i].z = (ss->points[i].z - ss->minz) * scale;
		ss->points[i].x = (int)(ss->points[i].x + 0.5);
		ss->points[i].y = (int)(ss->points[i].y + 0.5);
		ss->points[i].z = (int)(ss->points[i].z + 0.5);
	}
	for(int i = 0; i < ss->faceAmount; i++)
	{
		ss->faces[i].minx = (ss->faces[i].minx - ss->minx) * scale;
		ss->faces[i].miny = (ss->faces[i].miny - ss->miny) * scale;
		ss->faces[i].minz = (ss->faces[i].minz - ss->minz) * scale;
		ss->faces[i].maxx = (ss->faces[i].maxx - ss->minx) * scale;
		ss->faces[i].maxy = (ss->faces[i].maxy - ss->miny) * scale;
		ss->faces[i].maxz = (ss->faces[i].maxz - ss->minz) * scale;

		ss->faces[i].minx = (int)(ss->faces[i].minx + 0.5);
		ss->faces[i].miny = (int)(ss->faces[i].miny + 0.5);
		ss->faces[i].minz = (int)(ss->faces[i].minz + 0.5);
		ss->faces[i].maxx = (int)(ss->faces[i].maxx + 0.5);
		ss->faces[i].maxy = (int)(ss->faces[i].maxy + 0.5);
		ss->faces[i].maxz = (int)(ss->faces[i].maxz + 0.5);
	}
	ss->minx = (ss->minx - ss->minx) * scale;
	ss->miny = (ss->miny - ss->miny) * scale;
	ss->minz = (ss->miny - ss->minz) * scale;
	ss->maxx = (ss->maxx - ss->minx) * scale;
	ss->maxy = (ss->maxy - ss->miny) * scale;
	ss->maxz = (ss->maxy - ss->minz) * scale;
	ss->minx = (int)(ss->minx + 0.5);
	ss->miny = (int)(ss->miny + 0.5);
	ss->minz = (int)(ss->minz + 0.5);
	ss->maxx = (int)(ss->maxx + 0.5);
	ss->maxy = (int)(ss->maxy + 0.5);
	ss->maxz = (int)(ss->maxz + 0.5);
	Prehandle(ss);

// 	建多边形Y表；对每一个多边形根据顶点最小的y值，将多边形置入多边形Y表。
	CArray<CList<PolygonYListElement*>*> PolygonYList;
	PolygonYList.SetSize(HJQ_UPPER + 1);
	for(int i = 0; i <= HJQ_UPPER; i++)
		PolygonYList.SetAt(i, new CList<PolygonYListElement*>());

	aet.RemoveAll();
	for(int i = 0; i < ss->faceAmount; i++)
	{
		PolygonYListElement* element = new PolygonYListElement;
		element->IP = i;
		element->Ymax = ss->faces[i].maxy;
		PolygonYList[(int)(ss->faces[i].miny + 0.5)]->AddTail(element);
	}
// 	活化多边形表APT，活化边对表AET初始化为空。
	CList<PolygonYListElement*> APT;
	double ZB[HJQ_UPPER + 1];
	APT.RemoveAll();
	aet.RemoveAll();
	// 	for(每条扫描线j，j从小到大)
	// 	{
	for(int j = 0; j <= HJQ_UPPER; j++)
	{
// 		1. 帧缓存CB中相应单元置为背景色。
		for(int k = 0; k <= HJQ_UPPER; k++) CB[j][k] = RGB(0, 0, 0);
// 		2. 深度缓存ZB (一维数组) 置为无穷小。
		for(int k = 0; k < HJQ_UPPER; k++)	ZB[k] = -DBL_MAX;
// 		3. 将对应扫描线j的多边形Y表中的多边形加入到活化多边形表APT中。
		CList<PolygonYListElement*>* HandleList = PolygonYList[j];
		for(int k = 0; k < HandleList->GetCount(); k++)
		{
			PolygonYListElement* polygonInfo = HandleList->GetAt(HandleList->FindIndex(k));
			APT.AddTail(polygonInfo);

// 		4. 对新加入的多边形，生成其相应的边Y表。
			face* f = &(ss->faces[polygonInfo->IP]);
			if(ss->points[f->p1].y > ss->points[f->p2].y)
			{
				ETElement* ete = new ETElement;
				ete->x = ss->points[f->p2].x;
				ete->z = ss->points[f->p2].z;
				ete->dx = (ss->points[f->p1].x - ss->points[f->p2].x) / (ss->points[f->p1].y - ss->points[f->p2].y);
				ete->Ymax = ss->points[f->p1].y;
				f->et[(int)(ss->points[f->p2].y + 0.5)]->AddTail(ete);
			}else
			{
				ETElement* ete = new ETElement;
				ete->x = ss->points[f->p1].x;
				ete->z = ss->points[f->p1].z;
				ete->dx = (ss->points[f->p2].x - ss->points[f->p1].x) / (ss->points[f->p2].y - ss->points[f->p1].y);
				ete->Ymax = ss->points[f->p2].y;
				f->et[(int)(ss->points[f->p1].y + 0.5)]->AddTail(ete);
			}
			if(ss->points[f->p1].y > ss->points[f->p3].y)
			{
				ETElement* ete = new ETElement;
				ete->x = ss->points[f->p3].x;
				ete->z = ss->points[f->p3].z;
				ete->dx = (ss->points[f->p1].x - ss->points[f->p3].x) / (ss->points[f->p1].y - ss->points[f->p3].y);
				ete->Ymax = ss->points[f->p1].y;
				f->et[(int)(ss->points[f->p3].y + 0.5)]->AddTail(ete);
			}else
			{
				ETElement* ete = new ETElement;
				ete->x = ss->points[f->p1].x;
				ete->z = ss->points[f->p1].z;
				ete->dx = (ss->points[f->p3].x - ss->points[f->p1].x) / (ss->points[f->p3].y - ss->points[f->p1].y);
				ete->Ymax = ss->points[f->p3].y;
				f->et[(int)(ss->points[f->p2].y + 0.5)]->AddTail(ete);
			}
			if(ss->points[f->p2].y > ss->points[f->p3].y)
			{
				ETElement* ete = new ETElement;
				ete->x = ss->points[f->p3].x;
				ete->z = ss->points[f->p3].z;
				ete->dx = (ss->points[f->p2].x - ss->points[f->p3].x) / (ss->points[f->p2].y - ss->points[f->p3].y);
				ete->Ymax = ss->points[f->p2].y;
				f->et[(int)(ss->points[f->p3].y + 0.5)]->AddTail(ete);
			}else
			{
				ETElement* ete = new ETElement;
				ete->x = ss->points[f->p2].x;
				ete->z = ss->points[f->p2].z;
				ete->dx = (ss->points[f->p3].x - ss->points[f->p2].x) / (ss->points[f->p3].y - ss->points[f->p2].y);
				ete->Ymax = ss->points[f->p3].y;
				f->et[(int)(ss->points[f->p2].y + 0.5)]->AddTail(ete);
			}
// 		5. 对APT中每一个多边形，若其边Y表中对应扫描线j增加了新的边，将新的边配对，加到活化边对表AET中。
			AETElement* aete = new AETElement;
			{
				long p[3];
				p[0] = f->p1; p[1] = f->p2; p[2] = f->p3;
				// 找出最下坐标
				double miny = ss->points[p[0]].y;
				for(int i = 1; i < 3; i++)
					if(ss->points[p[i]].y < miny)
						miny = ss->points[p[i]].y;

				// 最下坐标有多少个点
				int countminy = 0;
				long hasminy[3];
				for(int i = 0; i < 3; i++)
					if(ss->points[p[i]].y == miny)
						hasminy[countminy++] = i;

				if(countminy == 1)
				{
					long hasleft, hasright;
					int index = hasminy[0];
					long dp1 = p[(index + 1) % 3];
					long dp2 = p[(index + 2) % 3];
					hasminy[0] = p[index];
					if(ss->points[dp1].x == ss->points[hasminy[0]].x)
					{
						if(ss->points[dp2].x < ss->points[hasminy[0]].x)
						{
							hasleft = dp2; hasright = dp1;
						}else
						{
							hasleft = dp1; hasright = dp2;
						}
					}else if(ss->points[dp2].x == ss->points[hasminy[0]].x)
					{
						if(ss->points[dp1].x < ss->points[hasminy[0]].x)
						{
							hasleft = dp1; hasright = dp2;
						}else
						{
							hasleft = dp2; hasright = dp1;
						}
					}else
					{
						double kdp1 = (ss->points[dp1].y - ss->points[hasminy[0]].y) / (ss->points[dp1].x - ss->points[hasminy[0]].x);
						double kdp2 = (ss->points[dp2].y - ss->points[hasminy[0]].y) / (ss->points[dp2].x - ss->points[hasminy[0]].x);
						if(kdp1 < 0 && kdp2 > 0)
						{
							hasleft = dp1; hasright = dp2;
						}else if(kdp2 < 0 && kdp1 > 0)
						{
							hasleft = dp2; hasright = dp1;
						}else
						{
							if(kdp2 > kdp1)
							{
								hasleft = dp2; hasright = dp1;
							}else
							{
								hasleft = dp1; hasright = dp2;
							}
						}
					}

					aete->xl = ss->points[hasminy[0]].x;
					aete->xr = ss->points[hasminy[0]].x;
					aete->ylmax = ss->points[hasleft].y;
					aete->yrmax = ss->points[hasright].y;
					aete->dxl = (ss->points[hasleft].x - ss->points[hasminy[0]].x) / (ss->points[hasleft].y - ss->points[hasminy[0]].y);
					aete->dxr = (ss->points[hasright].x - ss->points[hasminy[0]].x) / (ss->points[hasright].y - ss->points[hasminy[0]].y);
					aete->zl = ss->points[hasminy[0]].z;

					aete->crl = ss->points[hasminy[0]].IR;
					aete->cgl = ss->points[hasminy[0]].IG;
					aete->cbl = ss->points[hasminy[0]].IB;

					aete->nxl = ss->points[hasminy[0]].nx;
					aete->nyl = ss->points[hasminy[0]].ny;
					aete->nzl = ss->points[hasminy[0]].nz;

					aete->IP = polygonInfo->IP;

					// Z
					{
						double vec1[3] = {
							ss->points[hasleft].x - ss->points[hasminy[0]].x,
							ss->points[hasleft].y - ss->points[hasminy[0]].y,
							ss->points[hasleft].z - ss->points[hasminy[0]].z
						}, vec2[3]={
							ss->points[hasright].x - ss->points[hasminy[0]].x,
							ss->points[hasright].y - ss->points[hasminy[0]].y,
							ss->points[hasright].z - ss->points[hasminy[0]].z
						};

						double a = vec1[1] * vec2[2] - vec2[1] * vec1[2];
						double b = vec2[0] * vec1[2] - vec1[0] * vec2[2];
						double c = vec1[0] * vec2[1] - vec2[0] * vec1[1];

						aete->dzx = -a / c;
						aete->dzy = -b / c;
					}

					switch(pattern)
					{
					case 1:
						// R
						{
							double vec1R[3] = {
								ss->points[hasleft].x - ss->points[hasminy[0]].x,
								ss->points[hasleft].y - ss->points[hasminy[0]].y,
								ss->points[hasleft].IR - ss->points[hasminy[0]].IR
							}, vec2R[3]={
								ss->points[hasright].x - ss->points[hasminy[0]].x,
								ss->points[hasright].y - ss->points[hasminy[0]].y,
								ss->points[hasright].IR - ss->points[hasminy[0]].IR
							};

							double aR = vec1R[1] * vec2R[2] - vec2R[1] * vec1R[2];
							double bR = vec2R[0] * vec1R[2] - vec1R[0] * vec2R[2];
							double cR = vec1R[0] * vec2R[1] - vec2R[0] * vec1R[1];
							aete->dcrx = -aR / cR;
							aete->dcry = -bR / cR;
						}

						// G
						{
							double vec1G[3] = {
								ss->points[hasleft].x - ss->points[hasminy[0]].x,
								ss->points[hasleft].y - ss->points[hasminy[0]].y,
								ss->points[hasleft].IG - ss->points[hasminy[0]].IG
							}, vec2G[3]={
								ss->points[hasright].x - ss->points[hasminy[0]].x,
								ss->points[hasright].y - ss->points[hasminy[0]].y,
								ss->points[hasright].IG - ss->points[hasminy[0]].IG
							};

							double aG = vec1G[1] * vec2G[2] - vec2G[1] * vec1G[2];
							double bG = vec2G[0] * vec1G[2] - vec1G[0] * vec2G[2];
							double cG = vec1G[0] * vec2G[1] - vec2G[0] * vec1G[1];
							aete->dcgx = -aG / cG;
							aete->dcgy = -bG / cG;
						}

						// B
						{
							double vec1B[3] = {
								ss->points[hasleft].x - ss->points[hasminy[0]].x,
								ss->points[hasleft].y - ss->points[hasminy[0]].y,
								ss->points[hasleft].IB - ss->points[hasminy[0]].IB
							}, vec2B[3]={
								ss->points[hasright].x - ss->points[hasminy[0]].x,
								ss->points[hasright].y - ss->points[hasminy[0]].y,
								ss->points[hasright].IB - ss->points[hasminy[0]].IB
							};

							double aB = vec1B[1] * vec2B[2] - vec2B[1] * vec1B[2];
							double bB = vec2B[0] * vec1B[2] - vec1B[0] * vec2B[2];
							double cB = vec1B[0] * vec2B[1] - vec2B[0] * vec1B[1];
							aete->dcbx = -aB / cB;
							aete->dcby = -bB / cB;
						}
						break;
					case 2:
						// NX
						{
							double vec1X[3] = {
								ss->points[hasleft].x - ss->points[hasminy[0]].x,
								ss->points[hasleft].y - ss->points[hasminy[0]].y,
								ss->points[hasleft].nx - ss->points[hasminy[0]].nx
							}, vec2X[3]={
								ss->points[hasright].x - ss->points[hasminy[0]].x,
								ss->points[hasright].y - ss->points[hasminy[0]].y,
								ss->points[hasright].nx - ss->points[hasminy[0]].nx
							};

								double aX = vec1X[1] * vec2X[2] - vec2X[1] * vec1X[2];
								double bX = vec2X[0] * vec1X[2] - vec1X[0] * vec2X[2];
								double cX = vec1X[0] * vec2X[1] - vec2X[0] * vec1X[1];
								aete->dnxx = -aX / cX;
								aete->dnxy = -bX / cX;
						}

						// NY
						{
							double vec1Y[3] = {
								ss->points[hasleft].x - ss->points[hasminy[0]].x,
								ss->points[hasleft].y - ss->points[hasminy[0]].y,
								ss->points[hasleft].ny - ss->points[hasminy[0]].ny
							}, vec2Y[3]={
								ss->points[hasright].x - ss->points[hasminy[0]].x,
								ss->points[hasright].y - ss->points[hasminy[0]].y,
								ss->points[hasright].ny - ss->points[hasminy[0]].ny
							};

								double aY = vec1Y[1] * vec2Y[2] - vec2Y[1] * vec1Y[2];
								double bY = vec2Y[0] * vec1Y[2] - vec1Y[0] * vec2Y[2];
								double cY = vec1Y[0] * vec2Y[1] - vec2Y[0] * vec1Y[1];
								aete->dnyx = -aY / cY;
								aete->dnyy = -bY / cY;
						}

						// NZ
						{
							double vec1Z[3] = {
								ss->points[hasleft].x - ss->points[hasminy[0]].x,
								ss->points[hasleft].y - ss->points[hasminy[0]].y,
								ss->points[hasleft].nz - ss->points[hasminy[0]].nz
							}, vec2Z[3]={
								ss->points[hasright].x - ss->points[hasminy[0]].x,
								ss->points[hasright].y - ss->points[hasminy[0]].y,
								ss->points[hasright].nz - ss->points[hasminy[0]].nz
							};

								double aZ = vec1Z[1] * vec2Z[2] - vec2Z[1] * vec1Z[2];
								double bZ = vec2Z[0] * vec1Z[2] - vec1Z[0] * vec2Z[2];
								double cZ = vec1Z[0] * vec2Z[1] - vec2Z[0] * vec1Z[1];
								aete->dnzx = -aZ / cZ;
								aete->dnzy = -bZ / cZ;
						}
						break;
					}

					aete->left = ss->points[hasleft];
					aete->right = ss->points[hasright];
				}else if(countminy == 2)
				{
					long hasleft, hasright;
					hasminy[0] = p[hasminy[0]];
					hasminy[1] = p[hasminy[1]];
					if(ss->points[hasminy[0]].x < ss->points[hasminy[1]].x)
					{
						hasleft = hasminy[0];
						hasright = hasminy[1];
					}else
					{
						hasleft = hasminy[1];
						hasright = hasminy[0];
					}
					long hastop;
					for (int i = 0; i < 3; i++)
						if(p[i] != hasleft && p[i] != hasright)
							hastop = p[i];

					aete->xl = ss->points[hasleft].x;
					aete->xr = ss->points[hasright].x;
					aete->ylmax = ss->points[hastop].y;
					aete->yrmax = ss->points[hastop].y;
					aete->dxl = (ss->points[hastop].x - ss->points[hasleft].x) / (ss->points[hastop].y - ss->points[hasleft].y);
					aete->dxr = (ss->points[hastop].x - ss->points[hasright].x) / (ss->points[hastop].y - ss->points[hasright].y);
					aete->IP = polygonInfo->IP;
					aete->zl = ss->points[hasleft].z;

					aete->crl = ss->points[hasleft].IR;
					aete->cgl = ss->points[hasleft].IG;
					aete->cbl = ss->points[hasleft].IB;

					aete->nxl = ss->points[hasleft].nx;
					aete->nyl = ss->points[hasleft].ny;
					aete->nzl = ss->points[hasleft].nz;

					// Z
					{
						double vec1[3] = {
							ss->points[hasleft].x - ss->points[hastop].x,
							ss->points[hasleft].y - ss->points[hastop].y,
							ss->points[hasleft].z - ss->points[hastop].z}, 
							vec2[3] = {
								ss->points[hasright].x - ss->points[hastop].x,
								ss->points[hasright].y - ss->points[hastop].y,
								ss->points[hasright].z - ss->points[hastop].z};

						double a = vec1[1] * vec2[2] - vec2[1] * vec1[2];
						double b = vec2[0] * vec1[2] - vec1[0] * vec2[2];
						double c = vec1[0] * vec2[1] - vec2[0] * vec1[1];
						aete->dzx = -a / c;
						aete->dzy = -b / c;
					}

					switch(pattern)
					{
					case 1:
						// R
						{
							double vec1R[3] = {
								ss->points[hasleft].x - ss->points[hastop].x,
								ss->points[hasleft].y - ss->points[hastop].y,
								ss->points[hasleft].IR - ss->points[hastop].IR}, 
								vec2R[3] = {
									ss->points[hasright].x - ss->points[hastop].x,
									ss->points[hasright].y - ss->points[hastop].y,
									ss->points[hasright].IR - ss->points[hastop].IR};

							double aR = vec1R[1] * vec2R[2] - vec2R[1] * vec1R[2];
							double bR = vec2R[0] * vec1R[2] - vec1R[0] * vec2R[2];
							double cR = vec1R[0] * vec2R[1] - vec2R[0] * vec1R[1];
							aete->dcrx = -aR / cR;
							aete->dcry = -bR / cR;
						}

						// G
						{
							double vec1G[3] = {
								ss->points[hasleft].x - ss->points[hastop].x,
								ss->points[hasleft].y - ss->points[hastop].y,
								ss->points[hasleft].IG - ss->points[hastop].IG}, 
								vec2G[3] = {
									ss->points[hasright].x - ss->points[hastop].x,
									ss->points[hasright].y - ss->points[hastop].y,
									ss->points[hasright].IG - ss->points[hastop].IG};

							double aG = vec1G[1] * vec2G[2] - vec2G[1] * vec1G[2];
							double bG = vec2G[0] * vec1G[2] - vec1G[0] * vec2G[2];
							double cG = vec1G[0] * vec2G[1] - vec2G[0] * vec1G[1];
							aete->dcgx = -aG / cG;
							aete->dcgy = -bG / cG;
						}

						// B
						{
							double vec1B[3] = {
								ss->points[hasleft].x - ss->points[hastop].x,
								ss->points[hasleft].y - ss->points[hastop].y,
								ss->points[hasleft].IB - ss->points[hastop].IB}, 
								vec2B[3] = {
									ss->points[hasright].x - ss->points[hastop].x,
									ss->points[hasright].y - ss->points[hastop].y,
									ss->points[hasright].IB - ss->points[hastop].IB};

							double aB = vec1B[1] * vec2B[2] - vec2B[1] * vec1B[2];
							double bB = vec2B[0] * vec1B[2] - vec1B[0] * vec2B[2];
							double cB = vec1B[0] * vec2B[1] - vec2B[0] * vec1B[1];
							aete->dcbx = -aB / cB;
							aete->dcby = -bB / cB;
						}
						break;
					case 2:
						// NX
						{
							double vec1X[3] = {
								ss->points[hasleft].x - ss->points[hastop].x,
								ss->points[hasleft].y - ss->points[hastop].y,
								ss->points[hasleft].nx - ss->points[hastop].nx}, 
								vec2X[3] = {
									ss->points[hasright].x - ss->points[hastop].x,
									ss->points[hasright].y - ss->points[hastop].y,
									ss->points[hasright].nx - ss->points[hastop].nx};

							double aX = vec1X[1] * vec2X[2] - vec2X[1] * vec1X[2];
							double bX = vec2X[0] * vec1X[2] - vec1X[0] * vec2X[2];
							double cX = vec1X[0] * vec2X[1] - vec2X[0] * vec1X[1];
							aete->dnxx = -aX / cX;
							aete->dnxy = -bX / cX;
						}

						// NY
						{
							double vec1Y[3] = {
								ss->points[hasleft].x - ss->points[hastop].x,
								ss->points[hasleft].y - ss->points[hastop].y,
								ss->points[hasleft].ny - ss->points[hastop].ny}, 
								vec2Y[3] = {
									ss->points[hasright].x - ss->points[hastop].x,
									ss->points[hasright].y - ss->points[hastop].y,
									ss->points[hasright].ny - ss->points[hastop].ny};

							double aY = vec1Y[1] * vec2Y[2] - vec2Y[1] * vec1Y[2];
							double bY = vec2Y[0] * vec1Y[2] - vec1Y[0] * vec2Y[2];
							double cY = vec1Y[0] * vec2Y[1] - vec2Y[0] * vec1Y[1];
							aete->dnyx = -aY / cY;
							aete->dnyy = -bY / cY;
						}

						// NZ
						{
							double vec1Z[3] = {
								ss->points[hasleft].x - ss->points[hastop].x,
								ss->points[hasleft].y - ss->points[hastop].y,
								ss->points[hasleft].nz - ss->points[hastop].nz}, 
								vec2Z[3] = {
									ss->points[hasright].x - ss->points[hastop].x,
									ss->points[hasright].y - ss->points[hastop].y,
									ss->points[hasright].nz - ss->points[hastop].nz};

							double aZ = vec1Z[1] * vec2Z[2] - vec2Z[1] * vec1Z[2];
							double bZ = vec2Z[0] * vec1Z[2] - vec1Z[0] * vec2Z[2];
							double cZ = vec1Z[0] * vec2Z[1] - vec2Z[0] * vec1Z[1];
							aete->dnzx = -aZ / cZ;
							aete->dnzy = -bZ / cZ;
						}
						break;
					}

				}else
				{
					aete->ylmax = aete->yrmax = j;
					aete->xl = aete->xr = aete->dxl = aete->dxr = 0;
					aete->dzx = aete->dzy = aete->zl = 0;

					aete->dcrx = aete->dcry = aete->crl = 0;
					aete->dcgx = aete->dcgy = aete->cgl = 0;
					aete->dcbx = aete->dcby = aete->cbl = 0;

					aete->dnxx = aete->dnxy = aete->nxl = 0;
					aete->dnyx = aete->dnyy = aete->nyl = 0;
					aete->dnzx = aete->dnzy = aete->nzl= 0;

					aete->IP = polygonInfo->IP;
				}
				aet.AddTail(aete);
			}
		}
// 		6. 对AET中的每一对边：
		for(int k = 0; k < aet.GetCount(); k++)
		{
// 			6.1 对xl < x < xr 的每一个象素，按增量公式z = z+dzx算各点深度depth。
			AETElement* paete = aet.GetAt(aet.FindIndex(k));
			double z = paete->zl;

			double colorR = paete->crl;
			double colorG = paete->cgl;
			double colorB = paete->cbl;

			double holyNx = paete->nxl;
			double holyNy = paete->nyl;
			double holyNz = paete->nzl;

			for(int l = (int)(paete->xl + 0.5); l < (int)(paete->xr + 0.5); l++)
			{
// 			6.2 与ZB中的量比较，depth > ZB(j), 则令ZB(j) =depth，并计算颜色值，写帧缓存。 
				if(z > ZB[l])
				{
					ZB[l] = z;
					switch (pattern)
					{
					case 0:
						CB[j][l] = RGB(ss->faces[paete->IP].r, ss->faces[paete->IP].g, ss->faces[paete->IP].b);
						break;
					case 1:
						CB[j][l] = RGB((byte)(colorR), (byte)(colorG), (byte)(colorB));
						break;
					case 2:
						double para1 = Lx * holyNx + Ly * holyNy + Lz * holyNz;
						double para2 = 1;
						double dpara2 = Hx * holyNx + Hy * holyNy + Hz * holyNz;

						for(int inneri = 0; inneri < HolyN; inneri++)
							para2 *= dpara2;

						colorR = PhongR(para1, para2);
						colorG = PhongG(para1, para2);
						colorB = PhongB(para1, para2);
						CB[j][l] = RGB((byte)(colorR), (byte)(colorG), (byte)(colorB));
						break;
					}
				}
				z += paete->dzx;
				switch (pattern)
				{
				case 1:
					colorR += paete->dcrx;
					colorG += paete->dcgx;
					colorB += paete->dcbx;
					break;
				case 2:
					holyNx += paete->dnxx;
					holyNy += paete->dnyx;
					holyNz += paete->dnzx;
				}
			}
		}

// 		7. 删除APT中多边形顶点最大y坐标为j的多边形，并删除相应的边Y表ET 。
		int* record = new int[APT.GetCount()];
		int recindex = 0;
		for(int k = 0; k < APT.GetCount(); k++)
			if((int)(APT.GetAt(APT.FindIndex(k))->Ymax + 0.5) == j)
				record[recindex++] = k;

		for(int k = recindex - 1; k >= 0; k--)
		{
			APT.RemoveAt(APT.FindIndex(record[k]));
		}

		delete[] record;

// 		8. 对AET中的每一个边对，作如下处理：
		int* toBeDeleted = new int[aet.GetCount()];
		int toBeDeletedCount = 0;
		for(int k = 0; k < aet.GetCount(); k++)
		{
// 			8.1 删除ylmax或yrmax已等于j的边。若一边对中只删除了其中一边，需对该多边形的边重新配对。   
			AETElement* aete = aet.GetAt(aet.FindIndex(k));
			int intYLMax = (int)(aete->ylmax + 0.5), intYRMax = (int)(aete->yrmax + 0.5);
			if ((intYLMax <= j) || (intYRMax <= j))
			{
				if (intYLMax <= j && intYRMax <= j)
				{
					toBeDeleted[toBeDeletedCount++] = k;
				}else
				{
					if(intYLMax <= j)
					{
						aete->dxl = (aete->right.x - aete->left.x) / (aete->right.y - aete->left.y);
						aete->ylmax = aete->yrmax;
					}else
					{
						aete->dxr = (aete->right.x - aete->left.x) / (aete->right.y - aete->left.y);
						aete->ylmax = aete->ylmax;
					}
				}
			}

// 			8.2 用增量公式计算新的xl、xr和zl，更新边对中的信息；
			aete->xl = aete->xl + aete->dxl;
			aete->xr = aete->xr + aete->dxr;
			aete->zl = aete->zl + aete->dzy + aete->dzx * aete->dxl;

			aete->crl = aete->crl + aete->dcry + aete->dcrx * aete->dxl;
			aete->cgl = aete->cgl + aete->dcgy + aete->dcgx * aete->dxl;
			aete->cbl = aete->cbl + aete->dcby + aete->dcbx * aete->dxl;

			aete->nxl = aete->nxl + aete->dnxy + aete->dnxx * aete->dxl;
			aete->nyl = aete->nyl + aete->dnyy + aete->dnyx * aete->dxl;
			aete->nzl = aete->nzl + aete->dnzy + aete->dnzx * aete->dxl;
		}

		for(int i = toBeDeletedCount - 1; i >= 0; i--)
		{
			AETElement* aete = aet.GetAt(aet.FindIndex(toBeDeleted[i]));
			delete aete;
			aet.RemoveAt(aet.FindIndex(toBeDeleted[i]));
		}
		delete[] toBeDeleted;
	}

	// 	}
	// 清理内存	
	for(int i = PolygonYList.GetCount() - 1; i >= 0; i--)
	{
		CList<PolygonYListElement*>* pyle = PolygonYList.GetAt(i);
		for(int j = pyle->GetCount() - 1; j >= 0; j--)
		{
			delete pyle->GetAt(pyle->FindIndex(j));
			pyle->RemoveAt(pyle->FindIndex(j));
		}
		delete pyle;
		PolygonYList.RemoveAt(i);
	}

	for(int i = APT.GetCount() - 1; i >= 0; i--)
	{
		delete APT.GetAt(APT.FindIndex(i));
		APT.RemoveAt(APT.FindIndex(i));
	}
	delete[] ss->faces;
	delete[] ss->points;
	delete ss;
}

void CArtist3DDlg::AdjustLxyz()
{
	CSliderCtrl* pSlider1 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_LX));
	CSliderCtrl* pSlider2 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_LY));
	CSliderCtrl* pSlider3 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_LZ));
	int pos1 = pSlider1->GetPos();
	int pos2 = pSlider2->GetPos();
	int pos3 = pSlider3->GetPos();

	double total = sqrt(pos1 * pos1 + pos2 * pos2 + pos3 * pos3 + 0.0);

	Lx = pos1 / total;
	Ly = pos2 / total;
	Lz = pos3 / total;
}

void CArtist3DDlg::AdjustHxyz()
{
	CSliderCtrl* pSlider1 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_HX));
	CSliderCtrl* pSlider2 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_HY));
	CSliderCtrl* pSlider3 = (CSliderCtrl*)(GetDlgItem(IDC_SLIDER_HZ));
	int pos1 = pSlider1->GetPos();
	int pos2 = pSlider2->GetPos();
	int pos3 = pSlider3->GetPos();

	double total = sqrt(pos1 * pos1 + pos2 * pos2 + pos3 * pos3 + 0.0);

	Hx = pos1 / total;
	Hy = pos2 / total;
	Hz = pos3 / total;
}

void CArtist3DDlg::Prehandle(shape* s)
{
	switch (pattern)
	{
	case 0:
		PrehandleElement_1(s);
		break;
	case 1:
		PrehandleElement_2(s);
		break;
	case 2:
		PrehandleElement_3(s);
		break;
	}
}
void CArtist3DDlg::PrehandleElement_3(shape* s)
{

	for(int i = 0; i < s->pointAmount; i++)
	{
		s->points[i].faceAmount = 0;
		s->points[i].nx = 0;
		s->points[i].ny = 0;
		s->points[i].nz = 0;
	}

	for(int i = 0; i < s->faceAmount; i++)
	{
		face* f = &(s->faces[i]);
		point* p1 = &(s->points[f->p1]);
		point* p2 = &(s->points[f->p2]);
		point* p3 = &(s->points[f->p3]);
		point* tmp;
		if(p2->x < p1->x)
		{
			tmp = p1;
			p1 = p2;
			p2 = tmp;
		}
		if(p3->x < p1->x)
		{
			tmp = p1;
			p1 = p3;
			p3 = tmp;
		}

		if(p3->x - p1->x < 0.000001)
		{
			if(p3->y > p1->y)
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}else if(p2->x - p1->x < 0.000001)
		{
			if(p2->y < p1->y)
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}else
		{
			if( ((p3->y - p1->y) / (p3->x - p1->x)) > ((p2->y - p1->y) / (p2->x - p1->x)))
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}

		double v1[3] = {p3->x - p1->x, p3->y - p1->y, p3->z - p1->z};
		double v2[3] = {p2->x - p1->x, p2->y - p1->y, p2->z - p1->z};
		f->nx = v1[1] * v2[2] - v2[1] * v1[2];
		f->ny = v1[2] * v2[0] - v1[0] * v2[2];
		f->nz = v1[0] * v2[1] - v1[1] * v2[0];

		double total = sqrt(f->nx * f->nx + f->ny * f->ny + f->nz * f->nz);
		f->nx /= total;
		f->ny /= total;
		f->nz /= total;

		s->points[f->p1].nx += f->nx;
		s->points[f->p1].ny += f->ny;
		s->points[f->p1].nz += f->nz;
		s->points[f->p1].faceAmount++;

		s->points[f->p2].nx += f->nx;
		s->points[f->p2].ny += f->ny;
		s->points[f->p2].nz += f->nz;
		s->points[f->p2].faceAmount++;

		s->points[f->p3].nx += f->nx;
		s->points[f->p3].ny += f->ny;
		s->points[f->p3].nz += f->nz;
		s->points[f->p3].faceAmount++;
	}

	for(int i = 0; i < s->pointAmount; i++)
	{
		s->points[i].nx /= s->points[i].faceAmount;
		s->points[i].ny /= s->points[i].faceAmount;
		s->points[i].nz /= s->points[i].faceAmount;
	}
}
void CArtist3DDlg::PrehandleElement_2(shape* s)
{
	for(int i = 0; i < s->pointAmount; i++)
	{
		s->points[i].faceAmount = 0;
		s->points[i].nx = 0;
		s->points[i].ny = 0;
		s->points[i].nz = 0;
	}

	for(int i = 0; i < s->faceAmount; i++)
	{
		face* f = &(s->faces[i]);
		point* p1 = &(s->points[f->p1]);
		point* p2 = &(s->points[f->p2]);
		point* p3 = &(s->points[f->p3]);
		point* tmp;
		if(p2->x < p1->x)
		{
			tmp = p1;
			p1 = p2;
			p2 = tmp;
		}
		if(p3->x < p1->x)
		{
			tmp = p1;
			p1 = p3;
			p3 = tmp;
		}

		if(p3->x - p1->x < 0.000001)
		{
			if(p3->y > p1->y)
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}else if(p2->x - p1->x < 0.000001)
		{
			if(p2->y < p1->y)
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}else
		{
			if( ((p3->y - p1->y) / (p3->x - p1->x)) > ((p2->y - p1->y) / (p2->x - p1->x)))
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}

		double v1[3] = {p3->x - p1->x, p3->y - p1->y, p3->z - p1->z};
		double v2[3] = {p2->x - p1->x, p2->y - p1->y, p2->z - p1->z};
		f->nx = v1[1] * v2[2] - v2[1] * v1[2];
		f->ny = v1[2] * v2[0] - v1[0] * v2[2];
		f->nz = v1[0] * v2[1] - v1[1] * v2[0];

		double total = sqrt(f->nx * f->nx + f->ny * f->ny + f->nz * f->nz);
		f->nx /= total;
		f->ny /= total;
		f->nz /= total;

		s->points[f->p1].nx += f->nx;
		s->points[f->p1].ny += f->ny;
		s->points[f->p1].nz += f->nz;
		s->points[f->p1].faceAmount++;

		s->points[f->p2].nx += f->nx;
		s->points[f->p2].ny += f->ny;
		s->points[f->p2].nz += f->nz;
		s->points[f->p2].faceAmount++;

		s->points[f->p3].nx += f->nx;
		s->points[f->p3].ny += f->ny;
		s->points[f->p3].nz += f->nz;
		s->points[f->p3].faceAmount++;
	}

	for(int i = 0; i < s->pointAmount; i++)
	{
		s->points[i].nx /= s->points[i].faceAmount;
		s->points[i].ny /= s->points[i].faceAmount;
		s->points[i].nz /= s->points[i].faceAmount;

		double para1 = Lx * s->points[i].nx + Ly * s->points[i].ny + Lz * s->points[i].nz;
		double para2 = 1;
		double dpara2 = Hx * s->points[i].nx + Hy * s->points[i].ny + Hz * s->points[i].nz;

		for(int j = 0; j < HolyN; j++)
			para2 *= dpara2;

		s->points[i].IR = PhongR(para1, para2);
		s->points[i].IG = PhongG(para1, para2);
		s->points[i].IB = PhongB(para1, para2);
	}
}


void CArtist3DDlg::PrehandleElement_1(shape* s)
{
	for(int i = 0; i < s->faceAmount; i++)
	{
		face* f = &(s->faces[i]);
		point* p1 = &(s->points[f->p1]);
		point* p2 = &(s->points[f->p2]);
		point* p3 = &(s->points[f->p3]);
		point* tmp;
		if(p2->x < p1->x)
		{
			tmp = p1;
			p1 = p2;
			p2 = tmp;
		}
		if(p3->x < p1->x)
		{
			tmp = p1;
			p1 = p3;
			p3 = tmp;
		}

		if(p3->x - p1->x < 0.000001)
		{
			if(p3->y > p1->y)
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}else if(p2->x - p1->x < 0.000001)
		{
			if(p2->y < p1->y)
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}else
		{
			if( ((p3->y - p1->y) / (p3->x - p1->x)) > ((p2->y - p1->y) / (p2->x - p1->x)))
			{
				tmp = p2;
				p2 = p3;
				p3 = tmp;
			}
		}

		double v1[3] = {p3->x - p1->x, p3->y - p1->y, p3->z - p1->z};
		double v2[3] = {p2->x - p1->x, p2->y - p1->y, p2->z - p1->z};
		f->nx = v1[1] * v2[2] - v2[1] * v1[2];
		f->ny = v1[2] * v2[0] - v1[0] * v2[2];
		f->nz = v1[0] * v2[1] - v1[1] * v2[0];
		double total = sqrt(f->nx * f->nx + f->ny * f->ny + f->nz * f->nz);
		f->nx /= total;
		f->ny /= total;
		f->nz /= total;

		double para1 = Lx * f->nx + Ly * f->ny + Lz * f->nz;
		double para2 = 1;
		double dpara2 = Hx * f->nx + Hy * f->ny + Hz * f->nz;

		for(int i = 0; i < HolyN; i++)
			para2 *= dpara2;

		f->r = PhongR(para1, para2);
		f->g = PhongG(para1, para2);
		f->b = PhongB(para1, para2);
	}

}

byte CArtist3DDlg::PhongR(double para1, double para2)
{
	double result = IaR * KaR +IpR * KdR * para1 + IpR * KsR * para2;
	if(result >= 254.5)
		return (byte)255;
	else if(result < 0.5)
		return (byte)0;
	return (byte)(result + 0.5);
}
byte CArtist3DDlg::PhongG(double para1, double para2)
{
	double result = IaG * KaG +IpG * KdG * para1 + IpG * KsG * para2;
	if(result >= 254.5)
		return (byte)255;
	else if(result < 0.5)
		return (byte)0;
	return (byte)(result + 0.5);
}
byte CArtist3DDlg::PhongB(double para1, double para2)
{
	double result = IaB * KaB +IpB * KdB * para1 + IpB * KsB * para2;
	if(result >= 254.5)
		return (byte)255;
	else if(result < 0.5)
		return (byte)0;
	return (byte)(result + 0.5);
}

