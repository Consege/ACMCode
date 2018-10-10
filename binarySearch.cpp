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
