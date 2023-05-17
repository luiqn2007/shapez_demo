#pragma once

#include "AbstractDrawer.h"
#include "Common.h"

/**
 * \brief ������������ÿ��������Ҫ 24 �� float
 *
 * ��������ﵽ����������ֱ�ӻ��ƣ����� draw ����ʱ����
 */
class TextureDrawer : public AbstractDrawer
{
public:
	explicit TextureDrawer(const int count): total_(count)
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
	float* buf_ = nullptr;
};
