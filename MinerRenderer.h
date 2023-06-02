#pragma once
#include "BuildingRenderer.h"

class MinerRenderer final : public BuildingRenderer
{
public:
	void draw_building(int row, int col, const BuildingContext& context, GameRenderer& renderer,
	                   const GameMap& map) const override;
	void draw_holding(float x, float y, Side direction, GameRenderer& renderer, const GameMap& map) const override;
	void draw_icon(float x, float y, float size, GameRenderer& renderer) const override;
	void draw_overlay(int row, int col, const BuildingContext& context, GameRenderer& renderer,
	                  const GameMap& map) const override;

private:
	static Vec2 offset_item(Side direction, float cell_size, float p, float x0, float y0);
};
