//nlogn �㷨 ����������� ���������ַ��������ǵ�����������г��� �ѵ�һ�������е�Ԫ�ػ��ɸ�Ԫ���ڵڶ�������������λ�ã�����lis
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector <int> vec[1010];
int num[1000010],tmp[1000010];
void Initial(){
    for(int i=0;i<1010;i++){
        vec[i].clear();
    }
}
int main()
{
    char str[1010],cstr[1010];
    while(gets(str)){
        gets(cstr);
        Initial();
        int len=strlen(cstr);
        for(int i=0;i<len;i++){
            vec[cstr[i]].push_back(i);
        }

        int cnt=0;
        len=strlen(str);
        for(int i=0;i<len;i++){
            if(vec[str[i]].size()!=0){
                for(int j=vec[str[i]].size()-1;j>=0;j--){
                    num[cnt++]=vec[str[i]][j];
                }
            }
        }
        int counter=0;
        for(int i=0;i<cnt;i++){
            if(counter==0){
                tmp[0]=num[0];
                counter++;
            }
            else{
                if(tmp[counter-1]<num[i]){
                    tmp[counter]=num[i];
                    counter++;
                }
                else{
                    int s=lower_bound(tmp,tmp+counter,num[i])-tmp;
                    tmp[s]=num[i];
                }

            }
        }
        cout<<counter<<endl;
    }
    return 0;
}