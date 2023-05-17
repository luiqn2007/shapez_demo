#pragma once

#include <glad/glad.h>

#include "Common.h"
#include "AbstractDrawer.h"

/**
 * \brief ������������ÿ��������Ҫ 8 �� float �� 4 �� int
 *
 * ��������ﵽ����������ֱ�ӻ��ƣ����� draw ����ʱ����
 */
class TextureInstanceDrawer : public AbstractDrawer
{
public:
	/**
	 * \param count �����������
	 */
	explicit TextureInstanceDrawer(const int count) : total_(count)
	{
	}

	/**
	 * \brief ��ʼ�� 
	 */
	void initialize();

	/**
	 * \brief ׼����ʼ����
	 */
	void begin() const;

	/**
	 * \brief ������������
	 * \param tex ��������
	 */
	void tex(GLint tex);

	/**
	 * \brief ��͸������
	 * \param alpha �������� alpha ֵ
	 */
	void alpha(GLfloat alpha);

	/**
	 * \brief ��������
	 * \param x0 ���ϽǶ���� x ���꣬��λ����
	 * \param y0 ���ϽǶ���� y ���꣬��λ����
	 * \param x1 ���½Ƕ���� x ���꣬��λ����
	 * \param y1 ���½Ƕ���� y ���꣬��λ����
	 * \param u ���ϽǶ��� x ��������
	 * \param v ���ϽǶ��� y ��������
	 * \param w �����ȣ�[0, 1]
	 * \param h ����߶ȣ�[0, 1]
	 */
	void push(float x0, float y0, float x1, float y1, float u, float v, float w, float h);

	/**
	 * \brief ����
	 */
	void draw();

	/**
	 * \brief ����
	 */
	void destroy();

private:
	const int total_;
	int count_ = 0;
	GLint tex_ = 0;
	GLfloat alpha_ = 0;
	GLuint indices_ = 0;
	float* buf_vertices_ = nullptr;
	int* buf_indices_ = nullptr;
};
