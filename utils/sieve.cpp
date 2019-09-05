#define N 1000000
#define NOT_PRIME true
#define PRIME false

bool primes[N+1];

void eratosthenes_sieve(){
	int limit = floor(sqrt(N));
	
	primes[0] = NOT_PRIME;
	primes[1] = NOT_PRIME;

	for(int i = 2; i < limit; i++){
		if(primes[i] == PRIME){
			for(int j = i*i; j < N; j+=i)
				primes[j] = NOT_PRIME;
		}
	}
}