#include <stdio.h>

// ����ü: ����� ���� �ڷ���
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

// C ���� ����ü
typedef struct NewStruct
{
	int m_a;
	int m_b;
} NEWSTRUCT;

int main()
{
	// ����ü �ʱ�ȭ
	INFO info = { 10, 150.0f, 50.0f };

	// ����ü ��� ������ ����
	info.m_age = 26;
	info.m_height = 180.0f;
	info.m_weight = 70.0f;

	int size = sizeof(INFO);

	printf("%d\n", size);
}
