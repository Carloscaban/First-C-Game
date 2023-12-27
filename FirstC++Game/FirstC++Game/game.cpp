#define isDown(b) input->buttons[b].isDown
#define pressed(b) (input->buttons[b].isDown && input->buttons[b].hasChanged)
#define released(b) (!input->buttons[b].isDown && input->buttons[b].hasChanged)

float playerPosX = 0.f;
float playerPosY = 0.f;

internal void
simulateGame(Input* input) {
	clearScreen(0xff5500);
	if (pressed(BUTTON_UP)) playerPosY += 1.f;
	if (pressed(BUTTON_DOWN)) playerPosY -= 1.f;
	if (pressed(BUTTON_RIGHT)) playerPosX += 1.f;
	if (pressed(BUTTON_LEFT)) playerPosX -= 1.f;

	drawRect(playerPosX, playerPosY, 1, 1, 0x00ff22);
}