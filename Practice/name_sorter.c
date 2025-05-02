#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100  // �m�W���̤j����  

void Add(char ***name, int *num);
void Print(char **name, int num);
void Sort(char ***name, int num);
void swap(char **str1, char **str2);
void Exit(char ***name, int num);

/* �s�W 
	�s�W�@�өm�W��C��̤U�� 
	name : ���V�O���m�W���G���ʺA�}�C���_�l��m  
		-> �ǰѦҩI�s�A�� name ���O�����m ( &name )�A�ҥH�n�� ***name �� **name ����  
	num : �p���`�@���X�өm�W  
		-> �ǰѦҩI�s�A�� num ���O�����m ( &num )�A�ҥH�n�� *num �� num ����  
*/
void Add(char ***name, int *num) {
	
	/*
		input : �O����J���m�W 
		len : �p��m�W������  
		check : �ˬd��J���m�W�O�_�ŦX�榡 
			0 : ���X��  
			1 : �X��  
	*/
	
	char input[MAX_LEN] = {'\0'};
	int len, check;
	int i;
	
	len = check = 0;
	
	// ��J�m�W ( �j�p�g�^��r���ΪŮ� )
	while(!check) {
		printf("Enter name(letters or spaces): ");
		gets(input);
		len = strlen(input);		
		for(i = 0; i < len; i++) {  // �ˬd��J�O�_�X��  
			if(isalpha(input[i]) || input[i] == ' ') {  // �r���ΪŮ�  
				check = 1;  // �X��  
			} else {
				check = 0;  // ���X��  
				printf("ERROR, name format illegal.\n");
				break;
			}
		}
	}
	
	// �t�m�G���ʺA�}�C���Ĥ@���Ŷ�  
	if(!(*num)) {  // �Ĥ@���t�m�Ŷ�  
		*name = (char**)calloc((*num) + 1, sizeof(char*));  // +1 : �]���}�C���Ĥ@�Ӧ�m index = 0  
	} else {  // ���ܤw�t�m���Ŷ�  
		*name = (char**)realloc(*name, ((*num) + 1) * sizeof(char*));  // +1 : �]���}�C���Ĥ@�Ӧ�m index = 0  
	}
	// �t�m�G���ʺA�}�C���ĤG���Ŷ� 
	(*name)[*num] = (char*)calloc(len + 1, sizeof(char));  // +1 : �̫�@�Ӧ�m�� '\0' 
	// �N��J���m�W�[�J�}�C��  
	strcpy((*name)[*num], input);
	(*num)++;
}

/* �L�X 
	�ھڥثe���m�W�C��A�̧ǦC�X�Ҧ��m�W�A�@�өm�W���@�C  
	name : ���V�O���m�W���G���ʺA�}�C���_�l��m  
	num : �`�@���X�өm�W  
*/
void Print(char **name, int num) {
	
	int i;
	
	if(num > 0) {  // ����J���  
		for(i = 0; i < num; i++) {
			printf("%s\n", name[i]);
		}		
	} else {  // �S����J���  
		printf("No data.\n");
	}
}

/* �Ƨ� 
	�N�ثe���m�W�C��̷Ӧr��ƧǪ��覡�i��Ƨ� ( Ex: AaBbCcDd...Zz ) 
	name : ���V�O���m�W���G���ʺA�}�C���_�l��m  
		-> �ǰѦҩI�s�A�� name ���O�����m ( &name )�A�ҥH�n�� ***name �� **name ����  
	num : �`�@���X�өm�W  
*/
void Sort(char ***name, int num) {
	
	/*
		dict : �r��  
		len1 : �n������Ĥ@�Ӧr�ꪺ���� 
		len2 : �n������ĤG�Ӧr�ꪺ���� 
		index : �ثe���ĴX�Ӧr��  
		str1 : �O���Ĥ@�Ӧr��ثe���r���b�r�夤����m 
		str2 : �O���ĤG�Ӧr��ثe���r���b�r�夤����m  
	*/
	
	char dict[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz ";
	int len1, len2;
	int index;
	char* str1 = NULL;
	char* str2 = NULL;
	int i, j;
	
	len1 = len2 = index = 0;
	
	if(num > 0) {  // ����J���  
		// �w�j�Ƨ� 
		for(i = 0; i < num - 1; i++) {  // �񪺦^�X�� 
			for(j = 0; j < num - i - 1; j++) {  // �񪺦���  
				// �p��r�����  
				len1 = strlen((*name)[j]);
				len2 = strlen((*name)[j + 1]);
				// ��Ӧr�꦳�ۦP���r���A�~�򩹫��  
				index = 0;
				while(((*name)[j][index] == (*name)[j + 1][index]) && index < len1 && index < len2) {
					index++;
				}
				if(index == len1 || index == len2) {  // �䤤�@�Ӧr����� ( ��ثe����ۦP ) 
					if(len1 > len2) {
						// �洫���� 
						swap(&(*name)[j], &(*name)[j + 1]);  // �ǫ��Ъ��O�����m (&char*) 
					}
				} else {  // ��Ӧr��J�줣�P���r��  
					// �M��ثe�r���b�r�夤����m  
					str1 = strchr(dict, (*name)[j][index]);
					str2 = strchr(dict, (*name)[j + 1][index]);
					if(str1 > str2) {
						// �洫���� 
						swap(&(*name)[j], &(*name)[j + 1]);  // �ǫ��Ъ��O�����m (&char*)	
					}
				}
			}
		}
		printf("Sort finish.\n");
	} else {  // �S����J���  
		printf("No data.\n");
	}
}

/* �r��洫 
	�N str1 �P str2 ���洫 
	str1 : �n�洫���Ĥ@�Ӧr�ꪺ����  
		-> �ǰѦҩI�s�A�ǫ���( char* )���O�����m ( &(*name)[j] )�A�ҥH�n�� **str1 �� *str1 ����  
	str2 : �n�洫�o�ĤG�Ӧr�ꪺ���� 
		-> �ǰѦҩI�s�A�ǫ���( char* )���O�����m ( &(*name)[j + 1] )�A�ҥH�n�� **str2 �� *str2 ����  
*/
void swap(char **str1, char **str2) {
	
	char* tmp;  // ���Х洫�ɡA�@���Ȧs�� 
	
	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

/* ���}  
	���X�����ʺA�O����Ŷ��A�����{�� 
	name : ���V�O���m�W���G���ʺA�}�C���_�l��m  
		-> �ǰѦҩI�s�A�� name ���O�����m ( &name )�A�ҥH�n�� ***name �� **name ����  
	num : �`�@���X�өm�W  
*/
void Exit(char ***name, int num) {
	
	int i;
	
	// ����G���ʺA�}�C���ĤG���Ŷ�  
	for(i = 0; i < num; i++) {
		free((*name)[i]);
	}
	// ����G���ʺA�}�C���Ĥ@���Ŷ�  
	free(*name);
	(*name) = NULL;
} 

int main(void) {
	
	/*
		name : ���V�O���m�W���G���ʺA�}�C���_�l��m  
		option : �\��ﶵ 
			1. �s�W 
			2. �L�X  
			3. �Ƨ�  
			4. ���}  
		num : �`�@���X�өm�W  
	*/
	
	char **name = NULL;
	int option, num;
	
	option = num = 0;
	
	while(1) {
		// ��ܥ\�� ( 1-4 )
		printf("Enter option(1.Add 2.Print 3.Sort 4.Exit): ");
		scanf("%d%*c", &option);  // %*c : ��J option ��|�� Enter�A%*c �|�Y�� Enter�A�_�h�|�Q gets �Y��  
		while(option < 1 || option > 4) {  // �ˬd��J�O�_�X��  
			printf("ERROR, out of range.\n");
			printf("Enter option(1.Add 2.Print 3.Sort 4.Exit): ");
			scanf("%d%*c", &option);
		}
		// ����\�� 
		if(option == 1) {  // �s�W�@�өm�W  
			Add(&name, &num);	
		} else if(option == 2) {  // �L�X�Ҧ��m�W 
			Print(name, num);
		} else if(option == 3) {  // �N�m�W�̷Ӧr��Ƨ� ( Ex: AaBbCcDd...Zz ) 
			Sort(&name, num);
		} else if(option == 4) {  // �����{��  
			Exit(&name, num);
			break;
		}
	}
	
	return 0;
} 
