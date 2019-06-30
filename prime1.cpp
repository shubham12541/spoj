#include <iostream>
using namespace std;

int k=0;


int* getPrimeNumbers(int a, int b){
	int i;

	int arr[b-a];
	for(i=a;i<b;i++){
		arr[i] = 0;
	}
	for(i=a;i<b;i++){
		if(b%i !=0 ){
			arr[k++] = i;
		}
	}
	
	return arr;
	
}

int printArr(int a[], int b){
	int i;
	for (i=0;i<k;i++){
		cout << a[i] << endl;
	}
	return 0;
}

int main() {

	// your code here
	int n,i;	
	
	cin >> n;
	int l[n],m[n];

	for(i=0;i<n;i++){
		cin >> l[i] >> m[i];
	}
	
		
	for ( i=0;i< n;i++){
		// int p[m[i]-l[i]];
        int *p;
        malloc(sizeof(int)*(m[i]-l[i]));

		p = getPrimeNumbers(l[i],m[i]);
		printArr(p , k);
		k=0;
	}

	return 0;
}