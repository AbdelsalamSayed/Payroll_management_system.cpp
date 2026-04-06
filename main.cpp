#include "main.h"

int main() {
	string x;
	
	white(Bfont);
	bcolor(26, 26, 26);
	body();
	footer();
	move(0, 1);
	
	x = write_frame(5,normal);


	cout <<endl<< x;
}