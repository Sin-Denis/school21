//
// Created by Sin Denis on 2019-06-13.
//

#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	for (int i = 1; i < argc; ++i) {
		printf("%d: %s\n", i, argv[i]);
	}
	return (0);
}
