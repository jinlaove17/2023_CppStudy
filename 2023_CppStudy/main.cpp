#include <stdio.h>
#include <wchar.h>
#include <assert.h>

unsigned int GetLength(const wchar_t* p);
void WStrCat(wchar_t* dest, unsigned int bufferSize, const wchar_t* src);
int WStrCmp(const wchar_t* string1, const wchar_t* string2);

// �Լ� �����ε�: ������ �̸��� �Լ��� ������ ���� �� �ִ� ��(�� �Լ��� �Ű������� ������ Ÿ�����θ� �����Ѵ�.)
void Func(int a);
void Func(float a);

int main()
{
	// ����: char(1), wchar(2)
	char c = 'a';
	wchar_t wc = L'a';

	// ���� 1�� ���� 1�� �޸𸮿� �ٸ��� ����ȴ�.
	c = 1;
	c = '1';

	// ���ڿ�
	char str[] = "abcdef";

	// ���ڿ� L"abcdef"�� �迭 wStr�� �� ���� �����Ͽ� �ʱ�ȭ
	wchar_t wStr[] = L"abcdef"; // short arr[] = { 97, 98, 99, 100, 101, 102 };

	// L"abcdef"�� �޸� ������ ����Ű�� �����ͷ� �ʱ�ȭ 
	const wchar_t* p = L"abcdef";

	// �迭�� �����ϴ� ���̹Ƿ� ����
	wStr[1] = 'z';

	// ��� ���� �����ϴ� ���̹Ƿ� �Ұ��� 'b' = 'z';�� ���� ����
	// ���� L"abcdef"�� �ڵ� ����(Read Only Memory)���� �����Ǳ� ������ ������ �� ����.
	// ���� ĳ���� �� �����Ϸ��� ��� ���α׷��� ��Ÿ�� ������ �߻���Ų��.
	// p[1] = 'z';

	// ��Ƽ����Ʈ ���ڼ� ���: 1����Ʈ�� ǥ�� ������ ���ڴ� 1����Ʈ��, �� ���� ���ڴ� 2����Ʈ�� ǥ���ϴ� �������� ����� ���� ǥ�� ���(ǥ������ ������ ����)
	char test1[] = "abc�ѱ�";

	// �����ڵ� ���ڼ� ���: ��� ���ڸ� 2����Ʈ�� ǥ���ϴ� ���� ǥ�� ���
	wchar_t test2[] = L"abc�ѱ�";

	wchar_t name[] = L"Raimond";

	// wcslen(): ���ڿ��� ���̸� ���ϴ� �Լ�
	int len = wcslen(name);

	// wcslen() �Լ��� ���� �����غ���.
	len = GetLength(name);

	// wcscat_s(): �� ���ڿ��� �̾� ���̴� �Լ�
	wchar_t a[32] = L"Hello";

	// wcscat_s(a, 32, L" World"); // wcscat_s(a, L" World");
	WStrCat(a, 32, L" World");

	int result = wcscmp(L"abc", L"aba");

	result = WStrCmp(L"gbc", L"abb");
}

unsigned int GetLength(const wchar_t* p)
{
	unsigned int i = 0;

	// �� ������ �� ��, ���ʿ� r-value�� ���� ������ ������.
	// p[i] = '\0'�� ���� �Ǽ��� ������ ��, ������ �ܰ迡�� Ȯ���� �����ϱ� �����̴�.
	while ('\0' != p[i])
	{
		++i;
	}

	return i;
}

void WStrCat(wchar_t* dest, unsigned int bufferSize, const wchar_t* src)
{
	// �̾� ���� ���ڿ��� ���̰� bufferSize�� �Ѿ�� ��쿡 ���� ����ó�� ����
	int destLen = GetLength(dest);
	int srcLen = GetLength(src);
	
	// NULL ���� ���� +1
	assert(bufferSize >= destLen + srcLen + 1);

	// ���ڿ� �̾� ���̱�
	// 1. dest ���ڿ��� �� �ּ� �ľ�(���ڿ��� �̾� ���� ���� ��ġ �ľ�)
	// --> destLen
	
	// 2. �ݺ������� src ���ڿ��� dest �� ��ġ�� �����ϱ�
	// 3. src ���ڿ��� ���� ������ �ݺ� ����
	// ���ڿ��� ���� NULL ���ڵ� ����ǵ��� srcLen + 1��ŭ ����
	for (int i = 0; i < srcLen + 1; ++i)
	{
		dest[destLen + i] = src[i];
	}
}

int WStrCmp(const wchar_t* string1, const wchar_t* string2)
{
	// �� ���ڿ� ���ϱ�
	// 1. 0�� �ε������� �� ���ڿ� �� ª�� ���ڿ��� ���̱��� ��ȸ�ϸ� ���ڸ� ��
	// 2. ó������ �ٸ� ���ڰ� ������ ��, ���������� ������ ���� string1�� ��� -1��, string2�� ��� 1�� ��ȯ
	int i = 0, j = 0;

	while ('\0' != string1[i] && '\0' != string2[j])
	{
		if (string1[i] < string2[j])
		{
			return -1;
		}
		else if (string1[i] > string2[j])
		{
			return 1;
		}

		++i;
		++j;
	}

	// 3. �ݺ����� �����ٸ�, i�� j�� ���� ������ ��� ���� ����, �ٸ� ������ ��� ª�� ���� �� ���� ���ڷ� �Ǵ��� �� �ִ�.
	while ('\0' != string1[i])
	{
		++i;
	}

	while ('\0' != string2[j])
	{
		++j;
	}

	if (i < j)
	{
		return -1;
	}
	else if (i > j)
	{
		return 1;
	}

	return 0;
}

void Func(int a)
{
}

void Func(float a)
{
}
