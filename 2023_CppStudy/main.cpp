#include <stdio.h>

// ���� �и�: ������ �� ���� ���� ���
#include "func.h"
#include "common.h"

// ���� ����(global)
int n;

// ���� ����(static): ���� ������ �����ϳ�, ������ ������ ����, �Լ�, Ŭ���� ������ ���������ν� ���������� �������� �ø� �� �ִ�.
static int m;

// �ܺ� ����(extern): common.h�� ����Ǿ� ������, ���ʷ� �ʱ�ȭ�� �ʿ��ϴ�.
int externValue = 0;

int Test()
{
	static int i = 0;

	return ++i;
}

int main()
{
	Test();
	Test();

	int callCount = Test();

	printf("Test() �Լ� ȣ�� Ƚ��: %d\n", callCount);

	// * ��� ���Ͽ� ���ǵ� ���� ������ �� ���Ͽ��� ����ϴ� ����
	staticValue = 100;

	// F12: ���Ƿ� �̵� -> �� ������, �������� �̵�
	int j = Add(10, 20);

	printf("staticValue: %d\n", staticValue);

	// * ��� ���Ͽ� ���ǵ� �ܺ� ������ �� ���Ͽ��� ����ϴ� ����
	externValue = 200;

	int k = Sub(20, 10);

	printf("externValue: %d\n", externValue);
}
