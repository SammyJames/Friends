# Friends

So, have a look at type.hpp where I'm trying to friend a templated method in a namespace. That templated method is explicitly instantiated in type.cpp. 

MSVC will not compile this code with either branch of BROKEN (0 or 1)
Clang and GCC will compile with BROKEN 0