#include <time.h>

#include "src\graphics\graphics.h"
#include "src\maths\maths.h"
#include "src\input\Mouse.h"
#include "src\input\Keyboard.h"
#include "src\utils\fileutils.h"
#include "src\utils\Timer.h"

int main()
{
	srand(time(0));

	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	/////shader/////
	Shader * shader = new Shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	shader->enable();
	shader->setUniformMat4("pr_matrix", mat4::ortographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));

	TileLayer layer(shader);
	shader->enable();
	layer.add(new Sprite(0, 0, 2, 2, maths::vec4(0.1, 0.8, 0.7, 1.0)));

	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!window.closed())
	{
		window.clear();

		// mouse position
		vec2 pos = Mouse::getPosition(window);
		shader->enable();
		shader->setUniform2f("light_pos", vec2(( float ) (pos.x * 32.0f / window.getWidth() - 16.0f), ( float ) (9 - pos.y * 18.f / window.getHeigth())));

		/////draw/////
		layer.render();

		window.update();

		/////frame counter///
		frames++;
		if (time.elapsed() - timer > 1.f)
		{
			timer += 1;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}