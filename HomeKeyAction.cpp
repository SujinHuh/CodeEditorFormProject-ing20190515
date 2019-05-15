//HomeKeyAction.cpp

/*
���ϸ� : HomeKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : Ȩ Ű
���� :
*/

#include "HomeKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"

HomeKeyAction::HomeKeyAction(CodeEditorForm *codeEditorForm) :KeyAction(codeEditorForm) {
}

HomeKeyAction::~HomeKeyAction() {
}

void HomeKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	this->codeEditorForm->current->First();
}