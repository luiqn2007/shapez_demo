#pragma once

/**
 * \brief ����
 */
enum class Side
{
	up,
	down,
	left,
	right
};

/**
 * ˳ʱ����ת
 */
Side operator++(Side side);

/**
 * ��ʱ����ת
 */
Side operator--(Side side);

/**
 * ����
 */
Side operator-(Side side);