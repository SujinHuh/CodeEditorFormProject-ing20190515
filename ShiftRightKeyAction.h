/*
���ϸ� : RightKeyAction.h
�ۼ����� : 2019�� 05�� 02��
�ۼ��� : �����
��� : ShiftRightKeyAction ���� ����
*/
//ShiftRightKeyAction.h
#ifndef _SHIFTRIGHTKEYACTION_H
#define _SHIFTRIGHTKEYACTION_H
#include "KeyAction.h"
#include "RegionController.h"

class CodeEditorForm;

class ShiftRightKeyAction :public KeyAction {
public:
	ShiftRightKeyAction(CodeEditorForm *codeEditorForm);
	virtual ~ShiftRightKeyAction();
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

private:
	RegionController *regionController;
};
#endif // !_RIGHTKEYACTION_H