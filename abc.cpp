#include<iostream>
#include<functional>
#include<vector>

template<typename T>
auto reduce = [](std::function<T(T,T)> func, std::vector<T> ivec, T init_val)->T{
    T res = init_val;
    for(std::vector<T>::size_type i = 0; i != ivec.size(); ++i)
        res = func(res, ivec[i]);
    return res;
};

int main()
{
    int res = reduce<int>(
        [](int x, int y)->int{return x+y;},
        std::vector<int>{1,2,3,4,5,6,7,8,9,10},
        0
    );
    std::cout<<res<<std::endl;
}