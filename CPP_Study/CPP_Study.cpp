#pragma region cpp1강
//
//#include <iostream>
//using namespace std;
//// 이렇게 주석을 달 수 있어요!
//
//
//// 프로그래밍을 단순하게 생각하면
//// 적절한 데이터를 저장하고 가공하는 것
//// 데이터 + 로직
//
//int hp = 100;
//
//// 초기값이 0이거나, 초기값이 없는 변수는 .bss 영역
//char a; // 1바이트 ( -128 ~ 127 )
//short b; // 2바이트 (-32768 ~ 32767)
//int c; // 4바이트 (-21.4억 ~ 21.4억 )
//__int64 d; // 8바이트 
//
//unsigned char ua; // 1바이트 ( 0 ~ 255 )
//unsigned short ub; // 2바이트 ( 0 ~ 655355 )
//unsigned int uc; // 4바이트 ( 0 ~ 42억 )
//unsigned __int64 ud; // 8바이트 
//
//// 참고 ) 이론적으로 양수만 존재할 수 있는 데이터 unsigned ?
//// 무조건 unsigned를 사용할 지 의견이 갈림
//// - 레벨이 음수라는 것은 말이 안된다 -> 그럼 크래쉬를 내서 버그를 빨리 찾는게 낫다
//// - unsigned / signed 사이의 변환
//
//// 귀찮은데 그냥 대충 4바이트로 가면 안될까?
//// -> 콘솔/모바일게임 -> 메모리 늘 부족... 
//// -> 온라인게임 -> 4바이트 낭비 * 1만명  
//
//int main()
//{
//    // 정수 오버 플로우
//    b = 32767;
//    b = b + 1;
//    cout << b << endl; // -32768
//    cout << "체력이 " << hp<<" 남았습니다.";
//
//    // 정수 언더플로우
//    ub = 0;
//    ub = ub - 1;
//    cout << ub << endl;
//}

#pragma endregion

#pragma region cpp2강 불리언과 정수
//#include<iostream>
//using namespace std;
//
//// 불리언 -> 참/거짓
//bool isHighLevel = true; 
//bool isPlayer = true;
//bool isMale = false;
//
//// [Note]
//// 사실 bool은 그냥 1바이트 정수에 불과
//// 왜 정수 시간에 안 다뤘을까?
//// ->일리있음.. 어셈블리에는 심지어 bool이 없음.
//// bool만 봐도 참/거짓 둘 중 하나라는 힌트를 줍니다.(가독성)
//int isFemale = 1; // 
//
//// bool <- 1바이트 정수
//
//// 실수 (부동소수점)
//// float double
//// 3.14 
//// 점 앞/뒤를 기준으로 16비트씩 ?
//// 너무 표현 숫자가 적음. (0~65535).(0~65535) <- 좋은방법 x
//
//// 부동(뜰부)소수점 -> 소수점이 둥둥 움직이며 떠다님
//// .을 유동적으로 움직여서 표현하는 방법
//// 3.1415926535
//// 3.1415926535 = 0.31415926535 * 10 = 314.15926535 * 10^-2
//// 1) 정규화 = 0.31415926535 * 10
//// 2) 31415926535 (유효숫자) 1(지수 // 10의 몇승을 곱했냐)
//// 부동소수점 -> 유효부와 지수부 나눔
//
//// float -> 부호 1비트 지수 8비트 유효숫자 23비트 = 32비트 = 4바이트
//// double -> 부호 1비트 지수 11비트 유효숫자 52비트 = 64비트 = 8바이트
//float attackSpeed = -3.375f; // 4바이트 int처럼
//double attackSpeed2 = 123.4123; // 8바이트 
//
//// ex) -3.375라는 값을 저장
//// 1) 2진수 변환 = (3) + (0.375) = ob11 + 0b0.011 = 0b11.011
//// 0.375 = 0.5 * 0 + 0.25 * 1 + 0.125 * 1 = 0b0.011
//
//// 부동소수점은 항상 근사값
//// 수가 커질수록 오차 범위도 매우 커짐
//// 실수 2개를 == 으로 비교하는 것은 지양해야함
//
//int main()
//{
//    //if (isFemale != 1) // 이상
//    if(isMale == false) // 한번에 보임(가독성 good!)
//    {
//        //TODO
//    }
//
//    return 0;
//}
#pragma endregion

#pragma region 3강 문자와 문자열
//#include<iostream>
//using namespace std;
//
//// char : 알파벳 / 숫자 문자
//// wchar_t : 유니코드 문자를 나타낸다.
//char ch = 97; // 1바이트
//
//// ASCII ( American Standard Code for Information Interchange) - ANSI에서 만든 표준 코드체계
////-----------------------------------------------------------------
//// 전세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드(unicode)
//// UTF8 UTF16
//// 
//// UTF8(바이트 유동적)
//// - 알파벳, 숫자 1바이트(ASCII 동일한 번호)
//// - 유럽 지역의 문자는 2바이트
//// - 한글, 한자 등 3바이트
//
//// UTF16
//// - 모든 문자 2바이트 고정
//// - 매우 예외적으로 고대문자만 4바이트
//// wchar_t <- UTF16 타입
//wchar_t wch = L'안'; // L은 유니코드로 캐스팅
////wchar_t wch = 0xc548; 
//
//// Escape Sequence
//// 표현하기 애매한 애들을 표현
//// \t = 아스키코드9번 = Tab;
//// \n = 아스키코드10번 = LineFeed - 한줄아래로
//// \r = 아스키코드13번 = CarriageReturn ( 커서 << )
//// 엔터치면 \r\n
//// ' 를 문자로 표현하고 싶으면 \'
//
//// 문자열
//// 문자들이 열을 지여서 모여 있는 것
//// 정수(1~8바이트) 고정 길이였음 하지만
//// 문자열은 가변적!
//// 맨 끝에는 \0 (null - 아스키코드0번)
//
//char str[] = { 'h','e','l','l','0','\0' }; // '\0'로 끝나야만 함
//char str2[] = "Hello World"; // 자동으로 null 값 추가됨.
//wchar_t str3[] = L"Hello World"; // 유니코드도 자동으로 null 값 추가
//
//int main()
//{
//    //cout은 char 전용
//    cout << ch << endl;
//
//    wcout.imbue(locale("kor")); // 한국어를 인식해줘!
//    wcout << wch << endl;
// 
//    cout << str << endl; 
//
//    return 0;
//}
#pragma endregion

#pragma region 4강 데이터연산
#include<iostream>	
using namespace std;

// 데이터 연산
int a = 1;

int b = 2;

int main()
{
	//산술 연산자
	// ㄴ대입연산 
	// ㄴ사칙연산 

	// 대입연산
	// a에 b를 대입하고 b를 반환하라
	// -> b라는 바구니 안에 있는 값을, a라는 바구니 안에다 복사한다
	a = b;
	a = b = 3; // 오른쪽 부터 왼쪽으로 연달아 실행

	// 사칙연산
	// 언제 필요한가?
	// ex) 데미지 계산
	// ex) 체력을 깎는다거나
	// ex) 루프문에서 카운터를 1 증가시킨다거나

	return 0;
}


#pragma endregion 
//
//#include<iostream>	
//using namespace std;
//
//
//int main()
//{
//
//	return 0;
//}



