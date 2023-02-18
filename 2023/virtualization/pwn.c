#include <stdio.h>
#include <unistd.h>
//Run with ./pwn qemu-aarch64 -g 1234 ./bin/pwn $(echo -e "AAAAAAAAAA")
//Debug with gdb-multiarch --ex="set arch aarch64" --ex="target remote localhost:1234" --ex="break main" ./pwn

int (*sc)();

int main(int argc,char**argv){
  printf("Executing your shellcode\n");
  int (*ret)() = (int(*)())argv[1];
  ret();
}