
extern zend_class_entry *smce_core_queue_queuemodel_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueModel);

PHP_METHOD(Smce_Core_Queue_QueueModel, __construct);
PHP_METHOD(Smce_Core_Queue_QueueModel, addMinutes);
PHP_METHOD(Smce_Core_Queue_QueueModel, register);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuemodel___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuemodel_addminutes, 0, 0, 0)
	ZEND_ARG_INFO(0, minute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuemodel_register, 0, 0, 0)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_queue_queuemodel_method_entry) {
	PHP_ME(Smce_Core_Queue_QueueModel, __construct, arginfo_smce_core_queue_queuemodel___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Queue_QueueModel, addMinutes, arginfo_smce_core_queue_queuemodel_addminutes, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Queue_QueueModel, register, arginfo_smce_core_queue_queuemodel_register, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
