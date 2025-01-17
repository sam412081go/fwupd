/*
 * Copyright (C) 2020 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#include <glib-object.h>

#include "fwupd-enums.h"

G_BEGIN_DECLS

#define FWUPD_TYPE_PLUGIN (fwupd_plugin_get_type())
G_DECLARE_DERIVABLE_TYPE(FwupdPlugin, fwupd_plugin, FWUPD, PLUGIN, GObject)

struct _FwupdPluginClass {
	GObjectClass parent_class;
	/*< private >*/
	void (*_fwupd_reserved1)(void);
	void (*_fwupd_reserved2)(void);
	void (*_fwupd_reserved3)(void);
	void (*_fwupd_reserved4)(void);
	void (*_fwupd_reserved5)(void);
	void (*_fwupd_reserved6)(void);
	void (*_fwupd_reserved7)(void);
};

FwupdPlugin *
fwupd_plugin_new(void);
gchar *
fwupd_plugin_to_string(FwupdPlugin *self);

const gchar *
fwupd_plugin_get_name(FwupdPlugin *self);
void
fwupd_plugin_set_name(FwupdPlugin *self, const gchar *name);
guint64
fwupd_plugin_get_flags(FwupdPlugin *self);
void
fwupd_plugin_set_flags(FwupdPlugin *self, guint64 flags);
void
fwupd_plugin_add_flag(FwupdPlugin *self, FwupdPluginFlags flag);
void
fwupd_plugin_remove_flag(FwupdPlugin *self, FwupdPluginFlags flag);
gboolean
fwupd_plugin_has_flag(FwupdPlugin *self, FwupdPluginFlags flag) G_GNUC_WARN_UNUSED_RESULT;

FwupdPlugin *
fwupd_plugin_from_variant(GVariant *value);
GPtrArray *
fwupd_plugin_array_from_variant(GVariant *value);

G_END_DECLS
