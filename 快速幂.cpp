ll my_pow(ll a , ll x){
    ll res = 1 ;
    ll now = a;
    while(x){
        if(x%2) res = (res * now) %mod ;
        now = (now*now)%mod ;
        x>>=1 ;
    }
    return res ;
}
