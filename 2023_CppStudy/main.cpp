#include <stdio.h>
#include <wchar.h>
#include <assert.h>

unsigned int GetLength(const wchar_t* p);
void WStrCat(wchar_t* dest, unsigned int bufferSize, const wchar_t* src);
int WStrCmp(const wchar_t* string1, const wchar_t* string2);

// 함수 오버로딩: 동일한 이름의 함수를 여러개 만들 수 있는 것(각 함수는 매개변수의 개수와 타입으로만 구분한다.)
void Func(int a);
void Func(float a);

int main()
{
	// 문자: char(1), wchar(2)
	char c = 'a';
	wchar_t wc = L'a';

	// 숫자 1과 문자 1은 메모리에 다르게 저장된다.
	c = 1;
	c = '1';

	// 문자열
	char str[] = "abcdef";

	// 문자열 L"abcdef"를 배열 wStr에 한 개씩 복사하여 초기화
	wchar_t wStr[] = L"abcdef"; // short arr[] = { 97, 98, 99, 100, 101, 102 };

	// L"abcdef"의 메모리 공간을 가리키는 포인터로 초기화 
	const wchar_t* p = L"abcdef";

	// 배열을 수정하는 것이므로 가능
	wStr[1] = 'z';

	// 상수 값을 수정하는 것이므로 불가능 'b' = 'z';와 같은 구문
	// 또한 L"abcdef"는 코드 영역(Read Only Memory)에서 관리되기 때문에 수정할 수 없다.
	// 강제 캐스팅 후 수정하려는 경우 프로그램이 런타임 에러를 발생시킨다.
	// p[1] = 'z';

	// 멀티바이트 문자셋 방식: 1바이트로 표현 가능한 문자는 1바이트로, 그 외의 문자는 2바이트로 표현하는 가변길이 방식의 문자 표현 방식(표준으로 쓰이지 않음)
	char test1[] = "abc한글";

	// 유니코드 문자셋 방식: 모든 문자를 2바이트로 표현하는 문자 표현 방식
	wchar_t test2[] = L"abc한글";

	wchar_t name[] = L"Raimond";

	// wcslen(): 문자열의 길이를 구하는 함수
	int len = wcslen(name);

	// wcslen() 함수를 직접 구현해보자.
	len = GetLength(name);

	// wcscat_s(): 두 문자열을 이어 붙이는 함수
	wchar_t a[32] = L"Hello";

	// wcscat_s(a, 32, L" World"); // wcscat_s(a, L" World");
	WStrCat(a, 32, L" World");

	int result = wcscmp(L"abc", L"aba");

	result = WStrCmp(L"gbc", L"abb");
}

unsigned int GetLength(const wchar_t* p)
{
	unsigned int i = 0;

	// 비교 연산을 할 때, 왼쪽에 r-value를 놓는 습관을 들이자.
	// p[i] = '\0'와 같은 실수를 범했을 때, 컴파일 단계에서 확인이 가능하기 때문이다.
	while ('\0' != p[i])
	{
		++i;
	}

	return i;
}

void WStrCat(wchar_t* dest, unsigned int bufferSize, const wchar_t* src)
{
	// 이어 붙인 문자열의 길이가 bufferSize를 넘어서는 경우에 대한 예외처리 수행
	int destLen = GetLength(dest);
	int srcLen = GetLength(src);
	
	// NULL 문자 공간 +1
	assert(bufferSize >= destLen + srcLen + 1);

	// 문자열 이어 붙이기
	// 1. dest 문자열의 끝 주소 파악(문자열이 이어 붙을 시작 위치 파악)
	// --> destLen
	
	// 2. 반복적으로 src 문자열을 dest 끝 위치에 복사하기
	// 3. src 문자열의 끝을 만나면 반복 종료
	// 문자열의 끝인 NULL 문자도 복사되도록 srcLen + 1만큼 복사
	for (int i = 0; i < srcLen + 1; ++i)
	{
		dest[destLen + i] = src[i];
	}
}

int WStrCmp(const wchar_t* string1, const wchar_t* string2)
{
	// 두 문자열 비교하기
	// 1. 0번 인덱스부터 두 문자열 중 짧은 문자열의 길이까지 순회하며 문자를 비교
	// 2. 처음으로 다른 문자가 나왔을 때, 사전순으로 앞쪽인 값이 string1인 경우 -1을, string2인 경우 1를 반환
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

	// 3. 반복문이 끝났다면, i와 j가 같은 길이일 경우 동일 문자, 다른 길이일 경우 짧은 것이 더 앞의 문자로 판단할 수 있다.
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
