#include <iostream>

// 'std'라는 namespace를 사용하겠다.(생략하도록 만들겠다.)
// using namespace std;

// 특정 기능만 namespace를 사용하겠다.(생략하도록 만들겠다.)
using std::cout;
using std::wcout; // 2바이트
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
	// 객체 없이 호출 가능한 함수
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

// 멤버 변수가 없는 클래스는 1바이트 크기를 갖는다.
COstream myCout;
CIstream myCin;

void myEndl();

int main()
{
	// 지역 언어 설정
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	// :: - 범위 지정 연산자
	CTest::Test();

	// namespace를 통해 동일한 변수명을 구분지을 수 있다.
	MYSPACE::i = 10;
	OTHERSPACE::i = 20;

	myCout << 10 << 20 << 30 << myEndl;
	myCout << L"한글" << myEndl;

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
