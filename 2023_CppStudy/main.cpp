#include <stdio.h>

// 구조체: 사용자 정의 자료형
struct INFO
{
	int   m_age;
	float m_height;
	float m_weight;
};

struct NEW_INFO
{
	INFO m_info;
	int  m_iq;
};

// C 문법 구조체
typedef struct NewStruct
{
	int m_a;
	int m_b;
} NEWSTRUCT;

int main()
{
	// 구조체 초기화
	INFO info = { 10, 150.0f, 50.0f };

	// 구조체 멤버 변수값 변경
	info.m_age = 26;
	info.m_height = 180.0f;
	info.m_weight = 70.0f;

	int size = sizeof(INFO);

	printf("%d\n", size);
}
