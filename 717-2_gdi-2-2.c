#include <stdio.h>

 int main(void)
 {
 	int n, x, xm;
 	scanf("%d",&n);
 	scanf("%d",&xm);
 	for (int i=1; i<n; i++) {
 		scanf("%d",&x);
 		if (x<xm) {
 			xm=x;
 		}	
 	}
 	printf("%d",xm);
 	return 0;
 }

