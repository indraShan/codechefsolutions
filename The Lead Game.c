#include <stdio.h>
#include <stdlib.h>
 
int main() {
 
	int rounds = 0;
	scanf("%d", &rounds);
 
	int maxLead = 0;
	int leadPlayer = 1;
	int player1Lead = 0;
	int player2Lead = 0;
	for (int counter = 0; counter < rounds; counter++) {
		int player1 = 0;
		int player2 = 0;
		scanf("%d", &player1);
		scanf("%d", &player2);
		player1Lead += player1;
		player2Lead += player2;
 
		int lead = abs(player1Lead - player2Lead);
		int player = player1Lead > player2Lead ? 1 : 2;

		if (lead > maxLead) {
			maxLead = lead;
			leadPlayer = player;
		}
 
	}
 
	printf("%d %d \n", leadPlayer, maxLead);
 
	return 0;
}