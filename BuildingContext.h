#pragma once

#include "vec.h"

class Building;
enum class Side;

/**
 * \brief �����ڵ�ͼ�ϵ�����
 */
class BuildingContext
{
public:
	/**
	 * \brief ��������
	 */
	const Building& building;

	/**
	 * \brief ����λ��
	 */
	Vec2I pos;

	/**
	 * \brief ��Ҫ�������ͨ��Ϊ up��
	 */
	Side direction;
	
	BuildingContext(const Building& building, const Vec2I& pos, const Side direction) :
		building(building), pos(pos), direction(direction)
	{
	}
};