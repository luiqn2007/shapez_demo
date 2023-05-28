#pragma once

#include "Timer.h"

#include "Building.h"
#include "BuildingContext.h"

constexpr time_ms FAST = 500;
constexpr time_ms MIDDLE = 1000;
constexpr time_ms SLOW = 2000;

enum class BuildingStatus
{
	/**
	 * \brief ״̬�����У�����������벻�㣩
	 */
	waiting,

	/**
	 * \brief ״̬��������
	 */
	running,

	/**
	 * \brief ״̬�������������޷���ȫ�����
	 */
	blocking
};

class TickableBuilding;

class TickableContext : public BuildingContext
{
	friend TickableBuilding;

public:
	TickableContext(const Building& building, const Vec2I& pos, const Side direction, const time_ms required_time)
		: BuildingContext(building, pos, direction), required_time_(required_time)
	{
	}

protected:
	/**
	 * \brief ��ǰ����״̬
	 */
	BuildingStatus status_ = BuildingStatus::waiting;

	/**
	 * \brief ��ǰִ��ʱ��
	 */
	time_ms current_time_ = 0;

	/**
	 * \brief ��Ҫ����ʱ��
	 */
	const time_ms required_time_;
};


/**
 * \brief ��Ҫʱ�䴦��Ľ�������
 */
class TickableBuilding : public Building
{
public:
	void update(BuildingContext& context, GameMap& map) const override;

protected:
	explicit TickableBuilding(const BuildingSize size): Building(size)
	{
	}

	/**
	 * \brief ����Ƿ��������
	 */
	virtual bool can_start(TickableContext& context, const GameMap& map) const = 0;

	/**
	 * \brief ÿ�ε���������״̬ʱ����Ϊ
	 * \return ������ true�����ʾ����״̬����
	 */
	virtual bool on_blocking(TickableContext& context, const GameMap& map) const = 0;

	/**
	 * \brief ��һ�ֲ�������ʱ����Ϊ
	 * \return ������ false�����������״̬
	 */
	virtual bool on_finished(TickableContext& context, const GameMap& map) const = 0;

	static TickableContext& cast(BuildingContext& context)
	{
		return static_cast<TickableContext&>(context);
	}
};
