#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

 template<int index, typename... Ts>
 struct repeate_tuple_vector {
     void operator() (int repeat,tuple<Ts...>& t,tuple<vector<Ts>...> &result) {
         repeate_tuple_vector<index - 1, Ts...>{}(repeat,t,result);
         for(int i=0;i<repeat;i++)
            get<index-1>(result).push_back(get<index-1>(t));
     }
 };

 template<typename... Ts>
 struct repeate_tuple_vector<0, Ts...> {
     void operator() (int repeat,tuple<Ts...>& t,tuple<vector<Ts>...> &result) {
        for(int i=0;i<repeat;i++)
            get<0>(result).push_back(get<0>(t));
     }
 };

 template<typename... Ts>
 tuple<vector<Ts>...> repeate_tuple(size_t repeat,tuple<Ts...>& t) {
     const auto size = tuple_size<tuple<Ts...>>::value;
     tuple<vector<Ts>...> result;
     repeate_tuple_vector<size, Ts...>{}(repeat,t,result);
    return result;
 }

template<size_t index,typename T>
auto get_vector(T t){
}

 int main() {
    size_t repeat=10;
     auto t = make_tuple(1, 2.0,'a',"Hello",string("World"),4.5);
     auto x = repeate_tuple(repeat,t);
     for(int i=0;i<repeat;i++){
        cout << get<0>(x)[i] << " ";
        cout << get<1>(x)[i] << " ";
        cout << get<2>(x)[i] << " ";
        cout << get<3>(x)[i] << " ";
        cout << get<4>(x)[i] << " ";
        cout << get<5>(x)[i] << " ";
        cout << endl;
     }
     return 0;
 }