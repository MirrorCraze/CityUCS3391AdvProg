#include<stdio.h>
class path{
public:
    int len;
    string src;
    string sink;
    path()
    {

    }
    path(int len,string src,string sink)
    {
        this->len = len;
        this-> src = src;
        this->sink = sink;
    }
};
class comparator{
public:
    bool operator()(path &a, path&b)
    {
        return a.len > b.len;
    }
};
main()
{

}
