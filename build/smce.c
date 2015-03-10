
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "smce.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *smce_http_httpexception_ce;
zend_class_entry *smce_app_ce;
zend_class_entry *smce_components_collection_ce;
zend_class_entry *smce_components_output_ce;
zend_class_entry *smce_components_session_ce;
zend_class_entry *smce_core_di_ce;
zend_class_entry *smce_core_di_diadapter_ce;
zend_class_entry *smce_core_di_dicache_ce;
zend_class_entry *smce_core_di_disingleton_ce;
zend_class_entry *smce_core_eventmanager_ce;
zend_class_entry *smce_core_loader_ce;
zend_class_entry *smce_core_queue_ce;
zend_class_entry *smce_core_queue_queueadapter_ce;
zend_class_entry *smce_core_queue_queuelisten_ce;
zend_class_entry *smce_core_queue_queuemodel_ce;
zend_class_entry *smce_core_smceframework_ce;
zend_class_entry *smce_driver_adapter_ce;
zend_class_entry *smce_driver_memcache_ce;
zend_class_entry *smce_driver_redis_ce;
zend_class_entry *smce_http_response_ce;
zend_class_entry *smce_mvc_acl_ce;
zend_class_entry *smce_mvc_layout_ce;
zend_class_entry *smce_mvc_router_ce;
zend_class_entry *smce_mvc_router_exception_ce;
zend_class_entry *smce_mvc_router_route_ce;
zend_class_entry *smce_mvc_template_ce;
zend_class_entry *smce_mvc_url_ce;
zend_class_entry *smce_sm_ce;

ZEND_DECLARE_MODULE_GLOBALS(smce)

static PHP_MINIT_FUNCTION(smce)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Smce_Http_HttpException);
	ZEPHIR_INIT(Smce_App);
	ZEPHIR_INIT(Smce_Components_Collection);
	ZEPHIR_INIT(Smce_Components_Output);
	ZEPHIR_INIT(Smce_Components_Session);
	ZEPHIR_INIT(Smce_Core_Di);
	ZEPHIR_INIT(Smce_Core_Di_DiAdapter);
	ZEPHIR_INIT(Smce_Core_Di_DiCache);
	ZEPHIR_INIT(Smce_Core_Di_DiSingleton);
	ZEPHIR_INIT(Smce_Core_EventManager);
	ZEPHIR_INIT(Smce_Core_Loader);
	ZEPHIR_INIT(Smce_Core_Queue);
	ZEPHIR_INIT(Smce_Core_Queue_QueueAdapter);
	ZEPHIR_INIT(Smce_Core_Queue_QueueListen);
	ZEPHIR_INIT(Smce_Core_Queue_QueueModel);
	ZEPHIR_INIT(Smce_Core_SmceFramework);
	ZEPHIR_INIT(Smce_Driver_Adapter);
	ZEPHIR_INIT(Smce_Driver_Memcache);
	ZEPHIR_INIT(Smce_Driver_Redis);
	ZEPHIR_INIT(Smce_Http_Response);
	ZEPHIR_INIT(Smce_Mvc_Acl);
	ZEPHIR_INIT(Smce_Mvc_Layout);
	ZEPHIR_INIT(Smce_Mvc_Router);
	ZEPHIR_INIT(Smce_Mvc_Router_Exception);
	ZEPHIR_INIT(Smce_Mvc_Router_Route);
	ZEPHIR_INIT(Smce_Mvc_Template);
	ZEPHIR_INIT(Smce_Mvc_Url);
	ZEPHIR_INIT(Smce_Sm);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(smce)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_smce_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;

	zephir_globals->test.my_setting_1 = 1;
	zephir_globals->test.my_setting_2 = 100;
	zephir_globals->test.my_setting_3 = 7.5;
	zephir_globals->my_setting_1 = 1;
	zephir_globals->my_setting_2 = 10;
	zephir_globals->my_setting_3 = 15.2;

}

static PHP_RINIT_FUNCTION(smce)
{

	zend_smce_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(smce)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(smce)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SMCE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SMCE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SMCE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SMCE_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SMCE_ZEPVERSION);
	php_info_print_table_end();

	php_info_print_table_start();
	php_info_print_table_header(2, "Directive", "Value");
	php_info_print_table_row(2, "setting1", "value1");
	php_info_print_table_row(2, "setting2", "value2");
	php_info_print_table_end();
	php_info_print_table_start();
	php_info_print_table_header(2, "Directive", "Value");
	php_info_print_table_row(2, "setting3", "value3");
	php_info_print_table_row(2, "setting4", "value4");
	php_info_print_table_end();

}

static PHP_GINIT_FUNCTION(smce)
{
	php_zephir_init_globals(smce_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(smce)
{

}

zend_module_entry smce_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_SMCE_EXTNAME,
	NULL,
	PHP_MINIT(smce),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(smce),
#else
	NULL,
#endif
	PHP_RINIT(smce),
	PHP_RSHUTDOWN(smce),
	PHP_MINFO(smce),
	PHP_SMCE_VERSION,
	ZEND_MODULE_GLOBALS(smce),
	PHP_GINIT(smce),
	PHP_GSHUTDOWN(smce),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SMCE
ZEND_GET_MODULE(smce)
#endif
