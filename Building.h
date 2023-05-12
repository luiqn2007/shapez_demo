#pragma once

#include <vector>

#include "Common.h"
#include "GameMap.h"

using std::vector;

class Item;
class Building;

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
	ivec2 pos;

	/**
	 * \brief ����Ĭ��Ϊ DOWN
	 */
	Side direction;

	BuildingContext(const Building& building, const ivec2& pos, const Side direction) :
		building(building), pos(pos), direction(direction)
	{
	}
};

/**
 * \brief �������ͣ�ֻ���潨������Ϊ�������潨������
 */
class Building
{
public:
	/**
	 * \brief ������С 
	 */
	const ivec2 size;

	virtual ~Building() = default;

	explicit Building(const ivec2& size): size(size)
	{
	}

	/**
	 * \brief �����Ƿ�����������
	 * \param pos ��������λ��
	 * \param direction ��������
	 * \param map ��ͼ
	 */
	bool can_place(const ivec2& pos, Side direction, const GameMap& map) const;

	/**
	 * \brief �ж϶�Ӧλ���Ƿ���ܽ�����Ʒ����
	 * \param pos Ŀ�굥Ԫ
	 * \param side ���뷽��
	 * \param context ��������
	 */
	virtual bool can_receive(const ivec2& pos, Side side, const BuildingContext& context) const = 0;

	/**
	 * \brief �ж϶�Ӧλ���Ƿ��������ĳ��Ʒ
	 * \param item �������Ʒ
	 * \param pos Ŀ�굥Ԫ
	 * \param side ���뷽��
	 * \param context ��������
	 */
	virtual bool can_receive_item(const Item& item, const ivec2& pos, Side side,
	                              const BuildingContext& context) const = 0;

	/**
	 * \brief ��ĳλ�ý�����Ʒ�����ø÷���֮ǰӦ����֤ͨ�� can_receive_item ����
	 * \param item ������Ʒ
	 * \param pos Ŀ�굥Ԫ
	 * \param side ���뷽��
	 * \param context ��������
	 */
	virtual void receive(Item item, const ivec2& pos, Side side, BuildingContext& context) const = 0;

	/**
	 *\brief ���½���״̬
	 */
	virtual void update(BuildingContext& context, const GameMap& map) const = 0;

	/**
	 * \brief ��ȡ����ռ�õ����з���
	 * \param pos ��������λ��
	 * \param direction ��������
	 * \return ���з���
	 */
	static vector<ivec2> all_positions(const ivec2& pos, Side direction);

	/**
	 * \brief ������ĳ����������Ʒ
	 * \param pos ������
	 * \param direction ���ͷ��� 
	 * \param item ������Ʒ
	 * \param map ��ͼ
	 * \return �Ƿ�ɹ�����
	 */
	static bool send_item(const ivec2& pos, const Side direction, const Item& item, const GameMap& map)
	{
		const ivec2 target = pos + direction;
		if (BuildingContext* t_context = map.get_building(target);
			t_context && t_context->building.can_receive_item(item, target, -direction, *t_context))
		{
			t_context->building.receive(item, target, -direction, *t_context);
			return true;
		}

		return false;
	}
};
