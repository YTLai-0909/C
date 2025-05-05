#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

int main(void) {
	
	/*
		option : 執行的功能選項  
		item : 存 data.csv 檔的內容 
		num : 計算總共有幾條事項  
		printWay : 是否印出已完成的事項 
			Y / y : 印出已完成的事項 
			N / n : 不印出已完成的事項  
		choiceNum : 選擇要刪除或修改狀態的事項編號  
		inputState : 輸入要修改的狀態  
			O / o : 已完成 
			X / x : 未完成 
	*/
	
	int option;
	Item* item = NULL;
	int num;
	char printWay = '\0';
	int choiceNum;
	char inputState = '\0';
	
	option = num = choiceNum = 0;
	
	// 讀取檔案 
	readFile(&item, &num);
	
	while(1) {
		// 輸入要執行的功能選項 ( 1-6 ) 
		printf("Option: 1.Print item 2.Add item 3.Delete item 4.Revise state 5.Save file 6.Exit\n");
		printf("Enter option: ");
		scanf("%d%*c", &option);  // %*c : 輸入 option 後會按 Enter，%*c 會吃掉 Enter 
		while(option < 1 || option > 6) {  // 檢查輸入是否合格  
			printf("Illegal input.\n");
			printf("Option: 1.Print item 2.Add item 3.Delete item 4.Revise state 5.Save file 6.Exit\n");
			printf("Enter option: ");
			scanf("%d%*c", &option);
		}
		// 執行功能  
		if(option == 1) {  // 印出事項  
			if(item == NULL) {  // item 陣列中沒有事項  
				printf("No item.\n");
			} else {  // item 陣列中有事項  
				// 選擇是否印出已完成的事項  
				printf("Print completed items (Y / N): ");
				scanf("%c%*c", &printWay);  // %*c : 輸入 printWay 後會按 Enter，%*c 會吃掉 Enter  
				printWay = toupper(printWay);  // 解決 Y / y 或 N / n 問題  
				while(printWay != 'Y' && printWay != 'N') {  // 檢查輸入是否合格  
					printf("Illegal input.\n");
					printf("Print completed items (Y / N): ");
					scanf("%c%*c", &printWay);
					printWay = toupper(printWay);
				}
				// 根據選擇的條件印出事項  
				printItem(item, num, printWay);	
			}
		} else if(option == 2) {  // 新增事項  
			printf("Enter the content of item: ");
			addItem(&item, &num);
		} else if(option == 3) {  // 刪除事項  
			if(item == NULL) {  // item 陣列中沒有事項  
				printf("No item.\n");
			} else {  // item 陣列中有事項  
				// 列出 item 陣列中的所有事項  
				printItem(item, num, 'Y');
				// 選擇要刪除的事項編號  
				printf("Enter the item number to delete: ");
				scanf("%d%*c", &choiceNum);  // %*c : 輸入 choiceNum 後會按 Enter，%*c 會吃掉 Enter  
				while(choiceNum < 1 || choiceNum > num) {  // 檢查輸入是否合格  
					printf("Item number does not exist.\n");
					printf("Enter the item number to delete: ");
					scanf("%d%*c", &choiceNum);
				}
				// 刪除事項 
				deleteItem(&item, &num, choiceNum);
			}
		} else if(option == 4) {  // 修改狀態  
			if(item == NULL) {  // item 陣列中沒有事項  
				printf("No item.\n");
			} else {  // item 陣列中有事項  
				// 列出 item 陣列中的所有事項  
				printItem(item, num, 'Y');
				// 選擇要修改的事項編號 
				printf("Enter the item number to revise state: ");
				scanf("%d%*c", &choiceNum);  // %*c : 輸入 choiceNum 後會按 Enter，%*c 會吃掉 Enter  
				while(choiceNum < 1 || choiceNum > num) {  // 檢查輸入是否合格  
					printf("Item number does not exist.\n");
					printf("Enter the item number to revise state: ");
					scanf("%d%*c", &choiceNum);
				}
				// 輸入要修改的狀態 
				printf("Enter the state (O: completed, X: not completed):");
				scanf("%c%*c", &inputState);  // %*c : 輸入 inputState 後會按 Enter，%*c 會吃掉 Enter  
				inputState = toupper(inputState);  // 解決 O / o 或 X / x 問題  
				while(inputState != 'O' && inputState != 'X') {  // 檢查輸入是否合格  
					printf("Illegal input.\n");
					printf("Enter the state (O: completed, X: not completed):");
					scanf("%c%*c", &inputState);
					inputState = toupper(inputState);
				}
				// 修改狀態  
				reviseState(&item, choiceNum, inputState);
			}
		} else if(option == 5) {  // 儲存檔案  
			saveFile(item, num);
		} else if(option == 6) {  // 結束程式  
			if(item != NULL) {  // 有配置空間才需要釋出  
				Exit(&item, num);				
			}
			break;
		}
		printf("\n");
	}
	
	system("pause");  // 讓小黑框不會因為程式結束就消失 
	
	return 0; 
} 
