#include<stdio.h>
int main(){
	int ms,bs,nob,ef,n,mp[10],tif=0,i,p=0;
	printf("enter the total memory available (in Bytes): ");
	scanf("%d",&ms);
	printf("enter the block size (in Bytes): ");
	scanf("%d",&bs);
	nob=ms/bs;
	ef=ms-nob*bs;
	printf("enter the number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter memory requored for process %d (in Bytes): ",i+1);
		scanf("%d",&mp[i]);
	}
	printf("\nNo. of blocks available in memory %d ",nob);
	printf("\n\nPROCESS \tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");
	for(i=0;i<n&&p<nob;i++){
		printf("\n%d\t%d",i+1,mp[i]);
		if(mp[i]>bs)
			printf("\tNO\t---");
		else{
			printf("\tYES\t%d",bs-mp[i]);
			tif=tif+bs-mp[i];
			p++;
		}
	}
	if(i<n)
		printf("\nMemory is Full,Remaining processes cannot be accomodated");
	printf("\n\nTotal Internal Fragmentation is %d",tif);
	printf("\n\nTotal External Fragmentation is %d",ef);
}
