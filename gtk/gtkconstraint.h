/* gtkconstraint.h: Constraint between two widgets
 * Copyright 2019  GNOME Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Emmanuele Bassi
 */

#pragma once

#include <gtk/gtktypes.h>
#include <gtk/gtkenums.h>

G_BEGIN_DECLS

#define GTK_TYPE_CONSTRAINT (gtk_constraint_get_type ())

/**
 * GtkConstraint:
 *
 * An object describing the relation between two widget attributes.
 *
 * All relations are in the form:
 *
 * |[<!-- language=plain -->
 *   target.attr_name = source.attr_name × multiplier + constant
 * ]|
 *
 * A #GtkConstraint is immutable once it's created.
 */
GDK_AVAILABLE_IN_ALL
G_DECLARE_FINAL_TYPE (GtkConstraint, gtk_constraint, GTK, CONSTRAINT, GObject)

GDK_AVAILABLE_IN_ALL
GtkConstraint *         gtk_constraint_new                      (GtkWidget              *target_widget,
                                                                 GtkConstraintAttribute  target_attribute,
                                                                 GtkConstraintRelation   relation,
                                                                 GtkWidget              *source_widget,
                                                                 GtkConstraintAttribute  source_attribute,
                                                                 double                  multiplier,
                                                                 double                  constant,
                                                                 int                     strength);
GDK_AVAILABLE_IN_ALL
GtkConstraint *         gtk_constraint_new_constant             (GtkWidget              *target_widget,
                                                                 GtkConstraintAttribute  target_attribute,
                                                                 GtkConstraintRelation   relation,
                                                                 double                  constant,
                                                                 int                     strength);

GDK_AVAILABLE_IN_ALL
GtkWidget *             gtk_constraint_get_target_widget        (GtkConstraint          *constraint);
GDK_AVAILABLE_IN_ALL
GtkConstraintAttribute  gtk_constraint_get_target_attribute     (GtkConstraint          *constraint);
GDK_AVAILABLE_IN_ALL
GtkWidget *             gtk_constraint_get_source_widget        (GtkConstraint          *constraint);
GDK_AVAILABLE_IN_ALL
GtkConstraintAttribute  gtk_constraint_get_source_attribute     (GtkConstraint          *constraint);
GDK_AVAILABLE_IN_ALL
GtkConstraintRelation   gtk_constraint_get_relation             (GtkConstraint          *constraint);
GDK_AVAILABLE_IN_ALL
double                  gtk_constraint_get_multiplier           (GtkConstraint          *constraint);
GDK_AVAILABLE_IN_ALL
double                  gtk_constraint_get_constant             (GtkConstraint          *constraint);
GDK_AVAILABLE_IN_ALL
int                     gtk_constraint_get_strength             (GtkConstraint          *constraint);

GDK_AVAILABLE_IN_ALL
gboolean                gtk_constraint_is_required              (GtkConstraint          *constraint);
GDK_AVAILABLE_IN_ALL
gboolean                gtk_constraint_is_attached              (GtkConstraint          *constraint);

GDK_AVAILABLE_IN_ALL
void                    gtk_constraint_set_active               (GtkConstraint          *constraint,
                                                                 gboolean                is_active);
GDK_AVAILABLE_IN_ALL
gboolean                gtk_constraint_get_active               (GtkConstraint          *constraint);

G_END_DECLS