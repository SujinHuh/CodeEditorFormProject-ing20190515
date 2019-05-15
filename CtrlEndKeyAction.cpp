//CtrlEndKeyAction.cpp
/*
���ϸ� : CtrlEndKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : Ctrl + ���� Ű
���� :
*/
#include "CtrlEndKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"

CtrlEndKeyAction::CtrlEndKeyAction(CodeEditorForm *codeEditorForm) : KeyAction(codeEditorForm) {
}

CtrlEndKeyAction::~CtrlEndKeyAction() {

}
void CtrlEndKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long memoCurrent;
	memoCurrent = this->codeEditorForm->memo->Last();
	this->codeEditorForm->current = this->codeEditorForm->memo->GetAt(memoCurrent);
	this->codeEditorForm->current->Last();
}