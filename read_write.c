#include <stdio.h>
#define SIZE 10

int mygetch(void);

int main(int argc, char const *argv[])
{
	char ch;

	ch = mygetch();
	if(ch != EOF)
		printf("%c\n", ch);
	return 0;
}

int mygetch(void)
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

/*
int main(int argc, char const *argv[])
{
	char buf[SIZE];
	int n;

	while((n = read(0, buf, SIZE)) > 0)
		write(1, buf, SIZE);
	return 0;
}
*/