/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025, nisel11 <nisel11good@gmail.com>
 */

#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>
#include <lib/debug.h>

#define TOPRGU_BASE	0x10007000
#define WDT_MODE_KEY	0x22000000
#define WDT_MODE_EN	(1 << 0)

int fleur_init(void)
{
	unsigned long wdg_reg;

	// Disable watchdog
	wdg_reg = readl((volatile unsigned int *) TOPRGU_BASE);
	wdg_reg &= ~WDT_MODE_EN;
	wdg_reg |= WDT_MODE_KEY;
	writel(wdg_reg, (void *) TOPRGU_BASE);

	return 0;
}

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
	.early_init = fleur_init,
        .drivers_init = fleur_drv,
    },
    .quirks = 0
};
