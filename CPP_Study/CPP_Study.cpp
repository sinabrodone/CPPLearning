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
//#include<iostream>	
//using namespace std;
//
//// 데이터 연산
//int a = 1;
//
//int b = 2;
//
//int main()
//{
//	//산술 연산자
//	// ㄴ대입연산 
//	// ㄴ사칙연산 
//
//	// 대입연산
//	// a에 b를 대입하고 b를 반환하라
//	// -> b라는 바구니 안에 있는 값을, a라는 바구니 안에다 복사한다
//	a = b;
//	a = b = 3; // 오른쪽 부터 왼쪽으로 연달아 실행
//
//	// 사칙연산
//	// 언제 필요한가?
//	// ex) 데미지 계산
//	// ex) 체력을 깎는다거나
//	// ex) 루프문에서 카운터를 1 증가시킨다거나
//
//	return 0;
//}
#pragma endregion 

#pragma region 비트단위연산 잘모르는것!!!(복습)
//#include<iostream>
//#include <climits>
//using namespace std;
//
//
//int main()
//{
//	// 비트단위 연산자
//	// 언제 필요한가(사실 많이는 없음)
//	// 비트 단위의 조작이 필요할때
//	// 대표적으로 BitFlag
//
//	// ~ : bitwise not
//	// 단일 숫자의 모든 비트 대상으로, 0은1, 1은 0으로 뒤바뀜
//	// 0b1001 -> ob0110
//
//	// & bitwise and
//	// 두 숫자의 모든 비트 쌍을 대상으로, and연산
//	// 0b1100 & 0b1010 -> 0b1000
//
//	// | bitwise or
//	// 두 숫자의 모든 비트 쌍을 대상으로, or연산 -> 둘중 하나라도 1이면 1. 
//	// 0b1100 & 0b1010 -> 0b1110
//
//	// ^ bitwise xor
//	// 두 숫자의 모든 비트 쌍을 대상으로, xor연산 -> 두숫자가 같으면 0, 다르면 1
//	// 두번 xor연산하면 숫자 원상복구
//	// int a = 1; int b = 123; a ^ b 두번하면 다시 원상복구 -> 암호학에서 많이 쓰임
//
//	// << 비트 좌측 이동
//	// 비트열을 N만큼 왼쪽으로 이동
//	// 왼쪽의 넘치는 N개의 비트는 버린다, 새로 생성되는 n개의 비트는 0으로 채워짐.
//	// *2를 할 때 자주 보이는 패턴 (한칸씩 왼쪽갈때 2곱해짐)
//
//	// >> 비트 우측 이동
//	// 비트열을 N만큼 오른쪽으로 이동
//	// 오른쪽에 넘치는 n개의 비트는 버림.
//	// 왼쪽 생성되는 n개의 비트는
//	// - 부호 비트가 존재할 경우 부호 비트를 따라감(부호있는 정수라면 이 부분 유의)
//	// - 아니면 0
//
//	// 실습 (bitFlag)
//	// 0b0000 [무적][변이][스턴][공중부양] // 각자 bool로 만들어도 되지만 상태가 엄청 많다면 ?
//	// bitflag는 웬만하면 unsigned 형으로 -> 음수가 딸려올수 있음
//	unsigned char flag;
//
//	// 무적 상태로 만든다.
//	flag = (1 << 3); // 8로 기억하기 힘듦.
//
//	// 변이상태를 추가한다 (무적 + 변이)
//	flag |= (1 << 2);
//
//	// 무적인지 확인하고 싶다면 //bitmask(필요없는 정보 날릴 수 있음)
//	bool isInvincible = ((flag & (1 << 3)) != 0);
//
//	// 무적이거나 스턴 상태인지 확인하고 싶다면?
//	bool mask = (1 << 3) | (1 << 1);
//	bool isInvinOrStunned = ((flag & mask) != 0);
//
//	return 0;
//}

#pragma endregion

#pragma region 상수 메모리영역
//#include<iostream>
//using namespace std;
//
//// 한번 정해지면 절대 바뀌지 않을 값들
//// constant약자인 const (상수화)
//
//// 그러면 const도 바뀌지 않는 읽기전용이면 .rodata영역? 
//// 사실 C++ 표준에서 그렇게 하라는 말이 없음.
//const int AIR = 0;
//const int STUN = 1;
//const int POLYMORPH = 2;
//const int INVINCIBLE = 3; // INVINCIBLE = 4 <- 불가능 // const는 반드시 초기화 해줘야함 const int INVINCIBLE; 불가능
//
//// 전역변수 [데이터영역]
//// .data (초기값 있는 경우)
//int a = 2;
//// .bss (초기값 없는 경우)
//int b;
//// .rodata (읽기 전용 데이터) (READONLY)
//const char* msg = "Hello World!";
//
//int main()
//{
//	// 지역 변수 [스택영역]
//	int c = 3;
//
//}
#pragma endregion

#pragma region 유의사항
//#include<iostream>
//using namespace std;
////유의사항
//// 1)스택 괄호범위. 같은이름 변수 x
//// 2) 연산 우선순위 -> ()사용!
//// 3) 타입변환  -> 캐스팅.. 손실발생가능
//// 4) 사칙연산 관련 
//
//int main()
//{
//	int hp = 123;
//	cout << hp << endl;
//
//	// 캐스팅(바구니교체)
//	short hp2 = (short)hp; // 윗쪽 비트 데이터가 짤린 상태로 저장.
//	float hp3 = (float)hp; // 실수로 변환할 대 정밀도 차이가 있기 때문에 데이터 손실.
//	unsigned hp4 = (unsigned int)hp; // 비트단위는 데이터 똑같은데, 분석하는 방법이 달라져서..
//
//	// 곱셈
//	// - 오버플로우 -> 자료형(ex) int)이 표현할 수 있는 숫자 넘어설 수 있음
//	// 너무 큰값을 곱할때 조심
//
//	// 나눗셈
//	// - 0나누기 조심!!!
//	// - 실수(float) 관련
//
//	int maxHp = 1000;
//	float ratio = hp / maxHp; // int / int 는 int로 생각됨. 
//	// float/int or int / float => float으로 인식!
//	return 0;
//}

#pragma endregion

#pragma region 조건문
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	const int ROCK = 0;
//	const int PAPER = 1;
//	const int SCISSORS = 2;
//
//	int input = ROCK;
//
//	switch (input) // 정수계열만 넣을 수 있음
//	{
//	case ROCK:
//		cout << "주먹을 냈습니다" << endl;
//		break;
//	case SCISSORS:
//		cout << "가위를 냈습니다" << endl;
//		break;
//	case PAPER:
//		cout << "보를 냈습니다" << endl;
//		break;
//	default:
//		cout << "뭘 낸것입니까??" << endl;
//		break;
//	}
//
//	return 0;
//}
//
#pragma endregion

#pragma region 반복문(별찍기)
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	// 별찍기)
//	// 유저들이 어떤 정수를 입력하면
//	// N*N개의 별을 찍었으면 좋겠어요
//	//int input;
//	//cin >> input;
//
//	//for (int i = 0; i < input; i++)
//	//{
//	//	for (int j = 0; j < input; j++)
//	//	{
//	//		cout << '*';
//	//	}
//	//	cout << endl;
//	//}
//
//	// 별찍기2)
//	// 1개부터 시작해서 순차적으로 줄마다 증가하게 수정해주세요!
//	//int input; cin >> input;
//	//
//	//for (int i = 0 ; i < input; i++)
//	//{
//	//	for (int j = 0; j < i + 1; j++)
//	//	{
//	//		cout << '*';
//	//	}
//	//	cout << endl;
//	//}
//
//	// 별찍기3)
//	// n개부터 시작해서 줄마다 1개씩 줄어드는 형태로!
//	// 
//	/*int input; cin >> input;
//	for (int i = 0 ; i < input; i++)
//	{
//		for (int j = 0; j < input - i; j++)
//		{
//			cout << '*';
//		}
//
//		cout << endl;
//	}*/
//
//
//	// 구구단)
//	// 2단부터 9단까지 구구단을 출력해주세요
//	//
//	/*for(int i = 2; i<=9; i++)
//	{
//		for (int j = 1; j <= 9; j++)
//		{
//			cout << i << " * " << j << " = " << i * j << endl;
//		}
//		cout << i << "단 끝!" << endl;
//	}*/
//	return 0;
//}

#pragma endregion

#pragma	region 가위바위보(랜덤만들기)
//#include<iostream>
//using namespace std;
//
//const int ROCK = 1;
//const int SCISSORS = 2;
//const int PAPER = 3;
//
//int main()
//{
//	// 시드값 설정
//	srand(unsigned int(time(0))); 
//
//	//rand(); // 0~32767
//	//rand() % 3; // 0~2
//	int value = 1+ (rand() % 3); // 1~3 (가위바위보)
//
//	int wins = 0;
//	int totalGame = 0;
//
//	while (true)
//	{
//		cout << "바위(1) 가위(2) 보(3) 골라주세요!" << endl;
//		
//		cout << "> ";
//
//		if (totalGame != 0)
//		{
//			cout << "현재승률 : "<< (wins * 100) / totalGame << endl;
//		}
//		else
//			cout << "현재승률 : 없음" << endl;
//		
//		int computer = 1 + (rand() % 3); // 1~3 (가위바위보)
//		int input;
//		cin >> input;
//
//		switch (input)
//		{
//		case ROCK:
//			if (computer == ROCK)
//				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다";
//			else if (computer == SCISSORS)
//			{
//				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다";
//				wins += 1;
//			}
//				
//			else
//				cout << "바위(님) vs 보(컴퓨터) 졌습니다";
//			break;
//		case SCISSORS:
//			if (computer == ROCK)
//				cout << "가위(님) vs 바위(컴퓨터) 졌습니다";
//			else if (computer == SCISSORS)
//				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다";
//			else
//			{
//				cout << "가위(님) vs 보(컴퓨터) 이겼습니다";
//				wins++;
//			}
//			break;
//		case PAPER:
//			if (computer == ROCK)
//			{
//				cout << "보(님) vs 바위(컴퓨터) 이겼습니다";
//				wins++;
//			}
//			else if (computer == SCISSORS)
//				cout << "보(님) vs 가위(컴퓨터) 졌습니다";
//			else
//				cout << "보(님) vs 보(컴퓨터) 비겼습니다";
//			break;
//		default:
//			break;
//		}
//		totalGame++;
//		cout << endl;
//		cout << endl;
//		
//
//		if (input > 3 || input < 1)
//		{
//			cout << "게임을 끝냈습니다!" << endl;
//			break;
//		}
//	}
//
//
//	return 0 ;
//}

#pragma endregion

#pragma region 열거형
//#include<iostream>
//using namespace std;
//
//// const int 이런것들은 상수인건 알겠는데 너무 따로노는 느낌
//// const 는 초기값을 정해야 했음
//// 하나의 세트로 관리
//
//// 숫자를 지정 안하면 0부터 시작
//// 나머지 값들은 이전값부터 ++
//enum ENUM_SRP
//{
//	ENUM_SCISSORS = 1,
//	ENUM_ROCK,
//	ENUM_PAPER,
//};
//
//// #이 붙은거 -> 전처리 지시문 (전처리단계에서) - 코드 바꿔치기
//// ㄴ#include<iostream> 이라는 파일을 찾아서 복붙해줘!
//// ㄴ빌드단계 : 1) 전처리(기초작업) 2) 컴파일(통역사) 3) 링크 (오브젝트파일 엮기)
//#define DEFINE_SCISSORS 1 // #define 매크로 만들기 
//#define DEFINE_TEST cout << "Hello World" << endl; // #define 매크로 만들기 
//
//int main()
//{
//	DEFINE_TEST;
//	return 0;
//}
#pragma endregion 

#pragma region 함수
//함수 : 프로시져, 메소드(C#), 함수, 루틴 다양하게 불림

//int MultbyInt(int a, int b)
//{
//	return a * b;
//}
//
//// 디버그 : f10 -> 함수단위건너뜀, f11-> 한 줄 한 줄
//int main()
//{
//	int result = MultbyInt(2, 3);
//	return 0;
//}

#pragma endregion

// 구조체 크기는 자료형의 합 크기 아님.. 패딩

#pragma region 포인터
//#include<iostream>
//using namespace std;
//void SetHP(int* hp)
//{
//	*hp = 100;
//}
//int main()
//{
//	int number = 1;
//	// TYPE* 변수이름;
//	// 일단 2가지 요소
//	// - TYPE
//	// - *
//
//	// 다른 타입처럼 바구니는 바구니인데..
//	// [주소를 저장하는 바구니이다!!]
//	// 변수 선언할 때 * 등장했다 -> 포인터 -> 포인터는 주소를 떠올리면됨.
//	// ex) 포인터라는 바구니는 4바이트(x84 32비트환경) or 8바이트(x64환경) 고정 크기(int*건 char*건 상관없음)
//
//	// 포탈을 타고 순간이동 한다고 생각하자.
//	// *이 여러번 등장하니 헷갈리는데, 사용시점에 따라서 구분해서 기억하자.
//	// - 변수선언(주소를 저장하는 바구니다!)
//	// - 사용할 때(포탈 타고 순간이동!)
//	int* ptr = &number;
//	*ptr = 4;
//	int value = *ptr;
//	cout << number << ' ' << *ptr << endl;
//
//	// TYPE(int)은 왜 붙여줄까?
//	// 4 or 8바이트 고정인데 왜..?
//	// 포인터에 대한 추가 정보	
//	// 주소에 가면 뭐가 있는데?
//	// ex) 결혼식 청첩장에 있는 주소 -> 예식장 주소
//	// ex) 명함에 있는 주소 -> 회사 주소
//	
//	// 타입의 불일치 테스트
//	__int64* ptr2 = (__int64*)&number;
//
//	int hp = 1;
//	cout << "before SetHP() hp : " << hp << endl;
//	SetHP(&hp);
//	cout << "after SetHP() hp : " << hp << endl;
//	return 0;
//}
#pragma endregion

#pragma region 포인터 연산
//#include<iostream>
//using namespace std;
//
//struct Player
//{
//	int hp;
//	int damage;
//};
//
//// 포인터 연산
//// 1) 주소 연산자(&)
//// 2) 산술 연산자(+ -)
//// 3) 간접 연산자
//// 4) 간접 멤버 연산자
//
//int main()
//{
//	int number = 1;
//
//	// 1) 주소 연산자 (&)
//	// - 해당 변수의 주소를 알려주세요~
//	// - 더 정확히 말하면 해당 변수 타입에 따라서 TYPE* 반환
//	int* pointer = &number;
//	
//	// 2) 산술 연산자(+ -) // 배열 때문에 사용.
//	number += 1; // 1 증가함
//
//	// int*
//	// - * -> 포인터 타입이네! (8바이트) 주소를 담는 바구니!
//	// - int : 주소를 따라가면 int가 있다고 가정해라!
//
//	// [!] 포인터에서 +나 -등 산술 연산으로 1을 더하거나 빼면
//	// 정말 '그 숫자'를 더하고 빼라는 의미가 아니다.
//	// 한번에 TYPE의 크기만큼 이동하라!
//	// 다음 바구니로 이동시켜줘 라고 생각해야함
//	// 즉 1을 더하면 -> 바구니 1개 이동시켜줘
//	// 3을더하면 -> 바구니 3개 이동시켜줘
//	pointer += 1; // 4 * 1증가함.(int 크기만큼)
//
//	// 3) 간접 연산자(*)
//	// - 포탈 타고 해당 주소로 슝~ 이동
//	*pointer = 3;
//
//	
//	Player player;
//	player.hp = 100;
//	player.damage = 10;
//
//	Player* playerPtr = &player;
//	(*playerPtr).hp = 200;
//	(*playerPtr).damage = 20;
//
//	// 4) 간접 멤버 연산자 (->)
//	// * : 간접 연산자 ( 포탈타고 해당 주소로 gogo )
//	// . : 구조체의 특정 멤버를 다룰때 사용
//	// ->는 *와 .을 합친것
//	playerPtr->hp = 180;
//	playerPtr->damage = 80;
//
//
//	return 0;
//}
#pragma endregion


#pragma endregion 