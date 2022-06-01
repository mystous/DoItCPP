#include <iostream>

int main()
{
    int i, j;
    std::cout << "Enter num_1: ";	//문자열 출력
    std::cin >> i;			//사용자에게 정수형 숫자 입력 받아서 변수 i 에 저장
    std::cout << "Enter num_2: ";	//문자열 출력
    std::cin >> j;			// 사용자에게 정수형 숫자 입력 받아서 변수 j 에 저장
    std::cout << " num_1 + num_2 = " << i + j << std::endl;	//입력 받은 두 숫자 합계 출력
    return 0;
}

