#pragma once

#include "Building.h"
#include "Common.h"

class BuildingHub;

class HubContext : public BuildingContext
{
public:
	/**
	 * \brief ��������
	 */
	int total_count;

	/**
	 * \brief ������Ʒ
	 */
	Item item;

	/**
	 * \brief �ѽ�����Ʒ����
	 */
	int accept_count = 0;

	/**
	 * \brief �ȼ�
	 */
	int level = 1;

	HubContext(const Building& building, const ivec2& pos, const Side direction, const int total_count, Item item)
		: BuildingContext(building, pos, direction), total_count(total_count), item(std::move(item))
	{
	}
};

class BuildingHub : public Building
{
public:
	explicit BuildingHub()
		: Building({4, 4})
	{
	}

	bool can_receive(const ivec2& pos, Side side, const BuildingContext& context) const override;
	bool can_receive_item(const Item& item, const ivec2& pos, Side side, const BuildingContext& context) const override;
	void receive(Item item, const ivec2& pos, Side side, BuildingContext& context) const override;
	void update(BuildingContext& context, const GameMap& map) const override;

private:
	static HubContext& cast(BuildingContext& context)
	{
		return static_cast<HubContext&>(context);
	}

	static void set_next_level(HubContext& context);
};
