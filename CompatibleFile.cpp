#include "stdafx.h"
#include "CompatibleFile.h"

CompatibleFile::CompatibleFile(CString path)
{
	char* cpath = path.GetBuffer();
	fp = fopen(cpath, "r");
}

CString CompatibleFile::ReadLine()
{
	CString result = "";
	for(char c = fgetc(fp); c != '\n' && c != -1; c = fgetc(fp))
	{	
		if(c == '\r')
			continue;
		result.AppendChar(c);
	}
	return result;
}

void CompatibleFile::Close()
{
	fclose(fp);
}

BOOL CompatibleFile::IsEOF()
{
	return feof(fp);
}