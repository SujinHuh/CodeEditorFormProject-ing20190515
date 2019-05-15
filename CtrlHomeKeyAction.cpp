//CtrlHomeKeyAction.cpp
/*
���ϸ� : CtrlHomeKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : Ctrl + Ȩ Ű
���� :
*/
#include "CtrlHomeKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"

CtrlHomeKeyAction::CtrlHomeKeyAction(CodeEditorForm *codeEditorForm) : KeyAction(codeEditorForm) {
}

CtrlHomeKeyAction::~CtrlHomeKeyAction() {

}
void CtrlHomeKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long memoCurrent;
	memoCurrent = this->codeEditorForm->memo->First();
	this->codeEditorForm->current = this->codeEditorForm->memo->GetAt(memoCurrent);
	this->codeEditorForm->current->First();
}