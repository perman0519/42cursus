#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern size_t my_strlen(const char *str);  // 어셈블리 함수 선언
extern ssize_t my_write(int fildes, const void *buf, size_t nbyte);  // 어셈블리 함수 선언
extern int my_strcmp(const char *s1, const char *s2);
extern char *my_strcpy(char *restrict dst, const char *restrict src);
extern ssize_t my_read(int fildes, void *buf, size_t nbyte);
extern char * my_strdup(const char *s1);

void my_strlen_test() {
    printf("=================my_strlen_test=================\n");
    const char *str = "Hello, World!";
    size_t a = strlen(str);
    size_t b = my_strlen(str);
    printf("a: %ld, b: %ld\n", a, b);
    a == b ? printf("Same\n") : printf("Different\n");
    const char *str2 = "Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!";
    a = strlen(str2);
    b = my_strlen(str2);
    printf("a: %ld, b: %ld\n", a, b);
    a == b ? printf("Same\n") : printf("Different\n");
}

void my_strcmp_test() {
    printf("=================my_strcmp_test=================\n");
    char *s1 = "Hello, World!";
    char *s2 = "Hello, World!";
    int a = strcmp(s1, s2);
    int b = my_strcmp(s1, s2);
    printf("a: %d, b: %d\n", a, b);
    a == b ? printf("Same\n") : printf("Different\n");
    
    s1 = "Hello, World!";
    s2 = "Hello, World!Hello, World!";
    a = strcmp(s1, s2);
    b = my_strcmp(s1, s2);
    printf("a: %d, b: %d\n", a, b);
    a == b ? printf("Same\n") : printf("Different\n");

    s1 = "Hello, World!Hello, World!";
    s2 = "Hello, World!";
    a = strcmp(s1, s2);
    b = my_strcmp(s1, s2);
    printf("a: %d, b: %d\n", a, b);
    a == b ? printf("Same\n") : printf("Different\n");
    
    s1 = "Hello, Wqrld!";
    s2 = "Hello, World!Hello, World!";
    a = strcmp(s1, s2);
    b = my_strcmp(s1, s2);
    printf("a: %d, b: %d\n", a, b);
    a == b ? printf("Same\n") : printf("Different\n");
}

void my_strcpy_test() {
    printf("=================my_strcpy_test=================\n");
    char *src = "Hello, World!";
    char *dst = (char *)malloc(sizeof(char) * 14);
    char *dst2 = (char *)malloc(sizeof(char) * 14);
    char *a = strcpy(dst, src);
    printf("a: %s, dst: %s\n", a, dst);
    printf("a: %p, dst: %p\n", a, dst);
    a == dst ? printf("Same\n") : printf("Different\n");

    char *b = my_strcpy(dst2, src);
    printf("b: %s, dst: %s\n", b, dst2);
    printf("b: %p, dst: %p\n", b, dst2);
    b == dst2 ? printf("Same\n") : printf("Different\n");
}

void my_write_test() {
    printf("=================my_write_test=================\n");
    size_t a = write(1, "Hello, World!\n", 14);
    size_t b = my_write(1, "Hello, World!\n", 14);
    printf("a: %ld, b: %ld\n", a, b);
    a == b ? printf("Same\n") : printf("Different\n");
    a = write(999, "Hello, World!\n", 14);
    printf("a: %ld, errno: %d, error: %s\n", a, errno, strerror(errno));
    // printf("a: %ld\n", a);
    b = my_write(999, "Hello, World!\n", 14);
    printf("b: %ld, errno: %d, error: %s\n", b, errno, strerror(errno));
    a == b ? printf("Same\n") : printf("Different\n");
}

void my_read_test() {
    printf("=================my_read_test=================\n");
    char *buf = malloc(100);
    printf("stdin: %d\n", STDIN_FILENO);
    ssize_t a = read(0, buf, 100);
    printf("a: %ld, buf: %s\n", a, buf);
    ssize_t b = my_read(0, buf, 100);
    printf("b: %ld, buf: %s\n", b, buf);
    a == b ? printf("Same\n") : printf("Different\n");

    printf("\nread error Test\n");
    a = read(999, buf, 100);
    printf("a: %ld, buf: %s errono: %d error: %s\n", a, buf, errno, strerror(errno));
    b = my_read(999, buf, 100);
    printf("b: %ld, buf: %s errono: %d error: %s\n", b, buf, errno, strerror(errno));
    a == b ? printf("Same\n") : printf("Different\n");
}

void my_strdup_test() {
    printf("=================my_strdup_test=================\n");
    char *s1 = "Hello, World!";
    char *a = strdup(s1);
    printf("a: %s\n", a);
    char *b = my_strdup(s1);
    printf("b: %s\n", b);
}

int main() {
    // my_strlen_test();
    // my_strcmp_test();
    // my_strcpy_test();
    // my_write_test();
    // my_read_test();
    my_strdup_test();
    return 0;
}
