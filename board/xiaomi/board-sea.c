/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026, Nisel <nisel11good@gmail.com>
 */

#include <board.h>
#include <util.h>
#include <string.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>
#include <lib/debug.h>

static struct video_info sea_fb = {
    .format = FB_FORMAT_ARGB8888,
    .width = 1088,
    .height = 2400,
    .stride = 4,
    .address = (void *)0x7bc10000
};

static const struct device sea_devices[] = {
	{ "simplefb", &sea_fb, "fb" },
};

struct board_data board_ops = {
    .name = "xiaomi-sea",
    .devices = sea_devices,
    .num_devices = ARRAY_SIZE(sea_devices),
    .quirks = 0
};
