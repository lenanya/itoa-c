// to clarify what the first arg of write actually means
#define STDOUT 1

// syscalls defined in syscalls.S
void write(int fd, char* str, int length);
void _exit(int code);
// macro stuff to write a newline after what we want to write
#define writeln(fd, str, length) {write(fd, str, length);write(fd, "\n", 1);}

// global buffers cuz stack is fucked (something to do with no libc)
char itoares[128];
char temp[128];

int cstrlen(char* str) { // shitty strlen
	int i = 0;
	while (str[i] != 0) ++i;
	return i;
}

void strrev(char* str) { // shitty string reversal
	int length = cstrlen(str);
	for (int i = 0; i < length; ++i) temp[i] = str[i]; // copy string to temp buffer
	for (int i = length - 1; i >= 0; --i) str[length - 1 - i] = temp[i]; // reverse iterate 
}

void clearbuffers() {
	for (int i = 0; i < 128; ++i) {
		itoares[i] = 0;
		temp[i] = 0;
	}
}

void itoa(char* ret, int n) {
	int negative = 0;
	if (n < 0) { 
		negative = 1;
		n *= -1; // basically abs(n)
	}
	int i = 0;
	while (n > 0) { // go through digits from right to left (in reverse)
		int temp = n % 10; // get digit
		ret[i] = temp + 0x30; // ascii of numbers is 0x30 to 0x39
		n = n / 10; // move to next digit
		++i;
	}
	if (negative) {
		ret[i] = 0x2D; // "-"
		++i;
	}	
	ret[i] = 0; // null terminate string so cstrlen and strrev work
	strrev(ret); // reverse the string
}

// _start because main comes from libc
void _start() {
	itoa(itoares, -69);
	writeln(STDOUT, itoares, cstrlen(itoares));
	clearbuffers();
	itoa(itoares, 3789423);
	writeln(STDOUT, itoares, cstrlen(itoares));
	_exit(0);
}
