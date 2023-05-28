#include "Main.h"

void Main::run()
{
	// ��ʼ��
	window_.initialize();
	game_.initialize(Timer::time());
	renderer_.initialize();
	// ��Ϸѭ��
	while (window_.is_active())
	{
		game_.update();
		renderer_.update(game_);
		glfwSwapBuffers(window_.window());
		glfwPollEvents();
	}
	// ����
	renderer_.destroy();
	game_.destroy();
	window_.destroy();
}
