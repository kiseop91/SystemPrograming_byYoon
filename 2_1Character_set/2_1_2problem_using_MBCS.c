// ��MBCS�� ������ ��� ������ �߻��ɼ� �ִ��� �ڵ�� �˾ƺ���

#include<stdio.h>
#include<string.h>
//������ 1
int Problem1()
{
	char str[] = "ABC�ѱ�";
	int size = sizeof(str);
	int len = strlen(str);
	
	printf("�迭�� ũ��: %d \n", size);
	//�迭�� ũ��� "ABC"�� 3�� "�ѱ�"�� 4 �׸��� null���� 1�� ������ 8�� ���´�

	printf("�迭�� ����: %d \n", len);
	//�迭�� ���̴� "ABC"�� ���� 1�� ���̸� �������� "�ѱ�"�� ���ڴ� ���� 2�� ���̸� ����
	//7�̶�� ���ڰ� ��µǰ� �ȴ�.

	return 0;

}

//������2
int Problem2()
{
	char str[] = "�ѱ��Դϴ�";
		int i;

	for (i = 0; i < 5; i++);
	fputc(str[i], stdout);				//�ѱ��� �ѱ��ڿ� 2byte�̹Ƿ� �ѱ� ������ ����

	fputs("\n", stdout);

	for (i = 0; i < 10; i++);
	fputc(str[i], stdout);				//�ѱ��Դϴ� �� ����Ϸ��� i�� 10���� �������־����

	fputs("\n", stdout);
	return 0;							//�������� �ѱ�, �ѱ��Դϴ�
}



// ��WBCS ����� ���α׷��� ����

int WBCS_practice()
{
	wchar_t str[] = L"ABC"; // ��Ʈ�� ���� ������ wchar_t�� �ϰ� ��Ʈ���� L""�� ���·� ����ȴ�.

	return 0;
}

/*SBCS�� WBCS��� �Լ���!
strlen		size_twcslen
strcpy		wchar_t*wcscpy
strncpy		wchar_t*wcsncpy
strcat		wchar_t*wcscat
strncat		wchar_t*wcsncat
strcmp		wchar_t*wcscmp
strncmp		wchar_t*wcsncmp   */
