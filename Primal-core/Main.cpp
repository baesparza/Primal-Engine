#include <time.h>

#include "src\utils\Timer.h"         
#include "src\graphics\graphics.h"
#include "src\utils\fileutils.h"  
#include "src\maths\maths.h"
#include "src\input\Mouse.h"
#include "src\input\Keyboard.h"

int main()
{
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* shader = new Shader("./res/shader/basic.vert", "./res/shader/basic.frag");
	shader->enable();

	TileLayer layer(shader);

	Texture* textures[] = {new Texture("./res/images/test.png"), new Texture("./res/images/test2.jpg"), new Texture("./res/images/test3.png")};

	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++)
		{
			//	layer.add(new Sprite(x, y, 1.f, 1.f, maths::vec4(1, 0, 1, 1)));
			layer.add(new Sprite(x, y, 1.f, 1.f, (rand() % 2 == 0) ? textures[0] : textures[2]));
		}
	}

	Group* group = new Group(mat4::translation(vec3(5.0f, 5.0f, 0)));
	group->add(new Sprite(0, 0, 6, 3, 0xffffff));
	Group* button = new Group(mat4::translation(vec3(0.5f, 0.5f, 0.0f)));
	button->add(new Sprite(0.f, 0.f, 5.f, 1.5f, textures[1]));
	group->add(button);
	layer.add(group);

	///////fps counter//////
	Group* group2 = new Group(mat4::translation(vec3(-15.0f, 6.0f, 0)));
	group2->add(new Sprite(0, 0, 4.2, 1.2, 0xdddddd99));
	Label * fps = new Label("", 0.2, 0.3, 0xff00ff00);
	group2->add(fps);

	layer.add(group2);

	GLint texIDs[] = {0,1,2,3,4,5,6,7,8,9};

	shader->enable();
	shader->setUniform1iv("textures", texIDs, 10);
	shader->setUniformMat4("pr_matrix", mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	/////frame counter/////
	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();

		shader->enable();
		vec2 pos = Mouse::getPosition(window);
		shader->setUniform2f("light_pos", vec2((float) (pos.x * 32.0f / window.getWidth() - 16.0f), (float) (9.0f - pos.y * 18.0f / window.getHeigth())));
		layer.render();

		/////frame counter/////
		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			fps->text = std::to_string(frames) + "fps";
			frames = 0;
		}
	}

	for (const Texture* t : textures)
		delete t;

	return 0;
}