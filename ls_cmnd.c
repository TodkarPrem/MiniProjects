#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <string.h>

char HIDDEN_FLAG = 0;

int main(int argc, char *argv[])
{
	DIR *DirPtr = 0;
	struct dirent *ReadPtr = 0;
	struct stat stat_var;

	int i = 1, j, k = 0;
	char options[10] = {}, temp1[50], temp2[100];

	while (i < argc) {
		if (argv[i][0] == '.') {
			strcpy(temp1, argv[i]);
			DirPtr = opendir(temp1);

			if (DirPtr == NULL) {
				printf("my_ls: cannot access %s: No such file "
					"or directory\n", argv[i]);
				return 0;
			}
		} else if (argv[i][0] == '-') {
			j = 1;
			while (argv[i][j])
				options[k++] = argv[i][j++];
		} else {
			printf("my_ls: cannot access %s: No such file "
					"or directory\n", argv[i]);
			return 0;
		}
		i++;
	}

	if (DirPtr == NULL)
		DirPtr = opendir(strcpy(temp1, "."));

	while (ReadPtr = readdir(DirPtr)) {
		strcpy(temp2, temp1);
		strcat(temp2, "/");
		lstat(strcat(temp2, ReadPtr->d_name), &stat_var);

		if (ReadPtr->d_name[0] != '.') {
here:			if (strstr(options, "i"))
				printf("%lu ", stat_var.st_ino);
			if (strstr(options, "s")) {
				k = stat_var.st_size / 1024;

				if (stat_var.st_size % 1024)
					k += 4;
				printf("%2d ", k - k % 4);
			}
			if (strstr(options, "l")) {
				switch (stat_var.st_mode & S_IFMT) {
				case S_IFBLK:
					printf("b");
					break;
				case S_IFCHR:
					printf("c");
					break;
				case S_IFDIR:
					printf("d");
					break;
				case S_IFIFO:
					printf("p");
					break;
				case S_IFLNK:
					printf("l");
					break;
				case S_IFREG:
					printf("-");
					break;
				case S_IFSOCK:
					printf("s");
					break;
				}

				i = 3;
				j = 0;
				while (i--) {
					if (stat_var.st_mode & 256 >> j++)
						putchar('r');
					else
						putchar('-');
					if (stat_var.st_mode & 256 >> j++)
						putchar('w');
					else
						putchar('-');
					if (stat_var.st_mode & 256 >> j++)
						putchar('x');
					else
						putchar('-');
				}

				printf(" %2lu ", stat_var.st_nlink);
				if (stat_var.st_uid == 1000)
					printf("premraj ");
				if (stat_var.st_gid == 1000)
					printf("premraj ");
				printf("%5lu ", stat_var.st_size);
				printf("%.24s ", ctime(&stat_var.st_mtime));
			}
			printf("%s\n", ReadPtr->d_name);
		} else if (strstr(options, "a"))
			goto here;
	}
	return 0;
}
