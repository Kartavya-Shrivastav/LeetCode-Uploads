#include <bits/stdc++.h>
using namespace std;

// Problem: Four Divisors
// Approach: We use a sieve to precompute prime numbers up to a certain limit. For each number in the input array, we determine if it has exactly four divisors by checking its prime factorization. The two possible cases for a number to have exactly four divisors are:
// 1. It is of the form p^3, where p is a prime number.
// 2. It is of the form p * q, where p and q are distinct prime numbers.

// Steps:
// 1. Implement a sieve function to generate all prime numbers up to 316 (since 316^2 > 10^5).
// 2. For each number in the input array, factor it using the list of primes.
// 3. Count the number of distinct prime factors and their exponents.
// 4. If the number has exactly four divisors, calculate the sum of those divisors and add it to the result.
// 5. Return the total sum of divisors for all numbers with exactly four divisors.

// Time Complexity: O(n * sqrt(m)), where n is the number of elements in the input array and m is the maximum value in the array, due to the factorization step.
// Space Complexity: O(m), for storing the sieve and divisor sums.

const int N=316;
bitset<N+1> isPrime=0;
vector<int> prime;
int Div4[100001];

class Solution {
public:
    static void Sieve(){ 
        if (isPrime[2]) return ; 
        isPrime.set(); 
        memset(Div4, -1, sizeof(Div4)); 
        isPrime[0]=isPrime[1]=0; 
        Div4[0]=Div4[1]=0; 
        int Nsqrt=sqrt(N-1); 
        for(int p=2; p<=Nsqrt; p+=1+(p&1)){ 
            if (isPrime[p]){ 
                Div4[p]=0;// prime has only 2 divisors 
                prime.push_back(p); 
                for(int i=p*p; i<N; i+=p) 
                    isPrime[i]=0; 
            } 
        } 
        for(int i=Nsqrt+((Nsqrt&1)==0); i<N; i+=2){ 
            if (isPrime[i]) 
                prime.push_back(i); 
        } 
    }

    static int sum4Div(int x){
        if (Div4[x]!=-1) return Div4[x];
        int y=x, sum=1+x, cntPF=0, xsqrt=sqrt(x);
        for(int p: prime){
            if (p>xsqrt) break;
            if (y%p) continue;
            int e=0;
            while(y%p==0){
                y/=p;
                e++;
            }
            cntPF++;

            if (e==3 && y==1 && cntPF==1)
                return Div4[x]=1+p+p*p+p*p*p;

            if (e>1||cntPF>2) return Div4[x]=0;
            sum+=p;
        }
        if (y>1){
            cntPF++;
            sum+=y;
        }
        return Div4[x]=(cntPF==2)?sum:0;
    }

    static int sumFourDivisors(vector<int>& nums) {
        Sieve();
        int ans=0;
        for(int x: nums)
            ans+=sum4Div(x);
        return ans;
    }
};