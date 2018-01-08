  //两边都取的写法
  int lft = 0 , rgt = n ;
        while(lft<rgt){
            int mid = (lft+rgt+1)>>1 ;
            if(can(mid)){
                lft = mid ;
            }
            else{
                rgt = mid -1;
            }

        }
