#include <stdio.h>

int main(void) {
	
	/*
		monsterLv : �Ǫ����� 
		monsterHp : �Ǫ��ͩR�� 
		monsterAtk : �Ǫ������O 
		humanLv : �i�̵��� 
		humanHp : �i�̥ͩR�� 
		humanAtk : �i�̧����O 
		humanRe : �i�̫�_�O  
		round : �^�X�� 
		nowHumanHp : �i�̥ثe���ͩR�� 
		option : �i�̪��ʧ@�ﶵ 
	*/
	
	int monsterLv, monsterHp, monsterAtk;
	int humanLv, humanHp, humanAtk, humanRe;
	int round, nowHumanHp, option;
	
	monsterLv = monsterHp = monsterAtk = humanLv = humanHp = humanAtk = humanRe = round = nowHumanHp = option = 0;
	
	// ��J�Ǫ����� ( 1-3 ) 
	printf("Enter the monster level (1 to 3): ");
	scanf("%d", &monsterLv);
	while(monsterLv < 1 || monsterLv > 3) {  // �ˬd��J�O�_�X��  
		printf("ERROR, out of range.\n");
		printf("Enter the monster level (1 to 3): ");
		scanf("%d", &monsterLv);
	}
	// ��J�i�̵��� ( 1-3 ) 
	printf("Enter the human level (1 to 3): ");
	scanf("%d", &humanLv);
	while(humanLv < 1 || humanLv > 3) {  // �ˬd��J�O�_�X��  
		printf("ERROR, out of range.\n");
		printf("Enter the human level (1 to 3): ");
		scanf("%d", &humanLv);
	}
	
	printf("\n");
	
	// �]�w�Ǫ��ƭ� 
	switch(monsterLv) {
		case 1:
			monsterHp = 1000;
			monsterAtk = 50;
			break;
		case 2:
			monsterHp = 5000;
			monsterAtk = 200;
			break;
		case 3:
			monsterHp = 30000;
			monsterAtk = 500;
			break;	
	}
	// �]�w�i�̼ƭ� 
	switch(humanLv) {
		case 1:
			humanHp = 800;
			humanAtk = 50;
			humanRe = 600;
			break;
		case 2:
			humanHp = 1500;
			humanAtk = 100;
			humanRe = 700;
			break;
		case 3:
			humanHp = 3000;
			humanAtk = 400;
			humanRe = 1000;
			break;		
	}
	
	// �C���}�l  
	nowHumanHp = humanHp;  // �O���i�̥ثe���ͩR��  
	while(1) {
		// �L�X�^�X�ơA�i�̻P�Ǫ�����T  
		round++;  // �j��C����@���^�X�ƥ[�@ 
		printf("Round %d\n", round);
		printf("Human\n");
		printf("    HP�G%d ATK�G%d RE�G%d\n", nowHumanHp, humanAtk, humanRe);
		printf("Monster\n");
		printf("    HP�G%d ATK�G%d\n", monsterHp, monsterAtk);
		// ��J�ﶵ  
		printf("1.attack 2.recover 3.run away\n");
		printf("Enter the option (1 to 3): ");
		scanf("%d", &option);
		while(option < 1 || option > 3){   // �ˬd��J�O�_�X��  
			printf("ERROR, out of range.\n");
			printf("Enter the option (1 to 3): ");
			scanf("%d", &option);
		}
		// ����ﶵ ( �i�̳��� )
		if(option == 1) {  // ��ܧ��� 
			monsterHp -= humanAtk;
			if(monsterHp <= 0) {  // �Ǫ��ͩR���k�s�A�Ǫ���A�C�������A���X�j�� 
				monsterHp = 0;
				printf("Human attack Monster HP�G%d\n\n", monsterHp);
				break;
			} else {  // �Ǫ������A�C���~��  
				printf("Human attack Monster HP�G%d\n", monsterHp);
			}
		} else if(option == 2) {  // ��ܫ�_ 
			nowHumanHp += humanRe;
			if(nowHumanHp >= humanHp) {  // �i�̥ͩR�ȶW�L�@�}�l�]�w���ȡA�H�@�}�l�]�w���Ȫ�� 
				nowHumanHp = humanHp;
			} 
			printf("Human recover Human HP�G%d\n", nowHumanHp);
		} else if(option == 3) {  // ��ܰk�]�A�C�������A���X�j��  
			printf("Human run away\n\n");
			break;
		}
		// �Ǫ����� 
		nowHumanHp -= monsterAtk;
		if(nowHumanHp <= 0) {  // �i�̥ͩR���k�s�A�i�̿�A�C�������A���X�j��  
			nowHumanHp = 0;
			printf("Monster attack Human HP�G%d\n\n", nowHumanHp);
			break;
		} else {  // �i�̥����A�C���~��  
			printf("Monster attack Human HP�G%d\n\n", nowHumanHp);
		}
	}
	
	// �L�X�C�����G  
	if(monsterHp <= 0) {  // �i�̳ӧQ ( �Ǫ��ͩR���k�s ) 
		printf("Human HP�G%d\n", nowHumanHp);
		printf("Monster HP�G%d\n", monsterHp);
		printf("**Human Win!**");
	} else if(nowHumanHp <= 0 || option == 3) {  // �Ǫ��ӧQ ( �i�̥ͩR���k�s�Ϋi�̰k�] ) 
		printf("Human HP�G%d\n", nowHumanHp);
		printf("Monster HP�G%d\n", monsterHp);
		printf("**Monster Win!**");
	}
	
	return 0;			
}
