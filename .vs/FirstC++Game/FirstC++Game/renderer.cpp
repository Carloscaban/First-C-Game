internal void
clearScreen(u32 color) {
	u32* pixel = (u32*)renderState.memory;

	for (int y = 0; y < renderState.height; y++) {
		for (int x = 0; x < renderState.width; x++) {
			*pixel++ = color;
		}
	}
}

internal void
drawRectInPixels(int x0, int y0, int x1, int y1, u32 color) {
	
	// Setting limits so the window does not crash
	x0 = clamp(0, x0, renderState.width);
	x1 = clamp(0, x1, renderState.width);
	y0 = clamp(0, y0, renderState.height);
	y1 = clamp(0, y1, renderState.height);

	for (int y = y0; y < y1; y++) {
		u32* pixel = (u32*)renderState.memory + x0 + y*renderState.width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}

globalVariable float renderScale = 0.01f;

internal void
drawRect(float x, float y, float halfSizeX, float halfSizeY, u32 color) {
	x *= renderState.height * renderScale;
	y *= renderState.height * renderScale;
	halfSizeX *= renderState.height * renderScale;
	halfSizeY *= renderState.height * renderScale;

	x += renderState.width / 2.f;
	y += renderState.height / 2.f;


	// change to pixels
	int x0 = x - halfSizeX;
	int x1 = x + halfSizeX;
	int y0 = y - halfSizeY;
	int y1 = y + halfSizeY;

	drawRectInPixels(x0, y0, x1, y1, color);
}

internal void 
drawNumber(int number, float x, float y, float size, u32 color) {
	float halfSize = size * .5f;
	switch (number) {
		case 0: {
			drawRect(x - size, y, halfSize, 2.5f * size, color);
			drawRect(x + size, y, halfSize, 2.5f * size, color);
			drawRect(x, y + size * 2.f, halfSize, halfSize, color);
			drawRect(x, y - size * 2.f, halfSize, halfSize, color);
		} break;
		case 1: {
			drawRect(x + size, y, halfSize, 2.5f * size, color);
		}break;
		case 2: {
			drawRect(x, y + size * 2.f, 1.5f * size, halfSize, color);
			drawRect(x, y, 1.5f * size, halfSize, color);
			drawRect(x, y - size * 2.f, 1.5f * size, halfSize, color);
			drawRect(x + size, y + size, halfSize, halfSize, color);
			drawRect(x - size, y - size, halfSize, halfSize, color);
		}
	}
}