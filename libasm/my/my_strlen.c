#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern size_t my_strlen(const char *str);  // 어셈블리 함수 선언
extern ssize_t my_write(int fd, const void *buf, size_t count);  // 어셈블리 함수 선언
extern int my_strcmp(const char *s1, const char *s2);
extern char *my_strcpy(char *restrict dst, const char *restrict src);

int main() {
    const char *test_str = "Hetest_str2llo, wor\n";
    const char *test_str2 = "qwerqwerqwer, wor\n";
    char *test3 = malloc(sizeof(char) * 500);
    size_t len = my_strlen(test_str);
	my_write(1, (void *)test_str, len);
	// printf("strcmp %d\n", strcmp(test_str, test_str2));
	// printf("my_strcmp %d\n", my_strcmp(test_str, test_str2));
    strcpy(test3, test_str);
    printf("%s", test3);
    my_strcpy(test3, test_str2);
    printf("%s", test_str2);
    printf("%s", test3);
    return 0;
}
