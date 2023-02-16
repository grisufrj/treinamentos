#include <stdio.h>

//qemu-aarch64 -L /usr/aarch64-linux-gnu ./pwn
//gdb-multiarch --ex="set arch aarch64" --ex="set sysroot /usr/aarch64-linux-gnu/" --ex="target remote localhost:1234" --ex="break main" ./pwn
int ez(){

}

int main(){
  char buf[16];
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);

  printf("Qual o seu nome?\n");
  fgets(buf,128,stdin);
}