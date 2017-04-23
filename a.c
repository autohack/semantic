#include <stdio.h>
#include <string.h>
int sti(char *s)
{
	int r=0;
	int i=0;
	for(i=0;i<strlen(s);i++)
	{
		// printf("%d\n",r );
		r= r*10  + (s[i]-48);
	}
	// r=r*10+(s[i]-49);
	return r;
}

typedef struct 
{
	char *s1;	
	char *s2;	
	char *s3;	
	char *s4;	
	char *a1;	
	char *a2;	
	char *a3;	

}quadraple;

int main()
{
	
	printf("%d\n",sti("1221\0") );
	// quadraple q;
	// q.s1 = "avc";
	// printf("%s\n",q.	s1 );
	return 0;
}