#pragma once

#include <list>

#include "Building.h"
#include "Common.h"

using std::list;
using BI = pair<Item, float>;

class BuildingBelt;

/**
 * \brief ���ʹ�����
 */
enum class belt_type
{
	/**
	 * \brief ֱ��
	 */
	direct,

	/**
	 * \brief ����ת��
	 */
	left,

	/**
	 * \brief ����ת��
	 */
	right
};

class BeltContext : public BuildingContext
{
	friend BuildingBelt;

public:
	/**
	 * \brief ���ʹ�����
	 */
	const belt_type type;

	/**
	 * \brief ���ʹ��е���Ʒ
	 */
	list<BI> items;

	BeltContext(const Building& building, const ivec2& pos, const Side direction, const belt_type type):
		BuildingContext(building, pos, direction), type(type)
	{
		if (type == belt_type::left)
		{
			output_ = --direction;
		}
		else if (type == belt_type::right)
		{
			output_ = ++direction;
		}
		else
		{
			output_ = direction;
		}
	}

private:
	/**
	 * \brief ÿ ms ǰ���ٶ�
	 */
	const float speed_ = 0.2f;

	/**
	 * \brief ���ʹ������ն�����Ʒ
	 */
	const int max_item_count_ = 5;

	/**
	 * \brief �������
	 */
	Side output_;
};

/**
 * \brief ���ʹ�
 */
class BuildingBelt : public Building
{
public:
	explicit BuildingBelt(): Building({1, 1})
	{
	}

	bool can_receive(const ivec2& pos, Side side, const BuildingContext& context) const override;
	bool can_receive_item(const Item& item, const ivec2& pos, Side side, const BuildingContext& context) const override;
	void receive(Item item, const ivec2& pos, Side side, BuildingContext& context) const override;
	void update(BuildingContext& context, const GameMap& map) const override;

private:
	static BeltContext& cast(BuildingContext& context)
	{
		return static_cast<BeltContext&>(context);
	}

	static const BeltContext& cast(const BuildingContext& context)
	{
		return static_cast<const BeltContext&>(context);
	}
};
