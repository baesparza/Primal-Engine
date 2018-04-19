#include <time.h>

#include "src\utils\fileutils.h"  
#include "src\utils\Timer.h"         
#include "src\maths\maths.h"
#include "src\input\Mouse.h"
#include "src\input\Keyboard.h"
#include "src\graphics\graphics.h"

#define BATCH_RENDERER 1
#define TEST_50K_SPRITES 0


#if 1
int main()
{
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky!", 960, 540);
	// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* s = new Shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	Shader* s2 = new Shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	Shader& shader = *s;
	Shader& shader2 = *s2;
	shader.enable();
	shader2.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader2.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer(&shader);

#if TEST_50K_SPRITES
	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			layer.add(new Sprite(x, y, 0.09f, 0.09f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
#else
	Group* group = new Group(mat4::translation(vec3(-15.0f, 5.0f, 0)));
	group->add(new Sprite(0, 0, 6, 3, maths::vec4(1, 1, 1, 1)));
	Group* button = new Group(mat4::translation(vec3(0.5f, 0.5f, 0.0f)));

	button->add(new Sprite(0.f, 0.f, 5.f, 2.0f, maths::vec4(1, 0, 1, 1)));
	button->add(new Sprite(0.5f, 0.5f, 3.f, 1.0f, maths::vec4(0.2f, 0.3f, 0.8f, 1)));
	group->add(button);
	layer.add(group);
#endif

	TileLayer layer2(&shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, maths::vec4(1, 0, 1, 1)));

	Texture texture("test.png");

	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{

		window.clear();
		vec2 pos = Mouse::getPosition(window);
		shader.enable();
		shader.setUniform2f("light_pos", vec2((float)(pos.x * 32.0f / 960.0f - 16.0f), (float)(9.0f - pos.y * 18.0f / 540.0f)));
		//shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		//shader.setUniform2f("light_pos", vec2(-8, -3));
		shader2.enable();
		layer.render();
		//	layer2.render();

		glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(0, 4);
		glVertex2f(4, 4);
		glVertex2f(4, 0);
		glEnd();

		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}
#else

int main()
{
	const char* filename = "test.png";

	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//pointer to the image, once loaded
	FIBITMAP *dib(0);
	//pointer to the image data
	BYTE* bits(0);
	//image width and height
	unsigned int width(0), height(0);
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;

	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);
	//if the image failed to load, return failure
	if (!dib)
		return false;


	//retrieve the image data
	bits = FreeImage_GetBits(dib);

	unsigned int bitsPerPixel = FreeImage_GetBPP(dib);
	unsigned int pitch = FreeImage_GetPitch(dib);

	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;

	for (int y = 0; y < height; y++)
	{
		BYTE* pixel = (BYTE*)bits;
		for (int x = 0; x < width; x++)
		{
			std::cout << +pixel[FI_RGBA_RED] << ", " << +pixel[FI_RGBA_GREEN] << ", " << +pixel[FI_RGBA_BLUE] << '\n';
			pixel += 3;
		}
		bits += pitch;
	}


	std::cin.get();
	return 0;
}

#endif