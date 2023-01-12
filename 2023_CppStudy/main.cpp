#include <stdio.h>

// �Լ� ���� ���� ����Ű: Ctrl + Shift + Space

// �Ű������� �����͸� ����ϴ� ����, ����ü�� ���� �뷮�� ū ������ ���簡 �Ͼ�� �ʵ��� �ϱ� ���ؼ���.
// 64��Ʈ ���� �����ʹ� 8����Ʈ�̹Ƿ�, char, int�� ���� �ڷ����� ����Ǵ� ���� �� ����.
void Function(const int* p);

int main()
{
	// 1. const
	const int i = 100;

	// const�� ������
	int a = 0;
	int* p = &a;

	*p = 1;
	p = nullptr;

	// 2. const ������: �����Ͱ� ����Ű�� ����� ���� ������ �� ���� �Ѵ�.
	const int* constP = &a; // int const* constP = &a;

	// ����Ű�� ����� �� ���� �Ұ���
	// *constP = 10;

	int b = 0;

	// �ٸ� ����� ����Ű�� ���� ����
	constP = &b;

	// 3. ������ const: �����Ͱ� ����Ű�� ����� ������ �� ���� �Ѵ�.
	int* const pConst = &a;

	// ����Ű�� ����� �� ���� ����
	*pConst = 10;

	// �ٸ� ����� ����Ű�� ���� �Ұ���
	// pConst = &b;

	// 4. 2, 3���� ��츦 ����
	const int* const constPConst = nullptr;

	{
		int c = 0;
		const int* p = &c;
		
		// �� �ڵ�� c ��ü�� ���ȭ �Ǵ� ���� �ƴϴ�.
		c = 100;
		
		// �̰��� �Ұ���
		// *p = 100;
	}

	Function(&a);
}

void Function(const int* p)
{
	// const int*�� �Ű������� ���������� ������ �� �ִ�.
	// ��, const�� ���� �ٲ��� ����� �ǵ��� �����ϴ� �ϳ��� ��Ӱ��� ���̴�.
	int* p2 = (int*)p;

	*p2 = 1000;
}
