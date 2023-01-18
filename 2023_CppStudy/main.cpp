#include <iostream>

using namespace std;

class CParent
{
protected:
	int m_i;

public:
	CParent() :
		m_i(0)
	{
		cout << "CParent()" << endl;
	}

	CParent(int i) :
		m_i(i)
	{
		cout << "CParent(int i)" << endl;
	}

	~CParent()
	{
		cout << "~CParent()" << endl;
	}

	void SetInt(int i)
	{
		m_i = i;
	}

	// 가상 함수
	virtual void Print()
	{
		cout << "CParent()::Print()" << endl;
	}
};

class CChild : public CParent
{
private:
	float m_f;

public:
	CChild() : CParent(5), // 부모의 생성자를 선택할 수 있다.(생략 시 디폴트 생성자를 호출한다.)
		m_f(0.0f)
	{
		cout << "CChild()" << endl;
	}

	~CChild()
	{
		cout << "~CChild()" << endl;
	}

	void SetFloat(float f)
	{
		m_f = f;
	}

	// 상속 받은 부모의 함수를 재정의하였다.(오버 라이딩)
	virtual void Print()
	{
		cout << "CChild()::Print()" << endl;
	}
};

int main()
{
	// <객체지향(OOP) 언어의 특징>
	// 1. 캡슐화
	// 
	// 2. 상속
	// - 상속 시, 메모리는 부모->자식 순으로 배치된다.
	// - 자식 or 부모 클래스는 상속 관계에서 다른 클래스의 멤버를 초기화 할 수 없다.
	// - 생성자 '호출' 순서: CChild() -> CParent()
	// - 생성자 '실행' 순서: CParent() -> CChild()
	// - 소멸자 '호출/실행' 순서: CChild() -> CParent()
	// - 오버 라이딩: 부모 클래스의 멤버 함수를 자식 쪽에서 재정의 함으로써, 자식 클래스의 구현된 기능이 호출되도록 한다.
	// 
	// 3. 다형성
	// - 부모 포인터의 타입으로, 부모 클래스로부터 파생되는 모든 자식 클래스의 객체들의 주소를 가리킬 수 있다.
	// - 모든 객체를 부모 클래스 타입으로 인식하게 되기 때문에, 실제 객체가 무엇인지는 알 수 없다.
	// - virtual 키워드를 통해서, 각 클래스는 자신만의 고유한 가상함수 테이블을 갖게 된다.
	// - 각 클래스의 객체들은 가상함수 테이블 포인터에서 해당 클래스에 맞는 테이블을 가리키게 된다.
	// - 해당 테이블에는 해당 클래스의 가상 함수들이 등록되어 있다.
	// - 다운 캐스팅
	//   - 부모 클래스에서 선언되지 않은, 오직 자식쪽에서만 추가된 함수를 호출하고 싶을 때, 자식 포인터 타입으로 캐스팅하여 호출한다.
	//   - 문제가 발생할 수 있기 때문에 dynamic_cast로 안전하게 확인해 볼 수 있다.(고비용)
	//   - RTTI(Run Time Type Information)
	// 
	// 4. 추상화
	// - 실제 객체를 생성할 목적의 클래스가 아닌, 상속을 통해서 구현해야할 내용을 전달하는 상속 목적으로 만들어진 클래스
	// - virtual void func() = 0; --- 1개 이상의 순수 가상함수를 포함하면 추상 클래스가 된다.

	CParent parent;
	CChild child;

	parent.SetInt(10);
	child.SetInt(20);

	// 오버 라이딩 예시
	parent.Print();
	child.Print();
	
	// 오버 라이드 된 경우에도, 범위 지정연산자를 이용해 부모의 함수를 호출할 수 있다.
	child.CParent::Print();

	// 다형성 예시
	CParent* pParent = &parent; // ---(1) 가능
	CChild* pChild = &child;    // ---(2) 가능

	pParent = &child;           // ---(3) 가능
	// pChild = &parent;        // ---(4) 불가능(시작 주소로부터 8바이트를 가리킬 텐데, 실제 데이터는 4바이트만 저장되어 있어 문제가 발생한다.)

	// virtual 키워드를 이용하여, 현재 포인터 타입이 아닌 실객체의 포인터 타입의 오버라이드 된 함수를 호출할 수 있게 되었다.
	pParent->Print();

	// 가상 함수 테이블이 추가되어 클래스의 크기가 늘어났다.
	cout << sizeof(CParent) << endl;
	cout << sizeof(CChild) << endl;
}
