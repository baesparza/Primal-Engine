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

	mat4 ortho = mat4::ortographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	/////shader/////
	Shader shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);

	std::vector<Renderable2D*> sprites;

	BatchRenderer2D renderer;
	for (float y = 0; y < 9; y += 0.05)
		for (float x = 0; x < 16; x += 0.05)
		{
			sprites.push_back(new Sprite(x, y, 0.04f, 0.04f, maths::vec4(rand() % 1000 / 1000.f, rand() % 1000 / 1000.f, rand() % 1000 / 1000.f, 1.f)));
		}


	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!window.closed())
	{
		mat4 mat = mat4::translation(vec3(5, 5, 5));
		mat = mat * mat4::rotation(time.elapsed() * 50.0, vec3(0, 0, 1));
		mat = mat * mat4::translation(vec3(-5, -5, -5));
		shader.setUniformMat4("ml_matrix", mat);

		window.clear();
		// mouse position
		vec2 pos = Mouse::getPosition(window);
		shader.setUniform2f("light_pos", vec2(( float ) (pos.x * 16 / window.getWidth()), ( float ) (9 - pos.y * 9 / window.getHeigth())));

		/////draw/////
		renderer.begin();
		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.submit(sprites[i]);
		}
		renderer.end();

		renderer.flush();

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