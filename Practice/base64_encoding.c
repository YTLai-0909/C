#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 100 

int main(void) {
	
	/*
		table : base64 索引表 
		input : 輸入的字串 
		len : 記錄輸入的字串長度  
		bits : 計算總共有幾位元  
		bit : 存字串轉成位元的結果  
		index : 計算 6 個位元轉成 1 個 base64 字元的索引值  
	*/
	
	char table[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
	char input[MAX_SIZE] = {'\0'};
	int len, bits;
	int bit[8 * (MAX_SIZE + 1)] = {0};  // +1 : 用來補零的空間  
	int index;
	int i, j;
	
	len = bits = index = 0;
	
	printf("Input string:\n");
	printf("> ");
	while(gets(input) != NULL) {  // 輸入 EOF 時 ( ctrl + z (^z) )，結束程式 
		len = strlen(input);
		bits = 8 * len;
		// 將字串轉成位元  
		for(i = 0; i < len; i++) {
			for(j = 8 * i + 7; j >= 8 * i; j--) {  // 1 個 ASCII 字元 = 8 個位元 
				// 每 8 個位元一組，倒著放入 bit 陣列  
				bit[j] = input[i] % 2;
				input[i] /= 2;
			}
		}
		// 補零 
		if(len % 3 == 1) { 
			// 1 個 ASCII 字元 = 8 個位元，6 個位元 = 1 個 base64 字元。多 2 個位元，需要補 4 個零才能轉換成 base64 字元  
			for(i = 8 * len; i < 8 * len + 4; i++) {
				bit[i] = 0;
			}
			bits += 4;
		} else if(len % 3 == 2) {
			// 2 個 ASCII 字元 = 16 個位元，12 個位元 = 2 個 base64 字元。多 4 個位元，需要補 2 個零才能轉換成 base64 字元  
			for(i = 8 * len; i < 8 * len + 2; i++) {
				bit[i] = 0;
			}
			bits += 2;
		}
		// 將位元轉成 base64 字元，並印出 
		printf("Base64:\n");
		for(i = 0; i < bits / 6; i++) {
			index = 0;
			for(j = 6 * i; j < 6 * i + 6; j++) {  // 6 個位元 = 1 個 base64 字元  
				// 每 6 個位元一組，每組的第一個位元乘以 2^5，第二個位元乘以 2^4，第三個位元乘以 2^3，以此類推  
				index += bit[j] * pow(2, 5 - j % 6);
			}
			printf("%c", table[index]);
		}
		if(len % 3 == 1) {  // 輸入字串不等於 3 的倍數，多一個字元 ( 一個位元組 )，所以要補兩個位元組。轉成 base64 後，補兩個 =  
			printf("==");
		} else if(len % 3 == 2) {  // 輸入字串不等於 3 的倍數，多兩個字元 ( 兩個位元組 )，所以要補一個位元組。轉成 base64 後，補一個 =  
			printf("=");
		}
		printf("\n");
		// 初始化 
		for(i = 0; i < bits; i++) {  // 清空 bit 陣列  
			bit[i] = 0;
		}
		len = bits = index = 0;
		// 下一輪的輸入  
		printf("\nInput string:\n");
		printf("> ");
	}
	
	return 0;
} 
