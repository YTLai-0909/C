#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100  // 姓名的最大長度  

void Add(char ***name, int *num);
void Print(char **name, int num);
void Sort(char ***name, int num);
void swap(char **str1, char **str2);
void Exit(char ***name, int num);

/* 新增 
	新增一個姓名到列表最下方 
	name : 指向記錄姓名的二維動態陣列的起始位置  
		-> 傳參考呼叫，傳 name 的記憶體位置 ( &name )，所以要用 ***name 取 **name 的值  
	num : 計算總共有幾個姓名  
		-> 傳參考呼叫，傳 num 的記憶體位置 ( &num )，所以要用 *num 取 num 的值  
*/
void Add(char ***name, int *num) {
	
	/*
		input : 記錄輸入的姓名 
		len : 計算姓名的長度  
		check : 檢查輸入的姓名是否符合格式 
			0 : 不合格  
			1 : 合格  
	*/
	
	char input[MAX_LEN] = {'\0'};
	int len, check;
	int i;
	
	len = check = 0;
	
	// 輸入姓名 ( 大小寫英文字母或空格 )
	while(!check) {
		printf("Enter name(letters or spaces): ");
		gets(input);
		len = strlen(input);		
		for(i = 0; i < len; i++) {  // 檢查輸入是否合格  
			if(isalpha(input[i]) || input[i] == ' ') {  // 字母或空格  
				check = 1;  // 合格  
			} else {
				check = 0;  // 不合格  
				printf("ERROR, name format illegal.\n");
				break;
			}
		}
	}
	
	// 配置二維動態陣列的第一維空間  
	if(!(*num)) {  // 第一次配置空間  
		*name = (char**)calloc((*num) + 1, sizeof(char*));  // +1 : 因為陣列的第一個位置 index = 0  
	} else {  // 改變已配置的空間  
		*name = (char**)realloc(*name, ((*num) + 1) * sizeof(char*));  // +1 : 因為陣列的第一個位置 index = 0  
	}
	// 配置二維動態陣列的第二維空間 
	(*name)[*num] = (char*)calloc(len + 1, sizeof(char));  // +1 : 最後一個位置放 '\0' 
	// 將輸入的姓名加入陣列中  
	strcpy((*name)[*num], input);
	(*num)++;
}

/* 印出 
	根據目前的姓名列表，依序列出所有姓名，一個姓名佔一列  
	name : 指向記錄姓名的二維動態陣列的起始位置  
	num : 總共有幾個姓名  
*/
void Print(char **name, int num) {
	
	int i;
	
	if(num > 0) {  // 有輸入資料  
		for(i = 0; i < num; i++) {
			printf("%s\n", name[i]);
		}		
	} else {  // 沒有輸入資料  
		printf("No data.\n");
	}
}

/* 排序 
	將目前的姓名列表依照字典排序的方式進行排序 ( Ex: AaBbCcDd...Zz ) 
	name : 指向記錄姓名的二維動態陣列的起始位置  
		-> 傳參考呼叫，傳 name 的記憶體位置 ( &name )，所以要用 ***name 取 **name 的值  
	num : 總共有幾個姓名  
*/
void Sort(char ***name, int num) {
	
	/*
		dict : 字典  
		len1 : 要比較的第一個字串的長度 
		len2 : 要比較的第二個字串的長度 
		index : 目前比到第幾個字元  
		str1 : 記錄第一個字串目前的字元在字典中的位置 
		str2 : 記錄第二個字串目前的字元在字典中的位置  
	*/
	
	char dict[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz ";
	int len1, len2;
	int index;
	char* str1 = NULL;
	char* str2 = NULL;
	int i, j;
	
	len1 = len2 = index = 0;
	
	if(num > 0) {  // 有輸入資料  
		// 泡沫排序 
		for(i = 0; i < num - 1; i++) {  // 比的回合數 
			for(j = 0; j < num - i - 1; j++) {  // 比的次數  
				// 計算字串長度  
				len1 = strlen((*name)[j]);
				len2 = strlen((*name)[j + 1]);
				// 兩個字串有相同的字元，繼續往後比  
				index = 0;
				while(((*name)[j][index] == (*name)[j + 1][index]) && index < len1 && index < len2) {
					index++;
				}
				if(index == len1 || index == len2) {  // 其中一個字串先比完 ( 到目前為止都相同 ) 
					if(len1 > len2) {
						// 交換指標 
						swap(&(*name)[j], &(*name)[j + 1]);  // 傳指標的記憶體位置 (&char*) 
					}
				} else {  // 兩個字串遇到不同的字元  
					// 尋找目前字元在字典中的位置  
					str1 = strchr(dict, (*name)[j][index]);
					str2 = strchr(dict, (*name)[j + 1][index]);
					if(str1 > str2) {
						// 交換指標 
						swap(&(*name)[j], &(*name)[j + 1]);  // 傳指標的記憶體位置 (&char*)	
					}
				}
			}
		}
		printf("Sort finish.\n");
	} else {  // 沒有輸入資料  
		printf("No data.\n");
	}
}

/* 字串交換 
	將 str1 與 str2 做交換 
	str1 : 要交換的第一個字串的指標  
		-> 傳參考呼叫，傳指標( char* )的記憶體位置 ( &(*name)[j] )，所以要用 **str1 取 *str1 的值  
	str2 : 要交換得第二個字串的指標 
		-> 傳參考呼叫，傳指標( char* )的記憶體位置 ( &(*name)[j + 1] )，所以要用 **str2 取 *str2 的值  
*/
void swap(char **str1, char **str2) {
	
	char* tmp;  // 指標交換時，作為暫存用 
	
	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

/* 離開  
	釋出全部動態記憶體空間，結束程式 
	name : 指向記錄姓名的二維動態陣列的起始位置  
		-> 傳參考呼叫，傳 name 的記憶體位置 ( &name )，所以要用 ***name 取 **name 的值  
	num : 總共有幾個姓名  
*/
void Exit(char ***name, int num) {
	
	int i;
	
	// 釋放二維動態陣列的第二維空間  
	for(i = 0; i < num; i++) {
		free((*name)[i]);
	}
	// 釋放二維動態陣列的第一維空間  
	free(*name);
	(*name) = NULL;
} 

int main(void) {
	
	/*
		name : 指向記錄姓名的二維動態陣列的起始位置  
		option : 功能選項 
			1. 新增 
			2. 印出  
			3. 排序  
			4. 離開  
		num : 總共有幾個姓名  
	*/
	
	char **name = NULL;
	int option, num;
	
	option = num = 0;
	
	while(1) {
		// 選擇功能 ( 1-4 )
		printf("Enter option(1.Add 2.Print 3.Sort 4.Exit): ");
		scanf("%d%*c", &option);  // %*c : 輸入 option 後會按 Enter，%*c 會吃掉 Enter，否則會被 gets 吃到  
		while(option < 1 || option > 4) {  // 檢查輸入是否合格  
			printf("ERROR, out of range.\n");
			printf("Enter option(1.Add 2.Print 3.Sort 4.Exit): ");
			scanf("%d%*c", &option);
		}
		// 執行功能 
		if(option == 1) {  // 新增一個姓名  
			Add(&name, &num);	
		} else if(option == 2) {  // 印出所有姓名 
			Print(name, num);
		} else if(option == 3) {  // 將姓名依照字典排序 ( Ex: AaBbCcDd...Zz ) 
			Sort(&name, num);
		} else if(option == 4) {  // 結束程式  
			Exit(&name, num);
			break;
		}
	}
	
	return 0;
} 
