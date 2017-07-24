#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b){
  return a<b;
}
int main(){
  int t,n,a[1001];
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>a[i];
    sort(a,a+n,compare);
    int sum=0;
    for(int i=0;i<n-1;i++){
      a[i+1]=a[i]+a[i+1];
      sum+=a[i+1];
      for(int j=i+1;j<n-1;j++){
	if(a[j]>a[j+1]){
	  int temp=a[j];
	  a[j]=a[j+1];
	  a[j+1]=temp;
	}else
	  break;
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}

