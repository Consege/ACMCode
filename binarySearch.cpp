  //总结:如何避免死循环: 如果left = mid+1 那么while(left<right) mid = (left+right)/2  
  //否则:如果left= mid 那么while(left+1<right) mid = (left+right+1)/2
  //以后再也不难写2分了
  
  //查找最后一个满足条件的元素
  int lft = 0 , rgt = n ;
        while(lft!=rgt){
            int mid = (lft+rgt+1)>>1 ; 
            if(can(mid)){
                lft = mid ;
            }
            else{
                rgt = mid -1;
            }

        }

//查找第一个满足条件的元素

int lft=0,rgt=n+1,mid;
while(lft<rgt){
    mid=lft+rgt>>1;
    if(can(mid)) rgt=mid;
    else lft=mid+1;
}
return lft;
