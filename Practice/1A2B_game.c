#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define LEN 4 

bool checkRepeat(char arr[], int index);

/* 檢查重複  
	arr : 要檢查的陣列 
	index : 要被檢查的數字所在的位置 
	回傳 : 
		有重複 : true 
		沒有重複 : false  
*/
bool checkRepeat(char arr[], int index) {

	int i;
	
	for(i = 0; i < index; i++) {  // 與自己前面的所有數字做比較，判斷是否有重複    
		if(arr[index] == arr[i]) {  // 有重複 
			return true;
		}
	}
	return false;  // 沒有重複 
}

int main(void) {
	
	/*
		ans : 存隨機生成的題目 
		input : 存輸入的數字  
		size : 輸入數字的長度 
		check : 檢查輸入是否合格，以及判斷遊戲是否結束  
			0 : 輸入不合格 or 遊戲繼續  
			1 : 輸入合格 or 遊戲結束   
		numA : 數字對，位置對的有幾個  
		numB : 數字對，位置錯的有幾個 
	*/
	
	char ans[LEN] = {'\0'};
	char input[100] = {'\0'};
	int size, check, numA, numB;
	int i, j;
	
	size = check = numA = numB = 0;

	// 隨機出題 ( 4 個數字都不重複 ) 
	srand(time(NULL));  // 設定隨機數種子  
	for(i = 0; i < LEN; i++) {
		do {
			ans[i] = rand() % 10 + '0';  // +'0' 是將 0-9 的數字轉成字元  
			
		} while(checkRepeat(ans, i));
//		printf("%c ", ans[i]);  // 印出產生的題目  
	}
	
	// 遊戲開始   
	do {
		// 輸入數字 
		printf("Please enter four numbers (0 to 9): ");
		scanf("%s", input);
		// 檢查輸入是否合格 ( 數字長度，重複 ) 
		size = strlen(input);
		if(size < LEN || size > LEN) {  // 檢查輸入數字長度  
			if(size < LEN) {
				printf("Illegal input, too few numbers.\n");	
			} else if(size > LEN) {
				printf("Illegal input, too many numbers.\n");
			}
			check = 0;  // 輸入不合格  
		} else {  // 檢查輸入的數字是否有重複  
			for(i = 0; i < LEN; i++) {
				if(checkRepeat(input, i)) {  // 有重複  
					printf("Illegal input, repeated numbers\n");
					check = 0;  // 輸入不合格  
					break;
				} else {  // 沒有重複  
					check = 1;  // 輸入合格  
				}		
			}
		}
		// 輸入合格才會判斷幾 A 幾 B   
		if(check == 1) {
			// 判斷幾 A 幾 B ( 數字對保底 B，位置對變成 A ) 
			for(i = 0; i < LEN; i++) {
				for(j = 0; j < LEN; j++) {
					if(ans[i] == input[j]) {  // 數字對  
						if(i == j) {  // 位置對  
							numA++;
						} else {  // 位置不對  
							numB++;
						}
						break;
					}
				}
			}
			printf("%dA%dB\n", numA, numB);
			// 判斷是否結束遊戲  
			if(numA == LEN) {  // 猜到答案，4A0B 
				check = 1;  // 遊戲結束 		 
			} else {  // 沒猜到答案  
				check = 0;  // 遊戲繼續  
				numA = numB = 0;
			}			
		}		
	} while(!check);
	
	printf("\nYou Win!");
	
	return 0;
}
