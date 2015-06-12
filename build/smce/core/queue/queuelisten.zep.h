
extern zend_class_entry *smce_core_queue_queuelisten_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueListen);

PHP_METHOD(Smce_Core_Queue_QueueListen, __construct);
PHP_METHOD(Smce_Core_Queue_QueueListen, start);
PHP_METHOD(Smce_Core_Queue_QueueListen, on);
PHP_METHOD(Smce_Core_Queue_QueueListen, setOn);
PHP_METHOD(Smce_Core_Queue_QueueListen, getOn);
PHP_METHOD(Smce_Core_Queue_QueueListen, transactions);
PHP_METHOD(Smce_Core_Queue_QueueListen, stop);
PHP_METHOD(Smce_Core_Queue_QueueListen, sleep);
PHP_METHOD(Smce_Core_Queue_QueueListen, isQue);
PHP_METHOD(Smce_Core_Queue_QueueListen, onPoint);
PHP_METHOD(Smce_Core_Queue_QueueListen, getOnPoint);
PHP_METHOD(Smce_Core_Queue_QueueListen, lastTransactionTime);
PHP_METHOD(Smce_Core_Queue_QueueListen, getLastTransactionTime);
PHP_METHOD(Smce_Core_Queue_QueueListen, changeStatus);
PHP_METHOD(Smce_Core_Queue_QueueListen, getStatus);
PHP_METHOD(Smce_Core_Queue_QueueListen, status);
PHP_METHOD(Smce_Core_Queue_QueueListen, getAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, adapter)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_seton, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_geton, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_transactions, 0, 0, 1)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_sleep, 0, 0, 0)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_isque, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_onpoint, 0, 0, 2)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_getonpoint, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_lasttransactiontime, 0, 0, 2)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_changestatus, 0, 0, 2)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuelisten_getstatus, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_queue_queuelisten_method_entry) {
	PHP_ME(Smce_Core_Queue_QueueListen, __construct, arginfo_smce_core_queue_queuelisten___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Queue_QueueListen, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Queue_QueueListen, on, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_Queue_QueueListen, setOn, arginfo_smce_core_queue_queuelisten_seton, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueListen, getOn, arginfo_smce_core_queue_queuelisten_geton, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueListen, transactions, arginfo_smce_core_queue_queuelisten_transactions, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_Queue_QueueListen, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Queue_QueueListen, sleep, arginfo_smce_core_queue_queuelisten_sleep, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Queue_QueueListen, isQue, arginfo_smce_core_queue_queuelisten_isque, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Queue_QueueListen, onPoint, arginfo_smce_core_queue_queuelisten_onpoint, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueListen, getOnPoint, arginfo_smce_core_queue_queuelisten_getonpoint, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueListen, lastTransactionTime, arginfo_smce_core_queue_queuelisten_lasttransactiontime, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueListen, getLastTransactionTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Queue_QueueListen, changeStatus, arginfo_smce_core_queue_queuelisten_changestatus, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueListen, getStatus, arginfo_smce_core_queue_queuelisten_getstatus, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueListen, status, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Queue_QueueListen, getAll, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
