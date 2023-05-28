#pragma once

#include <utility>

#include "Color.h"
#include "ResourceType.h"
#include "Shape.h"

using std::pair;

/**
 * \brief ��Ⱦɫ�����״��ɵ���Ʒ
 */
struct ColoredShapes
{
	pair<Color, Shape> down_right;
	pair<Color, Shape> down_left;
	pair<Color, Shape> up_right;
	pair<Color, Shape> up_left;

	static ColoredShapes from_resource(ResourceType type);

	/**
	 * \brief ˳ʱ����ת��Ʒ
	 */
	void operator++();

	/**
	 * \brief ��ʱ����ת��Ʒ
	 */
	void operator--();

	/**
	 * \brief У�����״�Ƿ���Ա�������ɫȾɫ
	 * \param color ��ɫ
	 * \return �Ƿ�ɱ�Ⱦɫ
	 */
	bool operator|(Color color) const;

	bool operator==(const ColoredShapes&) const;
};
