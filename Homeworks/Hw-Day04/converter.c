#include <stdio.h>

int len(char str[]);
int digitValue(char c);
int toDecimal(char number[], int base);
char resultValue(int num);
int convert(char inNum[], int base1, int base2);

int main(void) {
    
    char num[256];
    unsigned inBase;
    unsigned outBase;

    scanf("%s", num);
    scanf("%i", &inBase);
    scanf("%i", &outBase);

    if (inBase < 2 || inBase > 36){
        fprintf(stderr, "Invalid input base!\n");
    }

    if (outBase < 2 || outBase > 36){
        fprintf(stderr, "Invalid output base!\n");
    }

    
    if (convert(num, inBase, outBase)) {
        fprintf(stderr, "Invalid Number\n");
    }

    return 0;
}

int len(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) { }

    return i;
}


int digitValue(char c) {
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

int toDecimal(char number[], int base) {
	int l = len(number);

	int power = 1;

	int num = 0;
	for (int i = l - 1; i >= 0; i--) {

		if (digitValue(number[i]) >= base) {
			return -1;
		}

		num += digitValue(number[i]) * power;
		power = power * base;
	}

	return num;
}

char resultValue(int num) {
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}
int convert(char inNum[], int base1, int base2) {
	int num = toDecimal(inNum, base1);
    if (-1 == num){
        return 1;
    }
    char res[256];

    int i = 0;
	while (num > 0) {

		res[i] = resultValue(num % base2);

        i++;
		num /= base2;
	}

    res[i] = '\0';

	for (int i = len(res) - 1; i >= 0; i--){
        printf("%c", res[i]);
    }

    putchar('\n');
    return 0;
}