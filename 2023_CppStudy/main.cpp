#include <stdio.h>

int main()
{
	// l-value: ����
	// r-value: ���

	// const(���ȭ)
	const int i = 100;

	// �Ұ���
	// i = 100;
	
	// ���� ĳ����
	int* p = (int*)&i;

	// ���� �ٲ� �� �ִ�.
	*p = 300;

	printf("%d\n", *p);
}
