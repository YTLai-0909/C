#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/* Ū���ɮ� 
	Ū�� data.csv �ɪ����e�A�æs�J item �}�C��  
	item : �s data.csv �ɤ��A�ƶ������A�P���e  
		-> �ǰѦҩI�s�A�� *item ���O�����m ( &item )�A�ҥH�n�� **item �� *item ����  
	num : �p���`�@���X���ƶ� 
		-> �ǰѦҩI�s�A�� num ���O�����m ( &num )�A�ҥH�n�� *num �� num ����   
*/
void readFile(Item **item, int *num) {
	
	/*
		rptr : ���V�ɮת����� 
		inputState : �Ψ�Ū���ƶ������A  
		inputContent : �Ψ�Ū���ƶ������e  
		len : �O�� inputContent ������  
	*/
	 
	FILE* rptr = fopen("data.csv", "r");
	char inputState = '\0';
	char inputContent[MAX_SIZE * 2] = {'\0'};  //  *2 : �@�Ӥ���r���� = 2  
	int len = 0;
	
	if(rptr != NULL) {  // Ū���ɮצ��\�Adata.csv �s�b  
		// Ū���ɮפ��e  
		while(fscanf(rptr, "%c,%s\n", &inputState, inputContent) != EOF) {
			// �t�m�Ŷ�  
			len = strlen(inputContent);
			createMemory(&(*item), *num, len);
			// �N��Ʀs�J item �}�C��  
			(*item)[*num].state = inputState;
			strcpy((*item)[*num].content, inputContent);
			(*num)++;
		}
	}
	fclose(rptr);
}

/* �t�m�O����Ŷ�  
	�t�m�@�� item �}�C�M content ���Ŷ� 
	item : �s�ƶ������A�P���e  
		-> �ǰѦҩI�s�A�� *item ���O�����m ( &item )�A�ҥH�n�� **item �� *item ����  
	num : �ثe���X���ƶ�  
	len : ���e������  
*/
void createMemory(Item **item, int num, int len) {
	
	// �t�m item �}�C���Ŷ� 
	if((*item) == NULL) {  // �Ĥ@���t�m�Ŷ�   
		*item = (Item*)calloc(num + 1, sizeof(Item));  // +1 : �]���}�C���Ĥ@�Ӧ�m index = 0  
	} else {  // ���ܤw�t�m���Ŷ�   
		*item = (Item*)realloc(*item, (num + 1) * sizeof(Item));  // +1 : �]���}�C���Ĥ@�Ӧ�m index = 0  
	}			
	// �t�m content ���Ŷ�  
	(*item)[num].content = (char*)calloc(len + 1, sizeof(char));  // +1 : �̫�@�Ӧ�m�� '\0' 
}

/* �L�X�ƶ�  
	�ھڿ�ܪ�����L�X�ƶ������A�P���e�A�w�������ƶ����@�w�|�L�A���������ƶ��@�w�|�L  
	item : �s�ƶ������A�P���e  
	num : �`�@���X���ƶ�  
	printWay : �O�_�L�X�w�������ƶ� 
		Y / y : �L�X�w�������ƶ� 
		N / n : ���L�X�w�������ƶ�  
*/
void printItem(Item *item, int num, char printWay) {
	
	/*
		check : �P�_���S�����������ƶ� 
			0 : �S�����������ƶ�  
			1 : �����������ƶ�  
	*/
	
	int check = 0;
	int i;

	if(printWay == 'Y') {  // �L�X�w�������ƶ� ( ���L ) 
		for(i = 0; i < num; i++) {
			if(item[i].state == 'O') {  // �w�������ƶ� 
				printf("%d. (O) ", i + 1);
			} else if(item[i].state == 'X') {  // ���������ƶ� 
				printf("%d. (X) ", i + 1);
			}
			printf("%s\n", item[i].content);
		}
	} else if(printWay == 'N') {  // ���L�X�w�������ƶ� ( �u�L�������� )
		for(i = 0; i < num; i++) {
			if(item[i].state == 'X') {
				printf("%d. (X) %s\n", i + 1, item[i].content);
				check = 1;
			}
		}
		if(!check) {  // �S�����������ƶ�  
			printf("All items are completed.\n");
		}
	}
}

/* �s�W�ƶ� 
	�s�W�ƶ��b�Ҧ��ƶ����̫�A�üХܬ������� 
	item : �s�ƶ������A�P���e  
		-> �ǰѦҩI�s�A�� *item ���O�����m ( &item )�A�ҥH�n�� **item �� *item ����  
	num : �p���`�@���X���ƶ� 
		-> �ǰѦҩI�s�A�� num ���O�����m ( &num )�A�ҥH�n�� *num �� num ����   	 
*/
void addItem(Item **item, int *num) {
	
	/*
		inputContent : �s��J�ƶ������e  
		len : �O�� inputContent ������  
	*/ 
	
	char inputContent[MAX_SIZE * 2] = {'\0'};  //  *2 : �@�Ӥ���r���� = 2 
	int len = 0;
	
	// ��J�ƶ����e  
	gets(inputContent);
	// �t�m�Ŷ�  
	len = strlen(inputContent);
	createMemory(&(*item), *num, len);
	// �N��Ʀs�J item �}�C�� 
	(*item)[*num].state = 'X';  // �Хܬ�������  
	strcpy((*item)[*num].content, inputContent);
	(*num)++;
}

/* �R���ƶ� 
	�R�� item �}�C�����S�w�@���ƶ�  
	item : �s�ƶ������A�P���e  
		-> �ǰѦҩI�s�A�� *item ���O�����m ( &item )�A�ҥH�n�� **item �� *item ����  
	num : �p���`�@���X���ƶ� 
		-> �ǰѦҩI�s�A�� num ���O�����m ( &num )�A�ҥH�n�� *num �� num ����   
	choiceNum : �n�R�����ƶ��s��  
*/
void deleteItem(Item **item, int *num, int choiceNum) {
	
	/*
		tmp : �Ȧs�n�Q�R�����ƶ�   
	*/
	
	Item tmp;
	int i;
	
	// �N item �}�C���n�R�����ƶ����ʨ�̫� 
	tmp = (*item)[choiceNum - 1];  // -1 : �]���}�C���Ĥ@�Ӧ�m index = 0 
	for(i = choiceNum - 1; i < (*num) - 1; i++) {  // �N�ƶ����e����  
		(*item)[i] = (*item)[i + 1];
	}
	(*item)[i] = tmp;  // �N�n�R�����ƶ����̫�  
	// �R���ƶ��A���X�t�m���Ŷ�  
	(*num)--;
	free((*item)[i].content);
	(*item)[i].content = NULL;
	*item = realloc(*item, (*num) * sizeof(Item));
}

/* �ק窱�A  
	�ק� item �}�C���S�w�@���ƶ������A 
	item : �s�ƶ������A�P���e  
		-> �ǰѦҩI�s�A�� *item ���O�����m ( &item )�A�ҥH�n�� **item �� *item ����  
	choiceNum : �n�ק窱�A���ƶ��s��   
	inputState : �n�ק諸���A 
*/
void reviseState(Item **item, int choiceNum, char inputState) {
	
	(*item)[choiceNum - 1].state = inputState;  // -1 : �]���}�C���Ĥ@�Ӧ�m index = 0 
}

/* �x�s�ɮ�  
	�N item �}�C�����e�̷� csv �ɪ��榡��X�� data.csv �ɤ�  
	item : �s�ƶ������A�P���e  
	num : �`�@���X���ƶ�  
*/
void saveFile(Item *item, int num) {
	
	/*
		wptr : ���V�ɮת����� 
	*/
	
	FILE* wptr = fopen("data.csv", "w");
	int i;
	
	if(wptr == NULL) {  // �}�ɥ��� ( �x�s���� ) 
		printf("Save failed.\n");
		Exit(&(item), num); 
		system("pause");  // ���p�®ؤ��|�]���{�������N���� 
		exit(EXIT_FAILURE);  // �����{��  
	} else {  // �}�ɦ��\ ( �x�s���\ ) 
		printf("Save success.\n");
		for(i = 0; i < num; i++) {
			fprintf(wptr, "%c,%s\n", item[i].state, item[i].content);
		}
	}
	fclose(wptr);
}

/* �����{��  
	�{�������ɡA����Ҧ��t�m���O����Ŷ� 
	item : �s�ƶ������A�P���e  
		-> �ǰѦҩI�s�A�� *item ���O�����m ( &item )�A�ҥH�n�� **item �� *item ����  
	num : �`�@���X���ƶ� 
*/
void Exit(Item **item, int num) {
	
	int i;
	
	// ����t�m�� content ���Ŷ�  
	for(i = 0; i < num; i++) {
		free((*item)[i].content);
		(*item)[i].content = NULL; 
	}
	// ������ item �}�C  
	free(*item);
	*item = NULL;
}


