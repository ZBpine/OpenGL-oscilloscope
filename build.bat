g++ oscilloscope.cpp source/*.cpp img/uestc.res -o oscilloscope.exe -g -m64 -Wall -static-libgcc -fexec-charset=GBK -I./include/ -L./lib/ -lglfw3dll -lglad -ljsoncpp ./lib/freetype.lib -lwsock32
start oscilloscope.exe