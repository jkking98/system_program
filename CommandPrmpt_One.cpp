    CommandPrmpt_One.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h> 

#define STR_LEN    256
#define CMD_TOKEN_NUM  10

TCHAR ERROR_CMD[] 

int CmdProcessing(void);
TCHAR * StrLower(TCHAR *);

int main(int agrc, TCHAR * argv[])
{
	_tsetlocale(LC_ALL, _T("Korean")); 
	
	DWORD isExit;
	while(1)
	{
		isExit = CmdProcessing();
		if(isExit == TRUE)
		{
			break;
		}
	}

	return 0; 
}


TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[]   = _T(" ,\t\n");

int CmdProcessing(void)
{
	_fputts( _T("Best command prompt>> "), stdout );
	_getts(cmdString);

	TCHAR * token = _tcstok(cmdString, seps);

	int tokenNum = 0;
	while(token != NULL)
	{
		_tcscpy (
			cmdTokenList[tokenNum++], StrLower(token)
		);
		token = _tcstok(NULL, seps);
	}
	
	if( !_tcscmp(cmdTokenList[0],_T("exit")) )
	{
		return TRUE;
	}
	{
	}
	{
	}
	else
	{
		_tprintf(ERROR_CMD, cmdTokenList[0]);
	}

	return 0;
}


TCHAR * StrLower(TCHAR *pStr)
{
	TCHAR *ret = pStr;

	while(*pStr)
	{
		if(_istupper(*pStr))
			*pStr = _totlower(*pStr);
		pStr++;
	}

	return ret;
}


