#ifndef __TTY_H__
#define __TTY_H__

/* bold/not bold */
#define TXT_BOLD_ON  "\x1b[1m"
#define TXT_BOLD_OFF "\x1b[21m"

/* Text colors */
#define TXT_NORMAL	"\x1B[0m"
#define TXT_RED  	"\x1B[31m"
#define TXT_GREEN	"\x1B[32m"
#define TXT_YELLOW	"\x1B[33m"
#define TXT_BLUE	"\x1B[34m"
#define TXT_MAGENTA	"\x1B[35m"
#define TXT_CYAN	"\x1B[36m"
#define TXT_WHITE	"\x1B[37m"

/* white background */
#define WHITE_BG_ON	"\x1b[47;30m"

/* Card Suite symbols */
#define CHR_HEART 	"\xE2\x99\xA5"
#define CHR_SPADE 	"\xE2\x99\xA0"
#define CHR_DIAMOND "\xE2\x99\xA6"
#define CHR_CLUB 	"\xE2\x99\xA3"

#endif /* __TTY_H__ */
