## MBCS�� WBCS ��������

<br>

### ����
�������� ��� �ý����� �����ڵ带 �������� �ʴ´�. �ֳ��ϸ� ���߹� ����Ʈ��� ������ ȯ���� ���� ���� �ʾұ� �����̴�.
������ �̷��� ������ �ϳ��� ���α׷��ε��� �ұ��ϰ� MBCS��� ���α׷��� WBCS ������α׷�, 
2���� ���α׷��� ���� ����� �����ؾ� �ϴ� ��Ȳ�̳�, �������� ������ �߻��� ���� �ִٴ� ���̴�.
�̿� ������ �ذ�å���� �ΰ��� ���ڼ��� ���ÿ� �����ϴ� ���α׷��� ����� �ȴٴ� ���� �ִ�.
windows�� �̹� �̷��� ����Ҽ� �ִ� ���� ��ũ�ο� ���ø��� �����ϸ�,
�ñ������� �� ���� �����ڰ� �Ǳ� ���ؼ� MBCS�� WBCS�� ���ÿ� �����ϴ� ���α׷����� �ؾ��Ѵ�.

<br>

### windows ���� �ڷ���
	#include<windows.h)

	typedef	char			CHAR;
	typedef	wchar			WCHAR;

	#define CONST			const

	typedef	CHAR *			LPSTR;
	typedef	CONST CHAR *	LPCSTR;
	
	typedef	WCHAR *			LPWSTR;
	typedef	CONST WCHAR *	LPCWSTR;
ȸ��, ���� ���۰Դ� ������Ʈ���� ���̹��� �޸� �ϴ� ��찡 �ֱ� ������ �̰��� �ּ��̶� �� ���� ����.
���̹��� ������Ʈ�� ���ݰ� Ÿ�Կ� ���� �޶����� �ִ� �κ��̱� �����̴�.

<br>

������ �̷����� ���� �ִٶ�� Ȱ�밡�ɼ��� �߿��� ������, �̰��� ����� �����ϴ� ���� �ƴϴ�.

<br>

### MBCS�� WBCS �������� ��ũ��

���Ǻ� �������� �ϸ�ȴ�.

###### �ܼ������� ���
	#ifdef UNICODE
		typedef	WCHAR		TCHAR;
		typedef	LPWSTR		LPTSTR;
		typedef LPCWSTR		LPCTSTR;
	#else
		typedef CHAR		TCHAR
		typedef	LPSTR		LPTSR;
		typedef LPCSTR		LPCTSTR;
	#endif

>�ڵ带 �ؼ��� ���ڸ�
��ũ�� UNICODE�� ���� �Ǿ��ִٸ�
TCHAR -> WCHAR -> wchar_t
��ũ�� UNICODE�� ���ǵ��� �ʾҴٸ�
TCHAR -> CHAR -> char
�� �ȴٴ� ���̴�.

<br>

###### L""�� ���·� ���ڿ��� �����Ҷ�

	#ifdef _UNICODE
		#define			__T(x)	L##x	// __T("ABC") -> L"ABC"
	#else
		#define			__T(x)	x
	#endif
		
	#define _T(x)		__T(x)
	#define _TEXT(x)	__T(x)			// �ΰ��� ���ٴ� �Ҹ�..

>�ڵ带 �ؼ��� ���ڸ�
��ũ�� _UNICODE�� ���ǵ� �ִٸ�
_T("ABC") -> __T("ABC") -> L"ABC"
��ũ�� _UNICODE�� ���ǵ� ���� �ʴٸ�
_T("ABC") -> __T("ABC") -> "ABC"
�� �ȴٴ� ���̴�.

### MBCS�� WBCS �������� �Լ�

	#ifdef _UNICODE
		#define				_tmain		wmain
		#define				_tcslen		wcslen
		#define				_tprintf	wprintf
		#define				_tscanf		wscanf
	#else
		#define				_tmain		main
		#define				_tcslen		strlen
		#define				_tprintf	printf
		#define				_tscanf		scanf
	#endif
