const ll N = 20000000;
ll prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};
void getPrim()
{
    for (ll i = 2 ; i < N ; i ++)
    {
        if (! isNotPrime[i])
            prime[num_prime ++] = i;
        //关键处1
        for (ll j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
        {
            isNotPrime[i * prime[j]] = 1;
            if ( !(i % prime[j] ) ) //关键处2
                break;
        }
    }
    return 0;
}

