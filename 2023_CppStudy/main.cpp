// <����Ű>
// ���� ���� �ּ� ó��: Ctrl + k + c
// ���� ���� �ּ� ����: Ctrl + k + u
// ���� �� ����: Alt + Drag
// ����� ����: F5
// ����� ��, ���� �ߴ������� ����: F5
// �ߴ��� ���� �� ����: F9
// ���ν��� ���� ����: F10
// �� �ܰ辿 �ڵ� ����: F11
// ����� �����ϱ�: Shift + F5

#include <stdio.h>

// �Լ�
int Add(int a, int b);
int Factorial(int n);

int main()
{
	int data = Add(10, 20);

	// �ݺ���
	// continue: �̹� ���� ����
	// break: �ݺ��� ����
	 
	// for��
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 1)
		{
			continue;
		}

		printf("Output Test(%d)\n", i);
	}

	// while��
	int i = 0;

	while (i < 10)
	{
		printf("Output Test(%d)\n", i);

		++i;
	}

	scanf_s("%d", &i);
	printf("%d\n", i);

	// �Լ��� ����ϴ� �޸� ����: ���� �޸� ����(�Ű�����, ��������)

	// Factorial �����ϱ�
	printf("%d", Factorial(6));
}

int Add(int a, int b)
{
	return a + b;
}

int Factorial(int n)
{
	int value = 1;

	for (int i = n; i > 1; --i)
	{
		value *= i;
	}

	return value;
}
