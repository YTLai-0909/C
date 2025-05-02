#include <stdio.h>

int main(void) {

	/*
		petNum : 寵物數量 
		star : 星辰數量 
		cp : 寵物的 CP 值 
		iv : 寵物的 IV 值 
		level : 可以升幾等  
		maxCP : 記錄最高 CP 值是多少 
		num : 記錄最高 CP 值的寵物編號  
	*/
		
	int petNum, star;
	int cp, iv;
	int level, maxCP, num;
	int i;
	
	petNum = star = cp = iv = level = maxCP = num = 0;
	
	// 輸入寵物數量 ( 正整數 ) 
	printf("Enter the number of pet (positive integer): ");
	scanf("%d", &petNum);
	while(petNum <= 0) {  // 檢查輸入是否合格  
		printf("ERROR, out of range.\n");
		printf("Enter the number of pet (positive integer): ");
		scanf("%d", &petNum);		
	}
	// 輸入星辰數量 ( 非負整數 ) 
	printf("Enter the number of star (not negative integer): ");
	scanf("%d", &star);
	while(star < 0) {  // 檢查輸入是否合格  
		printf("ERROR, out of range.\n");
		printf("Enter the number of star (not negative integer): ");
		scanf("%d", &star);
	}
	
	// 印出 IV 區間對應的 CP 值  
	printf("\n");
	printf("IV: 0-29, CP: +10\n");
	printf("IV: 30-39, CP: +50\n");
	printf("IV: 40-50, CP: +100\n");
	printf("\n");
	
	for(i = 1; i <= petNum; i++) { 
		// 輸入寵物的 CP 值 ( 正整數 )
		printf("Pet No.%d CP (positive integer): ", i);
		scanf("%d", &cp);
		while(cp <= 0) {  // 檢查輸入是否合格  
			printf("ERROR, out of range.\n");
			printf("Pet No.%d CP (positive integer): ", i);
			scanf("%d", &cp);
		}
		// 輸入寵物的 IV 值 ( 0-50 ) 
		printf("Pet No.%d IV (0 to 50): ", i);
		scanf("%d", &iv);
		while(iv < 0 || iv > 50) {  // 檢查輸入是否合格  
			printf("ERROR, out of range.\n");
			printf("Pet No.%d IV (0 to 50): ", i);
			scanf("%d", &iv);
		}
		// 計算現有星辰可以升幾等 ( 升一等要消耗 1000 星辰 ) 
		level = star / 1000;
		// 計算寵物 CP 值  
		if(iv >= 0 && iv <= 29) {  // IV 區間 0-29，每升一等 CP 值加 10  
			cp += 10 * level;
		} else if(iv >= 30 && iv <= 39) {  // IV 區間 30-39，每升一等 CP 值加 50  
			cp += 50 * level;
		} else if(iv >= 40 && iv <= 50) {  // IV 區間 40-50，每升一等 CP 值加 100  
			cp += 100 * level;
		}
//		printf("No.%d CP = %d\n", i, cp);  // 檢查各寵物的 CP 值  
		// 記錄 CP 值最高的寵物資訊  
		if(cp > maxCP) {  // 和最大值做比較，比最大值大，才會記錄該寵物的 CP 值與編號  
			maxCP = cp;
			num = i;
		}
	}
	
	printf("\n");
	
	// 印出 CP 值最高的寵物資訊  
	printf("Pet No.%d has the highest CP = %d.", num, maxCP);
	
	return 0;
} 
