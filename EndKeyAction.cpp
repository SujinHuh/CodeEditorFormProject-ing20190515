//EndKeyAction.cpp

/*
���ϸ� : EndtKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : ���� Ű
���� :
*/

#include "EndKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"


EndKeyAction::EndKeyAction(CodeEditorForm *codeEditorForm) :KeyAction(codeEditorForm) {
}

EndKeyAction::~EndKeyAction() {
}

void EndKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	this->codeEditorForm->current->Last();
}
