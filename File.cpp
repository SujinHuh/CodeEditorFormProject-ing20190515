/*
���ϸ� : File.cpp
�ۼ����� : 2019�� 04�� 02��
�ۼ��� : �迵��
��� : ���� Ŭ���� (������)
���� :20190403 OpenDialog ��� ����
*/

//File.cpp

#include "File.h"
#include <iostream>
#include <fstream>
#include <afxdlgs.h>


/*
�Լ���: File
���: ����Ʈ ������
���� : 20190404 fileName ����
*/
File::File() {
	this->pathName = "";
	this->fileName = "*.txt";
}

/*
�Լ���: File
���: �Ű����� ������
*/
File::File(string pathName, string fileName) {
	this->pathName = pathName;
	this->fileName = fileName;
}

/*
�Լ���: File
���: ���� ������
*/
File::File(const File& source) {
	this->pathName = source.pathName;
	this->fileName = source.fileName;
}

/*
�Լ���: ~File
���: �Ҹ���
*/
File::~File() {
}

/*
�Լ���: Save
���: �����ϴ�
*/
void File::Save(string contents, string pathName) {
	fstream fs;

	fs.open(pathName, ios::out);

	if (!fs.bad()) {
		fs << contents;
		fs.flush();
		fs.close();
	}
}

/*
�Լ���: Load
���: �ҷ�����
*/
string File::Load(string pathName) {
	fstream fs;
	string text = "";
	char line[256];

	fs.open(pathName, ios::in);

	if (fs.is_open()) {
		while (fs.getline(line, 256)) {
			text += (line);
			text += '\n';
		}
	}
	fs.close();

	return text;
}

/*
�Լ���: OpenDialog
���: Load, Save�� ���������� FileName, PathName�� �����´�
���� : Load, Save ���� 20190404 cFileDialog 3��° �Ű����� ����
*/
void File::OpenDialog(bool isOpen) {
	char szFilter[] = "�ؽ�Ʈ ����(*.txt)|*.txt|��� ����||";
	CString fileName;

	if (isOpen == TRUE) {
		fileName = "";
	}
	else {
		fileName = this->fileName.c_str();
	}
	
	CFileDialog cFileDialog(isOpen, ".txt", fileName, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, szFilter, NULL, 0, NULL);
	if (cFileDialog.DoModal() == IDOK) {
		this->fileName = cFileDialog.GetFileName();
		this->pathName = cFileDialog.GetPathName();
	}
}

/*
�Լ���: operator=
���: ġȯ ������
*/
File& File::operator=(const File& source) {
	this->pathName = source.pathName;
	this->fileName = source.fileName;

	return *this;
}