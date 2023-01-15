#include <iostream>

// �Լ��� ��μ� ȣ���� �� Ÿ���� �����ȴ�.
// �ٽ� ���� �Լ��� �ƴ� �ϳ��� Ʋ�̴�.
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
	// <�Լ� ���ø�>
	// - ����� �����ѵ� �Ű� ������ �ڷ��� ������ �Լ��� ������ ����� ��츦 �ذ��ϱ� ���� ���
	Add<int>(5, 10); // ���� ���� Add(5, 10);

	// <Ŭ���� ���ø�>
	// - �ʿ信 ���� ���ø��� Ŭ�������� ������ �� �ִ�.
	// - Ŭ���� ���ø��� ��� �Լ��� �ݵ�� ��� ���Ͽ� ���ǵǾ�� �Ѵ�.
	CInfo<int> info(5);
}
