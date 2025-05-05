typedef struct item Item;
void readFile(Item **item, int *num);
void createMemory(Item **item, int num, int len);
void printItem(Item *item, int num, char printWay);
void addItem(Item **item, int *num);
void deleteItem(Item **item, int *num, int choiceNum);
void reviseState(Item **item, int choiceNum, char inputState);
void saveFile(Item *item, int num);
void Exit(Item **item, int num);
