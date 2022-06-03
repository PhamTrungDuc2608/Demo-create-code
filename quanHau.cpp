//* Cho 1 mang 2 chieu nxn va nhap vao cac vi tri tuong ung neu vi tri nao
// có quan hau thi co gia tri 1, vi tri ko coa quan hau thi se co gia tri la 0. Cau hoi: 
// Tim cac cap quan hau de doa nhau
//  Su dung Visual Studio & Eclispse

#include<stdio.h>

	int inputArray(int n,int a[][100]){
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
	}
	int outputArray(int n, int a[][100]){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	int toHop(int n, int k){
		if(k==0 || k==n) return 1;
		return (toHop(n-1,k-1) + toHop(n-1,k));
	}
	int countNumberRows (int n,int a[][100]){		// theo hang
		int sum=0;
		int count;
		for(int i=0;i<n;i++){
			count = 0;
			for(int j=0;j<n;j++){
				if(a[i][j] == 1 ) count++;
			}
			if(count >1) sum=sum + toHop(count,2);
		}
		return sum;
	}
	int countNumberColumns(int n,int a[][100]){			// theo cot
		int sum=0;
		int count;
		for(int i=0;i<n;i++){
			count = 0;
			for(int j=0;j<n;j++){
				if(a[j][i] == 1 ) count++;
			}
			if(count >1) sum=sum + toHop(count,2);
		}
		return sum;
	}
//	int countNumberCross(int n,int a[][100]){		////  duong chéo chính
//		int count=0,sum=0;
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				if(j==i&& a[i][j]==1) count++;
//			}
//		}
//		if(count >1) sum=toHop(count,2);
//		return sum;
//	}
	int crossExtra(int n,int a[][100]){		/// duong nua duong chéo trái phai
		int sum=0,k=0;
		while(k<n){
			int count1=0,count2=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==j-k &&  a[i][j]==1 && i!=j) count2++;
					if(j==i-k && a[i][j]==1) count1++;
				}
			}
			if(count2 >1) sum=sum+toHop(count2,2);
			if(count1 >1) sum=sum+toHop(count1,2);
			//n--;
			k++;
		}
		return sum;
	}
	int crossLeft(int n,int a[][100]){		/// duong nua duong chéo trái phai
		int b[100][100];
		int p=0,q=0;
		for(int i=0;i<n;i++){
			q=0;
			for(int j=n-1;j>=0;j--){
				b[p][q] = a[i][j];
				q++;
			}
			p++;
		}
		crossExtra(n,b);
	}
	int main(){
		int n;
		scanf("%d",&n);
		int a[100][100];
		inputArray(n,a);
		//outputArray(n,a);
	//	printf("%d\n",countNumberRows(n,a));
	//	printf("%d\n",countNumberColumns(n,a));
		// printf("%d",crossExtra(n,a));
		printf("%d",crossLeft(n,a)+crossExtra(n,a)+countNumberColumns(n,a)+countNumberRows(n,a));
	}
	