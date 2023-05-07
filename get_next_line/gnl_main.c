#include "get_next_line.h"

int main()
{
	int fd = open("./test1.txt", O_RDONLY);
	close(fd);
	fd = open("./test1.txt", O_RDONLY);
	printf("1 gnl");
	printf("|%s|", get_next_line(fd));
	printf("\n|2 gnl|");
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	// printf("\n|3 gnl|\n");
	printf("|%s|", get_next_line(fd));
	// printf("\n|4 gnl|\n");
	printf("|%s|", get_next_line(fd));
	// printf("\n|5 gnl|\n");
	printf("|%s|", get_next_line(fd));
	// printf("\n|6 gnl|\n");
	printf("|%s|", get_next_line(fd));
	// printf("\n|7 gnl|\n");
	printf("|%s|", get_next_line(fd));
	// printf("\n|8 gnl|\n");
	printf("|%s|", get_next_line(fd));
	// printf("\n|9 gnl|\n");
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
}
