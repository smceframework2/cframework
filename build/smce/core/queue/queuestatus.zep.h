
extern zend_class_entry *smce_core_queue_queuestatus_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueStatus);

PHP_METHOD(Smce_Core_Queue_QueueStatus, __construct);
PHP_METHOD(Smce_Core_Queue_QueueStatus, getStatus);
PHP_METHOD(Smce_Core_Queue_QueueStatus, status);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuestatus___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, adapter)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuestatus_getstatus, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_queue_queuestatus_method_entry) {
	PHP_ME(Smce_Core_Queue_QueueStatus, __construct, arginfo_smce_core_queue_queuestatus___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Queue_QueueStatus, getStatus, arginfo_smce_core_queue_queuestatus_getstatus, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueStatus, status, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
