#pragma region 포인터 실습
//#include<iostream>
//using namespace std;
//struct StatInfo
//{
//	int hp; // +0(메모리 위치)
//	int attack; // +4
//	int defence; // +8
//};
//
//void EnterLobby();
//StatInfo CreatePlayer();
//void CreateMonster(StatInfo* info);
//// 플레이어 승리시 true, 아니면 false
//bool StartBattle(StatInfo* player, StatInfo* monster);
//
//int main()
//{
//	EnterLobby();
//	return 0;
//}
//#pragma endregion
//
//void EnterLobby()
//{
//	cout << "로비에 입장 했습니다." << endl;
//
//	StatInfo player;
//	player.hp = 0xbbbbbbbb;
//	player.attack = 0xbbbbbbbb;
//	player.defence = 0xbbbbbbbb;
//	player = CreatePlayer();
//
//	StatInfo monster;
//	monster.hp = 0xbbbbbbbb;
//	monster.attack = 0xbbbbbbbb;
//	monster.defence = 0xbbbbbbbb;
//
//	CreateMonster(&monster);
//
//	// 번외편
//	// 구조체끼리 복사할 때 무슨 일이 벌어질까?
//	// 
//	player = monster; 
//	// 내부에서는 이런 일이 일어남. 한줄짜리여도 빠르지 않음.
//	player.hp = monster.hp;
//	player.attack = monster.attack;
//	player.defence = monster.defence;
//
//	bool victory = StartBattle(&player, &monster);
//	if (victory)
//		cout << "승리~!" << endl;
//	else
//		cout << "패배" << endl;
//}
//
//StatInfo CreatePlayer()
//{
//	StatInfo ret;
//	cout << "플레이어 생성" << endl;
//	ret.hp = 100;
//	ret.attack = 10;
//	ret.defence = 2;
//	return ret;
//}
//
//void CreateMonster(StatInfo* info)
//{
//	cout << "몬스터 생성" << endl;
//
//	info->hp = 40;
//	info->attack = 8;
//	info->defence = 1;
//}
//
//bool StartBattle(StatInfo* player, StatInfo* monster)
//{
//	while (true)
//	{
//		int damage = player->attack - monster->defence;
//		if (damage < 0)
//			damage = 0;
//		
//		monster->hp -= damage;
//		if (monster->hp < 0)
//			monster->hp = 0;
//
//		cout << "몬스터 HP: " << monster->hp << endl;
//
//		if (monster->hp == 0)
//			return true;
//
//		damage = monster->attack - player->defence;
//		if (damage < 0)
//			damage = 0;
//
//		cout << "플레이어 HP: " << player->hp << endl;
//		if (player->hp == 0)
//			return false;
//	}
//}

#pragma endregion
#pragma region 배열
//#include<iostream>
//using namespace std;
//struct StatInfo
//{
//	int hp = 0XAAAAAAAA;
//	int attack = 0XBBBBBBBB;
//	int defence  = 0XBBBBBBBB;
//};
//int main()
//{
//	// 배열의 이름은 뭐지?
//	const int monsterCount = 10;
//	StatInfo monsters[monsterCount]; // 상수만 배열 개수 가능
//
//	// 배열의 이름은 곧 배열의 시작 주소
//	// 정확히는 시작 위치를 가리키는 Type* 포인터
//	StatInfo* whoAmI = monsters; // 메모리 주소 검색할때 그냥 monsters로 검색해도 나옴. &monsters가 아니라
//	
//	// StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
//	StatInfo* monster_0 = monsters;
//	monster_0->hp = 100;
//	monster_0->attack = 10;
//	monster_0->defence = 1;
//
//	StatInfo* monster_1 =  monster_0 + 1; // 포인터라 다음 주소로! (StatInfo 크기만큼 이동)
//	monster_1->hp = 200;
//	monster_1->attack = 20;
//	monster_1->defence = 2;
//
//	//포인터와 참조는 자유자재로 변환 가능
//	StatInfo& monster_2 = *(monsters + 2);
//	monster_2.hp = 300;
//	monster_2.attack = 30;
//	monster_2.defence = 3;
//
//	// 자동화
//	for (int i = 0; i < 10; i++)
//	{
//		StatInfo& monster = *(monsters + i);
//		monster.hp = 100 *(i + 1);
//		monster.attack = 10 * (i + 1);
//		monster.defence = 1 * (i + 1);
//	}
//
//	// 근데 *(monsters + i) 가독성이 안좋음
//	// 인덱스 사용! [0] ~ [n]
//	// *(monsters + i) == monsters[i] 
//	// 인덱스는 0번부터
//	for (int i = 0; i < 10; i++)
//	{
//		monsters[i].hp = 100 * (i + 1);
//		monsters[i].attack = 10 * (i + 1);
//		monsters[i].defence = 1 * (i + 1);
//	}
//
//	// 배열 초기화 문법 몇가지 (for문도 가능)
//	int numbers[5]; // 초기화 안됨. 
//	int numbers2[5] = {}; // 모두 0으로 초기화
//	int numbers3[10] = {1,2,3,4,5}; // 1,2,3,4,5 까지는 초기화 나머지는 0으로 초기화
//	int numbers4[] = {1,2,3,4,5}; // 5개 배열 생성.
//
//	char helloString[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
//	cout << helloString << endl;
//
//
//	return 0;
//}
#pragma endregion

#pragma region 포인터 vs 배열
#include<iostream>
using namespace std;

// 포인터 vs 배열
int main()
{
	// 주소[H][e][l][l][o][][W]....  .data영역에있음 
	// test1[ 주소 ] << 8바이트크기
	const char* test1 = "Hello World";
	
	char test2[] = "Hello World";
	
	return 0;
}
#pragma endregion