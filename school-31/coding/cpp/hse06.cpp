#include <stdio.h>
#define n 5
int main() {
	int x[n+1],s,i,j,k,t,flag,ppp=0;
	long y;

	for(i=1,y=0; i<= n; i++) {
		x[i]=i;
		y=y*10+x[i];
	}
	printf("%d\n",y);
	j=1;
	ppp=1;
	while (j!=n) {
		k=n-1;
		while (x[k] > x[k + 1]) {
			k--;
		}
		t=k+1;
		do {
			if (t<n) {
				flag = x[t+1]>x[k];
				if (flag)
					t++;
			} else
				flag=0;
		}
		while( flag);
		s=x[k];
		x[k]=x[t];
		x[t]=s;
		for (i=1 ;i<=((n-k)/2); i++) {
			s=x[i+k];
			x[i+k]=x[n-i+1];
			x[n-i+1]=s;
		}
		if (x[j]==n-j+1)
			j++;
		for (i=1,y=0; i<= n; i++)
			y=y*10+x[i];
		printf("%d\n",y);
		++ppp;
	}
	printf("%d\n",ppp);
	return 0;
}