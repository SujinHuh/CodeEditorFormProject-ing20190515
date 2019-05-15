//CtrlRightKeyAction.cpp
/*
���ϸ� : CtrlRightKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : Ctrl + ������ ����Ű
���� :
*/

#include "CtrlRightKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"

CtrlRightKeyAction::CtrlRightKeyAction(CodeEditorForm * codeEditorForm)
	:KeyAction(codeEditorForm) {
	
}

CtrlRightKeyAction::~CtrlRightKeyAction() {
}

void CtrlRightKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Glyph* line;
	Glyph* memo;
	Long lineCurrent;
	Long lineLength;

	memo = this->codeEditorForm->memo;
	line = this->codeEditorForm->current;
	
	line->RightWord();

	lineCurrent = line->GetCurrent();
	lineLength = line->GetLength();

	if (lineCurrent == lineLength) {
		memo->RightWord();
	}

}
