#include <stdio.h>

void printChar(char c, int n, int newLine);

/* �L�X���w�r��  
	c : �n�L���r�� 
	n : �L�X�� 
	newLine : �O�_�n����  
		0 : ���� 
		1 : ��  
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
		layers : �t�Ͼ𪺼h�� 
		topHeight : �t�Ͼ�̤W�h���T���ΰ���  
		growth : �t�Ͼ𪺤U�@�h��W�@�h���h�� 
		height : �C�h�T���Ϊ�����  
		treeWidth : ��ʸt�Ͼ𪺼e��   
		trunkWidthMax : �t�Ͼ��F�e�ת��W����  
		trunkWidth : �t�Ͼ��F���e�� 
		trunkHeight : �t�Ͼ��F������  
	*/
	
	int layers, topHeight, growth, height, treeWidth, trunkWidthMax, trunkWidth, trunkHeight;
	int i, j;
	
	layers = topHeight = growth = height = treeWidth = trunkWidthMax = trunkWidth = trunkHeight = 0;
	
	//��J�t�Ͼ𪺼h�� ( 2-5 ) 
	printf("Enter the number of tree layers (2 to 5): ");
	scanf("%d", &layers);
	while(layers < 2 || layers > 5) {  // �ˬd��J�O�_�X��   
		printf("ERROR, out of range.\n");
		printf("Enter the number of tree layers (2 to 5): ");
		scanf("%d", &layers);		
	}
	
	// ��J�t�Ͼ�̤W�h���T���ΰ��� ( 3-6 )
	printf("Enter the height of top layer (3 to 6): ");
	scanf("%d", &topHeight);
	while(topHeight < 3 || topHeight > 6) {  // �ˬd��J�O�_�X��   
		printf("ERROR, out of range.\n");		
		printf("Enter the height of top layer (3 to 6): ");
		scanf("%d", &topHeight);		
	}
	
	// ��J�t�Ͼ𪺤U�@�h��W�@�h���h��  ( 1-5 )
	printf("Enter the growth of each tree layer (1 to 5): ");
	scanf("%d", &growth);
	while(growth < 1 || growth > 5) {  // �ˬd��J�O�_�X��   
		printf("ERROR, out of range.\n");		
		printf("Enter the growth of each tree layer (1 to 5): ");
		scanf("%d", &growth);		
	}
	
	// �p���ʸt�Ͼ𪺼e�סAan = a1 + ( n-1 ) * d  
	height = topHeight + (layers - 1) * growth;  // �t�Ͼ�̤U�h���T���ΰ���  
	treeWidth = 1 + (height - 1) * 2;
	// �p��t�Ͼ��F�e�ת��W����  
	if(treeWidth <= 9) {  // �����F��t�Ͼ�e  
		trunkWidthMax = treeWidth - 2;	
	} else {
		trunkWidthMax = 9;	
	}
	// ��J�t�Ͼ��F���e�� ( 3-9 ���_�� )
	printf("Enter the trunk width (odd number, 3 to %d): ", trunkWidthMax);
	scanf("%d", &trunkWidth);
	while(trunkWidth < 3 || trunkWidth > trunkWidthMax || trunkWidth % 2 == 0) {  // �ˬd��J�O�_�X��   
		if(trunkWidth < 3 || trunkWidth > trunkWidthMax) {
			printf("ERROR, out of range.\n");
		} else if(trunkWidth % 2 == 0) {  // ��J���ƭȬO����  
			printf("ERROR, not odd number.\n");
		}
		printf("Enter the trunk width (odd number, 3 to %d): ", trunkWidthMax);
		scanf("%d", &trunkWidth);		
	}	
	
	// ��J�t�Ͼ��F������ ( 4-10 ) 
	printf("Enter the trunk height (4 to 10): ");
	scanf("%d", &trunkHeight);
	while(trunkHeight < 4 || trunkHeight > 10) {  // �ˬd��J�O�_�X��   
		printf("ERROR, out of range.\n");		
		printf("Enter the trunk height (4 to 10): ");
		scanf("%d", &trunkHeight);
	}
	
	printf("\n"); 

	// �L�X�t�Ͼ𪺳̳���  
	printChar(' ', treeWidth / 2, 0);
	printChar('#', 1, 1);
	
	// �L�X�t�Ͼ𪺨���  
    height = topHeight;
	for(i = 0; i < layers; i++) {
		// �L�X�C�ӤT���ΡA���]�t���I   
		for(j = 1; j < height; j++) {  // j �q 1 �}�l�A�]���C�ӤT���Ϊ������P�U�@�ӤT���Ϊ����I���|  
			printChar(' ', treeWidth / 2 - j, 0);
			if(j != height - 1) {  // �L�X�T���ΡA���]�t���I�M�̤U�h    
				printChar('#', 1, 0);
				printChar('@', 2 * j - 1, 0);
				printChar('#', 1, 1);			
			} else {  // �L�X�T���Ϊ��̤U�h  
				printChar('#', 2 * j + 1, 1);
			} 
		}
		// �C�L���@�ӤT���Ϋ�A�p��U�@�ӤT���Ϊ���  
		height += growth; 
	}
	
	// �L�X�t�Ͼ𪺾�F  
	for(i = 0; i < trunkHeight; i++) {
		printChar(' ', (treeWidth - trunkWidth) / 2, 0);
		if(i != trunkHeight - 1) {  // ��F���F�̤U�h�A��L���L�����n����  
			printChar('|', trunkWidth, 1);
		} else {  // ��F���̤U�h�L��������  
			printChar('|', trunkWidth, 0);
		}
	}
	
	return 0;			
} 
