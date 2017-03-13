//this program manually generates random numbers

#include <iostream>
#include <cmath>

using namespace std;

void GenRandNums(const int z, int m, int n, int rand_nums[]);
void printAry(int z, int rand_nums[], bool print);

int main()
{
    const int z = 25; //how many nums to generate and store in ary
    int m = 1; //range of the desired numbers. from
    int n = 100; //to
    int rand_nums[z]; //holds random nums
    bool print = true; //set to true if you want to print nums, otherwise false

    GenRandNums(z, m, n, rand_nums);
    printAry(z, rand_nums, print);

    return 0;
}

void GenRandNums(const int z, int m, int n, int rand_nums[])
{
    long long d = pow(2,32);
    long long y = 568731;
    long long x = 0;
    for (int i=1;i<=z;i++)
    {
        y = (15625*y+22221)%d;
        x = m+floor(((n-m+1)*y)/d);
        rand_nums[i-1] = x;
    }
}

void printAry(int z, int rand_nums[], bool print)
{
    if (print)
    {
        for (int i=0;i<z;i++)
            cout << i+1 << ": " << rand_nums[i] << endl;
    }
}

/*
The Algorithm:
method to generate uniformly distributed random ints in the interval m to n,
where m and n are ints with m < n

1) let d=2^32
2) choose any int y such that 999,999 > y > 100,000
3) let i = 1
4) let y = mod(15625y + 22221,d)
5) let x1 = m+ floor(((n-m+1)Y)/d)
6) let i = i+1
7) go to step 4

possible recommended choice is y=568731

to generate random numbers (not just integers) in an interval
a to b with a<b use the algorithm above, replacing the formula
in step 5 by: let x1 = a+(y(b-1))/(d-1)
*/
