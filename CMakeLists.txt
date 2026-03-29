cmake_minimum_required(VERSION 4.0)
project(SDA_ATM)

set(CMAKE_CXX_STANDARD 20)

add_executable(SDA_ATM  main.cpp
        domain/Transaction.h
        domain/Transaction.cpp
                        TAD/Collection.h
                        TAD/Collection.cpp
                        repository/RepoTransactions.h
                        repository/RepoTransactions.cpp
                        service/Service.h
                        service/Service.cpp
                        ui/UI.h
                        ui/UI.cpp)