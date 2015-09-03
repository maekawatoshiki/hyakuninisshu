#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct HYAKUNIN {
	char kami[0xff];
	char shimo[0xff];
	char kami_hira[0xff];
	char shimo_hira[0xff];
	char name[0xff];
};

int main() {
	FILE *fp = fopen("hyaku.c", "rb");
	int i = 0;
	struct HYAKUNIN hi[128] = { 0 };

	srand(time(0));

	for(i = 0; i < 100; i++) {
		fscanf(fp, "%s %s %s %s %s", 
			hi[i].kami, hi[i].shimo, hi[i].kami_hira, 
			hi[i].shimo_hira, hi[i].name);
	}

	while(1) {
		i = 48 + (rand() % 26);
		printf("作者: %s\n\t%s %s\n\t%s %s\n", hi[i].name, hi[i].kami, hi[i].shimo, hi[i].kami_hira, hi[i].shimo_hira);
		getchar();
	}
}