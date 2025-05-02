#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define LEN 4 

bool checkRepeat(char arr[], int index);

/* �ˬd����  
	arr : �n�ˬd���}�C 
	index : �n�Q�ˬd���Ʀr�Ҧb����m 
	�^�� : 
		������ : true 
		�S������ : false  
*/
bool checkRepeat(char arr[], int index) {

	int i;
	
	for(i = 0; i < index; i++) {  // �P�ۤv�e�����Ҧ��Ʀr������A�P�_�O�_������    
		if(arr[index] == arr[i]) {  // ������ 
			return true;
		}
	}
	return false;  // �S������ 
}

int main(void) {
	
	/*
		ans : �s�H���ͦ����D�� 
		input : �s��J���Ʀr  
		size : ��J�Ʀr������ 
		check : �ˬd��J�O�_�X��A�H�ΧP�_�C���O�_����  
			0 : ��J���X�� or �C���~��  
			1 : ��J�X�� or �C������   
		numA : �Ʀr��A��m�諸���X��  
		numB : �Ʀr��A��m�������X�� 
	*/
	
	char ans[LEN] = {'\0'};
	char input[100] = {'\0'};
	int size, check, numA, numB;
	int i, j;
	
	size = check = numA = numB = 0;

	// �H���X�D ( 4 �ӼƦr�������� ) 
	srand(time(NULL));  // �]�w�H���ƺؤl  
	for(i = 0; i < LEN; i++) {
		do {
			ans[i] = rand() % 10 + '0';  // +'0' �O�N 0-9 ���Ʀr�ন�r��  
			
		} while(checkRepeat(ans, i));
//		printf("%c ", ans[i]);  // �L�X���ͪ��D��  
	}
	
	// �C���}�l   
	do {
		// ��J�Ʀr 
		printf("Please enter four numbers (0 to 9): ");
		scanf("%s", input);
		// �ˬd��J�O�_�X�� ( �Ʀr���סA���� ) 
		size = strlen(input);
		if(size < LEN || size > LEN) {  // �ˬd��J�Ʀr����  
			if(size < LEN) {
				printf("Illegal input, too few numbers.\n");	
			} else if(size > LEN) {
				printf("Illegal input, too many numbers.\n");
			}
			check = 0;  // ��J���X��  
		} else {  // �ˬd��J���Ʀr�O�_������  
			for(i = 0; i < LEN; i++) {
				if(checkRepeat(input, i)) {  // ������  
					printf("Illegal input, repeated numbers\n");
					check = 0;  // ��J���X��  
					break;
				} else {  // �S������  
					check = 1;  // ��J�X��  
				}		
			}
		}
		// ��J�X��~�|�P�_�X A �X B   
		if(check == 1) {
			// �P�_�X A �X B ( �Ʀr��O�� B�A��m���ܦ� A ) 
			for(i = 0; i < LEN; i++) {
				for(j = 0; j < LEN; j++) {
					if(ans[i] == input[j]) {  // �Ʀr��  
						if(i == j) {  // ��m��  
							numA++;
						} else {  // ��m����  
							numB++;
						}
						break;
					}
				}
			}
			printf("%dA%dB\n", numA, numB);
			// �P�_�O�_�����C��  
			if(numA == LEN) {  // �q�쵪�סA4A0B 
				check = 1;  // �C������ 		 
			} else {  // �S�q�쵪��  
				check = 0;  // �C���~��  
				numA = numB = 0;
			}			
		}		
	} while(!check);
	
	printf("\nYou Win!");
	
	return 0;
}
