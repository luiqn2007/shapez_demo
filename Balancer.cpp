#include "Balancer.h"

#include "ItemType.h"
#include "BalancerRenderer.h"

BuildingContext* Balancer::build_context(const Vec2I& pos, const Side direction) const
{
	return new BalancerContext(*this, pos, direction);
}

bool Balancer::can_receive(const Vec2I& pos, const Side side, const BuildingContext& context) const
{
	return side == opposite(context.direction);
}

bool Balancer::can_receive_dye(Color color, const Vec2I& pos, Side side, const BuildingContext& context) const
{
	return can_receive(side, context);
}

bool Balancer::can_receive_shape(const ColoredShapes& shape, const Vec2I& pos, Side side,
                                 const BuildingContext& context) const
{
	return can_receive(side, context);
}

void Balancer::receive_dye(const Color color, const Vec2I& pos, Side side, BuildingContext& context) const
{
	auto& ctx = cast(context);
	ctx.colors_.push(color);
	ctx.types_.push(ItemType::dye);
}

void Balancer::receive_shape(const ColoredShapes& shape, const Vec2I& pos, Side side,
                             BuildingContext& context) const
{
	auto& ctx = cast(context);
	ctx.shapes_.push(shape);
	ctx.types_.push(ItemType::shape);
}

void Balancer::free_context(BuildingContext* context) const
{
	delete static_cast<BalancerContext*>(context);
}

const BuildingRenderer& Balancer::get_renderer() const
{
	static BalancerRenderer renderer;
	return renderer;
}

vector<Vec2I> Balancer::all_positions(const Vec2I& pos, const Side direction) const
{
	vector<Vec2I> p;
	p.push_back(pos);
	p.push_back(pos + ~direction);
	return p;
}

bool Balancer::can_start(const TickableContext& context) const
{
	return !cast(context).types_.empty();
}

bool Balancer::on_blocking(TickableContext& context, const GameMap& map) const
{
	auto& ctx = cast(context);
	send_first_item(ctx, map);
	return ctx.types_.size() < ctx.max_items_;
}

bool Balancer::can_receive(const Side side, const BuildingContext& context) const
{
	const auto& ctx = cast(context);
	return side == opposite(context.direction) && ctx.types_.size() != ctx.max_items_;
}

void Balancer::send_first_item(BalancerContext& context, const GameMap& map)
{
	const auto& type = context.types_.front();
	if (context.side_ == 0)
	{
		if (type == ItemType::dye)
		{
			if (send_dye(context.pos, context.direction, context.colors_.front(), map))
			{
				context.types_.pop();
				context.colors_.pop();
				// 交替输出
				context.side_ = !context.side_;
			}
			else if (send_dye(context.pos + ~context.direction, context.direction, context.colors_.front(), map))
			{
				context.types_.pop();
				context.colors_.pop();
			}
		}
		else
		{
			if (send_shape(context.pos, context.direction, context.shapes_.front(), map))
			{
				context.types_.pop();
				context.shapes_.pop();
				// 交替输出
				context.side_ = !context.side_;
			}
			else if (send_shape(context.pos + ~context.direction, context.direction, context.shapes_.front(), map))
			{
				context.types_.pop();
				context.shapes_.pop();
			}
		}
	}
	else
	{
		if (type == ItemType::dye)
		{
			if (send_dye(context.pos + ~context.direction, context.direction, context.colors_.front(), map))
			{
				context.types_.pop();
				context.colors_.pop();
				// 交替输出
				context.side_ = !context.side_;
			}
			else if (send_dye(context.pos, context.direction, context.colors_.front(), map))
			{
				context.types_.pop();
				context.colors_.pop();
			}
		}
		else
		{
			if (send_shape(context.pos + ~context.direction, context.direction, context.shapes_.front(), map))
			{
				context.types_.pop();
				context.shapes_.pop();
				// 交替输出
				context.side_ = !context.side_;
			}
			else if (send_shape(context.pos, context.direction, context.shapes_.front(), map))
			{
				context.types_.pop();
				context.shapes_.pop();
			}
		}
	}
}
