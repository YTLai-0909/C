#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#define MAX_SIZE 100  // 每條事項最多 100 個字元  

/* csv 檔中每筆事項的結構 
	state : 事項的狀態 
		O : 已完成 
		X : 未完成  
	content : 事項的內容  
*/ 
struct item {
	char state;
	char* content;
};

/* 讀取檔案 
	讀取 data.csv 檔的內容，並存入 item 陣列中  
	item : 存 data.csv 檔中，事項的狀態與內容  
		-> 傳參考呼叫，傳 *item 的記憶體位置 ( &item )，所以要用 **item 取 *item 的值  
	num : 計算總共有幾條事項 
		-> 傳參考呼叫，傳 num 的記憶體位置 ( &num )，所以要用 *num 取 num 的值   
*/
void readFile(Item **item, int *num) {
	
	/*
		rptr : 指向檔案的指標 
		inputState : 用來讀取事項的狀態  
		inputContent : 用來讀取事項的內容  
		len : 記錄 inputContent 的長度  
	*/
	 
	FILE* rptr = fopen("data.csv", "r");
	char inputState = '\0';
	char inputContent[MAX_SIZE * 2] = {'\0'};  //  *2 : 一個中文字長度 = 2  
	int len = 0;
	
	if(rptr != NULL) {  // 讀取檔案成功，data.csv 存在  
		// 讀取檔案內容  
		while(fscanf(rptr, "%c,%s\n", &inputState, inputContent) != EOF) {
			// 配置空間  
			len = strlen(inputContent);
			createMemory(&(*item), *num, len);
			// 將資料存入 item 陣列中  
			(*item)[*num].state = inputState;
			strcpy((*item)[*num].content, inputContent);
			(*num)++;
		}
	}
	fclose(rptr);
}

/* 配置記憶體空間  
	配置一個 item 陣列和 content 的空間 
	item : 存事項的狀態與內容  
		-> 傳參考呼叫，傳 *item 的記憶體位置 ( &item )，所以要用 **item 取 *item 的值  
	num : 目前有幾條事項  
	len : 內容的長度  
*/
void createMemory(Item **item, int num, int len) {
	
	// 配置 item 陣列的空間 
	if((*item) == NULL) {  // 第一次配置空間   
		*item = (Item*)calloc(num + 1, sizeof(Item));  // +1 : 因為陣列的第一個位置 index = 0  
	} else {  // 改變已配置的空間   
		*item = (Item*)realloc(*item, (num + 1) * sizeof(Item));  // +1 : 因為陣列的第一個位置 index = 0  
	}			
	// 配置 content 的空間  
	(*item)[num].content = (char*)calloc(len + 1, sizeof(char));  // +1 : 最後一個位置放 '\0' 
}

/* 印出事項  
	根據選擇的條件印出事項的狀態與內容，已完成的事項不一定會印，未完成的事項一定會印  
	item : 存事項的狀態與內容  
	num : 總共有幾條事項  
	printWay : 是否印出已完成的事項 
		Y / y : 印出已完成的事項 
		N / n : 不印出已完成的事項  
*/
void printItem(Item *item, int num, char printWay) {
	
	/*
		check : 判斷有沒有未完成的事項 
			0 : 沒有未完成的事項  
			1 : 有未完成的事項  
	*/
	
	int check = 0;
	int i;

	if(printWay == 'Y') {  // 印出已完成的事項 ( 全印 ) 
		for(i = 0; i < num; i++) {
			if(item[i].state == 'O') {  // 已完成的事項 
				printf("%d. (O) ", i + 1);
			} else if(item[i].state == 'X') {  // 未完成的事項 
				printf("%d. (X) ", i + 1);
			}
			printf("%s\n", item[i].content);
		}
	} else if(printWay == 'N') {  // 不印出已完成的事項 ( 只印未完成的 )
		for(i = 0; i < num; i++) {
			if(item[i].state == 'X') {
				printf("%d. (X) %s\n", i + 1, item[i].content);
				check = 1;
			}
		}
		if(!check) {  // 沒有未完成的事項  
			printf("All items are completed.\n");
		}
	}
}

/* 新增事項 
	新增事項在所有事項的最後，並標示為未完成 
	item : 存事項的狀態與內容  
		-> 傳參考呼叫，傳 *item 的記憶體位置 ( &item )，所以要用 **item 取 *item 的值  
	num : 計算總共有幾條事項 
		-> 傳參考呼叫，傳 num 的記憶體位置 ( &num )，所以要用 *num 取 num 的值   	 
*/
void addItem(Item **item, int *num) {
	
	/*
		inputContent : 存輸入事項的內容  
		len : 記錄 inputContent 的長度  
	*/ 
	
	char inputContent[MAX_SIZE * 2] = {'\0'};  //  *2 : 一個中文字長度 = 2 
	int len = 0;
	
	// 輸入事項內容  
	gets(inputContent);
	// 配置空間  
	len = strlen(inputContent);
	createMemory(&(*item), *num, len);
	// 將資料存入 item 陣列中 
	(*item)[*num].state = 'X';  // 標示為未完成  
	strcpy((*item)[*num].content, inputContent);
	(*num)++;
}

/* 刪除事項 
	刪除 item 陣列中的特定一條事項  
	item : 存事項的狀態與內容  
		-> 傳參考呼叫，傳 *item 的記憶體位置 ( &item )，所以要用 **item 取 *item 的值  
	num : 計算總共有幾條事項 
		-> 傳參考呼叫，傳 num 的記憶體位置 ( &num )，所以要用 *num 取 num 的值   
	choiceNum : 要刪除的事項編號  
*/
void deleteItem(Item **item, int *num, int choiceNum) {
	
	/*
		tmp : 暫存要被刪除的事項   
	*/
	
	Item tmp;
	int i;
	
	// 將 item 陣列中要刪除的事項移動到最後 
	tmp = (*item)[choiceNum - 1];  // -1 : 因為陣列的第一個位置 index = 0 
	for(i = choiceNum - 1; i < (*num) - 1; i++) {  // 將事項往前移動  
		(*item)[i] = (*item)[i + 1];
	}
	(*item)[i] = tmp;  // 將要刪除的事項放到最後  
	// 刪除事項，釋出配置的空間  
	(*num)--;
	free((*item)[i].content);
	(*item)[i].content = NULL;
	*item = realloc(*item, (*num) * sizeof(Item));
}

/* 修改狀態  
	修改 item 陣列中特定一條事項的狀態 
	item : 存事項的狀態與內容  
		-> 傳參考呼叫，傳 *item 的記憶體位置 ( &item )，所以要用 **item 取 *item 的值  
	choiceNum : 要修改狀態的事項編號   
	inputState : 要修改的狀態 
*/
void reviseState(Item **item, int choiceNum, char inputState) {
	
	(*item)[choiceNum - 1].state = inputState;  // -1 : 因為陣列的第一個位置 index = 0 
}

/* 儲存檔案  
	將 item 陣列的內容依照 csv 檔的格式輸出到 data.csv 檔中  
	item : 存事項的狀態與內容  
	num : 總共有幾條事項  
*/
void saveFile(Item *item, int num) {
	
	/*
		wptr : 指向檔案的指標 
	*/
	
	FILE* wptr = fopen("data.csv", "w");
	int i;
	
	if(wptr == NULL) {  // 開檔失敗 ( 儲存失敗 ) 
		printf("Save failed.\n");
		Exit(&(item), num); 
		system("pause");  // 讓小黑框不會因為程式結束就消失 
		exit(EXIT_FAILURE);  // 結束程式  
	} else {  // 開檔成功 ( 儲存成功 ) 
		printf("Save success.\n");
		for(i = 0; i < num; i++) {
			fprintf(wptr, "%c,%s\n", item[i].state, item[i].content);
		}
	}
	fclose(wptr);
}

/* 結束程式  
	程式結束時，釋放所有配置的記憶體空間 
	item : 存事項的狀態與內容  
		-> 傳參考呼叫，傳 *item 的記憶體位置 ( &item )，所以要用 **item 取 *item 的值  
	num : 總共有幾條事項 
*/
void Exit(Item **item, int num) {
	
	int i;
	
	// 釋放配置給 content 的空間  
	for(i = 0; i < num; i++) {
		free((*item)[i].content);
		(*item)[i].content = NULL; 
	}
	// 釋放整個 item 陣列  
	free(*item);
	*item = NULL;
}


