//CtrlLeftKeyAction.cpp
/*
���ϸ� : CtrlLeftKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : Ctrl + ���� ����Ű
���� :
*/

#include "CtrlLeftKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"

CtrlLeftKeyAction::CtrlLeftKeyAction(CodeEditorForm *codeEditorForm) :KeyAction(codeEditorForm) {
}

CtrlLeftKeyAction::~CtrlLeftKeyAction() {
}

void CtrlLeftKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Glyph* line;
	Glyph* memo;
	Long lineCurrent;

	memo = this->codeEditorForm->memo;
	line = this->codeEditorForm->current;

	line->LeftWord();

	lineCurrent = line->GetCurrent();

	if (lineCurrent == 0) {
		memo->LeftWord();
	}

}

