#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include <set>
using namespace std;

int features[10000][1000] ;

//P[0][(-1,-1)] represents P(Y=0) , P[0][(1,1)] represents P(X1=1|Y=0) 
map<pair<int,int>, double> P[5] ; 

void naive_bayes_train(pair<int,int> interval[][3],int * label,int K,int m,int cnt){
	int total[10000] ;
	memset(total,0,sizeof total) ;

	for(int i = 0 ;i<5;i++){
		P[i].clear() ;
	}
	for(int i = 0 ;i<m;i++){
		total[label[i]]++;
		if(P[label[i]].find(make_pair(-1,-1)) == P[label[i]].end()){
			P[label[i]][make_pair(-1,-1)] = 0.0;
		}
	
		P[label[i]][make_pair(-1,-1)]+=1.0 ;
	
		for(int j =0 ;j<cnt;j++){
			if(label[i] == 0&&j==cnt-1 && features[i][j] ==3){
				cout<<1<<endl;
			}
			if(P[label[i]].find(make_pair(j,features[i][j])) == P[label[i]].end()){
				P[label[i]][make_pair(j,features[i][j])] = 0.0 ;
			}
			P[label[i]][make_pair(j,features[i][j])] += 1.0 ;
		}
	}
	for(int i =0 ;i<K;i++){
		map<pair<int,int>, double>::iterator iter;
		for(iter = P[i].begin();iter!=P[i].end();iter++){
			if(iter->first.first ==-1){
				iter->second/=m ;
			}
			else{
				iter->second/=total[i];
			}
			//cout<<iter->second<<endl;
		}
	}
	
	
}
int main() {
	
	// Number of training samples
	int n;

	
	while(cin>>n){
		int label[10000] ;
		int cnt ;
		set<int> tmp ;
		
		//input label of training samples
		for(int i = 0 ;i<n;i++){
			scanf("%d",&label[i]) ;
			tmp.insert(label[i]);
		}
		// Number of label types
		int K = tmp.size();
		getchar();
		
		//input features of training samples
		//the last line is a testing sample, first n line is n trainging samples
		for(int i = 0 ;i<n+1;i++){
		
			cnt = 0;
			string str;
			getline(cin,str) ;

			stringstream ss(str);
			int x;
			while(ss>>x){
				features[i][cnt++] = x ;
				//cout<<features[i][cnt-1]<<endl;
			}
			
			
		}
		
//		for(int i = 0 ;i<n+1;i++){
//			for(int j  = 0 ;j<cnt;j++){
//				cout<<features[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		//Feature Discrete, for continuous feature, discrete them to 3 equal width interval
		//The 3rd, 4th, 5th features are continuous
		
		pair<int,int> interval[5][3] ;
		int concnt = 0 ;
		for(int j =0 ;j<cnt ;j++){
			if(j == 2 || j ==3 || j ==4){
				int maxn=-1e9 ,minn = 1e9;
				for(int i = 0;i<n-1;i++){
					if(features[i][j]>maxn){
						maxn = features[i][j] ;
					}
					if(features[i][j]<minn){
						minn = features[i][j] ;
					}
				}
				interval[concnt][0] = make_pair(0,maxn/3+1) ;
				interval[concnt][1] = make_pair(maxn/3+1,2*maxn/3+1) ;
				interval[concnt][2] = make_pair(2*maxn/3+1,maxn) ;
				concnt++ ;
			}
		}
		for(int i = 0;i<n+1;i++){
			concnt = 0 ;
			for(int j =0;j<cnt;j++){
				if(j == 2 || j==3 || j ==4){
					if(features[i][j] >= interval[concnt][0].first && features[i][j] < interval[concnt][0].second){
						features[i][j] = 1;
					}
					else if (features[i][j] >= interval[concnt][1].first && features[i][j] < interval[concnt][1].second){
						features[i][j] = 2 ;
					}
					else{
						features[i][j] = 3;
					}
					concnt++ ;
				}
			}
		}

		//training naive bayes
		naive_bayes_train(interval,label,K,n,cnt) ;
		
		
		//predict the prob of y = 0
		//output the p(y=1|x)/p(y=0|x)
		double ans = P[0][make_pair(-1,-1)] ;
		concnt = 0 ;
		double reans = P[1][make_pair(-1,-1)] ;
		for(int i = 0 ;i<cnt;i++){
			
			ans*= P[0][make_pair(i,features[n][i])];
			reans*= P[1][make_pair(i,features[n][i])] ;
			
		}
		//cout<<ans<<endl;
		//cout<<reans<<endl;
		printf("%.3f\n",reans/ans);
		
	}
}

/**
9
0 0 0 0 1 1 1 1 1
0 0 30 450 7
1 1 5 500 3
1 0 10 150 1
0 1 40 300 6
1 0 20 100 10
0 1 25 180 12
0 0 32 50 11
1 0 23 120 9
0 0 27 200 8
0 0 40 180 8
**/
