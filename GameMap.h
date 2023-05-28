#pragma once

#include <string>
#include <memory>
#include <functional>

#include "Common.h"
#include "ResourceType.h"
#include "vec.h"

using std::string;
using std::function;
using std::unique_ptr;

class BuildingContext;

/**
 * \brief ��Ϸ��ͼ
 */
class GameMap
{
public:
	/**
	 * \brief ��Ļ�е��Ӧ�� center.x �У��� center.y ��
	 */
	Vec2 center{CELL_COUNT / 2.0f, CELL_COUNT / 2.0f};

	/**
	 * \brief ÿһ����Ԫ��ĳ���
	 */
	float cell_size = 100;

	GameMap();

	/**
	 * \brief ��ʼ��
	 */
	void initialize();

	[[nodiscard]]
	ResourceType get_resource(int x, int y) const;

	[[nodiscard]]
	ResourceType get_resource(const Vec2I& pos) const
	{
		return get_resource(pos.x, pos.y);
	}

	void set_building(BuildingContext* context);

	[[nodiscard]]
	BuildingContext* get_building(int x, int y) const;

	[[nodiscard]]
	BuildingContext* get_building(const Vec2I& pos) const
	{
		return get_building(pos.x, pos.y);
	}

	void update_cell_size_and_position();

private:
	/**
	 * \brief ��ͼ��Դ
	 */
	ResourceType resources_[CELL_COUNT][CELL_COUNT]{};

	/**
	 * \brief ��ͼ����
	 */
	BuildingContext* buildings_[CELL_COUNT][CELL_COUNT]{};
};
