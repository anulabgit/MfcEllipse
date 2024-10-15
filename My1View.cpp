
// My1View.cpp: CMy1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "My1.h"
#endif

#include "My1Doc.h"
#include "My1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1View

IMPLEMENT_DYNCREATE(CMy1View, CView)

BEGIN_MESSAGE_MAP(CMy1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy1View 생성/소멸

CMy1View::CMy1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1View::~CMy1View()
{
}

BOOL CMy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy1View 그리기

void CMy1View::OnDraw(CDC* pDC)
{
    CMy1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // 클라이언트 영역의 크기 가져오기
    CRect r;
    GetClientRect(&r);

    // 임의의 타원을 그릴 사각형 생성
    int left = rand() % r.Width();
    int top = rand() % r.Height();
    int right = left + (rand() % (r.Width() - left)); // 오른쪽 경계
    int bottom = top + (rand() % (r.Height() - top)); // 아래쪽 경계
    CRect rr(left, top, right, bottom);

    // 임의의 색상 선택
    COLORREF rc = RGB(rand() % 256, rand() % 256, rand() % 256);

    // 브러시 생성
    CBrush brush(rc);
    CBrush* pOldBrush = pDC->SelectObject(&brush);

    // 타원 그리기
    pDC->Ellipse(rr);

    // 브러시 복원
    pDC->SelectObject(pOldBrush);
}



// CMy1View 인쇄

BOOL CMy1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy1View 진단

#ifdef _DEBUG
void CMy1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1Doc* CMy1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1Doc)));
	return (CMy1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1View 메시지 처리기
