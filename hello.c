#include <stdio.h>

void filecopy(FILE *ifp, FILE *ofp);

int main()
{
	FILE *fp,*ofp;
	fp = fopen("E:\\C\\test.txt","r");
	ofp = fopen("E:\\C\\result.txt","w");
	filecopy(fp,ofp);
	fclose(fp);
	fclose(ofp);
	return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
	char c;

	while((c = getc(ifp)) != EOF)
	{
		putc(c,ofp);
	}
}
