#include <getopt.h>
#include <stdio.h>

/**
 * @brief Prints the help message for the program.
 */
static void print_help(void) {
  printf(  //
      "Usage: " PROGRAM
      " [OPTION]... [FILE]\n"
      "  -h, --help     display this help and exit\n"
      "  -v, --version  output version information and exit\n");
}

/**
 * @brief Displays help information message to standard error output.
 */
static void print_help_info(void) {
  fprintf(stderr, "Try '" PROGRAM " --help' for more information.\n");
}

/**
 * @brief Processes command-line arguments and options,
 *  and executes the main functionality.
 */
int main(int argc, char *argv[]) {
  while (1) {
    static struct option long_options[] =  //
        {{"help", no_argument, 0, 'h'},
         {"version", no_argument, 0, 'v'},
         {0, 0, 0, 0}};
    int option_index = 0;
    int c = getopt_long(argc, argv, "hv", long_options, &option_index);
    if (c == -1) {
      break;
    }
    switch (c) {
      case 'h':
        print_help();
        return 0;
      case 'v':
        printf(PROGRAM " " VERSION "\n");
        return 0;
      case '?':
        print_help_info();
        return 1;
      default:
        return 1;
    }
  }
  // オプション以外の引数を表示する
  for (int i = optind; i < argc; i++) {
    printf("Non-option argument: %s\n", argv[i]);
  }
  // 引数を使わない場合はこっち
  //   // オプション以外の引数がある場合はエラーメッセージを表示して終了
  //   if (optind < argc) {
  //     fprintf(stderr, "%s: invalid argument -- %s\n", argv[0], argv[optind]);
  //     print_help_info();
  //     return 1;
  //   }

  printf("Hello, World!\n");
  return 0;
}
