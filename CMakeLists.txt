cmake_minimum_required(VERSION 3.23)
project(Algorithm_Study)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithm_Study
        #basic-algo-lecture/0x03/array_test.cpp
        #basic-algo-lecture/0x04/linked_list_test.cpp
        #basic-algo-lecture/0x05/stack_test.cpp
        #"untitled/0X03 배열/10808.cpp"
        #"untitled/0X03 배열/2577.cpp"
        #"untitled/0X03 배열/1475.cpp"
        #"untitled/0X03 배열/3273.cpp"
        #untitled/0X04/1406.cpp untitled/0X04/5397.cpp
        #untitled/0X04/1158.cpp
        #untitled/0X05/1874.cpp
        #untitled/0X05/2493.cpp
        #untitled/0X06/18258.cpp
        #untitled/0X06/2164.cpp
        #basic-algo-lecture/0x07/deque_test.cpp
        #untitled/0X07/1021.cpp
        #untitled/0X07/5430.cpp
        #untitled/0X08/10799.cpp
        #untitled/0X08/2504.cpp
        #untitled/0X08/3986.cpp
        #untitled/0X09/1926.cpp
        #untitled/0X09/hw1.c
        #untitled/0X09/hw2.c
        #"untitled/0X10 BFS/4179.cpp"
        #"untitled/0X10 BFS/1697.cpp"
        #"untitled/0X10 BFS/7562.cpp"
        #"untitled/0X10 BFS/10026.cpp"
        #"untitled/0X10 BFS/7569.cpp"
        #"untitled/0X10 BFS/2667.cpp"
        #"untitled/0X10 BFS/2206.cpp"
        #"untitled/0X10 BFS/2583.cpp"
        #"untitled/0X10 BFS/5014.cpp"
        #"untitled/0X10 BFS/2468.cpp"
        #"untitled/0X10 BFS/6593.cpp"
        #"untitled/0X10 BFS/9466.cpp"
        #"untitled/0X10 BFS/13549.cpp"
        #"untitled/0X10 BFS/1600.cpp"
        #"untitled/0X10 BFS/13913.cpp"
        #"untitled/0X10 BFS/2146.cpp"
        #"untitled/0X11 재귀/1780.cpp"
        #"untitled/0X11 재귀/1629.cpp"
        #"untitled/0X11 재귀/11729.cpp"
        #"untitled/0X11 재귀/1074.cpp"
        #"untitled/0X11 재귀/2630.cpp"
        #"untitled/0X11 재귀/1992.cpp"
        #"untitled/0X11 재귀/2447.cpp"
        #"untitled/0X11 재귀/2448.cpp"
        #"untitled/0X12 백트래킹/15649.cpp"
        #"untitled/0X12 백트래킹/9663.cpp"
        #"untitled/0X12 백트래킹/1182.cpp"
        #"untitled/0X12 백트래킹/15650.cpp"
        #"untitled/0X12 백트래킹/15651.cpp"
        #"untitled/0X12 백트래킹/15652.cpp"
        #"untitled/0X12 백트래킹/15654.cpp"
        #"untitled/0X12 백트래킹/15655.cpp"
        #"untitled/0X12 백트래킹/15656.cpp"
        #"untitled/0X12 백트래킹/15657.cpp"
        #"untitled/0X12 백트래킹/15664.cpp"
        #"untitled/0X12 백트래킹/15665.cpp"
        #"untitled/0X12 백트래킹/15666.cpp"
        #"untitled/0X12 백트래킹/6603.cpp"
        #"untitled/0X12 백트래킹/1759.cpp"
        #"untitled/이퍼 /1213.cpp"
        #"untitled/이퍼 /10799.cpp",
       # "untitled/이퍼 /11000.cpp"
       # "untitled/이퍼 /10971.cpp"
        #"untitled/이퍼 /3190.cpp"
        #"untitled/이퍼 /2580.cpp"
        #"untitled/이퍼 /매출최소화.cpp"
        #"untitled/이퍼 /매출최소화.cpp"
        #"untitled/이퍼 /매출저앋ㅂ.cpp"
        #"untitled/이퍼 /매출 최소화 dp.cpp"
        #"untitled/이퍼 /compression.cpp"
        #"untitled/이퍼 /11000-1.cpp"
       # "untitled/이퍼 /3n타일링.cpp"
      #  "untitled/이퍼 /10971-2.cpp"
        #"untitled/이퍼 /3190-2.cpp"
        #"untitled/이퍼 /2580-2.cpp"
        #"untitled/이퍼 /1213-2.cpp"
        #"untitled/0X13 시뮬레이션/15683.cpp"
        #"untitled/0X14 DP/1463.cpp"
        #"untitled/0X14 DP/9095.cpp"
        #"untitled/0X14 DP/2579.cpp"
        #"untitled/0X14 DP/1149.cpp"
        #"untitled/0X14 DP/11726.cpp"
        #"untitled/0X14 DP/11659.cpp"
        #"untitled/0X14 DP/12852.cpp"
        #"untitled/0X13 시뮬레이션/15683.cpp"
        #"untitled/0X13 시뮬레이션/18808.cpp"
        #"untitled/0X14 DP/1003.cpp"
        #"untitled/0X14 DP/1932.cpp"
        #"untitled/0X14 DP/11727.cpp"
        #"untitled/0X14 DP/2193.cpp"
        #"untitled/0X14 DP/1912.cpp"
        #"untitled/0X14 DP/15486.cpp"
        #"untitled/0X14 DP/10844.cpp"
        #"untitled/0X14 DP/9251.cpp"
        #"untitled/0X14 DP/1699.cpp"
        #"untitled/0X14 DP/9084.cpp"
        #"untitled/0X10 BFS/14442.cpp"
        #"untitled/0X10 BFS/16933.cpp"
        #"untitled/0X15 그리디/11047.cpp"
        #"untitled/0X15 그리디/1931.cpp"
       # "untitled/0X15 그리디/2217.cpp"
        #"untitled/0X15 그리디/1026.cpp"
        #"untitled/0X14 DP/12865.cpp"
        #"untitled/0X15 그리디/2457.cpp"
        #"untitled/0X15 그리디/1541.cpp"
        "untitled/0X15 그리디/11501.cpp"
        #"untitled/이퍼 /2840.cpp"
        #"untitled/이퍼 /31090정답.cpp"
)