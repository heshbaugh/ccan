/* Licensed under BSD-MIT - see LICENSE file for details */
#ifndef CCAN_LOG_H
#define CCAN_LOG_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>

#define LOG_CRITICAL 0
#define LOG_ERROR    1
#define LOG_WARNING  2
#define LOG_INFO     3
#define LOG_INVALID  4

#define LOG_VERBOSE 0
#define LOG_CONCISE 1

extern FILE *set_log_file(const char *);
extern int get_log_mode(void);
extern void set_log_mode(int);

#define print_log(level, ...) do {				\
				time_t _clk = time(NULL);	\
				_print_log(level, __FILE__, __func__, ctime(&_clk), __LINE__, __VA_ARGS__); \
			     } while (0)

extern void _print_log(int, const char *, const char *, char*, int, const char *, ...);
#endif // CCAN_LOG_H
