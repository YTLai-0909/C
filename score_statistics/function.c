#include <stdio.h>
#include <string.h>
#include "function.h"
#define ID_MAX_SIZE 100  // ID 的最大長度  
#define ID_LEN 5  // 預設 ID 長度  

/* 學生的結構   
	id : 學生 ID
		- 第一個字元 : 大寫英文字母  
		- 第一個以後的字元 : 編號  
	score : 學生分數  
*/
struct studentData {
	char id[ID_MAX_SIZE];  // 字串  
	int score;
};

/* 輸入學生的資料 ( 輸入為 0 0 時，停止輸入 ) 
	student : 存學生的 ID 與分數 
	num : 計算總共有幾人  
		-> 傳參考呼叫，傳 num 的記憶體位置 ( &num )，所以要用 *num 取 num 的值  
*/
void input(Student *student, int *num) {
	
	int len = 0;  // 記錄輸入的 ID 長度  
	int i;
	
	printf("Please input ID and Score (0 0 to stop input): \n");
	printf("ID (1 uppercase A to Z + 4 numbers)\n");
	printf("Score (0 to 100)\n");
	while(1) {
		// 輸入 ID 與分數  
		printf(">> ");
		scanf("%s %d", student[*num].id, &student[*num].score);
		// 輸入為 0 0 時，停止輸入  
		if(strcmp(student[*num].id, "0") == 0 && student[*num].score == 0) {
			break;
		}
		// 檢查 ID 是否合格 ( 長度 = 5，1 個大寫字母 + 4 個數字 ) 
		len = strlen(student[*num].id);
		if(len < ID_LEN || len > ID_LEN) {  // ID 長度不等於 5，重新輸入  
			if(len < ID_LEN) {
				printf("Illegal input, ID length is too short.\n");
			} else if(len > ID_LEN) {
				printf("Illegal input, ID length is too long.\n");
			}
			continue;
		} else if(student[*num].id[0] < 'A' || student[*num].id[0] > 'Z') {  // 第一個字不是大寫英文字母，重新輸入   
			printf("Illegal input, the first letter is not uppercase.\n");
			continue;
		} else {  // 第一個字後面出現非數字，重新輸入  
			for(i = 1; i < ID_LEN; i++) {
				if(student[*num].id[i] < '0' || student[*num].id[i] > '9') {
					printf("Illegal input, ID format is error.\n");
					break;
				}
			}
			if(i != ID_LEN) {  // ID 格式錯誤，不需要檢查分數直接要求重新輸入  
				continue;	
			}
		}
		// 檢查分數是否合格 ( 0-100 ) 
		if(student[*num].score < 0 || student[*num].score > 100) {  // 分數不在 0-100 的範圍，重新輸入  
			printf("Illegal input, score is out of range.\n");
			continue;
		}
		(*num)++;  // 儲存該筆資料  
	}	
}

/* 複製資料 
	將 data2 的資料複製到 data 1 
	data1 : 要被更新的資料  
	data2 : 原始資料  
	num : 總共有幾筆資料  
*/
void copy(Student *data1, Student *data2, int num) {

	int i;
	
	if(num > 0) {
		for(i = 0; i < num; i++) {
			strcpy(data1[i].id, data2[i].id);
			data1[i].score = data2[i].score;
		}
	}
}

/*  比較兩個 ID 
	student 學生的資料 
	one : 第一筆資料 
	two : 第二筆資料 
	回傳 :  
		1 : true，第一筆 id > 第二筆 id  ( strcmp 的回傳大於 0 ) 
		0 : false，第一筆 id < 第二筆 id ( strcmp 的回傳小於 0 ) 
*/ 
_Bool id(Student *student, int one, int two) {
	
	return strcmp(student[one].id, student[two].id) > 0;
}

/* 比較兩個分數 
	student 學生的資料 
	one : 第一筆資料 
	two : 第二筆資料 
	回傳 :  
		1 : true，第一筆分數 > 第二筆分數  
		0 : false，第一筆分數 < 第二筆分數   
*/
_Bool score(Student *student, int one, int two) {
	
	return student[one].score > student[two].score;
}

/* 對資料進行特定排序 
	student : 學生的資料 
	num : 總共有幾人 
	cmp : 排序方式 
		id : 依照 ID 
		score : 依照分數  
*/
// _Bool (*cmp)(Student*, int, int) : 函式指標作為參數 
void sort(Student *student, int num, _Bool (*cmp)(Student*, int, int)) {

	char tmpId[ID_MAX_SIZE] = {'\0'};  // ID 交換時，作為暫存用  
	int tmpScore = 0;  // 分數交換時，作為暫存用  
	int i, j;
	
	if(num > 0) {
		// 泡沫排序 ( 由小到大排序 ) 
		for(i = 0; i < num - 1; i++) {  // 要比的回合數  
			for(j = 0; j < num - i - 1; j++) {  // 每回合比的次數 
				if(cmp(student, j, j + 1)) {
					// 交換 ID 的位置  
					strcpy(tmpId, student[j].id);
					strcpy(student[j].id, student[j + 1].id);
					strcpy(student[j + 1].id, tmpId);
					// 交換分數的位置  
					tmpScore = student[j].score;
					student[j].score = student[j + 1].score;
					student[j + 1].score = tmpScore;
				}
			}
		}
	}
}

/* 印出排序結果 
	student : 學生的資料 
	num : 總共有幾人  
*/
void print(Student *student, int num) {
	
	int i;
	
	if(num > 0) {
		printf("\nSID      Score\n");
		for(i = 0; i < num; i++) {
			printf("%s    %d\n", student[i].id, student[i].score);
		}
		printf("-----------------------------\n");
	}
} 


/* 計算平均 
	student : 學生的資料 
	num : 總共有幾人  
*/ 
void getAverage(Student *student, int num) {
	
	int sum = 0;
	float avg = 0;
	int i;
	
	if(num > 0) {
		// 計算分數總合  
		for(i = 0; i < num; i++) {
			sum += student[i].score;
		}
		avg = sum * 1.0 / num;  // sum * 1.0 : 將 sum 從 int 轉成 float  
		printf("Average: %.4f\n", avg);  // 印到小數點第 4 位  	
	}
}

/* 計算四分位數 
	student : 學生的資料 
	num : 總共有幾人  
	numQ : 第幾四分位數 
		Q1 : 第一四分位數 ( P_25 第 25% 項的數值 )
		Q2 : 第二四分位數 ( P_50 第 50% 項的數值 )
		Q3 : 第三四分位數 ( P_75 第 75% 項的數值 ) 
*/ 
void getQuartile(Student *student, int num, int numQ) {
	
	float index = 0;  // 取第幾筆資料  
	
	if(num > 0) {
		// 將分數進行排序 
		sort(student, num, score);
		// 計算要取第幾筆資料 
		switch(numQ) {
			case 1:  // 第 25% 項的數值  
				index = (num * 1.0) * 25 / 100;  // num * 1.0 : 將 num 從 int 轉成 float  
				break;
			case 2:  // 第 50% 項的數值  
				index = (num * 1.0) * 50 / 100;
				break;
			case 3:  // 第 75% 項的數值  
				index = (num * 1.0) * 75 / 100;
				break;
		}
		if(index != (int)index) {  // index 不是整數時，取 ( index 的整數部分 + 1 ) 的那筆資料  
			// (int)index + 1 : 取 ( index 的整數部分 + 1 ) 的那筆資料  
			// -1 : 陣列的第一個位置為 0  
			// *1.0 : 將 int 轉成 float  
			printf("Q%d: %.1f  ", numQ, student[((int)index + 1) - 1].score * 1.0);
		} else {  // index 是整數時，取 ( index 與 index + 1 ) 兩筆資料的平均  
			// (int)index : 將 index 轉成整數後，取 ( index ) 那筆資料  
			// (int)index + 1 : 將 index 轉成整數後，取 ( index + 1 ) 那筆資料 
			// -1 : 陣列的第一個位置為 0  
			// *1.0 : 將 int 轉成 float 
			// /2 : 取 ( index 與 index + 1 ) 兩筆資料的平均  
			printf("Q%d: %.1f  ", numQ, (student[(int)index - 1].score + student[((int)index + 1) - 1].score) * 1.0 / 2);
		}
	}
}
