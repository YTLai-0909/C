#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);
char* my_strcpy(char *s1, const char *s2);
char* my_strcat(char *s1, const char *s2);
char* my_strstr(const char *s1, const char *s2);

/* 計算字串長度 
	從字串的第一個字元開始計算，直到遇到 '\0'，'\0' 不會被計算  
	s : 要計算的字串 
		const char *s : s 為常數資料，無法修改其內容  
	回傳 : 字串的長度 	
*/  
size_t my_strlen(const char *s) {
	
	const char* current = NULL;  // 目前在 s 的哪個位置  
	
	current = s;

	while(*current != '\0') {  // *current : 一個字元  
		current++;  // 前進到 s 的下一個位置  
	}
	
	return current - s;  // 字串長度 = 字串結尾的位置 - 字串頭的位置  
}

/* 比較兩個字串 
	從字串的第一個字元開始，比較兩者的 ASCII 碼  
		< 0 : s1 < s2 
			遇到第一個不相同的字元時，s1 的 ASCII < s2 的 ASCII  
		= 0 : s1 = s2 
			s1 與 s2 的內容相同 
		> 0 : s1 > s2  
			遇到第一個不相同的字元時，s1 的 ASCII > s2 的 ASCII  
	s1 : 第一個字串 
		const char *s1 : s1 為常數資料，無法修改其內容  
	s2 : 第二個字串 
		const char *s2 : s2 為常數資料，無法修改其內容  
	回傳 : 字串比較的結果  
*/
int my_strcmp(const char *s1, const char *s2) {
	
	// 兩個字串有相同的字元，繼續往後比  
	while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {  // *s1 : 一個字元，*s2 : 一個字元  
		s1++;  // 前進到 s1 的下一個位置  
		s2++;  // 前進到 s2 的下一個位置  
	}
	// 比較字串  
	if(*s1 < *s2) {  // s1 < s2，( s2 比較長，*s1 = '\0' )( s1 的 ASCII < s2 的 ASCII  ) 
		return -1;
	} else if(*s1 == *s2) {  // s1 = s2，( *s1 = *s2 = '\0' ) 
		return 0;
	} else if(*s1 > *s2) {  // s1 > s2，( s1 比較長，*s2 = '\0' )( s1 的 ASCII > s2 的 ASCII ) 
		return 1;
	}
}

/* 複製字串 
	將第二個字串的內容複製給第一個字串，並在最後補上 '\0' 
	s1 : 第一個字串  
	s2 : 第二個字串 
		const char *s2 : s2 為常數資料，無法修改其內容 
	回傳 : 字串複製後的結果  
*/ 
char* my_strcpy(char *s1, const char *s2) {
	
	char* current = NULL;  // 目前在 s1 的哪個位置  
	
	current = s1;
	
	while(*s2 != '\0') {  // *s2 : 一個字元  
		*current = *s2;
		current++;  // 前進到 s1 的下一個位置  
		s2++;  // 前進到 s2 的下一個位置  
	}
	*current = '\0';  // 補上結束字元  
	
	return s1; 
}

/* 連接字串 
	將第二個字串的內容連接到第一個字串的尾端，並在最後補上 '\0' 
	s1 : 第一個字串 
	s2 : 第二個字串 
		const char *s2 : s2 為常數資料，無法修改其內容 
	回傳 : 字串連接後的結果  
*/
char* my_strcat(char *s1, const char *s2) {
	
	char* current = NULL;  // 目前在 s1 的哪個位置  
	
	current = s1;
	
	// 尋找第一個字串的尾端  
	while(*current != '\0') {  // *current : 一個字元  
		current++;  // 前進到 s1 的下一個位置  
	}
	// 連接字串  
	while(*s2 != '\0') {
		*current = *s2;
		current++;  // 前進到 s1 的下一個位置  
		s2++;  // 前進到 s2 的下一個位置  
	}
	*current = '\0';  // 補上結束字元 
	
	return s1;
}

/* 搜尋字串 
	在第一個字串中，尋找第二個字串第一次出現的位置，如果沒找到回傳 NULL 
	s1 : 第一個字串  
		const char *s1 : s1 為常數資料，無法修改其內容 
	s2 : 第二個字串  
		const char *s2 : s2 為常數資料，無法修改其內容 
	回傳 : 搜尋結果  
*/
char* my_strstr(const char *s1, const char *s2) {
	
	const char* current1 = NULL;  // 進行匹配時，s1 目前的位置  
	const char* current2 = NULL;  // 進行匹配時，s2 目前的位置 
	
	if(*s2 == '\0') {  // 當 s2 是空字串時，回傳 s1  
		return (char*)s1;
	}
	
	while(*s1 != '\0') {  // *s1 : 一個字元  
		current1 = s1;
		current2 = s2;
		// 進行字串匹配  
		while(*current1 == *current2 && *current2 != '\0') {
			current1++;  // 前進到 s1 的下一個位置  
			current2++;  // 前進到 s2 的下一個位置  
		}
		if(*current2 == '\0') {  // 匹配成功，在 s1 中找到與 s2 相同的字串  
			return (char*)s1;
		}
		s1++;  // 匹配失敗，前進到 s1 的下一個位置繼續匹配  
	}
	
	return NULL;	
}

int main(void) {
	
    char a1[20] = "I love dog ";
    char b1[20] = "and cat.";
    char c1[20] = "love";
    char d1[20] = {'\0'};
    char e1[20] = "lion";
    char n1[20] = {'\0'};

    char a2[20] = "I love dog ";
    char b2[20] = "and cat.";
    char c2[20] = "love";
    char d2[20] = {'\0'};
    char e2[20] = "lion";
    char n2[20] = {'\0'};
    
	/* strlen : 計算長度  
		1. 空字串 
		2. 字串  
	*/
	printf("1. Strlen of NULL: %u\n", strlen(n1));
	printf("1. My_strlen of NULL: %u\n", my_strlen(n1));
    printf("2. Strlen of a1: %u\n", strlen(a1));
    printf("2. My_Strlen of a1: %u\n", my_strlen(a1));
    printf("\n");
    
    printf("\n\n");

	/* strcmp : 比較字串  
		1. 空字串 < 字串 
		2. str1 < str2  
		3. 空字串 = 空字串 
		4. str1 = str2
		5. 字串 > 空字串 
		6. str1 > str2   
	*/ 
	// str1 < str2 -> -1 
	printf("1. Strcmp of NULL and a1: %d\n", strcmp(n1, a1));
	printf("1. My_Strcmp of NULL and a1: %d\n", my_strcmp(n1, a1));
    printf("2. Strcmp of a1 and b1: %d\n", strcmp(a1, b1));
    printf("2. My_Strcmp of a1 and b1: %d\n", my_strcmp(a1, b1));
    printf("\n");
		
	// str1 = str2 -> 0 
	printf("3. Strcmp of NULL and NULL: %d\n", strcmp(n1, n1));
	printf("3. My_Strcmp of NULL and NULL: %d\n", my_strcmp(n1, n1));
    printf("4. Strcmp of a1 and a2: %d\n", strcmp(a1, a2));
    printf("4. My_Strcmp of a1 and a2: %d\n", my_strcmp(a1, a2));
    printf("\n");

	// str1 > str2 -> 1 
	printf("5. Strcmp of a1 and NULL: %d\n", strcmp(a1, n1));
	printf("5. My_Strcmp of a1 and NULL: %d\n", my_strcmp(a1, n1));	
    printf("6. Strcmp of c1 and a1: %d\n", strcmp(c1, a1));
    printf("6. My_Strcmp of c1 and a1: %d\n", my_strcmp(c1, a1));
    printf("\n");
    
    printf("\n\n");    

	/* strcpy : 複製字串  
		1. 空字串 <- 空字串  
		2. 空字串 <- 字串  
	*/ 
	printf("1. Strcpy of n1 and NULL: %s\n", strcpy(n1, n1));
	printf("1. My_Strcpy of n2 and NULL: %s\n", strcpy(n2, n2));	
    printf("2. Strcpy of d1 and a1: %s\n", strcpy(d1, a1));
    printf("2. My_Strcpy of d2 and a2: %s\n", my_strcpy(d2, a2));
    printf("\n");
    
    printf("\n\n");      

	/* strcat : 連接字串  
		1. 空字串 + 空字串 
		2. 字串 + 空字串 
		3. 空字串 + 字串 
		4. 字串 + 字串  
	*/
	printf("1. Strcat of NULL and NULL: %s\n", strcat(n1, n1));
	printf("1. My_Strcat of NULL and NULL: %s\n", strcat(n2, n2));
	printf("2. Strcat of a1 and NULL: %s\n", strcat(a1, n1));
	printf("2. My_Strcat of a2 and NULL: %s\n", strcat(a2, n2));	
	printf("3. Strcat of NULL and a1: %s\n", strcat(n1, a1));
	printf("3. My_Strcat of NULL and a2: %s\n", strcat(n2, a2));		
    printf("4. Strcat of d1 and b1: %s\n", strcat(d1, b1));
    printf("4. My_Strcat of d2 and b2: %s\n", my_strcat(d2, b2));
    printf("\n");
    
    printf("\n\n");      

	int i;
	for(i = 0; i < 20; i++) {
		n1[i] = '\0';
		n2[i] = '\0';
	}

	/* strstr 搜尋字串  
		1. 空字串 -> 空字串 
		2. 空字串 -> 字串 
		3. 字串 -> 空字串 
		4. 字串 -> 字串 
			4-1. 有找到 
			4-2. 沒找到  
	*/
	printf("1. Strstr of NULL and NULL: %s\n", strstr(n1, n1));
	printf("1. My_Strstr of NULL and NULL: %s\n", my_strstr(n1, n1));
	printf("2. Strstr of NULL and c1: %s\n", strstr(n1, c1));
	printf("2. My_Strstr of NULL and c2: %s\n", my_strstr(n1, c2));
	printf("3. Strstr of d1 and NULL: %s\n", strstr(d1, n1));
	printf("3. My_Strstr of d2 and NULL: %s\n", my_strstr(d2, n1));
    printf("4-1. Strstr of d1 and c1: %s\n", strstr(d1, c1));
    printf("4-1. My_Strstr of d2 and c2: %s\n", my_strstr(d2, c2));
    printf("4-2. Strstr of d1 and e1: %s\n", strstr(d1, e1));
    printf("4-2. My_Strstr of d2 and e2: %s\n", my_strstr(d2, e2));
    printf("\n");

    return 0;
}
