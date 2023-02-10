#include "../tomb5/pch.h"
#include "box.h"
#include "lot.h"
#include "../specific/3dmath.h"
#include "lara_states.h"
#include "../specific/function_stubs.h"
#include "draw.h"
#include "control.h"
#include "items.h"
#include "tomb4fx.h"
#include "objects.h"
#include "deltapak.h"

void InitialiseCreature(short item_number)
{
	ITEM_INFO* item;

	item = &items[item_number];
	item->collidable = 1;
	item->data = 0;
	item->draw_room = ((item->pos.x_pos - room[item->room_number].x) >> 10 & 0xFF) << 8 | ((item->pos.z_pos - room[item->room_number].z) >> 10 & 0xFF);
	item->item_flags[2] = item->pos.y_pos - room[item->room_number].minfloor & 0xFF00 | item->room_number & 0xFF;
	item->TOSSPAD = item->pos.y_rot & 0xE000;
}

long CreatureActive(short item_number)
{
	ITEM_INFO* item;

	item = &items[item_number];

	if (item->flags & IFL_CLEARBODY)
		return 0;

	if (item->status == 3)
	{
		if (!EnableBaddieAI(item_number, 0))
			return 0;

		item->status = 1;
	}

	return 1;
}

void CreatureAIInfo(ITEM_INFO* item, AI_INFO* info)
{
	CREATURE_INFO* creature;
	OBJECT_INFO* obj;
	ITEM_INFO* enemy;
	ROOM_INFO* r;
	FLOOR_INFO* floor;
	short* zone;
	long x, y, z;
	short pivot, ang, state;

	creature = (CREATURE_INFO*)item->data;

	if (!creature)
		return;

	obj = &objects[item->object_number];
	enemy = creature->enemy;

	if (!enemy)
	{
		enemy = lara_item;
		creature->enemy = lara_item;
	}

	zone = ground_zone[creature->LOT.zone][flip_status];
	r = &room[item->room_number];
	floor = &r->floor[((item->pos.z_pos - r->z) >> 10) + r->x_size * ((item->pos.x_pos - r->x) >> 10)];
	item->box_number = floor->box;
	info->zone_number = zone[item->box_number];

	r = &room[enemy->room_number];
	floor = &r->floor[((enemy->pos.z_pos - r->z) >> 10) + r->x_size * ((enemy->pos.x_pos - r->x) >> 10)];
	enemy->box_number = floor->box;
	info->enemy_zone = zone[enemy->box_number];

	if (boxes[enemy->box_number].overlap_index & creature->LOT.block_mask ||
		creature->LOT.node[item->box_number].search_number == (creature->LOT.search_number | 0x8000))
		info->enemy_zone |= 0x4000;

	pivot = obj->pivot_length;

	if (enemy == lara_item)
		ang = lara.move_angle;
	else
		ang = enemy->pos.y_rot;

	x = enemy->pos.x_pos + (14 * enemy->speed * phd_sin(ang) >> 14) - (pivot * phd_sin(item->pos.y_rot) >> 14) - item->pos.x_pos;
	y = item->pos.y_pos - enemy->pos.y_pos;
	z = enemy->pos.z_pos + (14 * enemy->speed * phd_cos(ang) >> 14) - (pivot * phd_cos(item->pos.y_rot) >> 14) - item->pos.z_pos;

	ang = (short)phd_atan(z, x);

	if (z > 32000 || z < -32000 || x > 32000 || x < -32000)
		info->distance = 0x7FFFFFFF;
	else if (creature->enemy)
		info->distance = SQUARE(x) + SQUARE(z);
	else
		info->distance = 0x7FFFFFFF;

	info->angle = ang - item->pos.y_rot;
	info->enemy_facing = ang - enemy->pos.y_rot + 0x8000;

	x = abs(x);
	z = abs(z);

	if (enemy == lara_item)
	{
		state = lara_item->current_anim_state;

		if (state == AS_DUCK || state == AS_DUCKROLL || (state > AS_MONKEY180 && state < AS_HANG2DUCK) || state == AS_DUCKROTL || state == AS_DUCKROTR )
			y -= 384;
	}

	if (x > z)
		info->x_angle = (short)phd_atan(x + (z >> 1), y);
	else
		info->x_angle = (short)phd_atan(z + (x >> 1), y);

	info->ahead = info->angle > -0x4000 && info->angle < 0x4000;
	info->bite = info->ahead && enemy->hit_points > 0 && abs(enemy->pos.y_pos - item->pos.y_pos) <= 512;
}

long SearchLOT(LOT_INFO* LOT, long expansion)
{
	BOX_NODE* node;
	BOX_NODE* expand;
	BOX_INFO* box;
	short* zone;
	long index, done, box_number, overlap_flags, change;
	short search_zone;

	zone = ground_zone[LOT->zone][flip_status];
	search_zone = zone[LOT->head];

	for (int i = 0; i < expansion; i++)
	{
		if (LOT->head == 2047)
		{
			LOT->tail = 2047;
			return 0;
		}

		box = &boxes[LOT->head];
		node = &LOT->node[LOT->head];
		index = box->overlap_index & 0x3FFF;
		done = 0;

		do
		{
			box_number = overlap[index];
			index++;
			overlap_flags = box_number & ~2047;

			if (box_number & 0x8000)
				done = 1;

			box_number &= 2047;

			if (!LOT->fly && search_zone != zone[box_number])	//zone isn't in search area + can't fly
				continue;

			change = boxes[box_number].height - box->height;

			if ((change > LOT->step || change < LOT->drop) && (!(overlap_flags & 0x2000) || !LOT->can_monkey))	//can't traverse block + can't monkey
				continue;

			if (overlap_flags & 0x800 && !LOT->can_jump)	//can't jump
				continue;

			expand = &LOT->node[box_number];

			if ((node->search_number & 0x7FFF) < (expand->search_number & 0x7FFF))
				continue;

			if (node->search_number & 0x8000)
			{
				if ((node->search_number & 0x7FFF) == (expand->search_number & 0x7FFF))
					continue;

				expand->search_number = node->search_number;
			}
			else
			{
				if ((node->search_number & 0x7FFF) == (expand->search_number & 0x7FFF) && !(expand->search_number & 0x8000))
					continue;

				if (boxes[box_number].overlap_index & LOT->block_mask)
					expand->search_number = node->search_number | 0x8000;
				else
				{
					expand->search_number = node->search_number;
					expand->exit_box = LOT->head;
				}
			}

			if (expand->next_expansion == 2047 && box_number != LOT->tail)
			{
				LOT->node[LOT->tail].next_expansion = (short)box_number;
				LOT->tail = (short)box_number;
			}

		} while (!done);

		LOT->head = node->next_expansion;
		node->next_expansion = 2047;
	}

	return 1;
}

long UpdateLOT(LOT_INFO* LOT, long expansion)
{
	BOX_NODE* expand;

	if (LOT->required_box != 2047 && LOT->required_box != LOT->target_box)
	{
		LOT->target_box = LOT->required_box;
		expand = &LOT->node[LOT->required_box];

		if (expand->next_expansion == 2047 && LOT->tail != LOT->required_box)
		{
			expand->next_expansion = LOT->head;

			if (LOT->head == 2047)
				LOT->tail = LOT->target_box;

			LOT->head = LOT->target_box;
		}

		LOT->search_number++;
		expand->search_number = LOT->search_number;
		expand->exit_box = 2047;
	}

	return SearchLOT(LOT, expansion);
}

void TargetBox(LOT_INFO* LOT, short box_number)
{
	BOX_INFO* box;

	box = &boxes[box_number & 0x7FF];
	LOT->target.x = (((ulong)box->bottom - (ulong)box->top - 1) >> 5) * GetRandomControl() + ((ulong)box->top << 10) + 512;
	LOT->target.z = (((ulong)box->right - (ulong)box->left - 1) >> 5) * GetRandomControl() + ((ulong)box->left << 10) + 512;
	LOT->required_box = box_number & 0x7FF;

	if (LOT->fly)
		LOT->target.y = box->height - 384;
	else
		LOT->target.y = box->height;
}

long EscapeBox(ITEM_INFO* item, ITEM_INFO* enemy, short box_number)
{
	BOX_INFO* box;
	long x, z;

	box = &boxes[box_number];
	x = (((ulong)box->bottom + (ulong)box->top) << 9) - enemy->pos.x_pos;
	z = (((ulong)box->left + (ulong)box->right) << 9) - enemy->pos.z_pos;

	if (x > -5120 && x < 5120 && z > -5120 && z < 5120)
		return 0;

	return z > 0 == item->pos.z_pos > enemy->pos.z_pos || x > 0 == item->pos.x_pos > enemy->pos.x_pos;
}

long ValidBox(ITEM_INFO* item, short zone_number, short box_number)
{
	CREATURE_INFO* creature;
	BOX_INFO* box;

	creature = (CREATURE_INFO*)item->data;

	if (!creature->LOT.fly && ground_zone[creature->LOT.zone][flip_status][box_number] != zone_number)
		return 0;

	box = &boxes[box_number];

	if (creature->LOT.block_mask & box->overlap_index)
		return 0;

	if (item->pos.z_pos > box->left << 10 && item->pos.z_pos < box->right << 10 &&
		item->pos.x_pos > box->top << 10 && item->pos.x_pos < box->bottom << 10)
		return 0;

	return 1;
}

long StalkBox(ITEM_INFO* item, ITEM_INFO* enemy, short box_number)
{
	BOX_INFO* box;
	long x, z, xrange, zrange, enemy_quad, box_quad, baddie_quad;

	if (!enemy)
		return 0;

	box = &boxes[box_number];
	x = (((ulong)box->bottom + (ulong)box->top) << 9) - enemy->pos.x_pos;
	z = (((ulong)box->left + (ulong)box->right) << 9) - enemy->pos.z_pos;
	xrange = ((ulong)box->bottom - (ulong)box->top + 3) << 10;	//3 is the # of blocks
	zrange = ((ulong)box->right - (ulong)box->left + 3) << 10;

	if (x > xrange || x < -xrange || z > zrange || z < -zrange)
		return 0;

	enemy_quad = (enemy->pos.y_rot >> 14) + 2;
	box_quad = z <= 0 ? (x <= 0 ? 0 : 3) : (x > 0) + 1;

	if (enemy_quad == box_quad)
		return 0;

	baddie_quad = item->pos.z_pos <= enemy->pos.z_pos ? (item->pos.x_pos <= enemy->pos.x_pos ? 0 : 3) : (item->pos.x_pos > enemy->pos.x_pos) + 1;
	return enemy_quad != baddie_quad || abs(enemy_quad - box_quad) != 2;
}

target_type CalculateTarget(PHD_VECTOR* target, ITEM_INFO* item, LOT_INFO* LOT)
{
	BOX_INFO* box;
	long box_number, box_left, box_right, box_top, box_bottom;
	long left, right, top, bottom, prime_free;
	static ushort loops;

	UpdateLOT(LOT, 5);
	target->x = item->pos.x_pos;
	target->y = item->pos.y_pos;
	target->z = item->pos.z_pos;
	box_number = item->box_number;

	if (box_number == 2047)
		return NO_TARGET;

	box = &boxes[box_number];
	left = box->left << 10;
	right = (box->right << 10) - 1;
	top = box->top << 10;
	bottom = (box->bottom << 10) - 1;
	loops = 0;
	prime_free = 15;

	do
	{
		loops++;
		box = &boxes[box_number];

		if (LOT->fly)
		{
			if (target->y > box->height - 1024)
				target->y = box->height - 1024;
		}
		else if (target->y > box->height)
			target->y = box->height;

		box_left = box->left << 10;
		box_right = (box->right << 10) - 1;
		box_top = box->top << 10;
		box_bottom = (box->bottom << 10) - 1;

		if (item->pos.z_pos >= box_left && item->pos.z_pos <= box_right && item->pos.x_pos >= box_top && item->pos.x_pos <= box_bottom)
		{
			left = box->left << 10;
			right = (box->right << 10) - 1;
			top = box->top << 10;
			bottom = (box->bottom << 10) - 1;
		}
		else
		{
			if (item->pos.z_pos < box_left && prime_free != 2)
			{
				if (prime_free & 1 && item->pos.x_pos >= box_top && item->pos.x_pos <= box_bottom)
				{
					if (target->z < box_left + 512)
						target->z = box_left + 512;

					if (prime_free & 16)
						return SECONDARY_TARGET;

					if (box_top > top)
						top = box_top;

					if (box_bottom < bottom)
						bottom = box_bottom;

					prime_free = 1;
				}
				else if (prime_free != 1)
				{
					target->z = right - 512;

					if (prime_free != 15)
						return SECONDARY_TARGET;

					prime_free = 31;
				}
			}
			else if (item->pos.z_pos > box_right && prime_free != 1)
			{
				if (prime_free & 2 && item->pos.x_pos >= box_top && item->pos.x_pos <= box_bottom)
				{
					if (target->z > box_right - 512)
						target->z = box_right - 512;

					if (prime_free & 16)
						return SECONDARY_TARGET;

					if (box_top > top)
						top = box_top;

					if (box_bottom < bottom)
						bottom = box_bottom;

					prime_free = 2;
				}
				else if (prime_free != 2)
				{
					target->z = left + 512;

					if (prime_free != 15)
						return SECONDARY_TARGET;

					prime_free = 31;
				}
			}

			if (item->pos.x_pos < box_top && prime_free != 8)
			{
				if (prime_free & 4 && item->pos.z_pos >= box_left && item->pos.z_pos <= box_right)
				{
					if (target->x < box_top + 512)
						target->x = box_top + 512;

					if (prime_free & 16)
						return SECONDARY_TARGET;

					if (box_left > left)
						left = box_left;

					if (box_right < right)
						right = box_right;

					prime_free = 4;
				}
				else if (prime_free != 4)
				{
					target->x = bottom - 512;

					if (prime_free != 15)
						return SECONDARY_TARGET;

					prime_free = 31;
				}
			}
			else if (item->pos.x_pos > box_bottom && prime_free != 4)
			{
				if (prime_free & 8 && item->pos.z_pos >= box_left && item->pos.z_pos <= box_right)
				{
					if (target->x > box_bottom - 512)
						target->x = box_bottom - 512;

					if (prime_free & 16)
						return SECONDARY_TARGET;

					if (box_left > left)
						left = box_left;

					if (box_right < right)
						right = box_right;

					prime_free = 8;
				}
				else if (prime_free != 8)
				{
					target->x = top + 512;

					if (prime_free != 15)
						return SECONDARY_TARGET;

					prime_free = 31;
				}
			}
		}

		if (box_number == LOT->target_box)
		{
			if (prime_free & 3)
				target->z = LOT->target.z;
			else if (!(prime_free & 16))
			{
				if (target->z < box_left + 512)
					target->z = box_left + 512;
				else if (target->z > box_right - 512)
					target->z = box_right - 512;
			}

			if (prime_free & 12)
				target->x = LOT->target.x;
			else if (!(prime_free & 16))
			{
				if (target->x < box_top + 512)
					target->x = box_top + 512;
				else if (target->x > box_bottom - 512)
					target->x = box_bottom - 512;
			}

			target->y = LOT->target.y;
			return PRIME_TARGET;
		}

		box_number = LOT->node[box_number].exit_box;

		if (box_number != 2047 && boxes[box_number].overlap_index & LOT->block_mask)
			break;
	}
	while (box_number != 2047);

	if (!(prime_free & 16))
	{
		if (target->z < box_left + 512)
			target->z = box_left + 512;
		else if (target->z > box_right - 512)
			target->z = box_right - 521;
	}

	if (!(prime_free & 16))	//wut
	{
		if (target->x < box_top + 512)
			target->x = box_top + 512;
		else if (target->x > box_bottom - 512)
			target->x = box_bottom - 512;
	}

	if (LOT->fly)
		target->y = box->height - 320;
	else
		target->y = box->height;

	return NO_TARGET;
}

void CreatureMood(ITEM_INFO* item, AI_INFO* info, long violent)
{
	CREATURE_INFO* creature;
	ITEM_INFO* enemy;
	LOT_INFO* LOT;
	static target_type type;
	short index, box_no;

	creature = (CREATURE_INFO*)item->data;

	if (!creature)
		return;

	enemy = creature->enemy;
	LOT = &creature->LOT;

	switch (creature->mood)
	{
	case BORED_MOOD:
		box_no = LOT->node[(creature->LOT.zone_count * GetRandomControl()) >> 15].box_number;

		if (ValidBox(item, info->zone_number, box_no) && !(GetRandomControl() & 0xF))
		{
			if (StalkBox(item, enemy, box_no) && enemy->hit_points > 0 && creature->enemy)
			{
				TargetBox(&creature->LOT, box_no);
				creature->mood = BORED_MOOD;
			}
			else if (creature->LOT.required_box == 2047)
				TargetBox(&creature->LOT, box_no);
		}

		break;

	case ATTACK_MOOD:
		creature->LOT.target.x = enemy->pos.x_pos;
		creature->LOT.target.y = enemy->pos.y_pos;
		creature->LOT.target.z = enemy->pos.z_pos;
		creature->LOT.required_box = enemy->box_number;

		if (creature->LOT.fly && lara.water_status == LW_ABOVE_WATER)
			creature->LOT.target.y += GetBestFrame(enemy)[2];

		break;

	case ESCAPE_MOOD:
		box_no = LOT->node[(creature->LOT.zone_count * GetRandomControl()) >> 15].box_number;

		if (ValidBox(item, info->zone_number, box_no) && creature->LOT.required_box == 2047)
		{
			if (EscapeBox(item, enemy, box_no))
				TargetBox(&creature->LOT, box_no);
			else if (info->zone_number == info->enemy_zone && StalkBox(item, enemy, box_no) && !violent)
			{
				TargetBox(&creature->LOT, box_no);
				creature->mood = STALK_MOOD;
			}
		}

		break;

	case STALK_MOOD:

		if (creature->LOT.required_box == 2047 || !StalkBox(item, enemy, creature->LOT.required_box))
		{
			box_no = LOT->node[(creature->LOT.zone_count * GetRandomControl()) >> 15].box_number;

			if (ValidBox(item, info->zone_number, box_no))
			{
				if (StalkBox(item, enemy, box_no))
					TargetBox(&creature->LOT, box_no);
				else if (creature->LOT.required_box == 2047)
				{
					TargetBox(&creature->LOT, box_no);

					if (info->zone_number != info->enemy_zone)
						creature->mood = BORED_MOOD;
				}
			}
		}

		break;
	}

	if (creature->LOT.target_box == 2047)
		TargetBox(&creature->LOT, item->box_number);

	type = CalculateTarget(&creature->target, item, &creature->LOT);
	creature->jump_ahead = 0;
	creature->monkey_ahead = 0;

	if (LOT->node[item->box_number].exit_box != 2047)
	{
		index = boxes[item->box_number].overlap_index & 0x3FFF;

		do box_no = overlap[index++]; while (box_no != 2047 && box_no >= 0 && (box_no & 0x7FF) != LOT->node[item->box_number].exit_box);

		if ((box_no & 0x7FF) == LOT->node[item->box_number].exit_box)
		{
			if (box_no & 0x800)
				creature->jump_ahead = 1;

			if (box_no & 0x2000)
				creature->monkey_ahead = 1;
		}
	}
}

void GetCreatureMood(ITEM_INFO* item, AI_INFO* info, long violent)
{
	CREATURE_INFO* creature;
	ITEM_INFO* enemy;
	LOT_INFO* LOT;
	mood_type mood;

	creature = (CREATURE_INFO*)item->data;

	if (!creature)
		return;

	LOT = &creature->LOT;
	enemy = creature->enemy;

	if (creature->LOT.node[item->box_number].search_number == (creature->LOT.search_number | 0x8000))
		creature->LOT.required_box = 2047;

	if (creature->mood != ATTACK_MOOD && creature->LOT.required_box != 2047 && !ValidBox(item, info->zone_number, creature->LOT.target_box))
	{
		if (info->zone_number == info->enemy_zone)
			creature->mood = BORED_MOOD;

		creature->LOT.required_box = 2047;
	}

	mood = creature->mood;

	if (enemy)
	{
		if (enemy->hit_points <= 0 && enemy == lara_item)
			creature->mood = BORED_MOOD;
		else if (violent)
		{
			switch (creature->mood)
			{
			case BORED_MOOD:
			case STALK_MOOD:

				if (info->zone_number == info->enemy_zone)
					creature->mood = ATTACK_MOOD;
				else if (item->hit_status)
					creature->mood = ESCAPE_MOOD;

				break;

			case ATTACK_MOOD:

				if (info->zone_number != info->enemy_zone)
					creature->mood = BORED_MOOD;

				break;

			case ESCAPE_MOOD:

				if (info->zone_number == info->enemy_zone)
					creature->mood = ATTACK_MOOD;

				break;
			}
		}
		else
		{
			switch (creature->mood)
			{
			case BORED_MOOD:
			case STALK_MOOD:

				if (creature->alerted && info->zone_number != info->enemy_zone)
					creature->mood = info->distance > 3072 ? STALK_MOOD : BORED_MOOD;
				else if (info->zone_number == info->enemy_zone)
				{
					if (info->distance < 0x900000 || mood == STALK_MOOD && LOT->required_box == 2047)
						creature->mood = ATTACK_MOOD;
					else
						creature->mood = STALK_MOOD;
				}

				break;

			case ATTACK_MOOD:

				if (item->hit_status && (GetRandomControl() < 2048 || info->zone_number != info->enemy_zone))
					creature->mood = STALK_MOOD;
				else if (info->zone_number != info->enemy_zone && info->distance > 6144)
					creature->mood = BORED_MOOD;

				break;

			case ESCAPE_MOOD:

				if (info->zone_number == info->enemy_zone && GetRandomControl() < 256)
					creature->mood = STALK_MOOD;

				break;
			}
		}
	}
	else
		creature->mood = BORED_MOOD;

	if (mood != creature->mood)
	{
		if (mood == ATTACK_MOOD)
			TargetBox(LOT, LOT->target_box);

		LOT->required_box = 2047;
	}
}

long CreatureCreature(short item_number)
{
	ITEM_INFO* item;
	long x, z, dx, dz, dist;
	short yrot, rad, item_num;

	item = &items[item_number];
	x = item->pos.x_pos;
	z = item->pos.z_pos;
	yrot = item->pos.y_rot;
	rad = objects[item->object_number].radius;

	for (item_num = room[item->room_number].item_number; item_num != NO_ITEM; item_num = item->next_item)
	{
		item = &items[item_num];

		if (item_num != item_number && item != lara_item && item->status == ITEM_ACTIVE && item->hit_points > 0)
		{
			dx = abs(item->pos.x_pos - x);
			dz = abs(item->pos.z_pos - z);
			dist = dx > dz ? dx + (dz >> 1) : dz + (dx >> 1);

			if (dist < rad + objects[item->object_number].radius)
				return short(phd_atan(item->pos.z_pos - z, item->pos.x_pos - x) - yrot);
		}
	}

	return 0;
}

long BadFloor(long x, long y, long z, long box_height, long next_height, short room_number, LOT_INFO* LOT)
{
	FLOOR_INFO* floor;
	BOX_INFO* box;

	floor = GetFloor(x, y, z, &room_number);

	if (floor->box == 2047)
		return 1;

	if (LOT->is_jumping)
		return 0;

	box = &boxes[floor->box];

	if (box->overlap_index & LOT->block_mask)
		return 1;

	if (box_height - box->height > LOT->step || box_height - box->height < LOT->drop)
		return 1;

	if (box_height - box->height < -LOT->step && box->height > next_height)
		return 1;

	if (LOT->fly && y > box->height + LOT->fly)
		return 1;

	return 0;
}

void DropBaddyPickups(ITEM_INFO* item)
{
	ITEM_INFO* pickup;
	FLOOR_INFO* floor;
	short pickup_number, room_number;

	pickup_number = item->carried_item;

	while (pickup_number != NO_ITEM)
	{
		pickup = &items[pickup_number];
		pickup->pos.x_pos = (item->pos.x_pos & -512) | 512;
		pickup->pos.z_pos = (item->pos.z_pos & -512) | 512;

		room_number = item->room_number;
		floor = GetFloor(pickup->pos.x_pos, item->pos.y_pos, pickup->pos.z_pos, &room_number);
		pickup->pos.y_pos = GetHeight(floor,pickup->pos.x_pos, item->pos.y_pos, pickup->pos.z_pos);
		pickup->pos.y_pos -= GetBoundsAccurate(pickup)[3];

		ItemNewRoom(pickup_number, item->room_number);
		pickup->flags |= IFL_TRIGGERED;
		pickup_number = pickup->carried_item;
	}
}

void CreatureDie(short item_number, long explode)
{
	ITEM_INFO* item;

	item = &items[item_number];
	item->hit_points = -16384;
	item->collidable = 0;

	if (explode)
	{
		if (objects[item->object_number].HitEffect == 1)
			ExplodingDeath2(item_number, -1, 258);
		else
			ExplodingDeath2(item_number, -1, 256);

		KillItem(item_number);
	}
	else
		RemoveActiveItem(item_number);

	DisableBaddieAI(item_number);
	item->flags |= IFL_INVISIBLE | IFL_CLEARBODY;
	DropBaddyPickups(item);

	if (item->object_number == SCIENTIST && item->ai_bits == 8)
	{
		item = find_a_fucking_item(ROLLINGBALL);

		if (item && !(item->flags & IFL_INVISIBLE))
		{
			item->flags |= IFL_CODEBITS;
			AddActiveItem(item - items);
		}
	}
}

long CreatureAnimation(short item_number, short angle, short tilt)
{
	ITEM_INFO* item;
	CREATURE_INFO* creature;
	LOT_INFO* LOT;
	FLOOR_INFO* floor;
	PHD_VECTOR oldPos;
	short* zone;
	short* bounds;
	long box_height, y, height, next_box, next_height, x, z, wx, wz, xShift, zShift, dy;
	short room_number, rad;

	item = &items[item_number];
	creature = (CREATURE_INFO*)item->data;

	if (!creature)
		return 0;

	LOT = &creature->LOT;
	oldPos.x = item->pos.x_pos;
	oldPos.y = item->pos.y_pos;
	oldPos.z = item->pos.z_pos;
	height = boxes[item->box_number].height;
	zone = ground_zone[LOT->zone][flip_status];
	AnimateItem(item);

	if (item->status == ITEM_DEACTIVATED)
	{
		CreatureDie(item_number, 0);
		return 0;
	}

	bounds = GetBoundsAccurate(item);
	y = item->pos.y_pos + bounds[2];
	room_number = item->room_number;
	GetFloor(oldPos.x, y, oldPos.z, &room_number);
	floor = GetFloor(item->pos.x_pos, y, item->pos.z_pos, &room_number);
	box_height = boxes[floor->box].height;
	next_box = LOT->node[floor->box].exit_box;

	if (next_box == 2047)
		next_height = boxes[floor->box].height;
	else
		next_height = boxes[next_box].height;

	if (floor->box == 2047 || !LOT->is_jumping &&
		(zone[item->box_number] != zone[floor->box] || height - box_height > LOT->step || height - box_height < LOT->drop))
	{
		wx = item->pos.x_pos >> 10;
		wz = item->pos.z_pos >> 10;

		if (wx < oldPos.x >> 10)
			item->pos.x_pos = oldPos.x & ~0x3FF;
		else
			item->pos.x_pos = oldPos.x | 0x3FF;

		if (wz < oldPos.z >> 10)
			item->pos.z_pos = oldPos.z & ~0x3FF;
		else
			item->pos.z_pos = oldPos.z | 0x3FF;

		floor = GetFloor(item->pos.x_pos, y, item->pos.z_pos, &room_number);
		box_height = boxes[floor->box].height;
		next_box = LOT->node[floor->box].exit_box;

		if (next_box == 2047)
			next_height = boxes[floor->box].height;
		else
			next_height = boxes[next_box].height;
	}

	x = item->pos.x_pos;
	z = item->pos.z_pos;
	wx = x & 0x3FF;
	wz = z & 0x3FF;
	rad = objects[item->object_number].radius;
	xShift = 0;
	zShift = 0;

	if (wz < rad)
	{
		if (BadFloor(x, y, z - rad, box_height, next_height, room_number, LOT))
			zShift = rad - wz;

		if (wx < rad)
		{
			if (!BadFloor(x - rad, y, z, box_height, next_height, room_number, LOT))
			{
				if (!zShift && BadFloor(x - rad, y, z - rad, box_height, next_height, room_number, LOT))
				{
					if (item->pos.y_rot > -0x6000 && item->pos.y_rot < 0x2000)
						zShift = rad - wz;
					else
						xShift = rad - wx;
				}
			}
			else
				xShift = rad - wx;
		}
		else if (wx > 1024 - rad)
		{
			if (!BadFloor(x + rad, y, z, box_height, next_height, room_number, LOT))
			{
				if (!zShift && BadFloor(x + rad, y, z - rad, box_height, next_height, room_number, LOT))
				{
					if (item->pos.y_rot > -0x2000 && item->pos.y_rot < 0x6000)
						zShift = rad - wz;
					else
						xShift = 1024 - rad - wx;
				}
			}
			else
				xShift = 1024 - rad - wx;
		}
	}
	else if (wz > 1024 - rad)
	{
		if (BadFloor(x, y, z + rad, box_height, next_height, room_number, LOT))
			zShift = 1024 - rad - wz;

		if (wx < rad)
		{
			if (!BadFloor(x - rad, y, z, box_height, next_height, room_number, LOT))
			{
				if (!zShift && BadFloor(x - rad, y, z + rad, box_height, next_height, room_number, LOT))
				{
					if (item->pos.y_rot > -0x2000 && item->pos.y_rot < 0x6000)
						xShift = rad - wx;
					else
						zShift = 1024 - rad - wz;
				}
			}
			else
				xShift = rad - wx;

		}
		else if (wx > 1024 - rad)
		{
			if (!BadFloor(x + rad, y, z, box_height, next_height, room_number, LOT))
			{
				if (!zShift && BadFloor(x + rad, y, z + rad, box_height, next_height, room_number, LOT))
				{
					if (item->pos.y_rot > -0x6000 && item->pos.y_rot < 0x2000)
						xShift = 1024 - rad - wx;
					else
						zShift = 1024 - rad - wz;
				}
			}
			else
				xShift = 1024 - rad - wx;
		}
	}
	else if (wx < rad)
	{
		if (BadFloor(x - rad, y, z, box_height, next_height, room_number, LOT))
			xShift = rad - wx;
	}
	else if (wx > 1024 - rad)
	{
		if (BadFloor(x + rad, y, z, box_height, next_height, room_number, LOT))
			xShift = 1024 - rad - wx;
	}

	item->pos.x_pos += xShift;
	item->pos.z_pos += zShift;

	if (xShift || zShift)
	{
		floor = GetFloor(item->pos.x_pos, y, item->pos.z_pos, &room_number);
		item->pos.y_rot += angle;

		if (tilt)
			CreatureTilt(item, 2 * tilt);
	}

	if (item->speed && item->hit_points > 0)
	{
		angle = (short)CreatureCreature(item_number);

		if (angle)
		{
			if (abs(angle) < 1536)
				item->pos.y_rot -= angle;
			else if (angle > 0)
				item->pos.y_rot -= 1536;
			else
				item->pos.y_rot += 1536;

			return 1;
		}
	}

	if (LOT->fly && item->hit_points > 0)
	{
		dy = creature->target.y - item->pos.y_pos;

		if (dy > LOT->fly)
			dy = LOT->fly;
		else if (dy < -LOT->fly)
			dy = -LOT->fly;

		height = GetHeight(floor, item->pos.x_pos, y, item->pos.z_pos);

		if (item->pos.y_pos + dy > height)
		{
			if (item->pos.y_pos > height)
			{
				dy = -LOT->fly;
				item->pos.x_pos = oldPos.x;
				item->pos.z_pos = oldPos.z;
			}
			else
			{
				dy = 0;
				item->pos.y_pos = height;
			}
		}
		else if (objects[item->object_number].water_creature)
		{
			height = GetCeiling(floor, item->pos.x_pos, y, item->pos.z_pos);

			if (item->pos.y_pos + bounds[2] + dy < height)
			{
				if (item->pos.y_pos + bounds[2] < height)
				{
					dy = LOT->fly;
					item->pos.x_pos = oldPos.x;
					item->pos.z_pos = oldPos.z;
				}
				else
					dy = 0;
			}
		}
		else
		{
			GetFloor(item->pos.x_pos, y + 256, item->pos.z_pos, &room_number);

			if (room[room_number].flags & ROOM_UNDERWATER)
				dy = -LOT->fly;
		}

		item->pos.y_pos += dy;
		floor = GetFloor(item->pos.x_pos, y, item->pos.z_pos, &room_number);
		item->floor = GetHeight(floor, item->pos.x_pos, y, item->pos.z_pos);

		if (item->speed)
		{
			angle = (short)phd_atan(item->speed, -dy);

			if (angle < -3640)
				angle = -3640;
			else if (angle > 3640)
				angle = 3640;
		}
		else
			angle = 0;

		if (angle < item->pos.x_rot - 182)
			item->pos.x_rot -= 182;
		else  if (angle > item->pos.x_rot + 182)
			item->pos.x_rot += 182;
		else
			item->pos.x_rot = angle;
	}
	else if (LOT->is_jumping)
	{
		floor = GetFloor(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, &room_number);
		item->floor = GetHeight(floor, item->pos.x_pos, item->pos.y_pos, item->pos.z_pos);

		if (LOT->is_monkeying)
			item->pos.y_pos = GetCeiling(floor, item->pos.x_pos, y, item->pos.z_pos) - bounds[2];
		else if (item->pos.y_pos > item->floor)
		{
			if (item->pos.y_pos > item->floor + 256)
			{
				item->pos.x_pos = oldPos.x;
				item->pos.z_pos = oldPos.z;
				item->pos.y_pos = oldPos.y;
			}
			else
				item->pos.y_pos = item->floor;
		}
	}
	else
	{
		floor = GetFloor(item->pos.x_pos, y, item->pos.z_pos, &room_number);
		height = GetCeiling(floor, item->pos.x_pos, y, item->pos.z_pos);

		if (item->pos.y_pos + bounds[2] < height)
		{
			item->pos.x_pos = oldPos.x;
			item->pos.z_pos = oldPos.z;
			item->pos.y_pos = oldPos.y;
		}

		floor = GetFloor(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, &room_number);
		item->floor = GetHeight(floor, item->pos.x_pos, item->pos.y_pos, item->pos.z_pos);

		if (item->pos.y_pos > item->floor)
			item->pos.y_pos = item->floor;
		else if (item->floor - item->pos.y_pos > 64)
			item->pos.y_pos += 64;
		else if (item->pos.y_pos < item->floor)
			item->pos.y_pos = item->floor;
	}

	room_number = item->room_number;
	GetFloor(item->pos.x_pos, item->pos.y_pos - 32, item->pos.z_pos, &room_number);

	if (item->room_number != room_number)
		ItemNewRoom(item_number, room_number);

	return 1;
}

short CreatureTurn(ITEM_INFO* item, short maximum_turn)
{
	CREATURE_INFO* creature;
	ROOM_INFO* r;
	long x, z, feelxplus, feelzplus, feelxminus, feelzminus, feelxmid, feelzmid, feelplus, feelminus, feelmid;
	short angle;

	creature = (CREATURE_INFO*)item->data;

	if (!creature || !maximum_turn)
		return 0;

	x = item->pos.x_pos;
	z = item->pos.z_pos;
	r = &room[item->room_number];

	feelxplus = x + (512 * phd_sin(item->pos.y_rot + 8190) >> 14);
	feelzplus = z + (512 * phd_cos(item->pos.y_rot + 8190) >> 14);
	feelplus = r->floor[((feelzplus - r->z) >> 10) + r->x_size * ((feelxplus - r->x) >> 10)].stopper;

	feelxminus = x + (512 * phd_sin(item->pos.y_rot - 8190) >> 14);
	feelzminus = z + (512 * phd_cos(item->pos.y_rot - 8190) >> 14);
	feelminus = r->floor[((feelzminus - r->z) >> 10) + r->x_size * ((feelxminus - r->x) >> 10)].stopper;

	feelxmid = x + (512 * phd_sin(item->pos.y_rot) >> 14);
	feelzmid = z + (512 * phd_cos(item->pos.y_rot) >> 14);
	feelmid = r->floor[((feelzmid - r->z) >> 10) + r->x_size * ((feelxmid - r->x) >> 10)].stopper;

	if (feelminus && feelmid)
	{
		creature->target.x = feelxplus;
		creature->target.z = feelzplus;
	}
	else if (feelplus && feelmid)
	{
		creature->target.x = feelxminus;
		creature->target.z = feelzminus;
	}
	else if (feelplus || feelminus)
	{
		creature->target.x = feelxmid;
		creature->target.z = feelzmid;
	}

	x = creature->target.x - item->pos.x_pos;
	z = creature->target.z - item->pos.z_pos;
	angle = short(phd_atan(z, x) - item->pos.y_rot);

	if (angle > 0x4000 || angle < -0x4000)
	{
		if (SQUARE(x) + SQUARE(z) < SQUARE((item->speed << 14) / maximum_turn))
			maximum_turn >>= 1;
	}

	if (angle > maximum_turn)
		angle = maximum_turn;
	else if (angle < -maximum_turn)
		angle = -maximum_turn;

	item->pos.y_rot += angle;
	return angle;
}

void CreatureTilt(ITEM_INFO* item, short angle)
{
	angle = (angle << 2) - item->pos.z_rot;

	if (angle < -546)
		angle = -546;
	else if (angle > 546)
		angle = 546;

	if (abs(item->pos.z_rot) < 2730 || abs(item->pos.z_rot) > 5460)
		angle >>= 1;

	item->pos.z_rot += angle;
}

void inject_box(bool replace)
{
	INJECT(0x00408550, InitialiseCreature, replace);
	INJECT(0x00408630, CreatureActive, replace);
	INJECT(0x004086C0, CreatureAIInfo, replace);
	INJECT(0x00408BA0, SearchLOT, replace);
	INJECT(0x00408B00, UpdateLOT, replace);
	INJECT(0x00408E20, TargetBox, replace);
	INJECT(0x00408EF0, EscapeBox, replace);
	INJECT(0x00408FD0, ValidBox, replace);
	INJECT(0x00409770, StalkBox, replace);
	INJECT(0x004098B0, CalculateTarget, replace);
	INJECT(0x00409370, CreatureMood, replace);
	INJECT(0x004090A0, GetCreatureMood, replace);
	INJECT(0x00409E20, CreatureCreature, replace);
	INJECT(0x00409FB0, BadFloor, replace);
	INJECT(0x0040C5A0, DropBaddyPickups, replace);
	INJECT(0x0040A090, CreatureDie, replace);
	INJECT(0x0040A1D0, CreatureAnimation, replace);
	INJECT(0x0040AE90, CreatureTurn, replace);
	INJECT(0x0040B1B0, CreatureTilt, replace);
}