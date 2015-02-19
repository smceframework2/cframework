
extern zend_class_entry *smce_components_collection_ce;

ZEPHIR_INIT_CLASS(Smce_Components_Collection);

PHP_METHOD(Smce_Components_Collection, __construct);
PHP_METHOD(Smce_Components_Collection, each);
PHP_METHOD(Smce_Components_Collection, fetch);
PHP_METHOD(Smce_Components_Collection, map);
PHP_METHOD(Smce_Components_Collection, filter);
PHP_METHOD(Smce_Components_Collection, pull);
PHP_METHOD(Smce_Components_Collection, pop);
PHP_METHOD(Smce_Components_Collection, diff);
PHP_METHOD(Smce_Components_Collection, getAll);
PHP_METHOD(Smce_Components_Collection, first);
PHP_METHOD(Smce_Components_Collection, flatten);
PHP_METHOD(Smce_Components_Collection, get);
PHP_METHOD(Smce_Components_Collection, flip);
PHP_METHOD(Smce_Components_Collection, has);
PHP_METHOD(Smce_Components_Collection, isEmpty);
PHP_METHOD(Smce_Components_Collection, keys);
PHP_METHOD(Smce_Components_Collection, lists);
PHP_METHOD(Smce_Components_Collection, merge);
PHP_METHOD(Smce_Components_Collection, last);
PHP_METHOD(Smce_Components_Collection, offsetExists);
PHP_METHOD(Smce_Components_Collection, prepend);
PHP_METHOD(Smce_Components_Collection, reduce);
PHP_METHOD(Smce_Components_Collection, reverse);
PHP_METHOD(Smce_Components_Collection, search);
PHP_METHOD(Smce_Components_Collection, shift);
PHP_METHOD(Smce_Components_Collection, sort);
PHP_METHOD(Smce_Components_Collection, splice);
PHP_METHOD(Smce_Components_Collection, transform);
PHP_METHOD(Smce_Components_Collection, values);
PHP_METHOD(Smce_Components_Collection, unique);
PHP_METHOD(Smce_Components_Collection, shuffle);
PHP_METHOD(Smce_Components_Collection, count);
PHP_METHOD(Smce_Components_Collection, push);
PHP_METHOD(Smce_Components_Collection, offsetSet);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, items)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_each, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_fetch, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_map, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_filter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_pull, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, dt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_diff, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_first, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 1)
	ZEND_ARG_INFO(0, dt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, dt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_lists, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_merge, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_prepend, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_reduce, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, initial)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_search, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, strict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_sort, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_splice, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, replacement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_transform, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_push, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_collection_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_components_collection_method_entry) {
	PHP_ME(Smce_Components_Collection, __construct, arginfo_smce_components_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Components_Collection, each, arginfo_smce_components_collection_each, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, fetch, arginfo_smce_components_collection_fetch, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, map, arginfo_smce_components_collection_map, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, filter, arginfo_smce_components_collection_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, pull, arginfo_smce_components_collection_pull, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, pop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, diff, arginfo_smce_components_collection_diff, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, first, arginfo_smce_components_collection_first, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, flatten, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, get, arginfo_smce_components_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, flip, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, has, arginfo_smce_components_collection_has, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, lists, arginfo_smce_components_collection_lists, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, merge, arginfo_smce_components_collection_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, last, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, offsetExists, arginfo_smce_components_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, prepend, arginfo_smce_components_collection_prepend, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, reduce, arginfo_smce_components_collection_reduce, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, reverse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, search, arginfo_smce_components_collection_search, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, shift, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, sort, arginfo_smce_components_collection_sort, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, splice, arginfo_smce_components_collection_splice, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, transform, arginfo_smce_components_collection_transform, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, values, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, unique, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, shuffle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, push, arginfo_smce_components_collection_push, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Collection, offsetSet, arginfo_smce_components_collection_offsetset, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
