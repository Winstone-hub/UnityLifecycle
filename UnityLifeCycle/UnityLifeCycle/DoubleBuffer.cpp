#include "DoubleBuffer.h"

DoubleBuffer* DoubleBuffer::Instance = nullptr;

DoubleBuffer::DoubleBuffer()
{

}

DoubleBuffer::~DoubleBuffer()
{

}

void DoubleBuffer::Start()
{
	BufferIndex = 0;
}

void DoubleBuffer::CreateBuffer(const int& _Width, const int& _Height)
{
	COORD Size = { (SHORT)_Width, (SHORT)_Height };
	SMALL_RECT Rect;

	Rect.Left = 0;
	Rect.Top = 0;

	Rect.Right = _Width;
	Rect.Bottom = _Height;

	hBuffer[0] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);

	SetConsoleScreenBufferSize(hBuffer[0], Size);

	SetConsoleWindowInfo(hBuffer[0], TRUE, &Rect);


	hBuffer[1] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);

	SetConsoleScreenBufferSize(hBuffer[1], Size);

	SetConsoleWindowInfo(hBuffer[1], TRUE, &Rect);


	CONSOLE_CURSOR_INFO Cursor;

	Cursor.bVisible = false;
	Cursor.dwSize = 1;

	SetConsoleCursorInfo(hBuffer[0], &Cursor);
	SetConsoleCursorInfo(hBuffer[1], &Cursor);
}

void DoubleBuffer::WriteBuffer(const float& _x, const float& _y, char* _str)
{
	DWORD dw;
	COORD Cursor = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(hBuffer[BufferIndex], Cursor);
	WriteFile(hBuffer[BufferIndex], _str, strlen(_str), &dw, NULL);
}

void DoubleBuffer::FlippingBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[BufferIndex]);
	BufferIndex = !BufferIndex;
}

void DoubleBuffer::ClearBuffer()
{
	COORD Coord = { 0, 0 };
	DWORD dw;

	FillConsoleOutputCharacter(hBuffer[BufferIndex],
		' ', WIDTHSIZE * HEIGHTSIZE, Coord, &dw);
}
