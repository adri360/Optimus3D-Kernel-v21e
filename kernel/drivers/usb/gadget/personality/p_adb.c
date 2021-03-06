/* Copyright (C) 2010, 2011 emsys Embedded Systems GmbH
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "disable_init_defines.h"
#include "../f_adb.c"

int adb_bind_config(struct usb_configuration *c);

int adb_function_add(struct usb_composite_dev *cdev, struct usb_configuration *c)
{
 return adb_bind_config(c);
}

int personality_adb_bind_config(struct usb_configuration *c)
{
 return adb_bind_config(c);
}

/**
 * Defined in android.c, which is currently not used.
 */
void android_enable_function(struct usb_function *f, int enable)
{
  if (!f || !f->name || !_adb_dev || !_adb_dev->cdev) { return; }
  /* printk(KERN_INFO "%s(%p, %d) f->name=\"%s\"\n", __FUNCTION__, f, enable, f->name); */
  if (enable && !strcmp("adb", f->name)) {
    usb_composite_force_reset(_adb_dev->cdev);
  }
}
