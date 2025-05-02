#include <stdio.h>

void printChar(char c, int n, int newLine);

/* 印出指定字元  
	c : 要印的字元 
	n : 印幾個 
	newLine : 是否要換行  
		0 : 不換 
		1 : 換  
*/ 
void printChar(char c, int n, int newLine) {
	
	int i;
	
	for(i = 0; i < n; i++) {
		printf("%c", c);
	}	
	if(newLine) {
		printf("\n");
	}
}

int main(void) {
	
	/*
		layers : 聖誕樹的層數 
		topHeight : 聖誕樹最上層的三角形高度  
		growth : 聖誕樹的下一層比上一層高多少 
		height : 每層三角形的高度  
		treeWidth : 整棵聖誕樹的寬度   
		trunkWidthMax : 聖誕樹樹幹寬度的上限值  
		trunkWidth : 聖誕樹樹幹的寬度 
		trunkHeight : 聖誕樹樹幹的高度  
	*/
	
	int layers, topHeight, growth, height, treeWidth, trunkWidthMax, trunkWidth, trunkHeight;
	int i, j;
	
	layers = topHeight = growth = height = treeWidth = trunkWidthMax = trunkWidth = trunkHeight = 0;
	
	//輸入聖誕樹的層數 ( 2-5 ) 
	printf("Enter the number of tree layers (2 to 5): ");
	scanf("%d", &layers);
	while(layers < 2 || layers > 5) {  // 檢查輸入是否合格   
		printf("ERROR, out of range.\n");
		printf("Enter the number of tree layers (2 to 5): ");
		scanf("%d", &layers);		
	}
	
	// 輸入聖誕樹最上層的三角形高度 ( 3-6 )
	printf("Enter the height of top layer (3 to 6): ");
	scanf("%d", &topHeight);
	while(topHeight < 3 || topHeight > 6) {  // 檢查輸入是否合格   
		printf("ERROR, out of range.\n");		
		printf("Enter the height of top layer (3 to 6): ");
		scanf("%d", &topHeight);		
	}
	
	// 輸入聖誕樹的下一層比上一層高多少  ( 1-5 )
	printf("Enter the growth of each tree layer (1 to 5): ");
	scanf("%d", &growth);
	while(growth < 1 || growth > 5) {  // 檢查輸入是否合格   
		printf("ERROR, out of range.\n");		
		printf("Enter the growth of each tree layer (1 to 5): ");
		scanf("%d", &growth);		
	}
	
	// 計算整棵聖誕樹的寬度，an = a1 + ( n-1 ) * d  
	height = topHeight + (layers - 1) * growth;  // 聖誕樹最下層的三角形高度  
	treeWidth = 1 + (height - 1) * 2;
	// 計算聖誕樹樹幹寬度的上限值  
	if(treeWidth <= 9) {  // 防止樹幹比聖誕樹寬  
		trunkWidthMax = treeWidth - 2;	
	} else {
		trunkWidthMax = 9;	
	}
	// 輸入聖誕樹樹幹的寬度 ( 3-9 的奇數 )
	printf("Enter the trunk width (odd number, 3 to %d): ", trunkWidthMax);
	scanf("%d", &trunkWidth);
	while(trunkWidth < 3 || trunkWidth > trunkWidthMax || trunkWidth % 2 == 0) {  // 檢查輸入是否合格   
		if(trunkWidth < 3 || trunkWidth > trunkWidthMax) {
			printf("ERROR, out of range.\n");
		} else if(trunkWidth % 2 == 0) {  // 輸入的數值是偶數  
			printf("ERROR, not odd number.\n");
		}
		printf("Enter the trunk width (odd number, 3 to %d): ", trunkWidthMax);
		scanf("%d", &trunkWidth);		
	}	
	
	// 輸入聖誕樹樹幹的高度 ( 4-10 ) 
	printf("Enter the trunk height (4 to 10): ");
	scanf("%d", &trunkHeight);
	while(trunkHeight < 4 || trunkHeight > 10) {  // 檢查輸入是否合格   
		printf("ERROR, out of range.\n");		
		printf("Enter the trunk height (4 to 10): ");
		scanf("%d", &trunkHeight);
	}
	
	printf("\n"); 

	// 印出聖誕樹的最頂端  
	printChar(' ', treeWidth / 2, 0);
	printChar('#', 1, 1);
	
	// 印出聖誕樹的身體  
    height = topHeight;
	for(i = 0; i < layers; i++) {
		// 印出每個三角形，不包含頂點   
		for(j = 1; j < height; j++) {  // j 從 1 開始，因為每個三角形的底部與下一個三角形的頂點重疊  
			printChar(' ', treeWidth / 2 - j, 0);
			if(j != height - 1) {  // 印出三角形，不包含頂點和最下層    
				printChar('#', 1, 0);
				printChar('@', 2 * j - 1, 0);
				printChar('#', 1, 1);			
			} else {  // 印出三角形的最下層  
				printChar('#', 2 * j + 1, 1);
			} 
		}
		// 每印完一個三角形後，計算下一個三角形的高  
		height += growth; 
	}
	
	// 印出聖誕樹的樹幹  
	for(i = 0; i < trunkHeight; i++) {
		printChar(' ', (treeWidth - trunkWidth) / 2, 0);
		if(i != trunkHeight - 1) {  // 樹幹除了最下層，其他的印完都要換行  
			printChar('|', trunkWidth, 1);
		} else {  // 樹幹的最下層印完不換行  
			printChar('|', trunkWidth, 0);
		}
	}
	
	return 0;			
} 
