#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Ponglitics : public olc::PixelGameEngine
{
public:
	Ponglitics()
	{
		sAppName = "Ponglitics";
	}

	void cosmic_background()
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
	}

	void white_noise()
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
			{
				int shade = rand() % 256;
				Draw(x, y, olc::Pixel(shade, shade, shade));
			}
	}

private:
	bool bPaused = false;

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		//Lke What???
		

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Check for SPACE key press to toggle pause state
		if (GetKey(olc::Key::SPACE).bPressed) {
			bPaused = !bPaused; // Toggle the pause state
		}

		if (!bPaused) {
			//cosmic_background();
			white_noise();
		}

		//if (bPaused) {
		//	
		//	DrawString(10, 10, "Press SPACE to resume.", olc::BLACK);
		//}
		//else {
		//	DrawString(10, 10, "Press SPACE to pause.", olc::BLACK);
		//	// Draw game elements here
		//}

		return true;
	}
};


int main()
{
	Ponglitics demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}
