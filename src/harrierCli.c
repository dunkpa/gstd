/* harrierCli.c generated by valac, the Vala compiler
 * generated from harrierCli.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define TYPE_HARRIER_CLI (harrier_cli_get_type ())
#define HARRIER_CLI(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_HARRIER_CLI, HarrierCli))
#define HARRIER_CLI_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_HARRIER_CLI, HarrierCliClass))
#define IS_HARRIER_CLI(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_HARRIER_CLI))
#define IS_HARRIER_CLI_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_HARRIER_CLI))
#define HARRIER_CLI_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_HARRIER_CLI, HarrierCliClass))

typedef struct _HarrierCli HarrierCli;
typedef struct _HarrierCliClass HarrierCliClass;
typedef struct _HarrierCliPrivate HarrierCliPrivate;
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _HarrierCli {
	GObject parent_instance;
	HarrierCliPrivate * priv;
};

struct _HarrierCliClass {
	GObjectClass parent_class;
};

struct _HarrierCliPrivate {
	DBusGConnection* conn;
	DBusGProxy* harrier;
	gint active_id;
	char** cmds;
	gint cmds_length1;
	gint cmds_length2;
};


static gpointer harrier_cli_parent_class = NULL;

GType harrier_cli_get_type (void);
#define HARRIER_CLI_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_HARRIER_CLI, HarrierCliPrivate))
enum  {
	HARRIER_CLI_DUMMY_PROPERTY
};
HarrierCli* harrier_cli_new (GError** error);
HarrierCli* harrier_cli_construct (GType object_type, GError** error);
static gboolean _dynamic_PipelinePlay0 (DBusGProxy* self, gint param1, GError** error);
static gboolean harrier_cli_pipeline_play (HarrierCli* self, gint id);
static gboolean _dynamic_PipelinePause1 (DBusGProxy* self, gint param1, GError** error);
static gboolean harrier_cli_pipeline_pause (HarrierCli* self, gint id);
static gboolean _dynamic_PipelineNull2 (DBusGProxy* self, gint param1, GError** error);
static gboolean harrier_cli_pipeline_null (HarrierCli* self, gint id);
static gboolean _dynamic_DestroyPipeline3 (DBusGProxy* self, gint param1, GError** error);
static gboolean harrier_cli_pipeline_destroy (HarrierCli* self, gint id);
static gint _dynamic_CreatePipeline4 (DBusGProxy* self, const char* param1, GError** error);
gboolean harrier_cli_parse_cmd (HarrierCli* self, char** args, int args_length1, GError** error);
gboolean harrier_cli_cli (HarrierCli* self, char** args, int args_length1, GError** error);
gboolean harrier_cli_parse (HarrierCli* self, char** args, int args_length1, GError** error);
static gint harrier_cli_main (char** args, int args_length1);
static void harrier_cli_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);



HarrierCli* harrier_cli_construct (GType object_type, GError** error) {
	GError * _inner_error_;
	HarrierCli * self;
	char* env_id;
	DBusGConnection* _tmp0_;
	DBusGConnection* _tmp1_;
	DBusGProxy* _tmp2_;
	char* _tmp3_;
	_inner_error_ = NULL;
	self = (HarrierCli*) g_object_new (object_type, NULL);
	env_id = NULL;
	_tmp0_ = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_free0 (env_id);
		return NULL;
	}
	self->priv->conn = (_tmp1_ = _tmp0_, _dbus_g_connection_unref0 (self->priv->conn), _tmp1_);
	self->priv->harrier = (_tmp2_ = dbus_g_proxy_new_for_name (self->priv->conn, "com.ti.sdo.HarrierService", "/com/ti/sdo/HarrierObject", "com.ti.sdo.HarrierInterface"), _g_object_unref0 (self->priv->harrier), _tmp2_);
	self->priv->active_id = 0;
	env_id = (_tmp3_ = g_strdup (g_getenv ("HARRIER_ACTIVE_ID")), _g_free0 (env_id), _tmp3_);
	if (env_id != NULL) {
		self->priv->active_id = atoi (env_id);
		fprintf (stdout, "NOTICE: Using active id from enviroment variable: %d\n", self->priv->active_id);
	}
	_g_free0 (env_id);
	return self;
}


HarrierCli* harrier_cli_new (GError** error) {
	return harrier_cli_construct (TYPE_HARRIER_CLI, error);
}


static gboolean _dynamic_PipelinePlay0 (DBusGProxy* self, gint param1, GError** error) {
	gboolean result;
	dbus_g_proxy_call (self, "PipelinePlay", error, G_TYPE_INT, param1, G_TYPE_INVALID, G_TYPE_BOOLEAN, &result, G_TYPE_INVALID);
	if (*error) {
		return FALSE;
	}
	return result;
}


static gboolean harrier_cli_pipeline_play (HarrierCli* self, gint id) {
	gboolean result;
	GError * _inner_error_;
	gboolean ret;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	ret = _dynamic_PipelinePlay0 (self->priv->harrier, id, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	if (!ret) {
		fprintf (stdout, "Failed to put the pipeline to play\n");
		result = FALSE;
		return result;
	}
	result = ret;
	return result;
}


static gboolean _dynamic_PipelinePause1 (DBusGProxy* self, gint param1, GError** error) {
	gboolean result;
	dbus_g_proxy_call (self, "PipelinePause", error, G_TYPE_INT, param1, G_TYPE_INVALID, G_TYPE_BOOLEAN, &result, G_TYPE_INVALID);
	if (*error) {
		return FALSE;
	}
	return result;
}


static gboolean harrier_cli_pipeline_pause (HarrierCli* self, gint id) {
	gboolean result;
	GError * _inner_error_;
	gboolean ret;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	ret = _dynamic_PipelinePause1 (self->priv->harrier, id, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	if (!ret) {
		fprintf (stdout, "Failed to put the pipeline to pause\n");
		result = FALSE;
		return result;
	}
	result = ret;
	return result;
}


static gboolean _dynamic_PipelineNull2 (DBusGProxy* self, gint param1, GError** error) {
	gboolean result;
	dbus_g_proxy_call (self, "PipelineNull", error, G_TYPE_INT, param1, G_TYPE_INVALID, G_TYPE_BOOLEAN, &result, G_TYPE_INVALID);
	if (*error) {
		return FALSE;
	}
	return result;
}


static gboolean harrier_cli_pipeline_null (HarrierCli* self, gint id) {
	gboolean result;
	GError * _inner_error_;
	gboolean ret;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	ret = _dynamic_PipelineNull2 (self->priv->harrier, id, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	if (!ret) {
		fprintf (stdout, "Failed to put the pipeline to null\n");
		result = FALSE;
		return result;
	}
	result = ret;
	return result;
}


static gboolean _dynamic_DestroyPipeline3 (DBusGProxy* self, gint param1, GError** error) {
	gboolean result;
	dbus_g_proxy_call (self, "DestroyPipeline", error, G_TYPE_INT, param1, G_TYPE_INVALID, G_TYPE_BOOLEAN, &result, G_TYPE_INVALID);
	if (*error) {
		return FALSE;
	}
	return result;
}


static gboolean harrier_cli_pipeline_destroy (HarrierCli* self, gint id) {
	gboolean result;
	GError * _inner_error_;
	gboolean ret;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	ret = _dynamic_DestroyPipeline3 (self->priv->harrier, id, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	if (!ret) {
		fprintf (stdout, "Failed to destroy the pipeline\n");
		result = FALSE;
		return result;
	}
	result = ret;
	return result;
}


static gint _dynamic_CreatePipeline4 (DBusGProxy* self, const char* param1, GError** error) {
	gint result;
	dbus_g_proxy_call (self, "CreatePipeline", error, G_TYPE_STRING, param1, G_TYPE_INVALID, G_TYPE_INT, &result, G_TYPE_INVALID);
	if (*error) {
		return 0;
	}
	return result;
}


static glong string_get_length (const char* self) {
	glong result;
	g_return_val_if_fail (self != NULL, 0L);
	result = g_utf8_strlen (self, -1);
	return result;
}


gboolean harrier_cli_parse_cmd (HarrierCli* self, char** args, int args_length1, GError** error) {
	gboolean result;
	GError * _inner_error_;
	gint id = 0;
	GQuark _tmp4_;
	char* _tmp3_;
	static GQuark _tmp4__label0 = 0;
	static GQuark _tmp4__label1 = 0;
	static GQuark _tmp4__label2 = 0;
	static GQuark _tmp4__label3 = 0;
	static GQuark _tmp4__label4 = 0;
	static GQuark _tmp4__label5 = 0;
	static GQuark _tmp4__label6 = 0;
	static GQuark _tmp4__label7 = 0;
	static GQuark _tmp4__label8 = 0;
	static GQuark _tmp4__label9 = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	_tmp3_ = g_utf8_strdown (args[1], -1);
	_tmp4_ = (NULL == _tmp3_) ? 0 : g_quark_from_string (_tmp3_);
	g_free (_tmp3_);
	if (_tmp4_ == ((0 != _tmp4__label0) ? _tmp4__label0 : (_tmp4__label0 = g_quark_from_static_string ("create"))))
	do {
		gint _tmp0_;
		fprintf (stdout, "Creating pipe: %s\n", args[2]);
		_tmp0_ = _dynamic_CreatePipeline4 (self->priv->harrier, args[2], &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
		id = _tmp0_;
		if (id < 0) {
			fprintf (stdout, "Failed to create pipeline");
			result = FALSE;
			return result;
		}
		self->priv->active_id = id;
		fprintf (stdout, "Active id is now %d\n", self->priv->active_id);
		break;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label1) ? _tmp4__label1 : (_tmp4__label1 = g_quark_from_static_string ("destroy"))))
	do {
		if (self->priv->active_id == 0) {
			fprintf (stdout, "No valid active pipeline id\n");
			result = FALSE;
			return result;
		}
		result = harrier_cli_pipeline_destroy (self, self->priv->active_id);
		return result;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label2) ? _tmp4__label2 : (_tmp4__label2 = g_quark_from_static_string ("destroy_id"))))
	do {
		id = atoi (args[2]);
		result = harrier_cli_pipeline_destroy (self, id);
		return result;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label3) ? _tmp4__label3 : (_tmp4__label3 = g_quark_from_static_string ("play"))))
	do {
		if (self->priv->active_id == 0) {
			fprintf (stdout, "No valid active pipeline id\n");
			result = FALSE;
			return result;
		}
		result = harrier_cli_pipeline_play (self, self->priv->active_id);
		return result;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label4) ? _tmp4__label4 : (_tmp4__label4 = g_quark_from_static_string ("play_id"))))
	do {
		id = atoi (args[2]);
		result = harrier_cli_pipeline_play (self, id);
		return result;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label5) ? _tmp4__label5 : (_tmp4__label5 = g_quark_from_static_string ("pause"))))
	do {
		if (self->priv->active_id == 0) {
			fprintf (stdout, "No valid active pipeline id\n");
			result = FALSE;
			return result;
		}
		result = harrier_cli_pipeline_pause (self, self->priv->active_id);
		return result;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label6) ? _tmp4__label6 : (_tmp4__label6 = g_quark_from_static_string ("pause_id"))))
	do {
		id = atoi (args[2]);
		result = harrier_cli_pipeline_pause (self, id);
		return result;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label7) ? _tmp4__label7 : (_tmp4__label7 = g_quark_from_static_string ("null"))))
	do {
		if (self->priv->active_id == 0) {
			fprintf (stdout, "No valid active pipeline id\n");
			result = FALSE;
			return result;
		}
		result = harrier_cli_pipeline_null (self, self->priv->active_id);
		return result;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label8) ? _tmp4__label8 : (_tmp4__label8 = g_quark_from_static_string ("null_id"))))
	do {
		id = atoi (args[2]);
		result = harrier_cli_pipeline_null (self, id);
		return result;
	} while (0); else if (_tmp4_ == ((0 != _tmp4__label9) ? _tmp4__label9 : (_tmp4__label9 = g_quark_from_static_string ("help"))))
	do {
		if (args_length1 > 2) {
			{
				gboolean _tmp1_;
				id = 0;
				_tmp1_ = TRUE;
				while (TRUE) {
					if (!_tmp1_) {
						id++;
					}
					_tmp1_ = FALSE;
					if (!(id < (string_get_length (self->priv->cmds[0]) - 1))) {
						break;
					}
					if (_vala_strcmp0 (self->priv->cmds[(id * self->priv->cmds_length2) + 0], args[2]) == 0) {
						fprintf (stdout, "Command: %s\n", args[2]);
						fprintf (stdout, "Description: %s\n", self->priv->cmds[(id * self->priv->cmds_length2) + 2]);
						fprintf (stdout, "Syntax: %s\n", self->priv->cmds[(id * self->priv->cmds_length2) + 1]);
						result = TRUE;
						return result;
					}
				}
			}
			fprintf (stdout, "Unknown command: %s\n", args[2]);
			result = FALSE;
			return result;
		} else {
			fprintf (stdout, "%s", "Request the syntax of an specific command with " "\"help <command>\".\n" "This is the list of supported commands:\n");
			{
				gboolean _tmp2_;
				id = 0;
				_tmp2_ = TRUE;
				while (TRUE) {
					if (!_tmp2_) {
						id++;
					}
					_tmp2_ = FALSE;
					if (!(id < (string_get_length (self->priv->cmds[0]) - 1))) {
						break;
					}
					fprintf (stdout, " %s:\t%s\n", self->priv->cmds[(id * self->priv->cmds_length2) + 0], self->priv->cmds[(id * self->priv->cmds_length2) + 2]);
				}
			}
			fprintf (stdout, "\n");
		}
		break;
	} while (0); else
	do {
		fprintf (stderr, "Unkown command: %s\n", args[1]);
		result = FALSE;
		return result;
	} while (0);
	result = TRUE;
	return result;
}


gboolean harrier_cli_cli (HarrierCli* self, char** args, int args_length1, GError** error) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = FALSE;
	return result;
}


gboolean harrier_cli_parse (HarrierCli* self, char** args, int args_length1, GError** error) {
	gboolean result;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	if (args_length1 > 1) {
		gboolean _tmp0_;
		_tmp0_ = harrier_cli_parse_cmd (self, args, args_length1, &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
		result = _tmp0_;
		return result;
	} else {
		gboolean _tmp1_;
		_tmp1_ = harrier_cli_cli (self, args, args_length1, &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
		result = _tmp1_;
		return result;
	}
}


static gint harrier_cli_main (char** args, int args_length1) {
	gint result;
	GError * _inner_error_;
	HarrierCli* cli;
	_inner_error_ = NULL;
	cli = NULL;
	{
		HarrierCli* _tmp0_;
		HarrierCli* _tmp1_;
		gboolean _tmp2_;
		_tmp0_ = harrier_cli_new (&_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == DBUS_GERROR) {
				goto __catch0_dbus_gerror;
			}
			goto __catch0_g_error;
			goto __finally0;
		}
		cli = (_tmp1_ = _tmp0_, _g_object_unref0 (cli), _tmp1_);
		_tmp2_ = harrier_cli_parse (cli, args, args_length1, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == DBUS_GERROR) {
				goto __catch0_dbus_gerror;
			}
			goto __catch0_g_error;
			goto __finally0;
		}
		if (!_tmp2_) {
			result = -1;
			_g_object_unref0 (cli);
			return result;
		}
	}
	goto __finally0;
	__catch0_dbus_gerror:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			fprintf (stderr, "DBus failure: %s\n", e->message);
			result = 1;
			_g_error_free0 (e);
			_g_object_unref0 (cli);
			return result;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			fprintf (stderr, "Dynamic method failure\n");
			result = 1;
			_g_error_free0 (e);
			_g_object_unref0 (cli);
			return result;
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cli);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return 0;
	}
	result = 0;
	_g_object_unref0 (cli);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return harrier_cli_main (argv, argc);
}


static void harrier_cli_class_init (HarrierCliClass * klass) {
	harrier_cli_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (HarrierCliPrivate));
	G_OBJECT_CLASS (klass)->finalize = harrier_cli_finalize;
}


static void harrier_cli_instance_init (HarrierCli * self) {
	char** _tmp0_ = NULL;
	self->priv = HARRIER_CLI_GET_PRIVATE (self);
	self->priv->cmds = (_tmp0_ = g_new0 (char*, (5 * 3) + 1), _tmp0_[0] = g_strdup ("create"), _tmp0_[1] = g_strdup ("create <\"gst-launch like pipeline description in quotes\">"), _tmp0_[2] = g_strdup ("Create a new pipeline and returns the id for it on the servers"), _tmp0_[3] = g_strdup ("destroy"), _tmp0_[4] = g_strdup ("destroy"), _tmp0_[5] = g_strdup ("Destroys the active pipeline"), _tmp0_[6] = g_strdup ("destroy_id"), _tmp0_[7] = g_strdup ("destroy_id <id>"), _tmp0_[8] = g_strdup ("Destroys the pipeline with the specified id"), _tmp0_[9] = g_strdup ("play  "), _tmp0_[10] = g_strdup ("play"), _tmp0_[11] = g_strdup ("Sets the active pipeline to play state"), _tmp0_[12] = g_strdup ("play_id"), _tmp0_[13] = g_strdup ("play_id <id>"), _tmp0_[14] = g_strdup ("Sets the pipeline with the specified id to play state"), _tmp0_);
	self->priv->cmds_length1 = 5;
	self->priv->cmds_length2 = 3;
}


static void harrier_cli_finalize (GObject* obj) {
	HarrierCli * self;
	self = HARRIER_CLI (obj);
	_dbus_g_connection_unref0 (self->priv->conn);
	_g_object_unref0 (self->priv->harrier);
	self->priv->cmds = (_vala_array_free (self->priv->cmds, self->priv->cmds_length1 * self->priv->cmds_length2, (GDestroyNotify) g_free), NULL);
	G_OBJECT_CLASS (harrier_cli_parent_class)->finalize (obj);
}


GType harrier_cli_get_type (void) {
	static GType harrier_cli_type_id = 0;
	if (harrier_cli_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (HarrierCliClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) harrier_cli_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (HarrierCli), 0, (GInstanceInitFunc) harrier_cli_instance_init, NULL };
		harrier_cli_type_id = g_type_register_static (G_TYPE_OBJECT, "HarrierCli", &g_define_type_info, 0);
	}
	return harrier_cli_type_id;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




