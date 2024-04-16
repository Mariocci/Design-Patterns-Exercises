#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <set>


template <typename Iterator, typename Predicate>
Iterator mymax(
Iterator first, Iterator last, Predicate pred){
    if (first == last)
        return last;

    Iterator max = first;
    ++first;
    for (; first != last; ++first) {
        if (pred(*max, *first))
            max = first;
    }
    return max;
}
int gt_int(const int a, const int b) {
    if (a > b){
        return 0;
    }
    return 1;
}
int gt_char(const char c1, const char c2) {
	if (c1 > c2){
        return 0;
    }
    return 1;
}
int gt_str(const char *s1, const char *s2) {
	int result = strcmp(s1, s2);
    return result < 0 ? 1 : 0;
}


int main(){
    int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
    char arr_char[]="Suncana strana ulice";
    const char* arr_str[] = {
    "Gle", "malu", "vocku", "poslije", "kise",
    "Puna", "je", "kapi", "pa", "ih", "njise"};
    const int* maxint = mymax( &arr_int[0],
    &arr_int[sizeof(arr_int)/sizeof(*arr_int)], gt_int);
    std::cout <<*maxint <<"\n";
    const char* maxchar = mymax( &arr_char[0],
    &arr_char[sizeof(arr_char)/sizeof(*arr_char)], gt_char);
    std::cout <<*maxchar <<"\n";
    const char** maxstr = mymax( &arr_str[0],
    &arr_str[sizeof(arr_str)/sizeof(char*)], gt_str);
    std::cout <<*maxstr <<"\n";

    std::vector<int> vec_int = {1, 3, 5, 7, 4, 6, 9, 2, 0};
    std::vector<char> vec_char(arr_char, arr_char + sizeof(arr_char) / sizeof(char));
    std::vector<const char*> vec_str = {
        "Gle", "malu", "vocku", "poslije", "kise",
        "Puna", "je", "kapi", "pa", "ih", "njise"
    };
    auto maxint_vec = mymax(vec_int.begin(), vec_int.end(), gt_int);
    std::cout << "Max int set: " << *maxint_vec << std::endl;
    auto maxchar_vec = mymax(vec_char.begin(), vec_char.end(), gt_char);
    std::cout << "Max char set: " << *maxchar_vec << std::endl;
    auto maxstr_vec = mymax(vec_str.begin(), vec_str.end(), gt_str);
    std::cout << "Max string set: " << *maxstr_vec << std::endl;    

    std::set<int> set_int = {1, 3, 5, 7, 4, 6, 9, 2, 0};
    std::set<char> set_char(vec_char.begin(), vec_char.end());
    std::set<const char*> set_str = {
        "Gle", "malu", "vocku", "poslije", "kise",
        "Puna", "je", "kapi", "pa", "ih", "njise"
    };
    auto maxint_set = mymax(set_int.begin(), set_int.end(), gt_int);
    std::cout << "Max int vector: " << *maxint_set << std::endl;
    auto maxchar_set = mymax(set_char.begin(), set_char.end(), gt_char);
    std::cout << "Max char vector: " << *maxchar_set << std::endl;
    auto maxstr_set = mymax(set_str.begin(), set_str.end(), gt_str);
    std::cout << "Max string vector: " << *maxstr_set << std::endl;
}