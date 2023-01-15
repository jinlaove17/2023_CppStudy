#include <iostream>

// 'std'��� namespace�� ����ϰڴ�.(�����ϵ��� ����ڴ�.)
// using namespace std;

// Ư�� ��ɸ� namespace�� ����ϰڴ�.(�����ϵ��� ����ڴ�.)
using std::cout;
using std::wcout; // 2����Ʈ
using std::cin;
using std::endl;

namespace MYSPACE
{
	int i;
}

namespace OTHERSPACE
{
	int i;
}

class CTest
{
public:
	// ��ü ���� ȣ�� ������ �Լ�
	static void Test()
	{
	}
};

class COstream
{
public:
	COstream& operator <<(int data)
	{
		wprintf(L"%d", data);

		return *this;
	}

	COstream& operator <<(const wchar_t* data)
	{
		wprintf(L"%s", data);

		return *this;
	}

	COstream& operator <<(void(*f)())
	{
		f();

		return *this;
	}
};

class CIstream
{
public:
	CIstream& operator >>(int& data)
	{
		scanf_s("%d", &data);

		return *this;
	}
};

// ��� ������ ���� Ŭ������ 1����Ʈ ũ�⸦ ���´�.
COstream myCout;
CIstream myCin;

void myEndl();

int main()
{
	// ���� ��� ����
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	// :: - ���� ���� ������
	CTest::Test();

	// namespace�� ���� ������ �������� �������� �� �ִ�.
	MYSPACE::i = 10;
	OTHERSPACE::i = 20;

	myCout << 10 << 20 << 30 << myEndl;
	myCout << L"�ѱ�" << myEndl;

	int a = 0;

	myCin >> a;

	wprintf(L"%d\n", a);

	cout << &MYSPACE::i << '\n';
	cout << &myCout << '\n';
	cout << &a << '\n';
}

void myEndl()
{
	wprintf(L"\n");
}
