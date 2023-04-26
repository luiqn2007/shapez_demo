#pragma once

#include <vector>

#include "Common.h"

using std::vector;

class GameMap;
class Building;
class Item;

/**
 * ��ʾ����ʱ��״̬, NEXT ��Ҫ���ڵ��´��ʹ����
 */
enum class PlaceState
{
	// �������
	PLACED,
	// �׶��Է������
	NEXT,
	// ����ʧ��
	FAILED
};

/**
 * �����ڵ�ͼ�ϵ�����
 */
class BuildingContext
{
public:
	// ��������
	const Building& building;
	// ����λ��
	ivec2 pos;
	// ����
	Side direction;
	// ����ʱ�䣬���һ�θ���ʱ�䣬���¼��
	long long timePlacer, timeUpdate, timeDelta;
	// ռ�õ�����λ��
	vector<ivec2> all;

	BuildingContext(const Building& building, const ivec2& pos, Side direction, long long timePlacer,
	                long long timeUpdate, long long timeDelta, const vector<ivec2>& all) : building(building),
		pos(pos),
		direction(direction),
		timePlacer(timePlacer),
		timeUpdate(timeUpdate),
		timeDelta(timeDelta),
		all(all)
	{
	}
};

/**
 * �������ͣ�ֻ���潨������Ϊ�������潨������
 */
class Building
{
public:
	/**
	 * �����Ƿ�����������
	 * @param prev ����Ҫ��׶η��õ�����£���¼�ϴη��õ�λ�ã�����Ϊ nullptr
	 */
	virtual bool can_place(const ivec2& pos, Side direction, ivec2* prev, const GameMap& map) const = 0;

	/**
	 * ִ�з��ò���
	 */
	virtual PlaceState place_at(BuildingContext& context, GameMap& map) const = 0;

	/**
	 * �ж϶�Ӧλ���Ƿ���Խ���ĳ��Ʒ������
	 */
	virtual bool can_receive(Item& item, ivec2& pos, Side side, BuildingContext& context) const = 0;

	/**
	 * ��ĳλ�ý�����Ʒ
	 */
	virtual void receive(Item& item, ivec2& pos, Side side, BuildingContext& context) const = 0;

	/**
	 * ���¹���״̬
	 */
	virtual void update(BuildingContext& context, const GameMap& map) const = 0;
};
