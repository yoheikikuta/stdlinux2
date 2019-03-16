#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <getopt.h>

static void do_cat(FILE *f, int opt_for_word, char *replace_word);


static struct option longopts[] = {
    {"tabs", no_argument, NULL, 't'},
    {"linebreaks", no_argument, NULL, 'n'},
    {0,0,0,0}
};

int main(int argc, char *argv[]) {
    int opt;
    int opt_for_arg = -1;
    int opt_exist = 0;
    char *replace_word;

    while ((opt = getopt_long(argc, argv, "tn?", longopts, NULL)) != -1) {
        opt_exist++;
        switch (opt) {
            case 't':
                opt_for_arg = '\t';
                replace_word = "\\t";
                break;
            case 'n':
                opt_for_arg = '\n';
                replace_word = "$\n";
                break;
            case '?':
                fprintf(stderr, "Usage: %s [-t, -n] [FILE ...]\n", argv[0]);
                exit(1);
        }
    }

    if (argc == (1 + opt_exist)) {
        do_cat(stdin, opt_for_arg, replace_word);
    }
    else {
        for (int i = (1 + opt_exist); i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[i]);
                exit(1);
            }
            do_cat(f, opt_for_arg, replace_word);
            fclose(f);
        }
    }
    exit(0);
}

static void do_cat(FILE *f, int opt_for_arg, char *replace_word) {
    int c;

    while ((c = fgetc(f)) != EOF) {
        if (c == opt_for_arg) {
            if (fputs(replace_word, stdout) == EOF) exit(1);
        } else {
            if (putchar(c) < 0) exit(1);
        }
    }
}