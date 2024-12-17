#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern size_t my_strlen(const char *str);  // 어셈블리 함수 선언
extern ssize_t my_write(int fd, const void *buf, size_t count);  // 어셈블리 함수 선언
extern int my_strcmp(const char *s1, const char *s2);
extern char *my_strcpy(char *restrict dst, const char *restrict src);
extern ssize_t my_read(int fildes, void *buf, size_t nbyte);
extern char * my_strdup(const char *s1);

int main() {
    const char *test_str = "Hetest_str2llo, wor\n";
    const char *test_str2 = "qwerqwerqwer, wor\n";
    char *test3 = malloc(sizeof(char) * 500);
    size_t len = my_strlen(test_str);
	my_write(1, (void *)test_str, len);
	printf("strcmp %d\n", strcmp(test_str, test_str2));
	printf("my_strcmp %d\n", my_strcmp(test_str, test_str2));
    strcpy(test3, test_str);
    printf("test_str: %s", test_str);
    printf("test3: %s", test3);
    my_strcpy(test3, test_str2);
    printf("test_str2: %s", test_str2);
    printf("test3: %s", test3);

    // printf("write test\n");
    // errno = 0;
    // write(8888, "Hello, World!\n", 14);
    // printf("errno: %d\n", errno);
    // errno = 0;
    // write(1, "Hello, World!\n", 14);
    // printf("errno: %d\n", errno);
    // printf("my_write test\n");
    // errno = 0;
    // my_write(8888, "Hello, World!\n", 14);
    // printf("errno: %d\n", errno);
    // errno = 0;
    // my_write(1, "Hello, World!\n", 14);
    // printf("errno: %d\n", errno);

// //////////////////////////////
    printf("read test\n");
    errno = 0;
    read(8888, test3, 14);
    printf("errno: %d\n", errno);
    errno = 0;
    read(0, test3, 14);
    printf("errno: %d\n", errno);
    printf("my_read test\n");
    errno = 0;
    my_read(8888, test3, 14);
    printf("errno: %d\n", errno);
    errno = 0;
    my_read(0, test3, 14);
    printf("errno: %d\n", errno);

    // ///////////////////////////////
    // // test my_read
    // printf("%ld\n", my_read(0, test3, 10));
    // my_write(1, test3, 10);
    // read(0, test3, 10);
    // printf("%s", test3);

    //////////////////////////////
    // test my_strdup
    printf("test strdup\n");
    char *test4 = strdup(test_str);
    printf("%s", test4);
    printf("test my_strdup\n");
    char *test5 = my_strdup(test_str);
    printf("%s", test5);

    
    return 0;
}
