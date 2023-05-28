#pragma once

#include <vector>
#include <memory>

#include "vec.h"

#include "GameMap.h"
#include "BuildingSize.h"
#include "BuildingContext.h"
#include "ColoredShapes.h"

using std::vector;
using std::unique_ptr;

enum class ItemType;
enum class Color;

/**
 * \brief �������ͣ�ֻ���潨������Ϊ�������潨������
 */
class Building
{
public:
	/**
	 * \brief ������С 
	 */
	BuildingSize size;

	/**
	 * \brief �����Ƿ�����������
	 * \param pos ��������λ��
	 * \param direction ��������
	 * \param map ��ͼ
	 */
	[[nodiscard]]
	bool can_place(const Vec2I& pos, Side direction, const GameMap& map) const;

	/**
	 * \brief ���ݽ�����������
	 * \param pos ����λ��
	 * \param direction ����
	 * \return ����
	 */
	[[nodiscard]]
	virtual BuildingContext build_context(const Vec2I& pos, Side direction) const = 0;

	/**
	 * \brief �ж϶�Ӧλ���Ƿ���ܽ�����Ʒ���룬���ڴ��ʹ��ȿ����ӽ������
	 * \param pos Ŀ�굥Ԫ
	 * \param side ���뷽��
	 * \param context ��������
	 */
	[[nodiscard]]
	virtual bool can_receive(const Vec2I& pos, Side side, const BuildingContext& context) const = 0;

	/**
	 * \brief �ж϶�Ӧλ���Ƿ��������ĳȾ�ϣ�����ʵ����Ʒ����У��
	 * \param color �����Ⱦ��
	 * \param pos Ŀ�굥Ԫ
	 * \param side ���뷽��
	 * \param context ��������
	 */
	[[nodiscard]]
	virtual bool can_receive_dye(Color color, const Vec2I& pos, Side side, const BuildingContext& context) const = 0;

	/**
	 * \brief �ж϶�Ӧλ���Ƿ��������ĳͼ�Σ�����ʵ����Ʒ����У��
	 * \param shape �������Ʒ
	 * \param pos Ŀ�굥Ԫ
	 * \param side ���뷽��
	 * \param context ��������
	 */
	[[nodiscard]]
	virtual bool can_receive_shape(const ColoredShapes& shape, const Vec2I& pos, Side side, const BuildingContext& context) const = 0;

	/**
	 * \brief ����������ʱ����
	 * \param context ���µĽ���
	 */
	virtual void on_placed(BuildingContext& context)
	{
	}

	/**
	 * \brief ��ĳλ�ý���Ⱦ�ϣ����ø÷���֮ǰӦ����֤ͨ�� can_receive_dye ����
	 * \param color ������Ʒ
	 * \param pos Ŀ�굥Ԫ
	 * \param side ���뷽��
	 * \param context ��������
	 */
	virtual void receive_dye(Color color, const Vec2I& pos, Side side, BuildingContext& context) const = 0;

	/**
	 * \brief ��ĳλ�ý���ͼ����Ʒ�����ø÷���֮ǰӦ����֤ͨ�� can_receive_shape ����
	 * \param shape ������Ʒ
	 * \param pos Ŀ�굥Ԫ
	 * \param side ���뷽��
	 * \param context ��������
	 */
	virtual void receive_shape(const ColoredShapes& shape, const Vec2I& pos, Side side, BuildingContext& context) const = 0;

	/**
	 *\brief ���½���״̬
	 */
	virtual void update(BuildingContext& context, GameMap& map) const = 0;
	
	/**
	 * \brief ��������Сö��ת��Ϊ Vec2I ��ʾ�Ĵ�С
	 * \param size ������С
	 * \return �� Vec2I ��ʽ��ʾ�Ľ�����С
	 */
	static Vec2I size_as_vec(BuildingSize size);

	/**
	 * \brief ��ȡ����ռ�õ����з���
	 * \param pos ��������λ��
	 * \param size ������С
	 * \param direction ��������
	 * \return ���з���
	 */
	static vector<Vec2I> all_positions(const Vec2I& pos, BuildingSize size, Side direction);

	/**
	 * \brief ������ĳ��������Ⱦ��
	 * \param pos ������
	 * \param direction ���ͷ���
	 * \param color ����Ⱦ��
	 * \param map ��ͼ
	 * \return �Ƿ�ɹ�����
	 */
	static bool send_dye(const Vec2I& pos, Side direction, Color color, const GameMap& map);

	/**
	 * \brief ������ĳ����������Ʒ
	 * \param pos ������
	 * \param direction ���ͷ���
	 * \param shape ������״
	 * \param map ��ͼ
	 * \return �Ƿ�ɹ�����
	 */
	static bool send_shape(const Vec2I& pos, Side direction, const ColoredShapes& shape, const GameMap& map);

protected:
	/**
	 * \brief �������Ĺ��캯�������ɶ�Ӧ���ʹ���
	 * \param size ������С
	 */
	explicit Building(const BuildingSize size) : size(size)
	{
	}

public:
	Building(const Building&) = delete;

	Building(Building&&) = delete;

	virtual ~Building() = default;

	Building& operator=(const Building&) = delete;

	Building& operator=(const Building&&) = delete;
};
