#include "PainterRenderer.h"

#include "BuildingContext.h"
#include "GameLogic.h"
#include "GameRenderer.h"
#include "Painter.h"

void PainterRenderer::draw_building(const int row, const int col, const BuildingContext& context,
                                    GameRenderer& renderer, const GameMap& map) const
{
	const float x0 = renderer.edge_pos[col].x;
	const float y0 = renderer.edge_pos[row].y;
	const float x1 = renderer.edge_pos[col + 2].x;
	const float y1 = renderer.edge_pos[row + 1].y;
	renderer.tex_drawer.push(x0 - EXT_SIZE, y0 - EXT_SIZE, x1 + EXT_SIZE, y1 + EXT_SIZE, renderer.atlas, "painter.png",
	                         context.direction);
}

void PainterRenderer::draw_holding(const float x, const float y, const Side direction, GameRenderer& renderer,
                                   const GameMap& map) const
{
	renderer.tex_drawer.push(x - EXT_SIZE, y - EXT_SIZE, x + map.cell_size * 2 + EXT_SIZE, y + map.cell_size + EXT_SIZE,
	                         renderer.atlas, "painter_blue.png", direction);
}

void PainterRenderer::draw_icon(const float x, const float y, float size, GameRenderer& renderer) const
{
	renderer.tex_drawer.push(x + ICON_PADDING, y + ICON_PADDING,
	                         x + BUTTON_SIZE - ICON_PADDING, y + BUTTON_SIZE - ICON_PADDING,
	                         renderer.atlas, "painter_icon.png", Side::up);
}

void PainterRenderer::draw_items_in_building(int row, int col, const BuildingContext& context, GameRenderer& renderer,
                                             const GameMap& map) const
{
	const auto& ctx = Painter::cast(context);
	draw_output_item(ctx.right_pos_.x, ctx.right_pos_.y, map.cell_size, cw(context.direction), renderer, ctx.shapes_, ctx);
}
