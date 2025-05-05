#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"
#define MAX_SIZE 100  // �C���ƶ��̦h 100 �Ӧr��  

/* csv �ɤ��C���ƶ������c 
	state : �ƶ������A 
		O : �w���� 
		X : ������  
	content : �ƶ������e  
*/ 
struct item {
	char state;
	char* content;
};

int main(void) {
	
	/*
		option : ���檺�\��ﶵ  
		item : �s data.csv �ɪ����e 
		num : �p���`�@���X���ƶ�  
		printWay : �O�_�L�X�w�������ƶ� 
			Y / y : �L�X�w�������ƶ� 
			N / n : ���L�X�w�������ƶ�  
		choiceNum : ��ܭn�R���έק窱�A���ƶ��s��  
		inputState : ��J�n�ק諸���A  
			O / o : �w���� 
			X / x : ������ 
	*/
	
	int option;
	Item* item = NULL;
	int num;
	char printWay = '\0';
	int choiceNum;
	char inputState = '\0';
	
	option = num = choiceNum = 0;
	
	// Ū���ɮ� 
	readFile(&item, &num);
	
	while(1) {
		// ��J�n���檺�\��ﶵ ( 1-6 ) 
		printf("Option: 1.Print item 2.Add item 3.Delete item 4.Revise state 5.Save file 6.Exit\n");
		printf("Enter option: ");
		scanf("%d%*c", &option);  // %*c : ��J option ��|�� Enter�A%*c �|�Y�� Enter 
		while(option < 1 || option > 6) {  // �ˬd��J�O�_�X��  
			printf("Illegal input.\n");
			printf("Option: 1.Print item 2.Add item 3.Delete item 4.Revise state 5.Save file 6.Exit\n");
			printf("Enter option: ");
			scanf("%d%*c", &option);
		}
		// ����\��  
		if(option == 1) {  // �L�X�ƶ�  
			if(item == NULL) {  // item �}�C���S���ƶ�  
				printf("No item.\n");
			} else {  // item �}�C�����ƶ�  
				// ��ܬO�_�L�X�w�������ƶ�  
				printf("Print completed items (Y / N): ");
				scanf("%c%*c", &printWay);  // %*c : ��J printWay ��|�� Enter�A%*c �|�Y�� Enter  
				printWay = toupper(printWay);  // �ѨM Y / y �� N / n ���D  
				while(printWay != 'Y' && printWay != 'N') {  // �ˬd��J�O�_�X��  
					printf("Illegal input.\n");
					printf("Print completed items (Y / N): ");
					scanf("%c%*c", &printWay);
					printWay = toupper(printWay);
				}
				// �ھڿ�ܪ�����L�X�ƶ�  
				printItem(item, num, printWay);	
			}
		} else if(option == 2) {  // �s�W�ƶ�  
			printf("Enter the content of item: ");
			addItem(&item, &num);
		} else if(option == 3) {  // �R���ƶ�  
			if(item == NULL) {  // item �}�C���S���ƶ�  
				printf("No item.\n");
			} else {  // item �}�C�����ƶ�  
				// �C�X item �}�C�����Ҧ��ƶ�  
				printItem(item, num, 'Y');
				// ��ܭn�R�����ƶ��s��  
				printf("Enter the item number to delete: ");
				scanf("%d%*c", &choiceNum);  // %*c : ��J choiceNum ��|�� Enter�A%*c �|�Y�� Enter  
				while(choiceNum < 1 || choiceNum > num) {  // �ˬd��J�O�_�X��  
					printf("Item number does not exist.\n");
					printf("Enter the item number to delete: ");
					scanf("%d%*c", &choiceNum);
				}
				// �R���ƶ� 
				deleteItem(&item, &num, choiceNum);
			}
		} else if(option == 4) {  // �ק窱�A  
			if(item == NULL) {  // item �}�C���S���ƶ�  
				printf("No item.\n");
			} else {  // item �}�C�����ƶ�  
				// �C�X item �}�C�����Ҧ��ƶ�  
				printItem(item, num, 'Y');
				// ��ܭn�ק諸�ƶ��s�� 
				printf("Enter the item number to revise state: ");
				scanf("%d%*c", &choiceNum);  // %*c : ��J choiceNum ��|�� Enter�A%*c �|�Y�� Enter  
				while(choiceNum < 1 || choiceNum > num) {  // �ˬd��J�O�_�X��  
					printf("Item number does not exist.\n");
					printf("Enter the item number to revise state: ");
					scanf("%d%*c", &choiceNum);
				}
				// ��J�n�ק諸���A 
				printf("Enter the state (O: completed, X: not completed):");
				scanf("%c%*c", &inputState);  // %*c : ��J inputState ��|�� Enter�A%*c �|�Y�� Enter  
				inputState = toupper(inputState);  // �ѨM O / o �� X / x ���D  
				while(inputState != 'O' && inputState != 'X') {  // �ˬd��J�O�_�X��  
					printf("Illegal input.\n");
					printf("Enter the state (O: completed, X: not completed):");
					scanf("%c%*c", &inputState);
					inputState = toupper(inputState);
				}
				// �ק窱�A  
				reviseState(&item, choiceNum, inputState);
			}
		} else if(option == 5) {  // �x�s�ɮ�  
			saveFile(item, num);
		} else if(option == 6) {  // �����{��  
			if(item != NULL) {  // ���t�m�Ŷ��~�ݭn���X  
				Exit(&item, num);				
			}
			break;
		}
		printf("\n");
	}
	
	system("pause");  // ���p�®ؤ��|�]���{�������N���� 
	
	return 0; 
} 
