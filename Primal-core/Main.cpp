#include <time.h>

#include "src\utils\fileutils.h"  
#include "src\utils\Timer.h"         
#include "src\maths\maths.h"
#include "src\input\Mouse.h"
#include "src\input\Keyboard.h"
#include "src\graphics\graphics.h"

int main()
{
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky!", 960, 540);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* shader = new Shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	shader->enable();

	TileLayer layer(shader);

	Group* group = new Group(mat4::translation(vec3(-15.0f, 5.0f, 0)));
	group->add(new Sprite(0, 0, 6, 3, maths::vec4(1, 1, 1, 1)));
	Group* button = new Group(mat4::translation(vec3(0.5f, 0.5f, 0.0f)));

	button->add(new Sprite(0.f, 0.f, 5.f, 2.0f, maths::vec4(1, 0, 1, 1)));
	button->add(new Sprite(0.5f, 0.5f, 3.f, 1.0f, maths::vec4(0.2f, 0.3f, 0.8f, 1)));
	group->add(button);
	layer.add(group);

	Texture texture("test.png");
	texture.bind();

	/////frame counter/////
	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();

		shader->enable();
		vec2 pos = Mouse::getPosition(window);
		shader->setUniform2f("light_pos", vec2((float)(pos.x * 32.0f / 960.0f - 16.0f), (float)(9.0f - pos.y * 18.0f / 540.0f)));
		layer.render();

		/////frame counter/////
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
