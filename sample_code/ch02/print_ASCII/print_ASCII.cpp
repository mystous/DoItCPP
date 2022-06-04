#include <iostream>

using namespace std;

int main()
{
	cout << "ASCII 코드 출력하기 [32 ~ 126]:\n";

	for (char i = 32; i <= 126; i++)	//32부터 126까지 순차적으로 1씩 증가시키며 반복
	{
		//ASCII 코드를 출력할 때 공백을 넣되, 16개 마다 줄 바꾸기. 어려운 코드가 아니에요!
		cout << i << ((i % 16 == 15) ? '\n' : ' ');
	}

	return 0;
}
