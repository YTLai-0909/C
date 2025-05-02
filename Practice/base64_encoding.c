#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 100 

int main(void) {
	
	/*
		table : base64 ���ު� 
		input : ��J���r�� 
		len : �O����J���r�����  
		bits : �p���`�@���X�줸  
		bit : �s�r���ন�줸�����G  
		index : �p�� 6 �Ӧ줸�ন 1 �� base64 �r�������ޭ�  
	*/
	
	char table[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
	char input[MAX_SIZE] = {'\0'};
	int len, bits;
	int bit[8 * (MAX_SIZE + 1)] = {0};  // +1 : �ΨӸɹs���Ŷ�  
	int index;
	int i, j;
	
	len = bits = index = 0;
	
	printf("Input string:\n");
	printf("> ");
	while(gets(input) != NULL) {  // ��J EOF �� ( ctrl + z (^z) )�A�����{�� 
		len = strlen(input);
		bits = 8 * len;
		// �N�r���ন�줸  
		for(i = 0; i < len; i++) {
			for(j = 8 * i + 7; j >= 8 * i; j--) {  // 1 �� ASCII �r�� = 8 �Ӧ줸 
				// �C 8 �Ӧ줸�@�աA�˵۩�J bit �}�C  
				bit[j] = input[i] % 2;
				input[i] /= 2;
			}
		}
		// �ɹs 
		if(len % 3 == 1) { 
			// 1 �� ASCII �r�� = 8 �Ӧ줸�A6 �Ӧ줸 = 1 �� base64 �r���C�h 2 �Ӧ줸�A�ݭn�� 4 �ӹs�~���ഫ�� base64 �r��  
			for(i = 8 * len; i < 8 * len + 4; i++) {
				bit[i] = 0;
			}
			bits += 4;
		} else if(len % 3 == 2) {
			// 2 �� ASCII �r�� = 16 �Ӧ줸�A12 �Ӧ줸 = 2 �� base64 �r���C�h 4 �Ӧ줸�A�ݭn�� 2 �ӹs�~���ഫ�� base64 �r��  
			for(i = 8 * len; i < 8 * len + 2; i++) {
				bit[i] = 0;
			}
			bits += 2;
		}
		// �N�줸�ন base64 �r���A�æL�X 
		printf("Base64:\n");
		for(i = 0; i < bits / 6; i++) {
			index = 0;
			for(j = 6 * i; j < 6 * i + 6; j++) {  // 6 �Ӧ줸 = 1 �� base64 �r��  
				// �C 6 �Ӧ줸�@�աA�C�ժ��Ĥ@�Ӧ줸���H 2^5�A�ĤG�Ӧ줸���H 2^4�A�ĤT�Ӧ줸���H 2^3�A�H������  
				index += bit[j] * pow(2, 5 - j % 6);
			}
			printf("%c", table[index]);
		}
		if(len % 3 == 1) {  // ��J�r�ꤣ���� 3 �����ơA�h�@�Ӧr�� ( �@�Ӧ줸�� )�A�ҥH�n�ɨ�Ӧ줸�աC�ন base64 ��A�ɨ�� =  
			printf("==");
		} else if(len % 3 == 2) {  // ��J�r�ꤣ���� 3 �����ơA�h��Ӧr�� ( ��Ӧ줸�� )�A�ҥH�n�ɤ@�Ӧ줸�աC�ন base64 ��A�ɤ@�� =  
			printf("=");
		}
		printf("\n");
		// ��l�� 
		for(i = 0; i < bits; i++) {  // �M�� bit �}�C  
			bit[i] = 0;
		}
		len = bits = index = 0;
		// �U�@������J  
		printf("\nInput string:\n");
		printf("> ");
	}
	
	return 0;
} 
