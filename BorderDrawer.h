#pragma once

#include "AbstractDrawer.h"

/**
 * \brief ���ڱ߽��ֱ����Ⱦ����ɫΪ 0xF6F6F6
 */
class BorderDrawer: public AbstractDrawer
{
public:
	/**
	 * \param count �������Ƹ���
	 */
	explicit BorderDrawer(const int count) : total_(count)
	{
	}

	/**
	 * \brief ��ʼ��
	 */
	void initialize();

	/**
	 * \brief ׼������
	 */
	void begin() const;

	/**
	 * \brief ����һ��ֱ�ߵ���������
	 * \param x0 ��һ������� x ���꣬��λ����
	 * \param y0 ��һ������� y ���꣬��λ����
	 * \param x1 �ڶ�������� x ���꣬��λ����
	 * \param y1 �ڶ�������� y ���꣬��λ����
	 */
	void push(float x0, float y0, float x1, float y1);

	/**
	 * \brief �����ѻ��涥��
	 */
	void draw();

	/**
	 * \brief ����
	 */
	void destroy();

private:
	/**
	 * \brief �������������
	 */
	const int total_;

	/**
	 * \brief δ������ֱ����
	 */
	int count_ = 0;

	/**
	 * \brief ���㻺����ָ��
	 */
	float* buf_ = nullptr;
};
