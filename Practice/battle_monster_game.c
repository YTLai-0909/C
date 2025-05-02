#include <stdio.h>

int main(void) {
	
	/*
		monsterLv : 怪物等級 
		monsterHp : 怪物生命值 
		monsterAtk : 怪物攻擊力 
		humanLv : 勇者等級 
		humanHp : 勇者生命值 
		humanAtk : 勇者攻擊力 
		humanRe : 勇者恢復力  
		round : 回合數 
		nowHumanHp : 勇者目前的生命值 
		option : 勇者的動作選項 
	*/
	
	int monsterLv, monsterHp, monsterAtk;
	int humanLv, humanHp, humanAtk, humanRe;
	int round, nowHumanHp, option;
	
	monsterLv = monsterHp = monsterAtk = humanLv = humanHp = humanAtk = humanRe = round = nowHumanHp = option = 0;
	
	// 輸入怪物等級 ( 1-3 ) 
	printf("Enter the monster level (1 to 3): ");
	scanf("%d", &monsterLv);
	while(monsterLv < 1 || monsterLv > 3) {  // 檢查輸入是否合格  
		printf("ERROR, out of range.\n");
		printf("Enter the monster level (1 to 3): ");
		scanf("%d", &monsterLv);
	}
	// 輸入勇者等級 ( 1-3 ) 
	printf("Enter the human level (1 to 3): ");
	scanf("%d", &humanLv);
	while(humanLv < 1 || humanLv > 3) {  // 檢查輸入是否合格  
		printf("ERROR, out of range.\n");
		printf("Enter the human level (1 to 3): ");
		scanf("%d", &humanLv);
	}
	
	printf("\n");
	
	// 設定怪物數值 
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
	// 設定勇者數值 
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
	
	// 遊戲開始  
	nowHumanHp = humanHp;  // 記錄勇者目前的生命值  
	while(1) {
		// 印出回合數，勇者與怪物的資訊  
		round++;  // 迴圈每執行一次回合數加一 
		printf("Round %d\n", round);
		printf("Human\n");
		printf("    HP：%d ATK：%d RE：%d\n", nowHumanHp, humanAtk, humanRe);
		printf("Monster\n");
		printf("    HP：%d ATK：%d\n", monsterHp, monsterAtk);
		// 輸入選項  
		printf("1.attack 2.recover 3.run away\n");
		printf("Enter the option (1 to 3): ");
		scanf("%d", &option);
		while(option < 1 || option > 3){   // 檢查輸入是否合格  
			printf("ERROR, out of range.\n");
			printf("Enter the option (1 to 3): ");
			scanf("%d", &option);
		}
		// 執行選項 ( 勇者部分 )
		if(option == 1) {  // 選擇攻擊 
			monsterHp -= humanAtk;
			if(monsterHp <= 0) {  // 怪物生命值歸零，怪物輸，遊戲結束，跳出迴圈 
				monsterHp = 0;
				printf("Human attack Monster HP：%d\n\n", monsterHp);
				break;
			} else {  // 怪物未死，遊戲繼續  
				printf("Human attack Monster HP：%d\n", monsterHp);
			}
		} else if(option == 2) {  // 選擇恢復 
			nowHumanHp += humanRe;
			if(nowHumanHp >= humanHp) {  // 勇者生命值超過一開始設定的值，以一開始設定的值表示 
				nowHumanHp = humanHp;
			} 
			printf("Human recover Human HP：%d\n", nowHumanHp);
		} else if(option == 3) {  // 選擇逃跑，遊戲結束，跳出迴圈  
			printf("Human run away\n\n");
			break;
		}
		// 怪物攻擊 
		nowHumanHp -= monsterAtk;
		if(nowHumanHp <= 0) {  // 勇者生命值歸零，勇者輸，遊戲結束，跳出迴圈  
			nowHumanHp = 0;
			printf("Monster attack Human HP：%d\n\n", nowHumanHp);
			break;
		} else {  // 勇者未死，遊戲繼續  
			printf("Monster attack Human HP：%d\n\n", nowHumanHp);
		}
	}
	
	// 印出遊戲結果  
	if(monsterHp <= 0) {  // 勇者勝利 ( 怪物生命值歸零 ) 
		printf("Human HP：%d\n", nowHumanHp);
		printf("Monster HP：%d\n", monsterHp);
		printf("**Human Win!**");
	} else if(nowHumanHp <= 0 || option == 3) {  // 怪物勝利 ( 勇者生命值歸零或勇者逃跑 ) 
		printf("Human HP：%d\n", nowHumanHp);
		printf("Monster HP：%d\n", monsterHp);
		printf("**Monster Win!**");
	}
	
	return 0;			
}
