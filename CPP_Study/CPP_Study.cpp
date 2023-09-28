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

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<Windows.h>
#include<vector>    // C++ vectror   : https://blockdmask.tistory.com/70
#include<fstream>    // C++ 파일입출력 : https://blockdmask.tistory.com/322
using namespace std;

//콘솔 내부의 특정 위치로 커서를 이동시키는 함수 입니다.
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//keyboard 입력
int GetKeyDown()
{
    if (_kbhit() != 0)        //키보드에 뭔가 입력이 오면
    {
        return _getch();    //입력된 키값을 반환.
    }
    return 0;
}

//콘솔 세팅
void SetConsoleView()
{
    system("mode con:cols=50 lines=20");        //화면크기
    system("title [HangManGame] by.BlockDMask");    //게임이름
}

//시작화면 draw
void DrawReadyGame()
{
    system("cls");
    gotoxy(5, 2);
    cout << "==============================";
    gotoxy(5, 3);
    cout << "======= HANG MAN GAME ========";
    gotoxy(5, 4);
    cout << "==============================";
    gotoxy(6, 6);
    cout << "시작하려면 's'를 눌러주세요";
    gotoxy(6, 7);
    cout << "종료하려면 'q'를 눌러주세요";
    gotoxy(9, 14);
    cout << "by. BlockDMask" << endl;
}

//게임화면 draw
void DrawStartGame(int life, int score, vector<string>& pastWord)
{
    system("cls");
    gotoxy(5, 1);
    cout << "life = " << life;
    gotoxy(5, 2);
    cout << "score = " << score;
    gotoxy(5, 8);
    cout << "past = ";
    for (int i = 0; i < static_cast<int>(pastWord.size()); ++i)
    {
        cout << pastWord[i] << " ";
    }

    gotoxy(5, 12);
    cout << "input = ";
    gotoxy(13, 14);
    cout << "메인화면 'qq'" << endl;
}

//사전을 세팅하는 함수 입니다.
//[C++] 파일입출력 포스팅 : https://blockdmask.tistory.com/322
void SetDictionary(vector<string>& strArr)
{
    static const int INIT_NUM = 4;
    static const string str[INIT_NUM] = { "apple", "banana", "code", "program" };    //샘플 단어들
    ifstream readFromFile("words.txt");        //words.txt 파일을 읽기 전용으로 오픈
    if (!readFromFile.is_open())            //is_open이 되지 않는다는것은 파일이 존재하지 않다는 뜻.
    {
        ofstream writeToFile("words.txt");    //쓰기 전용으로 words.txt 파일을 오픈 (파일이 없으면 자동 생성됨)
        for (int i = 0; i < INIT_NUM; ++i)    //샘플 단어들을 format에 맞게 words.txt 파일에 입력
        {
            string tmp = str[i];
            if (i != INIT_NUM - 1)
            {
                tmp += "\n";
            }
            writeToFile.write(tmp.c_str(), tmp.size());    //파일에 쓰는 함수
            strArr.push_back(str[i]); //단어장(strArr)에 단어를 집어넣습니다.
        }
        writeToFile.close();    //쓰기전용파일 닫기
        return;                    //함수끝
    }

    //여기로 왔다는것은 읽기전용으로 파일오픈 되었다는뜻.
    while (!readFromFile.eof())    //파일 끝까지
    {
        string tmp;
        getline(readFromFile, tmp);    //한줄씩 읽어서
        strArr.push_back(tmp);        //단어장(strArr)에 단어 넣기
    }
    readFromFile.close();        //읽기전용파일 닫기
    return;
}
//시작화면 기능
bool ReadyGame()
{
    DrawReadyGame();    //시작화면 그리기
    while (true)
    {
        int key = GetKeyDown();                //키가 들어오면
        if (key == 's' || key == 'S')        //s는 스타트
        {
            return true;
        }
        else if (key == 'q' || key == 'Q')    //q는 끝
        {
            break;
        }
    }
    return false;
}

//게임 시작 함수.
void StartGame()
{
    int score = 0;
    vector<string> pastWord;    //입력한 영단어 저장
    vector<string> strArr;        //맞출 단어장
    SetDictionary(strArr);        //read from file

    while (true)    //하나의 탄을 표현하는 루프
    {
        //1 play
        int num = 0;
        srand((unsigned int)time(NULL));    //랜덤함수 : https://blockdmask.tistory.com/308
        num = rand() % static_cast<int>(strArr.size());    //단어장 내에 랜덤한 단어 선택

        string strQuestion;                        // _ _ _ _ _ 로 표현할 변수
        const string strOriginal = strArr[num];    //단어가 맞는지 정답확인용으로 저장
        const int originLen = static_cast<int>(strOriginal.length());

        //init
        for (int i = 0; i < originLen; ++i)
        {
            strQuestion += "_";    //정답 길이만큼 "_"
        }

        int life = originLen + 2;    //생명력은 정답 단어 길이 + 2

        //1 question
        while (true)    //하나의 단어를 맞추는 루프
        {
            DrawStartGame(life, score, pastWord);    //사용단어, 생명력, 점수표기

            //draw question
            gotoxy(5, 5);
            for (int i = 0; i < originLen; ++i)
            {
                cout << strQuestion[i] << " ";    // _ _ _ _ 표기
            }
            cout << endl;

            //input
            gotoxy(9, 12);
            string strInput;
            cin >> strInput;    //입력 받기.
            if (strInput == "qq")
            {
                return;
            }
            pastWord.push_back(strInput);    //한번 입력한 단어는 pastword에서 표기

            if (strInput.length() == 1)        //입력받은 스트링의 길이가 1인경우
            {
                //alphabet
                for (int i = 0; i < originLen; ++i)
                {
                    if (strOriginal[i] == strInput[0])    //오리지널 단어에 입력한 알파벳이 있는경우
                    {
                        strQuestion[i] = strInput[0];    // 해당 위치의 "_" 를 알파벳으로 바꿔줌 
                    }
                }
            }
            else if (strInput.length() > 1)    //입력받은 스트링의 길이가 1보다 큰 경우
            {
                //word
                if (strOriginal == strInput) //오리지널 단어랑 입력 단어가 같을때 (정답)
                {
                    //score up !!
                    score += 5;
                    pastWord.clear();
                    break;    //하나의 단어를 맞추는 루프를 나가게되고 다음 탄으로 넘어가게 됩니다.
                }
            }

            //틀리거나, 맞거나 어쨋든 입력이 되면 라이프가 무조건 1개씩 깎입니다.
            life -= 1;
            if (life < 0)
            {
                score -= 5;
                if (score < 0)
                {
                    score = 0;
                }
                pastWord.clear();
                break;
            }
        }
    }
}

//메인함수
int main(void)
{
    SetConsoleView();
    bool isStart = false;
    while (true)
    {
        isStart = ReadyGame();    //readgame함수가 true면
        if (isStart)
        {
            StartGame();        //게임시작
        }
        else
        {
            break;
        }
    }
    return 0;
}




