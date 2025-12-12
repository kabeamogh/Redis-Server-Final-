#include <iostream>
#include <cassert>
#include "../include/redisDatabase.h"

int main (){
    std::cout << "------ Starting Day 1 ------" << std::endl;

    RedisDatabase& db = RedisDatabase::getInstance();

    db.SET("username", "Amogh");

    std::string val;
    

    bool found = db.GET("username", val);

    assert(found = true);
    assert(val == "Amogh");
    std::cout<<"Passed"<<std::endl;

    return 0;

}