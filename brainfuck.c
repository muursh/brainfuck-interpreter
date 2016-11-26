/*
 * A basic brainfuck interpreter
 * Author: Ben Marsh
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void brainfuck(char* input_str, int cnt)
{
	char* instrucs = calloc(cnt, 1);
	char* p = &*instrucs;

	while (*input_str != '\0') {
		switch (*input_str) {
		case '>': ++p;
			break;
		case '<': --p;
			break;
		case '+': ++*p;
			break;
		case '-': --*p;
			break;
		case '.': printf("%c", *p);
			break;
		case ',': *p = getchar();
			break;
		case '[':
			if (!*p) {
				int loop_cnt = 1;
				while (loop_cnt) {
					++input_str;
					if (*input_str == ']')
						--loop_cnt;
					else if (*input_str == '[')
						++loop_cnt;
				}
			}
			break;
		case ']':
			if (*p) {
				int loop_cnt = 1;
				while (loop_cnt) {
					--input_str;
					if (*input_str == '[')
						--loop_cnt;
					else if (*input_str == ']')
						++loop_cnt;
				}
			}
			break;
		default:
			printf("Invalid character: %c\n", *input_str);
			break;
		}
		input_str++;
	}
	free(instrucs);
}

int main(void)
{
	/*TODO: allow input from a file*/
	char *input_str;
	printf("Enter your brainfuck code. Enter exit to end the program.\n");	
	scanf("%m[^\n]%*c", &input_str);
	if (*input_str == 'e' || *input_str == 'E')
		exit(0);
	brainfuck(input_str, strlen(input_str));
	free(input_str);
	return 0;
}

