#include <stdio.h>
#include <fcntl.h>
#define SIZE 10000

int main(int argc, char *argv[])
{
	int fp, fp2, n;
	char buf[SIZE];

	if ((fp = open("E:\\C\\test.txt", O_RDONLY, 0)) == -1)
		return 0;
	fp2 = 1;

	printf("%d\n", fp);

	while ((n = read(fp, buf, SIZE)) > 0)
		if (write(fp2, buf, n) != n)
			return 0;
	
	return 0;
}
