#include <iostream>

// 함수를 비로소 호출할 때 타입이 결정된다.
// 다시 말해 함수가 아닌 하나의 틀이다.
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

template<typename T>
class CInfo
{
private:
	T m_data;

public:
	CInfo(T data) :
		m_data(data)
	{
	}
};

int main()
{
	// <함수 템플릿>
	// - 기능이 유사한데 매개 변수의 자료형 때문에 함수를 여러개 만드는 경우를 해결하기 위한 방법
	Add<int>(5, 10); // 생략 가능 Add(5, 10);

	// <클래스 템플릿>
	// - 필요에 따라 템플릿은 클래스에도 적용할 수 있다.
	// - 클래스 템플릿의 멤버 함수는 반드시 헤더 파일에 정의되어야 한다.
	CInfo<int> info(5);
}
