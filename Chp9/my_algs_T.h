// my_agls_T.h
#pragma once

#ifndef GUARD_my_algs_T_h
#define GUARD_my_algs_T_h

#include <cctype> // isspace()
#include <string>
#include <algorithm> // find_if()

using namespace std;

// 최댓값
template<class T>
T max(const T& left, const T& right) {
	return left > right ? left : right;
}

// 최솟값
template<class T>
T min (const T& left, const T& right) {
	return left < right ? left : right;
}

// 같은 값
template<class T> 
bool equals(const T& left, const T& right) {
	return left == right ? true : false;
}
// 같지 않은 값
template<class T> 
bool not_equals(const T& left, const T& right) {
	// return left == right ? false : true
	// return left != right ? true : false
	return !equals(left, right);
}

// 알 수 없는 자료형의 벡터에 있는 요소(값)을 찾기
template<class In, class X>
In find(In begin, In end, const X& x) {
	// 끝까지 안가서 값도 찾지 못해서
	while (begin != end && *begin !=x) {
		++begin;
	}

	return begin;
}

// 사본 만들기
template<class In, class Out>
Out copy(In begin, In end, Out dest) {
	// 첫 요소부터 끝까지 모든 begin 반복자에 있는 요소를 dest 반복자로 복사하기
	while (begin != end) {
		*dest++ = *begin++; // 사본을 만들고 이동 반복
	}
	return  dest;
}

// 덮어 쓰기 (바꾸기)
template<class For, class X>
void replace(For beg, For end, const X& x, const X& y) {
	while (beg != end) {
		if (*beg == x)
			*beg = y;

		++beg;
	}
}

// 역방향으로 재저장하기 (Bi = 2개)
template<class Bi>
void reverse(Bi begin, Bi end) {
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

// 이진 탐색 알고리즘 (sort 먼저 해야함)
template<class Oct, class X>
bool binary_search(Oct begin, Oct end, const X& x) {
	while (begin < end) {
		// 범위의 중간 지점 찾기
		Oct mid = begin + (end - begin) / 2;

		// 중간 지점을 기준으로 어느 부분이 x를 포함하는지 확인하고
		// 해당 부분에만 탐색을 계속 진행
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		// 이 지점에 도달하면 *mid == x 이므로 탐색 종료
		else
			return true;
	}
	return false;
}

// 인수가 공백일 때는 true, 아니면 false
bool space(char c) {
	return isspace(c); // #include <cctype>
}

// 인수가 공백일 때는 false, 아니면 true
bool not_space(char c) {
	return !isspace(c);
}

// 문자열 나누기
template<class Out>
void split(const string& str, Out os){ // 변경됨
	typedef string::const_iterator iter;

	iter i = str.begin();
	
	while (i != str.end()) {
		// 선행 공백 무시
		// 지금 i 위치부터 끝까지 공백이 아닌 문자를 찾고 그 위치 반환
		i = find_if(i, str.end(), not_space);

		// 다음 단어의 끝을 찾음
		// while 반복할 때 항상 새로운 반복자 j 생성
		// 지금 i 위치부터 끝까지 공백인 문자를 찾고 그 위치 반환
		iter j = find_if(i, str.end(), space);

		// [i, j) 범위의 문자를 복사
		if (i != str.end())
			*os++ = string(i, j); // 출력 stream에서 출력


		// i 반복자 위치가 j 반복자의 위치를 저장히기
		i = j;

	}	
}

#endif 
