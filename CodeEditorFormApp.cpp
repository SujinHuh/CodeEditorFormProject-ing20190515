//CodeEditorFormApp.cpp
/*
���ϸ� : CodeEditorForm.cpp
�ۼ����� : 2019�� 03�� 27��
�ۼ��� : �迵��
��� : ����
���� :
*/

#include "CodeEditorFormApp.h"
#include "CodeEditorForm.h"
#include "resource.h"

/*
�Լ���: Initinstance
���: MFC ����
*/
BOOL CodeEditorFormApp::InitInstance() {
	CodeEditorForm *codeEditorForm = new CodeEditorForm;
	codeEditorForm->Create(NULL, (LPCTSTR)"������� - CodeEditorForm", WS_OVERLAPPEDWINDOW, CRect(200, 120, 640, 400), NULL, MAKEINTRESOURCE(IDR_MENU1));
	codeEditorForm->ShowWindow(SW_SHOW);
	codeEditorForm->UpdateWindow();
	this->m_pMainWnd = codeEditorForm;
	return TRUE;
}
CodeEditorFormApp codeEditorFormApp;