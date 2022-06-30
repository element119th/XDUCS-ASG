// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Child.h"

#include "ChildDoc.h"
#include "ChildView.h"
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<process.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HANDLE hWrite;

/////////////////////////////////////////////////////////////////////////////
// CChildView

IMPLEMENT_DYNCREATE(CChildView, CView)

BEGIN_MESSAGE_MAP(CChildView, CView)
	//{{AFX_MSG_MAP(CChildView)
	ON_COMMAND(ID_Pipe_WRITE, OnPipeWRITE)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildView construction/destruction

CChildView::CChildView()
{
	// TODO: add construction code here

}

CChildView::~CChildView()
{
}

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChildView drawing

void CChildView::OnDraw(CDC* pDC)
{
	CChildDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CChildView printing

BOOL CChildView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChildView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChildView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CChildView diagnostics

#ifdef _DEBUG
void CChildView::AssertValid() const
{
	CView::AssertValid();
}

void CChildView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChildDoc* CChildView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChildDoc)));
	return (CChildDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

//DEL void CChildView::OnPipeREAD() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	hRead=GetStdHandle(STD_INPUT_HANDLE);
//DEL 	char buf[100];
//DEL 	DWORD dwRead;
//DEL 	if (!ReadFile(hRead, buf, 100, &dwRead, NULL)) {
//DEL 		MessageBox("读取数据失败!");
//DEL 		return ;
//DEL 	}
//DEL 	MessageBox(buf);
//DEL }

void CChildView::OnPipeWRITE() 
{
	// TODO: Add your command handler code here
	hWrite = CreateFile("\\\\.\\pipe\\NamedPipe",FILE_SHARE_READ | FILE_SHARE_WRITE,              //打开命名管道
  0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(hWrite == INVALID_HANDLE_VALUE) {          //开命名管道失败报错
		MessageBox("打开命名管道失败！");
		hWrite=NULL;
		return ;
	}
	char buf[] = "命名管道测试程序";
	DWORD dwWrite;
	if (!WriteFile(hWrite, buf, strlen(buf) + 1, &dwWrite, NULL)) {           //向命名管道写入数据
		MessageBox("写入数据失败!");
		return ;
	}
}
