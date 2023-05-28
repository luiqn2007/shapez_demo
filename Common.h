#pragma once

/**
 * \brief ��ͼ�е�Ԫ��ĸ���
 */
constexpr int CELL_COUNT = 200;

class GameWindow;
class GameRenderer;
class GameLogic;

/**
 * \brief ��ǰ�����е���Ϸ
 */
extern GameLogic* current_game;

/**
 * \brief ��ǰ�����е���Ϸ����
 */
extern GameWindow* current_window;

/**
 * \brief ��ǰ�����е���Ϸ��Ⱦ��
 */
extern GameRenderer* current_renderer;

static int image_id = 0;

/**
 * \brief �����ã�У�� GL ����
 * \param name �쳣ԭ��
 */
void log_error(const char* name);

/**
 * \brief ��ȡһ�����õĵ�����λ
 * \return ��������λ
 */
inline int next_texture_id()
{
	return image_id++;
}
