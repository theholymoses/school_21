#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <getopt.h>

/* ------------------------------------------------------------ */
#define PROGNAME "cat"

#ifdef BUFFLEN
# undef BUFFLEN
# define BUFFLEN 4096
#endif

unsigned char buff[BUFFLEN];

int arg_index = 0;

#define OPTSTR "bnsvetET"

const struct option lopts[] = {
  {"number-nonblank", 0, 0, 'b'},
  {"number",          0, 0, 'n'},
  {"squeeze_blank",   0, 0, 's'},
  {0,                 0, 0,  0 }
};

struct {
  unsigned int number_nonblank  : 1; /* -b  --number-nonblank */
  unsigned int number_all       : 1; /* -n  --number          */
  unsigned int squeeze_blank    : 1; /* -s  --squeeze-blank   */
  unsigned int display_nonprint : 1; /* -v                    */
  unsigned int display_eol      : 1; /* -eE                   */
  unsigned int display_tab      : 1; /* -tT                   */
} flags;

/* ------------------------------------------------------------ */
int
main (int argc, char *argv[])
{
  int opt;
  int fd;

  while ((opt = getopt_long (argc, argv, OPTSTR, lopts, &arg_index)) != -1)
  {
    switch (opt)
    {
      case 'b':
        flags.number_nonblank = 1;
        break;

      case 'n':
        flags.number_all = 1;
        break;

      case 's':
        flags.squeeze_blank = 1;
        break;

      case 'v':
        flags.display_nonprint = 1;
        break;

      case 'e':
        flags.display_eol = 1;
        flags.display_nonprint = 1;
        break;

      case 't':
        flags.display_tab = 1;
        flags.display_nonprint = 1;
        break;

      case 'E':
        flags.display_eol = 1;
        break;

      case 'T':
        flags.display_tab = 1;
        break;

      default:
        exit (EXIT_FAILURE);
    }
  }

  return (EXIT_SUCCESS);
}

