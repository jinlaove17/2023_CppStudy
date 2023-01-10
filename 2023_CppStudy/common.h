#pragma once

// 정적 변수(static)
static int staticValue;

// 외부 변수(extern): 초기화하지 않아야 해당 변수가 있다는 것을 다른 파일에 알려준다. 이때, 다른 아무 곳에서나 int externValue = 0; 초기화가 되어야 한다.
extern int externValue;
