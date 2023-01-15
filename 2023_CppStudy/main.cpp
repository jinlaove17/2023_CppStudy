#include <iostream>

class CTest
{
	// 접근 제한 지정자: 클래스 내의 멤버 변수, 멤버 함수 등의 접근 레벨
	// private, protected, public
private:
	int m_i;

public:
	// 생성자
	CTest() :
		m_i() // 초기화 리스트
	{
		printf("클래스 CTest의 생성자 호출\n");
	}

	// 소멸자
	~CTest()
	{
		printf("클래스 CTest의 소멸자 호출\n");
	}

	// 대입 연산자
	// - 반환 타입이 const&가 되어서는 안된다.(예시: (a = b) = c))
	CTest& operator =(const CTest& other)
	{
		m_i = other.m_i;

		return *this;
	}

	void SetInt(int i)
	{
		m_i = i;

		// this 포인터: 이 멤버 함수를 호출시킨 객체(인스턴스)의 주소(생략 가능)
		// // 다시 말해 이 함수를 void SetInt(CTest* this, int i); 처럼 만든 것과 같다.
		// this->m_i = i;
	}

	int GetInt()
	{
		return m_i;
	}
};

int main()
{
	// <C++ 클래스>
	// - 생성자, 소멸자: 객체 생성 및 소멸 시 자동으로 호출, 별도로 작성하지 않아도 컴파일러가 자동으로 만든다.
	// - 멤버 함수: 해당 클래스가 사용하는 전용 함수, 이 함수는 객체(인스턴스)를 통해 호출할 수 있다.
	CTest test1, test2, test3;

	// 접근 제한 지정자가 private이므로, 외부에서 접근할 수 없다.
	// test1.m_i = 10;

	// 따라서 Setter, Getter 함수를 이용하여 값을 변경하였다.
	test1.SetInt(100);

	// 대입 연산자 호출(별도로 만들지 않으면 컴파일러가 자동으로 생성)
	(test3 = test2) = test1;

	int a = 10;

	// 1. 포인터 변수 선언: 자료형* 변수명;
	// 2. 변수의 주소값: &변수;
	int* p = &a;

	printf("%d\n", a);

	// 3. 포인터로 주소 역참조: *변수명;
	*p = 100;

	printf("%d\n", a);

	// 4. 래퍼런스 변수 선언: 자료형& 변수명;
	// 포인터와 유사, 원본 객체를 참조한다.
	// 역참조 없이 직접적으로 원본을 수정할 수 있다.
	int& ref = a;

	ref = 200;

	printf("%d\n", a);
}
