/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025, nisel11 <nisel11good@gmail.com>
 */

#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>
#include <lib/debug.h>

static struct video_info fleur_fb = {
    .format = FB_FORMAT_ARGB8888,
    .width = 1088,
    .height = 2400,
    .stride = 4,
    .address = (void *)0x7c010000
};

int fleur_drv(void)
{
	REGISTER_DRIVER("simplefb", simplefb_probe, &fleur_fb);
	return 0;
}

struct board_data board_ops = {
    .name = "xiaomi-fleur",
    .ops = {
        .drivers_init = fleur_drv,
    },
    .quirks = 0
};
