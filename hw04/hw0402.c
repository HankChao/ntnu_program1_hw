#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mahjong.h"
#define RAND_CARD ((rand() % 34) + 1)

void Rand(int8_t *, int8_t *);
void Enter(int8_t *, int8_t *);

int main()
{
	srand(time(0));
	while (1)
	{
		int8_t cards[22] = {};
		int8_t size = 0;
		printf("===\n");
		printf("a) rand\n");
		printf("b) enter\n");
		printf("other) end\n");
		printf("===\n");
		char tmp = ' ';
		scanf("%c", &tmp);
		while(getchar() != '\n');
		switch (tmp)
		{
		case 'a':
			Rand(cards, &size);
			break;
		case 'b':
			Enter(cards, &size);
			break;
		default:
			return 0;
		}
		#define NUMB(x) ((cards[x] - 1) % 9 + 1)
		#define TYPE(x) ((cards[x] <= 9) ? 'p' : (cards[x] <= 18) ? 's' : (cards[x] <= 27) ? 'm' : 'z')
		printf("Input:\n%d%c", NUMB(0), TYPE(0));
		for (int8_t i = 1; i < size; i++)
			printf("-%d%c", NUMB(i), TYPE(i));
		printf("\n");
		
		printf("Size : %d\n", size);
		printf("Check: %d\n", check(cards, size));
		
		for (int8_t i = 1; i < size; i++)
			for (int8_t j = 1; j < size; j++)
				if (cards[j - 1] > cards[j])
					cards[j - 1] ^= cards[j] ^= cards[j - 1] ^= cards[j];
		printf("Sorted:\n%d%c", NUMB(0), TYPE(0));
		for (int8_t i = 1; i < size; i++)
			printf("-%d%c", NUMB(i), TYPE(i));
		printf("\n");
	}
}

void Rand(int8_t * cards, int8_t * size)
{
	*size = 0;
	if (rand() % 16 == 0)
	{
		cards[0] = RAND_CARD;
		cards[1] = RAND_CARD;
		*size = 2;
	}
	else if (rand() % 4 != 0)
	{
		cards[0] = cards[1] = RAND_CARD;
		*size = 2;
	}
	while (*size < 17)
	{
		if (rand() % 2 == 0) // Add a sequence
		{
			cards[(*size)++] = rand() % 8 + 9 * (rand() % 3) + 1;
			cards[(*size)++] = cards[*size - 1] + 1;
			cards[(*size)++] = cards[*size - 1] + 1;
		}
		else if (rand() % 3 == 0) // Add a triplet
		{
			cards[(*size)++] = RAND_CARD;
			cards[(*size)++] = cards[*size - 1];
			cards[(*size)++] = cards[*size - 1];
			if (rand() % 2 == 0) // Add to a quad
				cards[(*size)++] = cards[*size - 1];
		}
	}
	for (int8_t i = 0; i < *size; i++)
	{
		int8_t _r = rand() % *size;
		if (_r != i)
			cards[i] ^= cards[_r] ^= cards[i] ^= cards[_r];
	}
	return;
}
void Enter(int8_t * cards, int8_t * size)
{
	*size = 0;
	while (1)
	{
		int32_t tmp;
		int8_t success = scanf("%d", &tmp);
		if (!success)
			break;
		if (tmp == 0)
			break;
		cards[(*size)++] = tmp;
	}
	while (getchar() != '\n');
	return;
}