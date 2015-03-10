
extern zend_class_entry *smce_core_queue_model_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Queue_Model);

PHP_METHOD(Smce_Core_Queue_Model, __construct);
PHP_METHOD(Smce_Core_Queue_Model, addMinutes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_model___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, que)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_queue_model_method_entry) {
	PHP_ME(Smce_Core_Queue_Model, __construct, arginfo_smce_core_queue_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Queue_Model, addMinutes, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
