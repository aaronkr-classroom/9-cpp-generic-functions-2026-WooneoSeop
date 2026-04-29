// main.cpp

#include <iostream>
#include "my_algs_T.h"
#include "Student_info.h"



int main() {
	string s;
	while (getline(cin, s)) {
		split(s, ostream_iterator<string>(cout, "\n"));
	}
	return 0;
}
