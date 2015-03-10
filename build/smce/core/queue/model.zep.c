
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Core_Queue_Model) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Queue, Model, smce, core_queue_model, smce_core_queue_model_method_entry, 0);

	zend_declare_property_null(smce_core_queue_model_ce, SL("que"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 *@param que
 *@return void
 */
PHP_METHOD(Smce_Core_Queue_Model, __construct) {

	zval *que;

	zephir_fetch_params(0, 1, 0, &que);




}

PHP_METHOD(Smce_Core_Queue_Model, addMinutes) {



}

