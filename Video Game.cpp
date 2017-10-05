#include <iostream>

int main() {

	int W = 0;
	std::cin >> W;
	
	int H = 0;
	std::cin >> H;
	
	int stacks[W];
	for (int counter = 0; counter < W; counter++) {
		std::cin >> stacks[counter];
	}	
	
	int command = 0;
	std::cin >> command;
	
	int cranePosition = 0;
	bool craneCarryingBox = false;
	

	
	while(command != 0) {
		//3 2 2 2 2 4 1 3 1 4 0
		//stack
		//3 1 2 1 4 0 1
		//3
		//2
		// crane position
		// 2
		
		//1:Move left
		if (command == 1 && cranePosition - 1 >= 0) {
			cranePosition--;
		}
		else if (command == 2 && cranePosition + 1 <= W-1) {
			//2:Move right
			cranePosition++;
		}
		else if (command == 3 && craneCarryingBox == false && (stacks[cranePosition] - 1) >= 0) {
			//3:Pick up box
			stacks[cranePosition] = stacks[cranePosition] - 1;
			craneCarryingBox = true;
		}
		else if (command == 4 && craneCarryingBox == true && (stacks[cranePosition] + 1) <= H) {
			//4:Drop box
			craneCarryingBox = false;
			stacks[cranePosition] = stacks[cranePosition] + 1;
		}
		
		
		// Take next command input
		std::cin >> command;
	}
	
	for (int counter = 0; counter < W; counter++) {
		if (counter != 0) {
			std::cout << " ";
		}
		std::cout << stacks[counter];
	}
	std::cout << "" << std::endl;
		
	return 0;
}