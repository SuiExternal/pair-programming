#include "server.hpp"
#include <cstdio>
#include <iostream>
#include <thread>

int main() {
    Server server;

    // Challenge 1: Make it possible for these to run concurrently
    server.put("key1", "value1");
    server.put("key2", "value2");

    printf("key1 %s \n", server.get("key1").value_or("Not Found").c_str());
    printf("key2 %s \n", server.get("key2").value_or("Not Found").c_str());

    // Challenge 2: make this atomic!
    server.multi_put({{"key3", "value3"}, {"key4", "value4"}});
    
    printf("key3 %s \n", server.get("key3").value_or("Not Found").c_str());
    printf("key4 %s \n", server.get("key4").value_or("Not Found").c_str());

    return 0;
}
