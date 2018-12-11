## ���α׷� ���� ���������� Win32 vs Win64

<br>

### 64��Ʈ ��� ���α׷���
+64��Ʈ ��� ���α׷���
64��Ʈ �������� ����� ���α׷������� �ڷ����� ���ؼ� ����ؾ� �Ѵ�.

+LLP64 vs LP64
32��Ʈ �ý��۰��� ȣȯ���� �߽��� ��
�ü�� | �� | char | short | int | long | ������
----------|------|-----|-------|------|-------|-------
Windows | LLP64 | 1byte | 2byte | 4byte | 4byte | **8byte**
UNIX | LP64 | 1byte | 2byte | 4byte | **8byte** | **8byte**

64��Ʈ ������� ���α׷����� �Ѵ�?? LLP64, LP64 ������شٴ� ���̴�.

<br>

### 64��Ʈ�� 32��Ʈ ������ ������
+������ �ս��� �� (64��Ʈ ����϶�)
	
	#include<stdio.h>
	int main()
	{
		int arr[10]={0,};						//�����ʹ� 8byte
		int arrVal = (int)arr;					//������ �ս��� �߻��� �� �ִ� ��ġ
												  8����Ʈ�� �����͸� 4����Ʈ ��Ƽ�� �ڷ������� ĳ�����ϴ°� �̶� ������ ����� �ִ�.
		printf("pointer : %d \n", arrVall);
		return 0;
	}

LLP64����϶� ������
�����ʹ� 4byte?? 
�ƴϴ�, �����ʹ� 8byte��

<br>

### Windows ��Ÿ�� �ڷ��� - polymorphic �ڷ���

+Polymorphic

	#if defined(_WIN64)							//64��Ʈ ���ȯ�濡�� ���α׷��� �ҽ� �⺻������ ���� ��ũ��
		typedef __int64 LONG_PTR;
		typedef unsigned __int64 ULONG_PTR
		typedef __int64 INT_PTR
		typedef unsigned __int64 UNIT_PTR		//�̶� UNIT_PTR 64��Ʈ��
	#else
		typedef long LONG_PTR
		typedef unsigned ULONG_PTR
		typedef int INT_PTR
		typedef unsigned int UNIT_PTR			//�̶� UNIT_PTR 32��Ʈ��(������)
	#endlf

>PTR�� ������ Ÿ���� �ƴϰ� **������ ������ ���� (polymorphic) �ڷ���**�̴�.
*������(polymorphic) - �ϳ��� �繰�� 2�� �̻��� Ư���� ���̴°� 

<br>

+�ڵ�� �˾ƺ��� �����߻�����

	UINT CalDistance(UINT a, UINT b)
	{
		return a-b;
	}

	int_tmain()
	{
		INT val1 = 10;
		INT val2 = 20;
		
		_tprintf(_T("Position %d, %d \n"),
		(UNIT)&val1, (UNIT)&val2);
		_tprintf(_T("ditance : %d \n"), 
		CalDistance((UNIT)&val1, (UNIT)&val2);		// ���Ը��� �ּҰ��� �Ÿ��� ����ϴ� �ڵ��̴�.

		return 0;
	}

1. ���⼭ UNIT�� 4����Ʈ�� ������ 32��Ʈ ��� ������ �ƹ��� ������ ����.
2. ������ 64��Ʈ ��ݿ����� ������ �߻��� Ȱ���� �����ϴ�. (�ּҰ��� 32��Ʈ �������� �������� ������)
3. ��� �ذ��ұ�?
4. �ּҰ� ������ ������ ���� polymorphic �ڷ����� �̿�(��ũ��)�Ѵ�!

	#if defined(_WIN64)
		typedef unsined __int64 UNIT_PTR;
	#else
		typedef unsined int UNIT_PTR;
	#endlif

5. ������ ������ ��쿡 �̷��� ������ ��Ÿ������ ���ɼ��� ����.

<br>

### ���� Ȯ��

1. ������ �ذ��ϱ� ����, ������ �� �߻���°��� ���� ã�ƾ� �Ѵ�.
2. �������� �ý��ۿ����� ���������� ����� �޸𸮿� ������ ���ε��� ������ �д�.
3. �� ���������� ������ �ϴ� �Լ��� GetLastError �Լ��̴�.
4. ex) ERROR_ARITHMETIC_OVERFLOW		Arithmetic result exceeded 32bits

	int_tmain()
	{
		HANDLE hFile=
		CreatFile(												// Windows system �Լ�,
			_T("ABC.DAT"), GENERIC_READ, FILE_SHARE_READ,	
			NULL< OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
			NULL);												// ���� ������ ���� ������ �б� �������� ���ٴ� ���� �ڵ��.
		if (hFile == INVALID_HANDLE_VALUE)						   **������ �߻��ߴ����� ���θ�**�� �Ǵ��ϴ� �б��̴�.
		{
			_tprintf(_T("erro codes : %d \n"), GetLastError();	//��°�� error code: 2
			return 0;
		}
		
	}

>GetLastError()�Լ��� ����Ҷ� ������
������ �߻��� ���Ŀ� ȣ���ؾߵȴ�. ���� ������ �߻��� �κ��� ������ �������� �κ���
�ִ� �κ� �ڿ� ȣ���ϸ�, ���� �ڵ�� ��µ����ʴ´�. (�������� ���� ������ ���Ѱ� �̹Ƿ�)