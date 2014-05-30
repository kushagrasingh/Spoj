#include<iostream>

using namespace std;

int ftree[10000001]={0};

int cum(int idx){
	int result=0;
	while(idx>0){
		result=result+ftree[idx];
		idx=idx-(idx & -idx);
	}

	return result;
}

void update(int idx,int val){
	while(idx<=10000000){
		ftree[idx]=ftree[idx]+val;
		idx=idx+(idx & -idx);
	}
}

int main()
{
	int t;
	cin>>t;
	for(int w=0;w<t;w++){
		int n;
		cin>>n;
		int ele;
		long long int count=0;
		for(int i=0;i<n;i++){
			cin>>ele;
			update(ele,1);
			count=count+cum(10000000)-cum(ele);
		}
		cout<<count<<"\n";
		for(int i=1;i<=10000000;i++)
			ftree[i]=0;
	}
	return 0;
}

