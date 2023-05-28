#pragma once

#include "AbstractDrawer.h"

/**
 * \brief ���Ƽ�ͼ��
 */
class ShapeDrawer : public AbstractDrawer
{
public:
	/**
	 * \brief ��ʼ��
	 */
	void initialize();

	/**
	 * \brief ���ƾ���
	 * \param x0 x0
	 * \param y0 y0
	 * \param x1 x1
	 * \param y1 y1
	 * \param r r
	 * \param g g
	 * \param b b
	 * \param a a
	 */
	void rect(float x0, float y0, float x1, float y1, float r, float g, float b, float a = 1) const;

	/**
	 * \brief ����
	 */
	void destroy() const;
};
