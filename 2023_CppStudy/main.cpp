// define ��ó��: ������, �������� ����
#define HUNGRY    0x0001
#define THIRSTY   0x0002
#define TIRED     0x0004
#define BURNING   0x0008
#define FROZEN    0x0010
#define POISON    0x0020

#define MAX_SIZE      20

// �ּ�: ���� ����, �ڵ�� �νĵ��� �ʴ´�.

int main()
{
	// �ڷ���(Data Type), ũ�� ����: ����Ʈ(byte)
	// ������: char(1), short(2), int(4), long(4), long long(8)
	// �Ǽ���: float(4), double(8)
	int i = 0;
	unsigned char c = 0;

	c = 0;
	//c = 255;
	c = -1;

	// 1. ����Ʈ�� ���, ���� �� �� ǥ��
	// -128 ~ 0 ~ 127
	char c1 = 0;

	c1 = 255;

	// ���� ���� ã��(2�� ������)
	// �����Ǵ� ����� ��ȣ�� ���� ��, 1�� ���Ѵ�.

	// �Ʒ� ���� �Ϲ��� ����ȯ�� �Ͼ��.
	int a = 4 + 4.0;

	// ����ǥ�� ��İ� �Ǽ� ǥ�� ����� �ٸ���.
	// �Ǽ� ǥ������� ���е��� �����Ѵ�.
	// ���� double �ڷ����� float ���� �� ������ ǥ���� �����ϴ�.

	// �Ǽ��� ����� ���� ��� �Ҽ��� �ڿ� f�� ���� ��� float �ڷ�������, ������ ���� ��� double �ڷ������� ó���Ѵ�.

	// ������ ��������, �Ǽ��� �Ǽ����� �����ϵ�, �� ǥ������� �ǿ����ڰ� ����� ��� ��������� ��ȯ����.
	float f = 10.2415f + (float)20;

	// ������
	// ���� ������: =
	// ��� ������: +, -, *, /, %(�ǿ����ڰ� ��� ������ ��쿡�� ��� ����)
	// ���� ������: ++, --
	// �� ������: !(REVERSE), &&(AND), ||(OR)
	// �� ������: ==, !=, <, >, <=, >=
	// ��: true, 0�� �ƴ� ������ �ַ� 1, ����: false, 0
	int data = 10 + 10;

	// data = data + 20;
	data += 20; 

	data = 10 / 3;
	data = 10 % 3;

	// data = 10.0 / 3.0;
	data = (int)(10.0 / 3.0);

	data = 0;
	data++; // 1
	data--; // 0

	// ���� �����ڴ� ������ �켱 ������ ���� �����̴�.
	++data; // ����
	data++; // ����

	a = 10;
	data = a++; // data�� 10

	// �����ϸ� ���� �����ڸ� �������.(Ŭ���� ������ �����ε��� ��� ���簡 �Ͼ �� �ֱ� ������)

	bool truefalse = true;
	bool isTrue = 100; // true

	isTrue = !truefalse;

	int n = 100;
	
	n = !n;
	n = 0 && 200;

	// ����
	// if, else
	if (100 && 200)
	{
		data = 0;
	}
	else if (data == 100)
	{
		data *= 10;
	}
	else
	{
		data /= 5;
	}
	
	// switch case
	// ������ ������ �迭�� ��� ����
	switch (5)
	{
	case 10:
	case 20:
		break;
	case 30:
		break;
	default:
		break;
	}

	// ���� ������
	data = (data == 20) ? 50 : 80;

	// ���� �ǹ�
	if (data == 20)
	{
		data = 50;
	}
	else
	{
		data = 80;
	}

	// ��Ʈ ������: <<, >>, ~(REVERSE), &(AND), |(OR), ^(XOR)
	// ~: 0�� 1����, 1�� 0����
	// &: �� �� 1�� ��� 1
	// |: ��� �ϳ��� 1�� ��� 1
	// ^: ������ 0, �ٸ��� 1
	unsigned char byte = 8;

	byte <<= 2; // 2^n�� ���Ѵ�.
	byte >>= 3; // 2^n�� ������.

	unsigned int status = HUNGRY; // status = 1;

	// ���� �߰�
	status |= THIRSTY;

	// ���� Ȯ��
	if (status & THIRSTY)
	{

	}

	// Ư�� �ڸ� ��Ʈ ����
	status &= ~THIRSTY;
}
