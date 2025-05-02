#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);
char* my_strcpy(char *s1, const char *s2);
char* my_strcat(char *s1, const char *s2);
char* my_strstr(const char *s1, const char *s2);

/* �p��r����� 
	�q�r�ꪺ�Ĥ@�Ӧr���}�l�p��A����J�� '\0'�A'\0' ���|�Q�p��  
	s : �n�p�⪺�r�� 
		const char *s : s ���`�Ƹ�ơA�L�k�ק�䤺�e  
	�^�� : �r�ꪺ���� 	
*/  
size_t my_strlen(const char *s) {
	
	const char* current = NULL;  // �ثe�b s �����Ӧ�m  
	
	current = s;

	while(*current != '\0') {  // *current : �@�Ӧr��  
		current++;  // �e�i�� s ���U�@�Ӧ�m  
	}
	
	return current - s;  // �r����� = �r�굲������m - �r���Y����m  
}

/* �����Ӧr�� 
	�q�r�ꪺ�Ĥ@�Ӧr���}�l�A�����̪� ASCII �X  
		< 0 : s1 < s2 
			�J��Ĥ@�Ӥ��ۦP���r���ɡAs1 �� ASCII < s2 �� ASCII  
		= 0 : s1 = s2 
			s1 �P s2 �����e�ۦP 
		> 0 : s1 > s2  
			�J��Ĥ@�Ӥ��ۦP���r���ɡAs1 �� ASCII > s2 �� ASCII  
	s1 : �Ĥ@�Ӧr�� 
		const char *s1 : s1 ���`�Ƹ�ơA�L�k�ק�䤺�e  
	s2 : �ĤG�Ӧr�� 
		const char *s2 : s2 ���`�Ƹ�ơA�L�k�ק�䤺�e  
	�^�� : �r���������G  
*/
int my_strcmp(const char *s1, const char *s2) {
	
	// ��Ӧr�꦳�ۦP���r���A�~�򩹫��  
	while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {  // *s1 : �@�Ӧr���A*s2 : �@�Ӧr��  
		s1++;  // �e�i�� s1 ���U�@�Ӧ�m  
		s2++;  // �e�i�� s2 ���U�@�Ӧ�m  
	}
	// ����r��  
	if(*s1 < *s2) {  // s1 < s2�A( s2 ������A*s1 = '\0' )( s1 �� ASCII < s2 �� ASCII  ) 
		return -1;
	} else if(*s1 == *s2) {  // s1 = s2�A( *s1 = *s2 = '\0' ) 
		return 0;
	} else if(*s1 > *s2) {  // s1 > s2�A( s1 ������A*s2 = '\0' )( s1 �� ASCII > s2 �� ASCII ) 
		return 1;
	}
}

/* �ƻs�r�� 
	�N�ĤG�Ӧr�ꪺ���e�ƻs���Ĥ@�Ӧr��A�æb�̫�ɤW '\0' 
	s1 : �Ĥ@�Ӧr��  
	s2 : �ĤG�Ӧr�� 
		const char *s2 : s2 ���`�Ƹ�ơA�L�k�ק�䤺�e 
	�^�� : �r��ƻs�᪺���G  
*/ 
char* my_strcpy(char *s1, const char *s2) {
	
	char* current = NULL;  // �ثe�b s1 �����Ӧ�m  
	
	current = s1;
	
	while(*s2 != '\0') {  // *s2 : �@�Ӧr��  
		*current = *s2;
		current++;  // �e�i�� s1 ���U�@�Ӧ�m  
		s2++;  // �e�i�� s2 ���U�@�Ӧ�m  
	}
	*current = '\0';  // �ɤW�����r��  
	
	return s1; 
}

/* �s���r�� 
	�N�ĤG�Ӧr�ꪺ���e�s����Ĥ@�Ӧr�ꪺ���ݡA�æb�̫�ɤW '\0' 
	s1 : �Ĥ@�Ӧr�� 
	s2 : �ĤG�Ӧr�� 
		const char *s2 : s2 ���`�Ƹ�ơA�L�k�ק�䤺�e 
	�^�� : �r��s���᪺���G  
*/
char* my_strcat(char *s1, const char *s2) {
	
	char* current = NULL;  // �ثe�b s1 �����Ӧ�m  
	
	current = s1;
	
	// �M��Ĥ@�Ӧr�ꪺ����  
	while(*current != '\0') {  // *current : �@�Ӧr��  
		current++;  // �e�i�� s1 ���U�@�Ӧ�m  
	}
	// �s���r��  
	while(*s2 != '\0') {
		*current = *s2;
		current++;  // �e�i�� s1 ���U�@�Ӧ�m  
		s2++;  // �e�i�� s2 ���U�@�Ӧ�m  
	}
	*current = '\0';  // �ɤW�����r�� 
	
	return s1;
}

/* �j�M�r�� 
	�b�Ĥ@�Ӧr�ꤤ�A�M��ĤG�Ӧr��Ĥ@���X�{����m�A�p�G�S���^�� NULL 
	s1 : �Ĥ@�Ӧr��  
		const char *s1 : s1 ���`�Ƹ�ơA�L�k�ק�䤺�e 
	s2 : �ĤG�Ӧr��  
		const char *s2 : s2 ���`�Ƹ�ơA�L�k�ק�䤺�e 
	�^�� : �j�M���G  
*/
char* my_strstr(const char *s1, const char *s2) {
	
	const char* current1 = NULL;  // �i��ǰt�ɡAs1 �ثe����m  
	const char* current2 = NULL;  // �i��ǰt�ɡAs2 �ثe����m 
	
	if(*s2 == '\0') {  // �� s2 �O�Ŧr��ɡA�^�� s1  
		return (char*)s1;
	}
	
	while(*s1 != '\0') {  // *s1 : �@�Ӧr��  
		current1 = s1;
		current2 = s2;
		// �i��r��ǰt  
		while(*current1 == *current2 && *current2 != '\0') {
			current1++;  // �e�i�� s1 ���U�@�Ӧ�m  
			current2++;  // �e�i�� s2 ���U�@�Ӧ�m  
		}
		if(*current2 == '\0') {  // �ǰt���\�A�b s1 �����P s2 �ۦP���r��  
			return (char*)s1;
		}
		s1++;  // �ǰt���ѡA�e�i�� s1 ���U�@�Ӧ�m�~��ǰt  
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
    
	/* strlen : �p�����  
		1. �Ŧr�� 
		2. �r��  
	*/
	printf("1. Strlen of NULL: %u\n", strlen(n1));
	printf("1. My_strlen of NULL: %u\n", my_strlen(n1));
    printf("2. Strlen of a1: %u\n", strlen(a1));
    printf("2. My_Strlen of a1: %u\n", my_strlen(a1));
    printf("\n");
    
    printf("\n\n");

	/* strcmp : ����r��  
		1. �Ŧr�� < �r�� 
		2. str1 < str2  
		3. �Ŧr�� = �Ŧr�� 
		4. str1 = str2
		5. �r�� > �Ŧr�� 
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

	/* strcpy : �ƻs�r��  
		1. �Ŧr�� <- �Ŧr��  
		2. �Ŧr�� <- �r��  
	*/ 
	printf("1. Strcpy of n1 and NULL: %s\n", strcpy(n1, n1));
	printf("1. My_Strcpy of n2 and NULL: %s\n", strcpy(n2, n2));	
    printf("2. Strcpy of d1 and a1: %s\n", strcpy(d1, a1));
    printf("2. My_Strcpy of d2 and a2: %s\n", my_strcpy(d2, a2));
    printf("\n");
    
    printf("\n\n");      

	/* strcat : �s���r��  
		1. �Ŧr�� + �Ŧr�� 
		2. �r�� + �Ŧr�� 
		3. �Ŧr�� + �r�� 
		4. �r�� + �r��  
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

	/* strstr �j�M�r��  
		1. �Ŧr�� -> �Ŧr�� 
		2. �Ŧr�� -> �r�� 
		3. �r�� -> �Ŧr�� 
		4. �r�� -> �r�� 
			4-1. ����� 
			4-2. �S���  
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
