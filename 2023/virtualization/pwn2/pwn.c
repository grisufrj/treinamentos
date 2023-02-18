#include <stdio.h>
#include <unistd.h>
//Run with  cat payload - | qemu-aarch64 -g 1234 ./bin/pwn
//Debug with gdb-multiarch --ex="set arch aarch64" --ex="target remote localhost:1234" --ex="break main" ./pwn
//Remove the option -g 1234 for disable debugging 
int main(){
  char buf[64];
  printf("Executing your shellcode\n");
  fgets(buf,64,stdin);
  int (*ret)() = (int(*)())buf;
  ret();
  
}