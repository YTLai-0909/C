#include <stdio.h>
#include <string.h>
#include "function.h"
#define ID_MAX_SIZE 100  // ID ���̤j����  
#define ID_LEN 5  // �w�] ID ����  

/* �ǥͪ����c   
	id : �ǥ� ID
		- �Ĥ@�Ӧr�� : �j�g�^��r��  
		- �Ĥ@�ӥH�᪺�r�� : �s��  
	score : �ǥͤ���  
*/
struct studentData {
	char id[ID_MAX_SIZE];  // �r��  
	int score;
};

/* ��J�ǥͪ���� ( ��J�� 0 0 �ɡA�����J ) 
	student : �s�ǥͪ� ID �P���� 
	num : �p���`�@���X�H  
		-> �ǰѦҩI�s�A�� num ���O�����m ( &num )�A�ҥH�n�� *num �� num ����  
*/
void input(Student *student, int *num) {
	
	int len = 0;  // �O����J�� ID ����  
	int i;
	
	printf("Please input ID and Score (0 0 to stop input): \n");
	printf("ID (1 uppercase A to Z + 4 numbers)\n");
	printf("Score (0 to 100)\n");
	while(1) {
		// ��J ID �P����  
		printf(">> ");
		scanf("%s %d", student[*num].id, &student[*num].score);
		// ��J�� 0 0 �ɡA�����J  
		if(strcmp(student[*num].id, "0") == 0 && student[*num].score == 0) {
			break;
		}
		// �ˬd ID �O�_�X�� ( ���� = 5�A1 �Ӥj�g�r�� + 4 �ӼƦr ) 
		len = strlen(student[*num].id);
		if(len < ID_LEN || len > ID_LEN) {  // ID ���פ����� 5�A���s��J  
			if(len < ID_LEN) {
				printf("Illegal input, ID length is too short.\n");
			} else if(len > ID_LEN) {
				printf("Illegal input, ID length is too long.\n");
			}
			continue;
		} else if(student[*num].id[0] < 'A' || student[*num].id[0] > 'Z') {  // �Ĥ@�Ӧr���O�j�g�^��r���A���s��J   
			printf("Illegal input, the first letter is not uppercase.\n");
			continue;
		} else {  // �Ĥ@�Ӧr�᭱�X�{�D�Ʀr�A���s��J  
			for(i = 1; i < ID_LEN; i++) {
				if(student[*num].id[i] < '0' || student[*num].id[i] > '9') {
					printf("Illegal input, ID format is error.\n");
					break;
				}
			}
			if(i != ID_LEN) {  // ID �榡���~�A���ݭn�ˬd���ƪ����n�D���s��J  
				continue;	
			}
		}
		// �ˬd���ƬO�_�X�� ( 0-100 ) 
		if(student[*num].score < 0 || student[*num].score > 100) {  // ���Ƥ��b 0-100 ���d��A���s��J  
			printf("Illegal input, score is out of range.\n");
			continue;
		}
		(*num)++;  // �x�s�ӵ����  
	}	
}

/* �ƻs��� 
	�N data2 ����ƽƻs�� data 1 
	data1 : �n�Q��s�����  
	data2 : ��l���  
	num : �`�@���X�����  
*/
void copy(Student *data1, Student *data2, int num) {

	int i;
	
	if(num > 0) {
		for(i = 0; i < num; i++) {
			strcpy(data1[i].id, data2[i].id);
			data1[i].score = data2[i].score;
		}
	}
}

/*  ������ ID 
	student �ǥͪ���� 
	one : �Ĥ@����� 
	two : �ĤG����� 
	�^�� :  
		1 : true�A�Ĥ@�� id > �ĤG�� id  ( strcmp ���^�Ǥj�� 0 ) 
		0 : false�A�Ĥ@�� id < �ĤG�� id ( strcmp ���^�Ǥp�� 0 ) 
*/ 
_Bool id(Student *student, int one, int two) {
	
	return strcmp(student[one].id, student[two].id) > 0;
}

/* �����Ӥ��� 
	student �ǥͪ���� 
	one : �Ĥ@����� 
	two : �ĤG����� 
	�^�� :  
		1 : true�A�Ĥ@������ > �ĤG������  
		0 : false�A�Ĥ@������ < �ĤG������   
*/
_Bool score(Student *student, int one, int two) {
	
	return student[one].score > student[two].score;
}

/* ���ƶi��S�w�Ƨ� 
	student : �ǥͪ���� 
	num : �`�@���X�H 
	cmp : �ƧǤ覡 
		id : �̷� ID 
		score : �̷Ӥ���  
*/
// _Bool (*cmp)(Student*, int, int) : �禡���Ч@���Ѽ� 
void sort(Student *student, int num, _Bool (*cmp)(Student*, int, int)) {

	char tmpId[ID_MAX_SIZE] = {'\0'};  // ID �洫�ɡA�@���Ȧs��  
	int tmpScore = 0;  // ���ƥ洫�ɡA�@���Ȧs��  
	int i, j;
	
	if(num > 0) {
		// �w�j�Ƨ� ( �Ѥp��j�Ƨ� ) 
		for(i = 0; i < num - 1; i++) {  // �n�񪺦^�X��  
			for(j = 0; j < num - i - 1; j++) {  // �C�^�X�񪺦��� 
				if(cmp(student, j, j + 1)) {
					// �洫 ID ����m  
					strcpy(tmpId, student[j].id);
					strcpy(student[j].id, student[j + 1].id);
					strcpy(student[j + 1].id, tmpId);
					// �洫���ƪ���m  
					tmpScore = student[j].score;
					student[j].score = student[j + 1].score;
					student[j + 1].score = tmpScore;
				}
			}
		}
	}
}

/* �L�X�Ƨǵ��G 
	student : �ǥͪ���� 
	num : �`�@���X�H  
*/
void print(Student *student, int num) {
	
	int i;
	
	if(num > 0) {
		printf("\nSID      Score\n");
		for(i = 0; i < num; i++) {
			printf("%s    %d\n", student[i].id, student[i].score);
		}
		printf("-----------------------------\n");
	}
} 


/* �p�⥭�� 
	student : �ǥͪ���� 
	num : �`�@���X�H  
*/ 
void getAverage(Student *student, int num) {
	
	int sum = 0;
	float avg = 0;
	int i;
	
	if(num > 0) {
		// �p������`�X  
		for(i = 0; i < num; i++) {
			sum += student[i].score;
		}
		avg = sum * 1.0 / num;  // sum * 1.0 : �N sum �q int �ন float  
		printf("Average: %.4f\n", avg);  // �L��p���I�� 4 ��  	
	}
}

/* �p��|����� 
	student : �ǥͪ���� 
	num : �`�@���X�H  
	numQ : �ĴX�|����� 
		Q1 : �Ĥ@�|����� ( P_25 �� 25% �����ƭ� )
		Q2 : �ĤG�|����� ( P_50 �� 50% �����ƭ� )
		Q3 : �ĤT�|����� ( P_75 �� 75% �����ƭ� ) 
*/ 
void getQuartile(Student *student, int num, int numQ) {
	
	float index = 0;  // ���ĴX�����  
	
	if(num > 0) {
		// �N���ƶi��Ƨ� 
		sort(student, num, score);
		// �p��n���ĴX����� 
		switch(numQ) {
			case 1:  // �� 25% �����ƭ�  
				index = (num * 1.0) * 25 / 100;  // num * 1.0 : �N num �q int �ন float  
				break;
			case 2:  // �� 50% �����ƭ�  
				index = (num * 1.0) * 50 / 100;
				break;
			case 3:  // �� 75% �����ƭ�  
				index = (num * 1.0) * 75 / 100;
				break;
		}
		if(index != (int)index) {  // index ���O��ƮɡA�� ( index ����Ƴ��� + 1 ) ���������  
			// (int)index + 1 : �� ( index ����Ƴ��� + 1 ) ���������  
			// -1 : �}�C���Ĥ@�Ӧ�m�� 0  
			// *1.0 : �N int �ন float  
			printf("Q%d: %.1f  ", numQ, student[((int)index + 1) - 1].score * 1.0);
		} else {  // index �O��ƮɡA�� ( index �P index + 1 ) �ⵧ��ƪ�����  
			// (int)index : �N index �ন��ƫ�A�� ( index ) �������  
			// (int)index + 1 : �N index �ন��ƫ�A�� ( index + 1 ) ������� 
			// -1 : �}�C���Ĥ@�Ӧ�m�� 0  
			// *1.0 : �N int �ন float 
			// /2 : �� ( index �P index + 1 ) �ⵧ��ƪ�����  
			printf("Q%d: %.1f  ", numQ, (student[(int)index - 1].score + student[((int)index + 1) - 1].score) * 1.0 / 2);
		}
	}
}
