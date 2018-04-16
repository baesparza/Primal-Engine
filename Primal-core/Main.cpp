#include <time.h>

#include "src\graphics\graphics.h"
#include "src\maths\maths.h"
#include "src\input\Mouse.h"
#include "src\input\Keyboard.h"
#include "src\utils\fileutils.h"
#include "src\utils\Timer.h"

#define BATCH_RENDERER 1
#define TEST_50K_SPRITES 0

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