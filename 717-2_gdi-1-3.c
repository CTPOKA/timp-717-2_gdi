#include <stdio.h>

 int main(void)
 {
 	int x, y, z=1;
 	scanf("%d%d",&x,&y);
 	for (int i=0; i<y; i++) {
 		z=z*x;
 		}
 	printf("%d",z);
 	return 0;
 }


