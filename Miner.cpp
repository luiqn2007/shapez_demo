#include "Miner.h"

#include "Color.h"
#include "ColoredShapes.h"
#include "GameLogic.h"
#include "MinerRenderer.h"

BuildingContext* Miner::build_context(const Vec2I& pos, const Side direction) const
{
	return new TickableContext(*this, pos, direction, SLOW);
}

bool Miner::can_receive(const Vec2I& pos, Side side, const BuildingContext& context) const
{
	return false;
}

bool Miner::can_receive_dye(Color color, const Vec2I& pos, Side side, const BuildingContext& context) const
{
	return false;
}

bool Miner::can_receive_shape(const ColoredShapes& shape, const Vec2I& pos, Side side,
                                      const BuildingContext& context) const
{
	return false;
}

void Miner::receive_dye(Color color, const Vec2I& pos, Side side, BuildingContext& context) const
{
}

void Miner::receive_shape(const ColoredShapes& shape, const Vec2I& pos, Side side,
                                  BuildingContext& context) const
{
}

void Miner::free_context(BuildingContext* context) const
{
	delete context;
}

const BuildingRenderer& Miner::get_renderer() const
{
	static MinerRenderer renderer;
	return renderer;
}

vector<Vec2I> Miner::all_positions(const Vec2I& pos, Side direction) const
{
	vector<Vec2I> p;
	p.push_back(pos);
	return p;
}

bool Miner::can_start(const TickableContext& context) const
{
	return current_game && current_game->map().get_resource(context.pos) != ResourceType::none;
}

bool Miner::on_blocking(TickableContext& context, const GameMap& map) const
{
	switch (const ResourceType res = map.get_resource(context.pos))
	{
	case ResourceType::none:
		return true;
	case ResourceType::color_red:
		return send_dye(context.pos, context.direction, Color::red, map);
	case ResourceType::color_blue:
		return send_dye(context.pos, context.direction, Color::blue, map);
	case ResourceType::color_green:
		return send_dye(context.pos, context.direction, Color::green, map);
	default:
		return send_shape(context.pos, context.direction, ColoredShapes::from_resource(res), map);
	}
}
