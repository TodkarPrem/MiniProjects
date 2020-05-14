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
	time_t time;
	int i, j, a, sum = 0;
	DIR *dPtr;
	struct dirent *dirPtr;
	struct group *grp;
	struct passwd *pswd;
	struct tm *tm, *t1;
	char s[200] = {}, tempStr[200] = {}, z[100] = {}, path[200] = {};
	struct stat var;

	if (argc < 2)
		strcpy(path, ".");
	else
		strcpy(path, argv[1]);

	dPtr = opendir(path);
	if (dPtr == NULL) {
		printf("Usage: ./a.out (PATH) (FLAGS)\n");
		perror("opendir");
		return 0;
	}

	if (argc == 3) {
		HIDDEN_FLAG = strchr(argv[2], 'a');
		while (dirPtr = readdir(dPtr)) {
			if (HIDDEN_FLAG) {
				strcpy(s, path);
				strcat(s, "/");
				strcat(s, dirPtr->d_name);
				stat(s, &var);
				sum += (int) var.st_blocks;
			}
			else if (dirPtr->d_name[0] != '.') {
				strcpy(s, path);
				strcat(s, "/");
				strcat(s, dirPtr->d_name);
				stat(s, &var);
				sum += (int) var.st_blocks;
			}
		}
		printf("Total : %d\n", sum/2);
	}

	dPtr = opendir(path);
	while (dirPtr = readdir(dPtr)) {
		strcpy(tempStr, dirPtr->d_name);
		if (HIDDEN_FLAG) {
			strcpy(s, path);
			strcat(s, "/");
			strcat(s, tempStr);
			stat(s, &var);
		}
		else if (dirPtr->d_name[0] != '.') {
			strcpy(s, path);
			strcat(s, "/");
			strcat(s, tempStr);
			stat(s, &var);
		}

		if (!HIDDEN_FLAG && (tempStr[0] == '.'))
			continue;

		if (argc < 3)
			printf("%s\n", tempStr);		
		else {
			if (strchr(argv[2], 'i'))
				printf("%u ", var.st_ino);
			if (strchr(argv[2], 's'))
				printf("%d ", var.st_blocks/2);

			if (strchr(argv[2], 'l')) {
				if (S_ISREG(var.st_mode))
					printf("-");
				if (S_ISDIR(var.st_mode))
					printf("d");
				if (S_ISLNK(var.st_mode))
					printf("l");
				if (S_ISCHR(var.st_mode))
					printf("c");
				if (S_ISBLK(var.st_mode))
					printf("b");
				if (S_ISFIFO(var.st_mode))
					printf("p");
				if (S_ISSOCK(var.st_mode))
					printf("s");

				a = var.st_mode;
				for (i = 8; i >= 0; i--) {
					if (i == 8 || i == 5 || i == 2) {
						if (a >> i & 1)
							printf("r");
						else
							printf("-");
					}
					if (i == 7 || i == 4 || i == 1) {
						if (a >> i & 1)
							printf("w");
						else
							printf("-");
					}
					if (i == 6 || i == 3 || i == 0) {
						if (a >> i & 1)
							printf("x");
						else
							printf("-");
					}
				}
				printf(" %d ", var.st_nlink);

				//pswd = getpwuid(var.st_uid);
				//printf("%s ", pswd->pw_name);
				//grp = getgrgid(var.st_gid);
				//printf("%s ", grp->gr_name);
				//printf("%u ", var.st_size);
				time = var.st_mtime;
				t1 = localtime(&time);
				strftime(z, sizeof(z), "%e", t1);
				printf("%s ", z);
				strftime(z, sizeof(z), "%R", t1);
				printf("%s ", z);
			}
			printf("%s\n", tempStr);
		}
	}
}
