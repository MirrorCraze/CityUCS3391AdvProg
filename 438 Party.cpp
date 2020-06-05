#include<stdio.h>
#include<iostream>
#include<algorithm>
main()
{
    int t;
    int n;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        std::cout << std::max(n-2,0) << std::endl;
    }
}
