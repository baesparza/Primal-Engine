#include "src\graphics\graphics.h"
#include "src\maths\maths.h"
#include "src\utils\fileutils.h"
#include "src\input\Mouse.h"
#include "src\input\Keyboard.h"

int main()
{
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	mat4 ortho = mat4::ortographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	/////shader/////
	Shader shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);

	Renderable2D sprite1(maths::vec3(4, 4, 0), maths::vec2(3, 3), maths::vec4(0.5f, 0.3f, 0.f, 1.f), shader);
	Renderable2D sprite2(maths::vec3(8, 3, 0), maths::vec2(1, 3), maths::vec4(0.5f, 0.3f, 0.7f, 1.f), shader);
	Simple2DRenderer renderer;

	while (!window.closed())
	{
		window.clear();
		// mouse position
		vec2 pos = Mouse::getPosition(window);
		shader.setUniform2f("light_pos", vec2(( float ) (pos.x * 16 / 960), ( float ) (9 - pos.y * 9 / 540)));

		/////draw/////
		renderer.submit(&sprite1);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}
	return 0;
}