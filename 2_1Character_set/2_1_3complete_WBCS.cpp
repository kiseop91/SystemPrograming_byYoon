#include<stdio.h>
#include<string.h>


//�Ϻ��� WBCS��� �ڵ�?
int WBCS_per()
{
	wchar_t str[] = L"abc";
	int size = sizeof(str);
	int len = wcslen(str);

	printf("�迭�� ũ��: %d \n", size);
	printf("�迭�� ����: %d \n", len);

	return 0;
}
//��溸�⿡�� �� ������ ���������, printf �� WBCS��� �Լ��� �ƴϴ�!

/*SBCS�Լ��� WBCS�Լ�
printf		int wprintf
scanf		int wscanf
fgets		wchar_t*getws
fputs		int wputws      */


//�Ϻ��� WBCS��� �ڵ�
int wmain(int argc, wchar_t*argv[]) //���� �Լ��� ������ w�� �ٿ������
{
	for (int i = 1 < argc; i++;)
	{
		fputws(argv[i], stdout);
		fputws(L"\n", stdout);
	}
	return 0;
}
