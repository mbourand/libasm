#include "tester.h"

int test_strcpy()
{
	int len = 17;
	int succeed = 0;
	static char* (srcs[17]) =
	{
		"\0", "", "FGILDEZHGLIOZGHOIEZGHY OIE yOAIUZFH IOUAEZ", "\\\t\f\\^^^$$alghùùù:::§ML00\v\v\rçç", "Salut!",
		"42 42 42 4242424242008487456", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"Salut!", "Test\0\0", "", "Lorem ipsum dolor sit amet", "          ", "\t\\\v$^*fgsg\a`\"ddddf447",
		"!!!!!!!!!!!", "402", "0", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	};

	for (int i = 0; i < len; i++)
	{
		char *original = (char*)malloc(sizeof(char) * (strlen(srcs[i]) + 1));
		char *user = (char*)malloc(sizeof(char) * (strlen(srcs[i]) + 1));

		strcpy(original, srcs[i]);
		ft_strcpy(user, srcs[i]);
		if (strncmp(original, user, strlen(srcs[i]) + 1) != 0)
			printf("%s\nTest %d :\t%s[KO]%s\nAttendu : %s\tObtenu : %s\n", RESET, i + 1, RED, RESET, original, user);
		else
		{
			printf("%sTest %d :\t%s[OK]\t", RESET, i + 1, GREEN);
			succeed++;
			if (succeed % 5 == 0)
				printf("\n");
			if (i == len - 1)
				printf("\n");
		}
		free(original);
		free(user);
	}
	return (succeed);
}

int test_strlen()
{
	int len = 17;
	static char* (parameters[17]) =
	{ 
		"\0", "", "FGILDEZHGLIOZGHOIEZGHY OIE yOAIUZFH IOUAEZ", "\\\t\f\\^^^$$alghùùù:::§ML00\v\v\rçç", "Salut!",
		"42 42 42 4242424242008487456", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"Salut!", "Test\0\0", "", "Lorem ipsum dolor sit amet", "          ", "\t\\\v$^*fgsg\a`\"ddddf447",
		"!!!!!!!!!!!", "402", "0", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	};
	int original;
	int user;
	int succeed = 0;

	for (int i = 0; i < len; i++)
	{
		user = ft_strlen(parameters[i]);
		original = strlen(parameters[i]);
		if (user != original)
			printf("%s\nTest %d :\t%s[KO]%s\nAttendu : %d\tObtenu : %d\n", RESET, i + 1, RED, RESET, original, user);
		else
		{
			printf("%sTest %d :\t%s[OK]\t", RESET, i + 1, GREEN);
			succeed++;
			if (succeed % 5 == 0)
				printf("\n");
			if (i == len - 1)
				printf("\n");
		}
	}
	return (succeed);
}

int test_read()
{
	int buf_len = 23;
	int files_len = 11;
	static int buffers[23] =
	{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 42, 45, 87, 100, 222, 1000, 2547896, 1000000, 10000000, 0, -1, -200
	};
	char * (filenames[11]) =
	{
		"read_test.txt", ".", "/dev/null", "/dev/zero", "/dev/", "test.c",
		"zekgjfhzeijoughzeiou giojzehgioz egoize o", "", "\\\t\f\\^^^$$alghùùù:::§ML00\v\v\rçç", "\0", "noperms.txt"
	};
	int fd;
	int succeed = 0;

	for (int j = 0; j < files_len; j++)
	{
		char *filename = filenames[j];
		for (int i = 0; i < buf_len; i++)
		{
			char *user_buf = malloc(sizeof(char) * ((buffers[i] < 0 ? 1 : buffers[i]) + 1));
			char *original_buf = malloc(sizeof(char) * ((buffers[i] < 0 ? 1 : buffers[i]) + 1));

			bzero(user_buf, (buffers[i] < 0 ? 1 : buffers[i]) + 1);
			bzero(original_buf, (buffers[i] < 0 ? 1 : buffers[i]) + 1);

			if ((fd = open(filename, O_RDONLY)) < 0)
				strerror(errno);
			int user = ft_read(fd, user_buf, buffers[i]);
			int user_errno = errno;
			close(fd);

			if ((fd = open(filename, O_RDONLY)) < 0)
				strerror(errno);
			int original = read(fd, original_buf, buffers[i]);
			int original_errno = errno;
			close(fd);

			if (original == user && strncmp(user_buf, original_buf, buffers[i]) == 0 && (original < 0 ? original_errno == user_errno : 1))
			{
				printf("%sTest %d :\t%s[OK]\t", RESET, buf_len * j + i + 1, GREEN);
				succeed++;
				if (succeed % 5 == 0)
					printf("\n");
			}
			else
				printf("\n%sTest %d :\t%s[KO]\n%sAttendu : %d / %s \tObtenu : %d / %s\n", RESET, 20 * j + i + 1, RED, RESET, original, original_buf, user, user_buf);
			if (i == buf_len - 1 && j == files_len - 1)
				printf("\n");
			free(user_buf);
			free(original_buf);
		}
	}
	return (succeed);
}

int test_write()
{
	int len = 17;
	static char* (parameters[17]) =
	{ 
		"\0", "", "FGILDEZHGLIOZGHOIEZGHY OIE yOAIUZFH IOUAEZ", "\\\t\f\\^^^$$alghùùù:::§ML00\v\v\rçç", "Salut!",
		"42 42 42 4242424242008487456", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"Salut!", "Test\0\0", "", "Lorem ipsum dolor sit amet", "          ", "\t\\\v$^*fgsg\a`\"ddddf447",
		"!!!!!!!!!!!", "402", "0", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	};
	char *user_file = "user_write.txt";
	char *original_file = "original_write.txt";
	int succeed = 0;

	for (int i = 0; i < len; i++)
	{
		int user_fd = open(user_file, O_CREAT | O_RDWR, 0644);
		int original_fd = open(original_file, O_CREAT | O_RDWR, 0644);

		int user = ft_write(user_fd, parameters[i], strlen(parameters[i]) - 15);
		int user_errno = errno;
		int original = write(original_fd, parameters[i], strlen(parameters[i]) - 15);
		int original_errno = errno;

		int diff = system("diff user_write.txt original_write.txt");
		
		if (diff == 0 && user == original && (original < 0 ? original_errno == user_errno : 1))
		{
			printf("%sTest %d :\t%s[OK]\t", RESET, i + 1, GREEN);
			succeed++;
			if (succeed % 5 == 0)
				printf("\n");
		}
		else
		{
			printf("%s\nTest %d :\t%s[KO]%s\nAttendu : %d\tObtenu : %d\n", RESET, i + 1, RED, RESET, original, user);
			printf("%sFichier attendu :\n", RESET);
			system("cat original_write.txt");
			printf("%sFichier obtenu :\n", RESET);
			system("cat user_write.txt");
		}

		remove(user_file);
		remove(original_file);
		if (i == len - 1)
			printf("\n");
	}
	return (succeed);
}

int test_strdup()
{
	int len = 17;
	int succeed = 0;
	static char* (srcs[17]) =
	{
		"\0", "", "FGILDEZHGLIOZGHOIEZGHY OIE yOAIUZFH IOUAEZ", "\\\t\f\\^^^$$alghùùù:::§ML00\v\v\rçç", "Salut!",
		"42 42 42 4242424242008487456", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"Salut!", "Test\0\0", "", "Lorem ipsum dolor sit amet", "          ", "\t\\\v$^*fgsg\a`\"ddddf447",
		"!!!!!!!!!!!", "402", "0", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	};

	for (int i = 0; i < len; i++)
	{
		char *original;
		char *user;

		original = strdup(srcs[i]);
		user = ft_strdup(srcs[i]);
		if ((original == 0 && user == 0) || strncmp(original, user, strlen(srcs[i]) + 1) != 0)
			printf("%s\nTest %d :\t%s[KO]%s\nAttendu : %s\tObtenu : %s\n", RESET, i + 1, RED, RESET, original, user);
		else
		{
			printf("%sTest %d :\t%s[OK]\t", RESET, i + 1, GREEN);
			succeed++;
			if (succeed % 5 == 0)
				printf("\n");
			if (i == len - 1)
				printf("\n");
		}
		free(original);
		free(user);
	}
	return (succeed);
}

void print_header(char *func_name)
{
	if (strlen(func_name) > 40)
		exit(1);
	printf(RESET);
	printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
	int mfw = (int)(60 + strlen(func_name) / 2);
	printf("|%*s%*s|\n", mfw, func_name, 120 - mfw, "");
	printf("--------------------------------------------------------------------------------------------------------------------------\n\n");
}

int main(void)
{
	int note = 0;

	print_header("Libasm Tester");

	print_header("ft_strlen");
	note += test_strlen();

	print_header("ft_strcpy");
	note += test_strcpy();

	print_header("ft_read");
	note += test_read();

	print_header("ft_write");
	note += test_write();

	print_header("ft_strdup");
	note += test_strdup();
	printf("Note : %s%d/321\n", GREEN, note);
}
