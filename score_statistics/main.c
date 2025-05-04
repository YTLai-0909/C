#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define ID_MAX_SIZE 100  // ID ���̤j����  
#define STUDENT_MAX_SIZE 100  // �̦h�i�H��J�X���ǥͪ����  

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

int main(void) {
	
	/*
		student : �s�C�@�Ӿǥͪ� ID �P���� 
		num : �p���`�@���X�H  
		copyData : �N�ǥͪ� ID �P���ư��ƥ�  
		option : �n������@�رƧǤ覡  
			0 : �����{�� 
			1 : �H ID ���Ƨ� 
			2 : �H���ư��Ƨ�  
	*/
	
	Student student[STUDENT_MAX_SIZE];
	int num;
	Student copyData[STUDENT_MAX_SIZE];
	int option;
	int i;
	
	num = option = 0;
	
	// ��J�ǥͪ� ID �P���� 
	input(student, &num);
	
	if(num > 0) {  // ����J���  
		// ��ǥͪ� ID �P���Ƹ�Ƴƥ��� copyData 
		copy(copyData, student, num);
	
		// �i���ƱƧǻP�έp���R  
		while(1) {
			// �C������ʧ@�e�A���N student �}�C��l�Ƭ��̪��J����� ( �N copyData ����ƽƻs�� student )
			copy(student, copyData, num);
			// ��J�ƧǤ覡 ( 0-2 )
			printf("\nSort By (1.ID 2.Score 0.exit): ");
			scanf("%d", &option);
			while(option < 0 || option > 2) {  // �ˬd��J�O�_�X��  
				printf("Illegal input, input can only be 0 or 1 or 2.\n");
				printf("Sort By (1.ID 2.Score 0.exit): ");
				scanf("%d", &option);
			}
			// ����Ƨ�  
			if(option == 0) {  // �����{��  
				break;
			} else if(option == 1) {  // �̷� ID �i��Ƨ� 
				sort(student, num, id);
			} else if(option == 2) {  // �̷Ӥ��ƶi��Ƨ�  
				sort(student, num, score);
			}
			// �L�X�Ƨǵ��G 
			print(student, num);
			// �έp���R  
			getAverage(student, num);  // �p�⥭��  
			for(i = 1; i <= 3; i++) {  // �p��|�����  
				getQuartile(student, num, i);
			}
			printf("\n");
		}
	} else {  // �S����J���  
		printf("No student data.\n");
	} 
	
	system("pause");  // ���p�®ؤ��|�]���{�������N����  
	
	return 0;
}
