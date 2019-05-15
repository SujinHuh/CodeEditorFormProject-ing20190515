/*
���ϸ� : ShiftLeftKeyAction.h
�ۼ����� : 2019�� 05�� 14��
��� : ShiftLeftKeyAction ���� ����
*/
//ShiftLeftKeyAction.h
#ifndef _SHIFTLEFTKEYACTION_H
#define _SHIFTLEFTKEYACTION_H
#include "KeyAction.h"
#include "RegionController.h"

class CodeEditorForm;

class ShiftLeftKeyAction :public KeyAction {
public:
	ShiftLeftKeyAction(CodeEditorForm *codeEditorForm);
	virtual ~ShiftLeftKeyAction();
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

private:
	RegionController *regionController;
};
#endif // !_RIGHTKEYACTION_H
