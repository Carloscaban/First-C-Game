#include <windows.h>

bool running = true;

LRESULT CALLBACK windowCallback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;

	switch (uMsg) {
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
		} break;

		case WM_SIZE: {
			RECT rect;
			GetClientRect(hwnd, &rect);
			int width = rect.right - rect.left;
			int height = rect.bottom - rect.top;

			int bufferSiz = width * height * sizeof(unsigned int);
		}

		default: {
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}

	return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	// Create Window class
	WNDCLASS windowClass = {};
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpszClassName = "Game Window Class";
	windowClass.lpfnWndProc = windowCallback;

	// Register class
	RegisterClass(&windowClass);

	// Create Window
	HWND window = CreateWindow(windowClass.lpszClassName, "My First Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

	while (running) {
		// input
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		// Simulate


		// Render


	}
}