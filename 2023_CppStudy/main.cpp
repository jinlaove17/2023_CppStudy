#include <stdio.h>

struct TEST
{
	// ���
	int   i;
	float f;
};

int main()
{
	// ����ü�� ������
	TEST t = { 10, 3.14f };
	TEST* p = &t;

	(*p).i = 100; // p->i = 100;
	(*p).f = 1.414f; // p->f = 1.414f;

	++p; // sizeof(TEST) ����Ʈ��ŭ �̵��� �ּҸ� ����Ų��.
}
