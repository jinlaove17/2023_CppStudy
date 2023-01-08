// define 전처리: 가독성, 유지보수 용이
#define HUNGRY    0x0001
#define THIRSTY   0x0002
#define TIRED     0x0004
#define BURNING   0x0008
#define FROZEN    0x0010
#define POISON    0x0020

#define MAX_SIZE      20

// 주석: 설명 역할, 코드로 인식되지 않는다.

int main()
{
	// 자료형(Data Type), 크기 단위: 바이트(byte)
	// 정수형: char(1), short(2), int(4), long(4), long long(8)
	// 실수형: float(4), double(8)
	int i = 0;
	unsigned char c = 0;

	c = 0;
	//c = 255;
	c = -1;

	// 1. 바이트로 양수, 음수 둘 다 표현
	// -128 ~ 0 ~ 127
	char c1 = 0;

	c1 = 255;

	// 음의 정수 찾기(2의 보수법)
	// 대응되는 양수의 부호를 반전 후, 1을 더한다.

	// 아래 식은 암묵적 형변환이 일어난다.
	int a = 4 + 4.0;

	// 정수표현 방식과 실수 표현 방식은 다르다.
	// 실수 표현방식은 정밀도에 의존한다.
	// 따라서 double 자료형이 float 보다 더 정밀한 표현이 가능하다.

	// 실수를 상수로 적을 경우 소수점 뒤에 f를 붙일 경우 float 자료형으로, 붙이지 않을 경우 double 자료형으로 처리한다.

	// 정수는 정수끼리, 실수는 실수끼리 연산하되, 두 표현방식의 피연산자가 연산될 경우 명시적으로 변환하자.
	float f = 10.2415f + (float)20;

	// 연산자
	// 대입 연산자: =
	// 산술 연산자: +, -, *, /, %(피연산자가 모두 정수인 경우에만 사용 가능)
	// 증감 연산자: ++, --
	// 논리 연산자: !(REVERSE), &&(AND), ||(OR)
	// 비교 연산자: ==, !=, <, >, <=, >=
	// 참: true, 0이 아닌 값으로 주로 1, 거짓: false, 0
	int data = 10 + 10;

	// data = data + 20;
	data += 20; 

	data = 10 / 3;
	data = 10 % 3;

	// data = 10.0 / 3.0;
	data = (int)(10.0 / 3.0);

	data = 0;
	data++; // 1
	data--; // 0

	// 후위 연산자는 연산자 우선 순위가 가장 나중이다.
	++data; // 전위
	data++; // 후위

	a = 10;
	data = a++; // data는 10

	// 웬만하면 전위 연산자를 사용하자.(클래스 연산자 오버로딩의 경우 복사가 일어날 수 있기 때문에)

	bool truefalse = true;
	bool isTrue = 100; // true

	isTrue = !truefalse;

	int n = 100;
	
	n = !n;
	n = 0 && 200;

	// 구문
	// if, else
	if (100 && 200)
	{
		data = 0;
	}
	else if (data == 100)
	{
		data *= 10;
	}
	else
	{
		data /= 5;
	}
	
	// switch case
	// 정수나 열거형 계열만 사용 가능
	switch (5)
	{
	case 10:
	case 20:
		break;
	case 30:
		break;
	default:
		break;
	}

	// 삼항 연산자
	data = (data == 20) ? 50 : 80;

	// 같은 의미
	if (data == 20)
	{
		data = 50;
	}
	else
	{
		data = 80;
	}

	// 비트 연산자: <<, >>, ~(REVERSE), &(AND), |(OR), ^(XOR)
	// ~: 0은 1으로, 1은 0으로
	// &: 둘 다 1인 경우 1
	// |: 적어도 하나가 1인 경우 1
	// ^: 같으면 0, 다르면 1
	unsigned char byte = 8;

	byte <<= 2; // 2^n를 곱한다.
	byte >>= 3; // 2^n로 나눈다.

	unsigned int status = HUNGRY; // status = 1;

	// 상태 추가
	status |= THIRSTY;

	// 상태 확인
	if (status & THIRSTY)
	{

	}

	// 특정 자리 비트 제거
	status &= ~THIRSTY;
}
