#include "TickableBuilding.h"

#include "GameLogic.h"

void TickableBuilding::update(BuildingContext& context, GameMap& map) const
{
	switch (auto& ctx = cast(context); ctx.status_)
	{
	case BuildingStatus::waiting:

		if (can_start(ctx, map))
		{
			// ��ʼ����
			ctx.current_time_ = 0;
			ctx.status_ = BuildingStatus::running;
		}
		break;

	case BuildingStatus::running:

		ctx.current_time_ += current_game->timer().delta_ms;
		if (ctx.current_time_ >= ctx.required_time_)
		{
			// �������
			if (on_finished(ctx, map))
			{
				// �������״̬
				ctx.status_ = BuildingStatus::waiting;
			}
			else
			{
				// ��������״̬
				ctx.status_ = BuildingStatus::blocking;
			}
		}
		break;

	case BuildingStatus::blocking:

		if (on_blocking(ctx, map))
		{
			// �������״̬
			ctx.status_ = BuildingStatus::waiting;
		}
		break;
	}
}
