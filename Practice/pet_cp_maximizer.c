#include <stdio.h>

int main(void) {

	/*
		petNum : �d���ƶq 
		star : �P���ƶq 
		cp : �d���� CP �� 
		iv : �d���� IV �� 
		level : �i�H�ɴX��  
		maxCP : �O���̰� CP �ȬO�h�� 
		num : �O���̰� CP �Ȫ��d���s��  
	*/
		
	int petNum, star;
	int cp, iv;
	int level, maxCP, num;
	int i;
	
	petNum = star = cp = iv = level = maxCP = num = 0;
	
	// ��J�d���ƶq ( ����� ) 
	printf("Enter the number of pet (positive integer): ");
	scanf("%d", &petNum);
	while(petNum <= 0) {  // �ˬd��J�O�_�X��  
		printf("ERROR, out of range.\n");
		printf("Enter the number of pet (positive integer): ");
		scanf("%d", &petNum);		
	}
	// ��J�P���ƶq ( �D�t��� ) 
	printf("Enter the number of star (not negative integer): ");
	scanf("%d", &star);
	while(star < 0) {  // �ˬd��J�O�_�X��  
		printf("ERROR, out of range.\n");
		printf("Enter the number of star (not negative integer): ");
		scanf("%d", &star);
	}
	
	// �L�X IV �϶������� CP ��  
	printf("\n");
	printf("IV: 0-29, CP: +10\n");
	printf("IV: 30-39, CP: +50\n");
	printf("IV: 40-50, CP: +100\n");
	printf("\n");
	
	for(i = 1; i <= petNum; i++) { 
		// ��J�d���� CP �� ( ����� )
		printf("Pet No.%d CP (positive integer): ", i);
		scanf("%d", &cp);
		while(cp <= 0) {  // �ˬd��J�O�_�X��  
			printf("ERROR, out of range.\n");
			printf("Pet No.%d CP (positive integer): ", i);
			scanf("%d", &cp);
		}
		// ��J�d���� IV �� ( 0-50 ) 
		printf("Pet No.%d IV (0 to 50): ", i);
		scanf("%d", &iv);
		while(iv < 0 || iv > 50) {  // �ˬd��J�O�_�X��  
			printf("ERROR, out of range.\n");
			printf("Pet No.%d IV (0 to 50): ", i);
			scanf("%d", &iv);
		}
		// �p��{���P���i�H�ɴX�� ( �ɤ@���n���� 1000 �P�� ) 
		level = star / 1000;
		// �p���d�� CP ��  
		if(iv >= 0 && iv <= 29) {  // IV �϶� 0-29�A�C�ɤ@�� CP �ȥ[ 10  
			cp += 10 * level;
		} else if(iv >= 30 && iv <= 39) {  // IV �϶� 30-39�A�C�ɤ@�� CP �ȥ[ 50  
			cp += 50 * level;
		} else if(iv >= 40 && iv <= 50) {  // IV �϶� 40-50�A�C�ɤ@�� CP �ȥ[ 100  
			cp += 100 * level;
		}
//		printf("No.%d CP = %d\n", i, cp);  // �ˬd�U�d���� CP ��  
		// �O�� CP �ȳ̰����d����T  
		if(cp > maxCP) {  // �M�̤j�Ȱ�����A��̤j�Ȥj�A�~�|�O�����d���� CP �ȻP�s��  
			maxCP = cp;
			num = i;
		}
	}
	
	printf("\n");
	
	// �L�X CP �ȳ̰����d����T  
	printf("Pet No.%d has the highest CP = %d.", num, maxCP);
	
	return 0;
} 
