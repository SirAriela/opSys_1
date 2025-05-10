#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // argv shoould recive 3 parametres ./PB "full name" "phone number"
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Name> <Phone>\n", argv[0]);
        exit(1);
    }

    // open the file for append
    FILE *file = fopen("phonebook.txt", "a");
    if (!file) {
        perror("fopen");  // error if file can't open
        exit(1);
    }

    // add line to phonebook
    fprintf(file, "%s,%s\n", argv[1], argv[2]);

    // close file
    fclose(file);

    return 0;
}
