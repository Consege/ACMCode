

ll base[1000006];
int mod = 1e9+7 ;
// hash based init
void init()
{
    base[0] = 1 ;
    for(int i=1; i<=1000006; i++){
        base[i] = base[i-1] * 26 % mod;
    }
}


// hash function if str is all lowercase letters
ll hsh = 0;

for(int i = 0;i<str.length();i++){
    str[i] -= 'a' ;
    hsh = (hsh + str[i]*base[i])%mod;
}
