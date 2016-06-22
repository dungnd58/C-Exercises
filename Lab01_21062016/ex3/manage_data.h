/*
Owner: Ngo Duc Dung
Added: 21/06/2016
Last update: 21/06/2016
*/

#ifndef MANAGE_DATA_H
#define MANAGE_DATA_H

#include "structs.h"

void enterStudentInfo(Class* classes, int class_id);
void searchStudents(Class* classes, int class_id, int student_id);
void printAStudentResult(Student* students, int student_id);
void printClassResults(Class* classes, int class_id);

#endif
