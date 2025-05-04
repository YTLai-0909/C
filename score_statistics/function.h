typedef struct studentData Student;
void input(Student *student, int *num);
void copy(Student *data1, Student *data2, int num);
_Bool id(Student *student, int one, int two);
_Bool score(Student *student, int one, int two);
void sort(Student *student, int num, _Bool (*cmp)(Student*, int, int));
void print(Student *student, int num);
void getAverage(Student *student, int num);
void getQuartile(Student *student, int num, int numQ);
