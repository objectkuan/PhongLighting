#include <stdio.h>

#ifndef __COMPATIBLEFILE_HJQ__
#define __COMPATIBLEFILE_HJQ__

class CompatibleFile
{
private:
	FILE* fp;
public:
	CompatibleFile(CString path);
	CString ReadLine();
	void Close();
	BOOL IsEOF();
};

#endif