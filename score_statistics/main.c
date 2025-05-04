#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define ID_MAX_SIZE 100  // ID 的最大長度  
#define STUDENT_MAX_SIZE 100  // 最多可以輸入幾筆學生的資料  

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

int main(void) {
	
	/*
		student : 存每一個學生的 ID 與分數 
		num : 計算總共有幾人  
		copyData : 將學生的 ID 與分數做備份  
		option : 要執行哪一種排序方式  
			0 : 結束程式 
			1 : 以 ID 做排序 
			2 : 以分數做排序  
	*/
	
	Student student[STUDENT_MAX_SIZE];
	int num;
	Student copyData[STUDENT_MAX_SIZE];
	int option;
	int i;
	
	num = option = 0;
	
	// 輸入學生的 ID 與分數 
	input(student, &num);
	
	if(num > 0) {  // 有輸入資料  
		// 把學生的 ID 與分數資料備份到 copyData 
		copy(copyData, student, num);
	
		// 進行資料排序與統計分析  
		while(1) {
			// 每次執行動作前，先將 student 陣列初始化為最初輸入的資料 ( 將 copyData 的資料複製到 student )
			copy(student, copyData, num);
			// 輸入排序方式 ( 0-2 )
			printf("\nSort By (1.ID 2.Score 0.exit): ");
			scanf("%d", &option);
			while(option < 0 || option > 2) {  // 檢查輸入是否合格  
				printf("Illegal input, input can only be 0 or 1 or 2.\n");
				printf("Sort By (1.ID 2.Score 0.exit): ");
				scanf("%d", &option);
			}
			// 執行排序  
			if(option == 0) {  // 結束程式  
				break;
			} else if(option == 1) {  // 依照 ID 進行排序 
				sort(student, num, id);
			} else if(option == 2) {  // 依照分數進行排序  
				sort(student, num, score);
			}
			// 印出排序結果 
			print(student, num);
			// 統計分析  
			getAverage(student, num);  // 計算平均  
			for(i = 1; i <= 3; i++) {  // 計算四分位數  
				getQuartile(student, num, i);
			}
			printf("\n");
		}
	} else {  // 沒有輸入資料  
		printf("No student data.\n");
	} 
	
	system("pause");  // 讓小黑框不會因為程式結束就消失  
	
	return 0;
}
