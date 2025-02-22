#define STDOUT 1

// syscalls defined in syscalls.S
void write(int fd, char* str, int length);
void _exit(int code);
#define writeln(fd, str, length) {write(fd, str, length);write(fd, "\n", 1);}

// global buffers cuz stack is fucked
char itoares[100];
char temp[100];

int cstrlen(char* str) {
	int i = 0;
	while (str[i] != 0) ++i;
	return i;
}

void strrev(char* str) {
	int length = cstrlen(str);
	for (int i = 0; i < length; ++i) {
		temp[i] = str[i];
	}
	for (int i = length - 1; i >= 0; --i) {
		str[length - 1 - i] = temp[i];
	}
}
		

void itoa(char* ret, int n) {
	int i = 0;
	while (n > 0) {
		int temp = n % 10;
		ret[i] = temp + 0x30; // ascii of numbers is 0x30 to 0x39
		n = n / 10;
		++i;
	}
	ret[i] = 0;
}

// _start because main comes from libc
void _start() {
	itoa(itoares, 69);
	strrev(itoares);
	writeln(STDOUT, itoares, cstrlen(itoares));
	_exit(0);
}
