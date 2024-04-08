#ifndef storeCourse_h
#define storeCourse_h


#include <string>
using namespace std;

class StoreCourse {
private:
	struct CourseNode {
		string courseCode;
		int creditHours;
		double grade;
		CourseNode* next;
	};
	CourseNode* head;
public:
	StoreCourse();
	void insert(string, int, double);
	int extractCourseNum(string);
	void deleteNode(string);
	void deleteAllNodes();
	void displayList();
	~StoreCourse();
};

#endif