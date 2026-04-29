// main_SI.cpp

#include <iomanip>
#include <ios>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>


#include "Student_info.h"
#include "median.h"
#include "my_algs_T.h"

using namespace std;

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	// 데이터 읽고 저장하기
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// 학생 정보를 알파벳 순으로 정렬
	sort(students.begin(), students.end(), compare);

	// 이름과 점수를 출력
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();

			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}
