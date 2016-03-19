#define _CRT_SECURE_NO_WARNINGS
#define TEST
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> 
#include<conio.h>
#define SIZE 10000

typedef struct Node {
	char *name;
	char *value; //单链表中的数据域
	int flag;
	struct Node *next;                       //单链表的指针域
}Node;                            //定义Linklist


char* Substr(char* str, int begin, int end) {
	char* s = (char*)malloc(end - begin + 1);
	strncpy(s, str + begin, end - begin);
	s[end - begin] = '\0';
	return s;
}







int main() {

#ifdef TEST
	freopen("D:\\seed\\less\\test.less", "r", stdin);
	freopen("D:\\seed\\css\\out.css", "a", stdout);
#endif

	//build buff
	char* buff = (char*)malloc(SIZE);
	char* string;
	Node *L,*p,*q,*r;
    L = new(Node);
	L->next = NULL;
	p = L;
	int i,j;


	//safe the global variable
	while ((fgets(buff, SIZE, stdin)) != NULL) {
		if (buff[0] == '@') {
			for (i = 1; i < strlen(buff); i++) {
				if (buff[i] == ':')
					break;
			}
			string = (char*)malloc(i);
			strncpy(string, buff + 1, i - 1);
			string[i - 1] = '\0';
			q = L->next;
			r = L;
			while (q != NULL) {
				if (strstr(q->name, string)) {
					r->next = q->next;
					free(q);
					if (r->next == NULL)
						p = r;
					break;
				}
				r = q;
				q = q->next;
			}
			free(string);
			p->next = new(Node);
			p = p->next;
			p->name = (char*)malloc(i);
			p->name = Substr(buff, 1, i);

			if (buff[i + 1] == '@') {
				p->flag = 1;
				i++;
			}
			else
				p->flag = 0;

			j = i + 1;
			for (;; j++) {
				if (buff[j] == ';')
					break;
			}

			p->value = (char*)malloc(strlen(buff) - i - 1);
			p->value = Substr(buff, i + 1, j);
			p->next = NULL;
			r = L->next;
			while (r) {
				printf("@%s:%s;\n", r->name, r->value);
				r = r->next;
			}
			printf("\n");
		}
	}

		// free buff
		free(buff);

		return 0;
	}