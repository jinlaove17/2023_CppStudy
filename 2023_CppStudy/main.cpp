#include <stdio.h>

int main()
{
	// void ������: ����Ű�� ���� � �ڷ������� �ؼ��� �� �������� ���� ������
	void* p = nullptr;

	int a = 0;
	float b = 0.0f;
	double c = 0.0;
	long long d = 0;

	// � ������ Ÿ���̴� �ּҸ� ���� �� �ִ�.
	p = &a;
	p = &b;
	p = &c;
	p = &d;

	// ������, ������ ������ ������ �� ����.
	// *p;
	// ++p;
}
