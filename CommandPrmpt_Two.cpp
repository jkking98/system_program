/*
    CommandPrmpt_Two.cpp
    프로그램 설명: 명령 프롬프트의 골격에 계산기능 구현.
    나눗셈 기능 추가 (16.4.4)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <tchar.h>
#include <windows.h> 

#define STR_LEN    256
#define CMD_TOKEN_NUM  10

TCHAR ERROR_CMD[] 
 = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다. \n");

int CmdProcessing(void);
TCHAR * StrLower(TCHAR *);
void Divide(double a, double b);

int main(int agrc, TCHAR * argv[])
{
	// 한글 입력을 가능케 하기 위해.
	_tsetlocale(LC_ALL, _T("Korean")); 
	
	DWORD isExit;
	while(1)
	{
		isExit = CmdProcessing();
		if(isExit == TRUE)
		{
			_fputts(_T("명령어 처리를 종료합니다. \n"), stdout );
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
	else if ( !_tcscmp(cmdTokenList[0],_T("divide")) )
	{
		Divide(_ttoi(cmdTokenList[1]), _ttoi(cmdTokenList[2]));
	}
	else if ( !_tcscmp(cmdTokenList[0],_T("multiple")) )
	{
	}
	else if ( !_tcscmp(cmdTokenList[0],_T("add")) )
	{
	}
	else if ( !_tcscmp(cmdTokenList[0],_T("minus")) )
	{
	}
	else if ( !_tcscmp(cmdTokenList[0],_T("minus")) )
	{
	}
	else
	{
		_tprintf(ERROR_CMD, cmdTokenList[0]);
	}

	return 0;
}

void Divide(double a, double b)
{
	_tprintf(_T("%f/%f=%f \n\n"), a, b, a/b);
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


