#pragma once

#include <list>
#include <typeinfo>

#include "Building.h"
#include "Item.h"
#include "BuildingBelt.h"
#include "GameMap.h"
#include "Common.h"

using std::list;
using BCE = std::pair<Item, float>;

class BalancerContext;

class BuildingBalancer;

class BalancerContext : public BuildingContext
{
	friend BuildingBalancer;

private:
	list<BCE> queue;
	int outputIndex = 0;
	float outputWaiting = 0;

	/**
	 * ƽ�����пɻ���������Ʒ����
	 */
	int maxItemCached = 6;
	/**
	 * �������֮����С��� s
	 */
	float outputDelay = 0.3f;
	/**
	 * ��Ʒ��ƽ��������̵�ʱ�� s
	 */
	float itemDelay = 0.3f;
};

/**
 * ƽ�����������������룬�����������Ʒ������һ��������������
 */
class BuildingBalancer : Building
{
public:
	bool can_place(const ivec2& pos, Side direction, ivec2* prev, const GameMap& map) const override;

	PlaceState place_at(BuildingContext& context, GameMap& map) const override;

	bool can_receive(Item& item, ivec2& pos, Side side, BuildingContext& context) const
	{
		return can_receive(item, pos, side, cast(context));
	}

	void receive(Item& item, ivec2& pos, Side side, BuildingContext& context) const
	{
		receive(item, pos, side, cast(context));
	}

	void update(BuildingContext& context, const GameMap& map) const override
	{
		update(cast(context), map);
	}

private:
	static BalancerContext& cast(BuildingContext& context)
	{
		return static_cast<BalancerContext&>(context);
	}

	bool can_receive(Item& item, ivec2& pos, Side side, BalancerContext& context) const;

	void receive(Item& item, ivec2& pos, Side side, BalancerContext& context) const;

	void update(BalancerContext& context, const GameMap& map) const;
};
